gcc %1.c -o %1
if %errorlevel%==0 (
    %1.exe
)