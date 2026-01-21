@echo off
setlocal
cd /d " "%%~dp0
if exist build-x86 rmdir /s /q build-x86
cmake -S . -B build-x86 -A Win32
if errorlevel 1 exit /b 1
cmake --build build-x86 --config Release
endlocal
