@echo off

call "./bin/Release_Windows_x64/BoonTest"

if NOT "%~1" == "--nopause" (
	if NOT "%~1" == "-np" (
		pause
	)
)