@echo off
set GCC_PATH=C:\Program Files\CodeSourcery\Sourcery G++ Lite\bin
path %GCC_PATH%;%path%;

rd ..\debug/s/q
md ..\debug

cd ..\source\modules

SET P_COUNT=16
set LOG_FILE=..\..\debug\stubgen.log
if {%*}=={} (set mods=*) else (set mods=%*)

REM ------------------------------Thumb code compile-----------------------------
SET CODE=ARM
SET COMPILER=GCC

for /d %%i in (%mods%) do call:sub_run_module "make %COMPILER%%CODE% %%i" "make %%i.a -j%P_COUNT% COMPILER=%COMPILER% CODE=%CODE% MODULE=%%i" 2 "..\..\debug\%%i.log"

copy ..\..\debug\*.a ..\..\..\..\variants\linkit_one /y

cd ..\..\build_gcc

rem ***************************************************************************
rem *** run Sub module
rem *** %1 = submodule description
rem *** %2 = command line
rem *** %3 = error direction (1 or 2)
rem *** %4 = log filename
rem *** %5 = log pattern
:sub_run_module
echo -----------------%~1----------------
echo =========================================================================== >> %LOG_FILE%
rem Reset the value of SUB_MODULE_RET to FAIL
set SUB_MODULE_RET=FAIL

echo [%Time%] %~1 >> %LOG_FILE%

%~2 %3> %~4

echo [%Time%] Executed %~1 >> %LOG_FILE%

rem Check if the program return success or not
IF %ERRORLEVEL% EQU 0 SET SUB_MODULE_RET=OK
IF %ERRORLEVEL% EQU 1 SET SUB_MODULE_RET=OK

IF NOT "%SUB_MODULE_RET%"=="OK" (
    echo Failed!! [%ERRORLEVEL%] >> %LOG_FILE%
    call:sub_parse_error %~4 %~5
)ELSE (
    echo Succeed. [%ERRORLEVEL%][%Time%] >> %LOG_FILE%
)

echo. >> %LOG_FILE%
goto:eof



rem ************************************************************
rem **************** Parse Error function **********************
rem ************************************************************
:sub_parse_error
echo log = [%1], error summarized: >> %LOG_FILE%
echo. >> %LOG_FILE%

IF .%2==. (
    FINDSTR /I /N /R "\<error\>" %1 > ~tmp.str
) ELSE (
    FINDSTR /I /N /R "\<%2\>" %1 > ~tmp.str
)
type ~tmp.str >> %LOG_FILE%
del ~tmp.str
goto:eof