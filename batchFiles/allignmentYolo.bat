@echo off
setlocal EnableDelayedExpansion

cd "C:\Users\hanmu\Desktop\2D_LidarCamFusion\LIDAR\Debug"

start LIDAR.exe

timeout /t 1

call activate py39

cd "C:\Users\hanmu\Desktop\Camera"

start python maruta.py

timeout /t 7

cd "C:\Users\hanmu\Desktop\2D_LidarCamFusion"

start python lidarCamAlignment.py

choice /c eq /n /t 0 /d q

if errorlevel 2 goto end

if errorlevel 1 goto waitForUserInput

taskkill /im LIDAR.exe /f
taskkill /im python.exe /f

pause