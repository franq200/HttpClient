mkdir %USERPROFILE%\vcpkg
cd %USERPROFILE%\vcpkg
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
call bootstrap-vcpkg.bat
.\vcpkg.exe install curl
.\vcpkg.exe integrate install