$ENV{HARNESS_ACTIVE} = 1;
$ENV{TOP} = 'E:/epics_for_win/extensions/src/seq/seq-2.2.5';
$ENV{PATH} = 'E:/epics_for_win/extensions/src/seq/seq-2.2.5/bin/windows-x64;E:/epics_for_win/base/base-3.15.5/bin/windows-x64;E:/epics_for_win/base/base-3.15.5/bin/windows-x64;;;;C:/vs2013/Common7/IDE/CommonExtensions/Microsoft/TestWindow;C:/Program Files (x86)/Microsoft SDKs/F#/3.1/Framework/v4.0/;C:/Program Files (x86)/MSBuild/12.0/bin;C:/vs2013/Common7/IDE/;C:/vs2013/VC/BIN/x86_amd64;C:/vs2013/VC/BIN;C:/vs2013/Common7/Tools;C:/Windows/Microsoft.NET/Framework/v4.0.30319;C:/vs2013/VC/VCPackages;C:/Program Files (x86)/HTML Help Workshop;C:/vs2013/Team Tools/Performance Tools;C:/Program Files (x86)/Windows Kits/8.1/bin/x86;C:/Program Files (x86)/Microsoft SDKs/Windows/v8.1A/bin/NETFX 4.5.1 Tools/x64/;D:/Python/Scripts/;D:/Python/;C:/Program Files/Microsoft MPI/Bin/;C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v9.0/bin;C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v9.0/libnvvp;C:/Windows/system32;C:/Windows;C:/Windows/System32/Wbem;C:/Windows/System32/WindowsPowerShell/v1.0/;C:/Program Files (x86)/NVIDIA Corporation/PhysX/Common;D:/Program Files/PuTTY/;D:/Program Files (x86)/National Instruments/LabVIEW 2013/user.lib/caLab/lib;D:/Program Files (x86)/National Instruments/LabVIEW 2013/user.lib/caLab/lib;C:/Program Files/Keysight/IO Libraries Suite/bin;C:/Program Files/IVI Foundation/VISA/Win64/ktvisa;C:/Program Files/IVI Foundation/VISA/Win64/bin;C:/Program Files (x86)/Keysight/IO Libraries Suite/bin;C:/Program Files (x86)/IVI Foundation/VISA/WinNT/ktvisa;C:/Program Files (x86)/IVI Foundation/VISA/WinNT/bin;C:/Program Files (x86)/IVI Foundation/IVI/bin;C:/Program Files/IVI Foundation/IVI/bin;C:/Program Files (x86)/IVI Foundation/VISA/WinNT/Bin/;C:/Program Files/IVI Foundation/VISA/Win64/Bin/;C:/Program Files (x86)/IVI Foundation/VISA/winnt/agvisa;C:/Program Files/dotnet/;C:/Program Files (x86)/VISA/winnt/agvisa;E:/epics_for_win/base-3.15.5/bin/windows-x64;C:/MinGW/mingw64/bin;C:/Strawberry/c/bin;C:/Strawberry/perl/site/bin;C:/Strawberry/perl/bin;C:/Program Files/Microsoft SQL Server/110/Tools/Binn/;C:/GunWin32/GetGnuWin32/bin;E:/opencv/build/x64/vc12/bin;C:/Users/Administrator/AppData/Local/Microsoft/WindowsApps;C:/Users/Administrator/AppData/Local/GitHubDesktop/bin;C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v9.0/bin;C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v9.0/lib/x64';
$ENV{EPICS_CA_SERVER_PORT} = 10000 + $$ % 30000;
#only for debugging:
#print STDERR "port=$ENV{EPICS_CA_SERVER_PORT}\n";
system "./commaOperator.exe -S -t";
