
STUB_INC = -I "../../../../system/libmtk/include"
OUTDIR = ../../debug

STUB_SOURCES_PATH = ./$(MODULE)
STUB_SOURCES = $(patsubst $(STUB_SOURCES_PATH)/%, %,$(wildcard $(STUB_SOURCES_PATH)/*.c))
STUB_OBJS = $(patsubst %.c, $(OUTDIR)/%.o, $(STUB_SOURCES))

INC_PATH_LIST = $(patsubst "%",%,$(filter "%",$(STUB_INC)))
STUB_HEADER_LIST = $(filter-out %enum_list.h,$(foreach list, $(INC_PATH_LIST), $(wildcard $(list)/*.h)))

ifeq ($(strip $(COMPILER)), GCC)
CC=arm-none-eabi-gcc.exe
AR=arm-none-eabi-ar.exe
STUBCFLAG=-c -fpic -fvisibility=hidden -mthumb -mcpu=arm7tdmi-s -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions
STUBARFLAG=cr 
endif

INC=$(STUB_INC)
OBJECTS=$(STUB_OBJS)
VPATH=$(STUB_SOURCES_PATH)

$(OUTDIR)/%.o: %.c $(STUB_HEADER_LIST)
	@echo Compiling $< & 
	@$(CC) $(STUBCFLAG) $(INC) $< -o $@	

$(MODULE).a: $(OBJECTS)
	@echo Linking $@ & 
	@$(AR) $(STUBARFLAG)$(OUTDIR)/$(MODULE).a $(OBJECTS)
