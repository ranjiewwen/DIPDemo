# Microsoft Developer Studio Project File - Name="DIPDemo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=DIPDemo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DIPDemo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DIPDemo.mak" CFG="DIPDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DIPDemo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DIPDemo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
F90=df.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DIPDemo - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "DIPDemo - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "DIPDemo - Win32 Release"
# Name "DIPDemo - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\cDlgMorphClose.cpp
# End Source File
# Begin Source File

SOURCE=.\cDlgMorphDilation.cpp
# End Source File
# Begin Source File

SOURCE=.\cDlgMorphErosion.cpp
# End Source File
# Begin Source File

SOURCE=.\cDlgMorphOpen.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\DIPDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\DIPDemoDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\DIPDemoView.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgColor.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgEdgeSobelPrewitt.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgFreqGaussBRF.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgFreqGaussHPF.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgFreqGaussLPF.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgFreqIdealLPF.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGamma.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGeoRota.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGeoTran.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGeoZoom.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGrayScaling.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgHist.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgHough.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLinerPara.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLinTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLog.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMidFilter.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMorph.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPointThre.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPointWin.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgProjRestore.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSharpThre.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSmooth.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgWndTran.cpp
# End Source File
# Begin Source File

SOURCE=.\Img.cpp
# End Source File
# Begin Source File

SOURCE=.\ImgProcess.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "DIPDemo - Win32 Release"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "DIPDemo - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# End Source File
# Begin Source File

SOURCE=.\Vector2D.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\cDlgMorphClose.h
# End Source File
# Begin Source File

SOURCE=.\cDlgMorphDilation.h
# End Source File
# Begin Source File

SOURCE=.\cDlgMorphErosion.h
# End Source File
# Begin Source File

SOURCE=.\cDlgMorphOpen.h
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\detect.h
# End Source File
# Begin Source File

SOURCE=.\DIPDemo.h
# End Source File
# Begin Source File

SOURCE=.\DIPDemoDoc.h
# End Source File
# Begin Source File

SOURCE=.\DIPDemoView.h
# End Source File
# Begin Source File

SOURCE=.\DlgColor.h
# End Source File
# Begin Source File

SOURCE=.\DlgEdgeSobelPrewitt.h
# End Source File
# Begin Source File

SOURCE=.\DlgFreqGaussBRF.h
# End Source File
# Begin Source File

SOURCE=.\DlgFreqGaussHPF.h
# End Source File
# Begin Source File

SOURCE=.\DlgFreqGaussLPF.h
# End Source File
# Begin Source File

SOURCE=.\DlgFreqIdealLPF.h
# End Source File
# Begin Source File

SOURCE=.\DlgGamma.h
# End Source File
# Begin Source File

SOURCE=.\DlgGeoRota.h
# End Source File
# Begin Source File

SOURCE=.\DlgGeoTran.h
# End Source File
# Begin Source File

SOURCE=.\DlgGeoZoom.h
# End Source File
# Begin Source File

SOURCE=.\DlgGrayScaling.h
# End Source File
# Begin Source File

SOURCE=.\DlgHist.h
# End Source File
# Begin Source File

SOURCE=.\DlgHough.h
# End Source File
# Begin Source File

SOURCE=.\DlgLinerPara.h
# End Source File
# Begin Source File

SOURCE=.\DlgLinTrans.h
# End Source File
# Begin Source File

SOURCE=.\DlgLog.h
# End Source File
# Begin Source File

SOURCE=.\DlgMidFilter.h
# End Source File
# Begin Source File

SOURCE=.\DlgMorph.h
# End Source File
# Begin Source File

SOURCE=.\DlgPointThre.h
# End Source File
# Begin Source File

SOURCE=.\DlgPointWin.h
# End Source File
# Begin Source File

SOURCE=.\DlgProjRestore.h
# End Source File
# Begin Source File

SOURCE=.\DlgSharpThre.h
# End Source File
# Begin Source File

SOURCE=.\DlgSmooth.h
# End Source File
# Begin Source File

SOURCE=.\DlgWndTran.h
# End Source File
# Begin Source File

SOURCE=.\Img.h
# End Source File
# Begin Source File

SOURCE=.\ImgProcess.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\test.h
# End Source File
# Begin Source File

SOURCE=.\Vector2D.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\DIPDemo.ico
# End Source File
# Begin Source File

SOURCE=.\DIPDemo.rc
# End Source File
# Begin Source File

SOURCE=.\res\DIPDemo.rc2
# End Source File
# Begin Source File

SOURCE=.\res\DIPDemoDoc.ico
# End Source File
# Begin Source File

SOURCE=.\test.bmp
# End Source File
# Begin Source File

SOURCE=.\testPD.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
