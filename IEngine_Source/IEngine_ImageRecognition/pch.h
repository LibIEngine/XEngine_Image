// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

#ifdef _MSC_BUILD
// 添加要在此处预编译的标头
#include "framework.h"
#include <tchar.h>
#include <atlconv.h>
#endif
#endif //PCH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
#include <opencv2/wechat_qrcode.hpp>
#include <qrencode.h>
using namespace std;
#include "../IEngine_CommHdr.h"
#include "ImageRecognition_Define.h"
#include "ImageRecognition_Error.h"
/********************************************************************
//    Created:     2022/04/26  11:01:05
//    File Name:   D:\IEngine_Image\IEngine_Source\IEngine_ImageRecognition\pch.h
//    File Path:   D:\IEngine_Image\IEngine_Source\IEngine_ImageRecognition
//    File Base:   pch
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     公用头文件
//    History:
*********************************************************************/
extern BOOL Image_IsErrorOccur;
extern DWORD Image_dwErrorCode;