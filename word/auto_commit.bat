git pull origin master
::input commit message
set /p commit_msg=PLease input commit message:
::show git status
git status
pause
git add .
pause
git commit -m "%commit_msg%"
pause
git push origin master
pause