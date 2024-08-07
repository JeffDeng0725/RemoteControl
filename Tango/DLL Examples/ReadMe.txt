
The examples are based on the TANGO DLL (32 and/or 64 bit), but might not use the latest DLL version.
--> Make sure always to use latest DLL version during setup of your own project.

Some examples require one or two of the TANGO DLL header files (Tango.h, TangoLSX_API.h, or Tango_DLL.h) or the Tango.cpp file, 
others possibly the Tango_DLL.lib file. Please check the examples or read the TANGO DLL Documentation.

The TANGO DLL might also require the MFC runtime file "mfc140.dll" in order to display its protocol window.
If the DLL does not work, especially the DLL's protocol window, make sure the Microsoft Redistributable Package is installed.
Usually this happens already when installing Microsoft software on the computer, but if not, it can be downloaded here:

https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170

--> 32 bit:   https://aka.ms/vs/17/release/vc_redist.x86.exe
--> 64 bit:   https://aka.ms/vs/17/release/vc_redist.x64.exe

