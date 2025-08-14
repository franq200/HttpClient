rm -f %USERPROFILE%\httpclient_tmp_vcpkg
mkdir %USERPROFILE%\httpclient_tmp_vcpkg
cd %USERPROFILE%\httpclient_tmp_vcpkg
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg.exe install curl
.\vcpkg.exe integrate install
rm -f %USERPROFILE%\httpclient_tmp_vcpkg