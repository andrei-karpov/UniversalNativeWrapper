@echo off
setlocal
cd /d " "%%~dp0
if exist build-x64 rmdir /s /q build-x64
cmake -S . -B build-x64 -A x64
if errorlevel 1 exit /b 1
cmake --build build-x64 --config Release
endlocal
