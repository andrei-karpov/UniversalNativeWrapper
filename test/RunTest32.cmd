@echo off
chcp 65001 >nul
set "CSCRIPT32=%SystemRoot%\SysWOW64\cscript.exe"
if exist "%CSCRIPT32%" (
    "%CSCRIPT32%" //nologo "%~dp0RunTest32.vbs"
) else (
    cscript //nologo "%~dp0RunTest32.vbs"
)
