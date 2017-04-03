## 《数字图像处理与机器视觉:Visual C++与Matlab实现》

- 各种标准图像处理算法(Matlab／Visual C++) 
- 汽车牌照的投影失真校正(Matlab／Visual C++) 
- 顶帽变换(Matlab／Visual C++) 
- 主成份分析(Matlab) 
- LBP特征提取(Matlab) 
- 基于人工神经网络的数字识别系统(visual C++) 
- 基于支持向量机的人脸识别系统(Matlab) 为想要了解数字图像处理与机器视觉领域的读者提供了一条扎实的进阶之路，从基本的图像处理算法，到投影校正、顶帽变换等高级应用，再到特征提取、分类器设计，以及像光学字符识别、人脸识别等综合案例，一步步地引导读者从阅读中获得知识，于实践中升华感悟。
- Matoab与Visusl C++两种语言描述的无缝连接，体现出科学研究和工程实践在图像处理与机器视觉领域的完美结合。

**该代码已经在VS2013下实验通过，很多基础的图像处理算法C++实现都在里面**
## MICROSOFT FOUNDATION CLASS LIBRARY : DIPDemo

AppWizard has created this DIPDemo application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your DIPDemo application.

>
DIPDemo.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CDIPDemoApp application class.

DIPDemo.cpp
    This is the main application source file that contains the application
    class CDIPDemoApp.

DIPDemo.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Visual C++.

DIPDemo.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

res\DIPDemo.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file DIPDemo.rc.

res\DIPDemo.rc2
    This file contains resources that are not edited by Microsoft 
	Visual C++.  You should place all resources not editable by
	the resource editor in this file.

## For the main frame window:

>
MainFrm.h, MainFrm.cpp
    These files contain the frame class CMainFrame, which is derived from
    CMDIFrameWnd and controls all MDI frame features.

res\Toolbar.bmp
    This bitmap file is used to create tiled images for the toolbar.
    The initial toolbar and status bar are constructed in the CMainFrame
    class. Edit this toolbar bitmap using the resource editor, and
    update the IDR_MAINFRAME TOOLBAR array in DIPDemo.rc to add
    toolbar buttons.

## For the child frame window:
>
ChildFrm.h, ChildFrm.cpp
    These files define and implement the CChildFrame class, which
    supports the child windows in an MDI application.


## AppWizard creates one document type and one view:
>
DIPDemoDoc.h, DIPDemoDoc.cpp - the document
    These files contain your CDIPDemoDoc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via CDIPDemoDoc::Serialize).

DIPDemoView.h, DIPDemoView.cpp - the view of the document
    These files contain your CDIPDemoView class.
    CDIPDemoView objects are used to view CDIPDemoDoc objects.

res\DIPDemoDoc.ico
    This is an icon file, which is used as the icon for MDI child windows
    for the CDIPDemoDoc class.  This icon is included by the main
    resource file DIPDemo.rc.


