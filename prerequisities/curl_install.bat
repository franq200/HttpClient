mkdir %USERPROFILE%\vcpkg
cd %USERPROFILE%\vcpkg
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
call bootstrap-vcpkg.bat
.\vcpkg.exe install curl
.\vcpkg.exe install nlohmann-json
.\vcpkg.exe install gtest
.\vcpkg.exe install gmock
.\vcpkg.exe integrate install