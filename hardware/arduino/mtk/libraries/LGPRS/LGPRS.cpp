#include <Arduino.h>
#include "LTask.h"
#include "LGPRS.h"
#include "IPAddress.h"
#include "vmnwsetting.h"
#include "vmconn.h"
#include "vmsim.h"
#include "vmcell.h"
#include "vmlog.h"
#include "vmtcp.h"
#include "vmsettings.h"

class LGPRSConnectContext;

LGPRSClass::LGPRSClass():
	m_simCardReady(0)
{
	
}

static void gprsSettingCallback(VMINT32 result, void *user_data)
{
	vm_log_info("gprsSettingCallback result=%d", result);
	
	// Is there GSM?
	VMINT protocol = vm_srv_nw_info_get_protocol(VM_SIM_SIM1);
	vm_log_info("SIM protocol=%d", protocol);

	// Is there GPRS?
	// VMINT networkReady = vm_srv_nw_info_channel_supports(VM_SIM_SIM1, VM_GPRS);
	//vm_log_info("SIM GPRS ready? %d", networkReady);

	// get APN info
	vm_apn_info_ext apnInfo;
	VMINT apnRet = vm_get_apn_info(&apnInfo);
	vm_log_info("vm_get_apn_info = %d", apnRet);
	vm_log_info("operator ID= %s", apnInfo.operator_id);
	vm_log_info("operator Name= %s", apnInfo.operator_name);	

	// retrieve cell info
	VMINT openResult = vm_cell_open();
	vm_log_info("open cell = %d", openResult);
	vm_cell_info_struct *pCell = vm_cell_get_cur_cell_info();
	if (pCell)
	{
		vm_log_info("cell rxlev=%d", pCell->rxlev);
		vm_log_info("cell arfcn=%d", pCell->arfcn);
		vm_log_info("cell bsic=%d", pCell->bsic);
		vm_log_info("cell mcc=%d", pCell->mcc);
		vm_log_info("cell mnc=%d", pCell->mnc);
		vm_log_info("cell lac=%d", pCell->lac);
		vm_log_info("cell ci=%d", pCell->ci);
	}
	else
	{
		vm_log_info("no cell info");
	}
	
	vm_cell_close();

	// release blocking signal
	LTask.post_signal();
}


boolean LGPRSClass::gprsCheckSIM(void *userData)
{
	LGPRSClass *pThis =(LGPRSClass*)userData; 
	vm_log_info("Has SIM? %d", vm_has_sim_card());
	vm_log_info("SIM count? %d", vm_sim_card_count());
	vm_log_info("IMEI=%s", vm_get_imei());

	// Is there SIM card ready?
	VMINT simCardCount = vm_sim_card_count();
	if (simCardCount > 0)
	{
		pThis->m_simCardReady = 1;
	}

	vm_set_active_sim_card(VM_SIM_SIM1);

	VMINT simStatus = vm_get_sim_card_status(VM_SIM_SIM1);
	vm_log_info("SIM card state=%d", simStatus);


	// Let's enable GPRS
	VMINT32 result = vm_setting_srv_command(VM_SETTING_CELLULAR_GPRS_SERVICE, 
											VM_OPERATION_GPRS_SERVICE_ON, 
											NULL, 
											NULL, 
											NULL,
											NULL);
	if (result == VM_SETTING_RESULT_OK)
	{
	   vm_log_info("vm_setting_srv_command OK");
	}
	else if (result == VM_SETTING_RESULT_INVALID)
	{
		vm_log_info("vm_setting_srv_command INVALID");
	}
	else
	{
		vm_log_info("vm_setting_srv_command failed.");
	}
	
	// Is there GSM?
	VMINT protocol = vm_srv_nw_info_get_protocol(VM_SIM_SIM1);
	vm_log_info("SIM protocol=%d", protocol);

	// Is there GPRS?
	// VMINT networkReady = vm_srv_nw_info_channel_supports(VM_SIM_SIM1, VM_GPRS);
	//vm_log_info("SIM GPRS ready? %d", networkReady);

	// get APN info
	vm_apn_info_ext apnInfo;
	VMINT apnRet = vm_get_apn_info(&apnInfo);
	vm_log_info("vm_get_apn_info = %d", apnRet);
	vm_log_info("operator ID= %s", apnInfo.operator_id);
	vm_log_info("operator Name= %s", apnInfo.operator_name);	

	// retrieve cell info
	VMINT openResult = vm_cell_open();
	vm_log_info("open cell = %d", openResult);
	vm_cell_info_struct *pCell = vm_cell_get_cur_cell_info();
	if (pCell)
	{
		vm_log_info("cell rxlev=%d", pCell->rxlev);
		vm_log_info("cell arfcn=%d", pCell->arfcn);
		vm_log_info("cell bsic=%d", pCell->bsic);
		vm_log_info("cell mcc=%d", pCell->mcc);
		vm_log_info("cell mnc=%d", pCell->mnc);
		vm_log_info("cell lac=%d", pCell->lac);
		vm_log_info("cell ci=%d", pCell->ci);
	}
	else
	{
		vm_log_info("no cell info");
	}
	
	vm_cell_close();

	
	return true;
}

struct LGPRSAttachContext
{
	vm_dtcnt_info_t info;
	VMINT result;
	VMUINT32 dataAccount;
};

boolean gprsSetCustomAPN(void *userData)
{
	LGPRSAttachContext *pCntx = (LGPRSAttachContext*)userData;
	VMUINT32 dtacct = 0;
	VMINT ret = 0;
	#if 0
	ret = vm_set_cust_apn_info(&pCntx->info, &dtacct);
	#endif
	
	if(0 != ret)
	{
		vm_log_error("vm_set_cust_apn_info fails with %d", ret);
		pCntx->result = ret;
		return true;
	}

	// we have only 1 SIM card
	ret = vm_dtacct_set(VM_SIM_SIM1, dtacct);
	if(0 != ret)
	{
		vm_log_error("vm_dtacct_set fails with %d", ret);
		pCntx->result = ret;
		return true;
	}
	
	pCntx->result = 0;
	return true;
}

int LGPRSClass::attachGPRS(const char *apn, const char *username, const char *password)
{
	LTask.remoteCall(&gprsCheckSIM, this);
	if(!m_simCardReady)
	{
		return m_simCardReady;
	}

	// setup custom APN
	LGPRSAttachContext cntx;
	memset(&cntx, 0, sizeof(cntx));
	strncpy((char*)cntx.info.APN, apn, VM_SRV_DTCNT_PROF_MAX);
	strncpy((char*)cntx.info.UserName, username, VM_SRV_DTCNT_PROF_MAX);
	strncpy((char*)cntx.info.Passwd, password,VM_SRV_DTCNT_PROF_MAX);

	// currently we don't configure proxy and DNS

	LTask.remoteCall(&gprsSetCustomAPN, &cntx);

	if(cntx.result == 0)
	{
		m_customAPN = true;
		return 1;
	}
	else
	{
		m_customAPN = false;
		return 0;
	}
}

int LGPRSClass::attachGPRS()
{
	m_customAPN = false;
	LTask.remoteCall(&gprsCheckSIM, this);
	return m_simCardReady;
}

VMINT LGPRSClass::getAPN() const
{
	if(m_customAPN)
	{
		return VM_APN_USER_DEFINE;
	}
	else
	{
		return VM_TCP_APN_CMNET;
	}
}

struct LGPRSResolveContext
{
	const char *domainName;
	vm_soc_dns_result dns;
	VMINT resolveState;

	LGPRSResolveContext():
		domainName(NULL),
		resolveState(VM_E_SOC_INVAL)
	{
		memset(&dns, 0, sizeof(dns));
	}

	~LGPRSResolveContext()
	{
	}
};

static VMINT gprsResolveCallback(VMINT jobId, vm_soc_dns_result *pDNS, void *userData)
{
	vm_log_info("gprsResolveCallback");
	LGPRSResolveContext *pContext = (LGPRSResolveContext*)userData;
	unsigned char* ipArray = (unsigned char*)&pDNS->address[0];
	vm_log_info("DNS resolve callback, cause=%d, num=%d, address=%d.%d.%d.%d", 
				pDNS->error_cause, 
				pDNS->num,
				ipArray[0],
				ipArray[1],
				ipArray[2],
				ipArray[3]);

	// TODO: since we don't know the definition of error_cause yet,
	// treat all as OK.
	if(pDNS && pDNS != &pContext->dns)
	{
		vm_log_info("pDNS != pContext->dns");
		pContext->dns = *pDNS;
	}
	pContext->resolveState = VM_E_SOC_SUCCESS;
	LTask.post_signal();
}


static boolean gprsResolveDomainName(void *userData)
{
	LGPRSResolveContext *pContext = (LGPRSResolveContext*)userData;

	vm_log_info("vm_soc_get_host_by_name_ex: %s", pContext->domainName);
	pContext->resolveState = vm_soc_get_host_by_name_ex(VM_TCP_APN_CMNET, 
														pContext->domainName, 
														&pContext->dns, 
														&gprsResolveCallback, 
														pContext);
	vm_log_info("vm_soc_get_host_by_name_ex ret = %d", pContext->resolveState);

	if (pContext->resolveState > 0)
	{
		// not done yet
		return false;
	}
	
	switch(pContext->resolveState)
	{
	case VM_E_SOC_SUCCESS:  // Get IP address successfully, result is filled.
  		return true;
	case VM_E_SOC_WOULDBLOCK:  // wait response from network, result could be gotten from callback.
		// need to wait, return directly
		// so MMI message loop may continue.
		return false;
	case VM_E_SOC_INVAL:  // invalid arguments: null domain_name, etc.
	case VM_E_SOC_ERROR:  // unspecified error
	case VM_E_SOC_LIMIT_RESOURCE:  // socket resources not available
	case VM_E_SOC_INVALID_ACCOUNT:  // invalid data account id  
		return true;
	}
}


int LGPRSClass::hostByName(const char* aHostname, IPAddress& aResult)
{
	vm_log_info("hostByName");
	LGPRSResolveContext context;
	// no memory copy since we're blocking call
	context.domainName = aHostname;
	LTask.remoteCall(&gprsResolveDomainName, (void*)&context);

	vm_log_info("context.resolveState = %d", context.resolveState);
	unsigned char* ipArray = (unsigned char*)&context.dns.address[0];
	vm_log_info("Arduino DNS resolve callback, cause=%d, num=%d, address=%d.%d.%d.%d", 
				context.dns.error_cause, 
				context.dns.num,
				ipArray[0],
				ipArray[1],
				ipArray[2],
				ipArray[3]);
	// parse result
	if (VM_E_SOC_SUCCESS == context.resolveState)
	{
		// TODO: why are there multiple ip addresses?
		
		aResult = context.dns.address[0];
		
		vm_log_info("get IP=%d.%d.%d.%d", 
					aResult[0],
					aResult[1],
					aResult[2],
					aResult[3]);
		return 1;
	}
	else
	{
		return 0;
	}
}


IPAddress LGPRSClass::localIP()
{
}

LGPRSClass LGPRS;

