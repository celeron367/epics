$ENV{HARNESS_ACTIVE} = 1;
$ENV{TOP} = 'E:/epics_for_win/extensions/src/seq/seq-2.2.5';
$ENV{PATH} = 'E:/epics_for_win/extensions/src/seq/seq-2.2.5/bin/windows-x64;E:/epics_for_win/base/base-3.15.5/bin/windows-x64;E:/epics_for_win/base/base-3.15.5/bin/windows-x64;;;;D:/Program Files (x86)/Microsoft Visual Studio 12.0/Common7/IDE/CommonExtensions/Microsoft/TestWindow;C:/Program Files (x86)/Microsoft SDKs/F#/3.1/Framework/v4.0/;C:/Program Files (x86)/MSBuild/12.0/bin;D:/Program Files (x86)/Microsoft Visual Studio 12.0/Common7/IDE/;D:/Program Files (x86)/Microsoft Visual Studio 12.0/VC/BIN/x86_amd64;D:/Program Files (x86)/Microsoft Visual Studio 12.0/VC/BIN;D:/Program Files (x86)/Microsoft Visual Studio 12.0/Common7/Tools;C:/Windows/Microsoft.NET/Framework/v4.0.30319;D:/Program Files (x86)/Microsoft Visual Studio 12.0/VC/VCPackages;C:/Program Files (x86)/HTML Help Workshop;D:/Program Files (x86)/Microsoft Visual Studio 12.0/Team Tools/Performance Tools;C:/Program Files (x86)/Windows Kits/8.1/bin/x86;C:/Program Files (x86)/Microsoft SDKs/Windows/v8.1A/bin/NETFX 4.5.1 Tools/x64/;D:/Program Files (x86)/basler/Runtime/Win32/;D:/Program Files (x86)/basler/Runtime/x64/;C:/ProgramData/Oracle/Java/javapath;C:/Program Files/Agilent/MassHunter/Workstation/Qual/B.05.00/bin;C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v8.0/bin;C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v8.0/libnvvp;C:/Program Files (x86)/Intel/iCLS Client/;C:/Program Files/Intel/iCLS Client/;C:/Windows/system32;C:/Windows;C:/Windows/System32/Wbem;C:/Windows/System32/WindowsPowerShell/v1.0/;C:/Program Files (x86)/Intel/Intel(R) Management Engine Components/DAL;C:/Program Files/Intel/Intel(R) Management Engine Components/DAL;C:/Program Files (x86)/Intel/Intel(R) Management Engine Components/IPT;C:/Program Files/Intel/Intel(R) Management Engine Components/IPT;C:/Program Files (x86)/NVIDIA Corporation/PhysX/Common;C:/Program Files/Intel/WiFi/bin/;C:/Program Files/Common Files/Intel/WirelessCommon/;C:/Users/win7/.dnx/bin;C:/Program Files/Microsoft DNX/Dnvm/;C:/Program Files/Microsoft SQL Server/130/Tools/Binn/;C:/Users/win7/.dnx/bin;C:/Program Files/Microsoft DNX/Dnvm/;C:/Program Files/Microsoft SQL Server/120/Tools/Binn/;C:/Program Files (x86)/nodejs/;C:/Program Files (x86)/Windows Kits/10/Windows Performance Toolkit/;C:/Program Files/JAI/SDK/bin;C:/Program Files/JAI/SDK/bin/Win32_i86;C:/Program Files/JAI/SDK/GenICam/bin/Win64_x64;C:/Program Files/JAI/SDK/GenICam/bin/Win32_i86;C:/Program Files/Git/cmd;D:/Strawberry/c/bin;D:/Strawberry/perl/site/bin;D:/Strawberry/perl/bin;e:/epics_for_win/base/base-3.15.5/bin/windows-x64-mingw;C:/Program Files/Microsoft SQL Server/110/Tools/Binn/;C:/gunwin/GetGnuWin32/bin;C:/Users/win7/AppData/Roaming/npm;d:/modeltech64_10.4/win64;C:/MinGW/bin';
$ENV{EPICS_CA_SERVER_PORT} = 10000 + $$ % 30000;
#only for debugging:
#print STDERR "port=$ENV{EPICS_CA_SERVER_PORT}\n";
system "./monitorEvflag.exe -S -t -d ../monitorEvflag.db";
