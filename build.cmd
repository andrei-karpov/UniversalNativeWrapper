@echo off
setlocal

set "VSDEV_CMD=C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat"
if not exist "%VSDEV_CMD%" goto :no_vsdev

call "%VSDEV_CMD%" -arch=amd64
if errorlevel 1 exit /b %errorlevel%

cmake -S . -B build -G "Visual Studio 17 2022" -A x64
if errorlevel 1 exit /b %errorlevel%

cmake --build build --config Release
exit /b %errorlevel%

:no_vsdev
echo Не найден VsDevCmd.bat: %VSDEV_CMD%
exit /b 1
