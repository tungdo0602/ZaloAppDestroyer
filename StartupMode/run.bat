@echo off
copy /Y init.exe "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup"
start init.exe
