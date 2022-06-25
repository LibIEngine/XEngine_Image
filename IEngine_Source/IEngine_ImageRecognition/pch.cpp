#include "pch.h"
#include "ImageRecognition_Help/ImageRecognition_Help.h"
/********************************************************************
//    Created:     2022/04/26  11:00:14
//    File Name:   D:\IEngine_Image\IEngine_Source\IEngine_ImageRecognition\pch.cpp
//    File Path:   D:\IEngine_Image\IEngine_Source\IEngine_ImageRecognition
//    File Base:   pch
//    File Ext:    cpp
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     导出定义实现
//    History:
*********************************************************************/
BOOL Image_IsErrorOccur = FALSE;
DWORD Image_dwErrorCode = 0;
//////////////////////////////////////////////////////////////////////////
CImageRecognition_Help m_ImageHelp;
//////////////////////////////////////////////////////////////////////////
//                            导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD ImageRecognition_GetLastError(int* pInt_SysError)
{
	if (NULL != pInt_SysError)
	{
		*pInt_SysError = errno;
	}
	return Image_dwErrorCode;
}
/************************************************************************/
/*                          图像识别帮助函数                            */
/************************************************************************/
extern "C" BOOL ImageRecognition_Help_QREncodec(LPCTSTR lpszFileName, LPCTSTR lpszMsgBuffer)
{
	return m_ImageHelp.ImageRecognition_Help_QREncodec(lpszFileName, lpszMsgBuffer);
}
extern "C" BOOL ImageRecognition_Help_QRDecodecFile(LPCTSTR lpszFileName, TCHAR * ptszMsgBuffer, LPCTSTR lpszDetectProto, LPCTSTR lpszDetectModel, LPCTSTR lpszSrProto, LPCTSTR lpszSrModel)
{
	return m_ImageHelp.ImageRecognition_Help_QRDecodecFile(lpszFileName, ptszMsgBuffer, lpszDetectProto, lpszDetectModel, lpszSrProto, lpszSrModel);
}
extern "C" BOOL ImageRecognition_Help_QRDecodecMemory(LPCSTR lpszMsgBuffer, int nMsgLen, TCHAR * ptszMsgBuffer, LPCTSTR lpszDetectProto, LPCTSTR lpszDetectModel, LPCTSTR lpszSrProto, LPCTSTR lpszSrModel)
{
	return m_ImageHelp.ImageRecognition_Help_QRDecodecMemory(lpszMsgBuffer, nMsgLen, ptszMsgBuffer, lpszDetectProto, lpszDetectModel, lpszSrProto, lpszSrModel);
}
extern "C" BOOL ImageRecognition_Help_QRCamera(TCHAR * ptszMsgBuffer, LPCTSTR lpszDetectProto, LPCTSTR lpszDetectModel, LPCTSTR lpszSrProto, LPCTSTR lpszSrModel, int nDeviceID, int nTimeout)
{
	return m_ImageHelp.ImageRecognition_Help_QRCamera(ptszMsgBuffer, lpszDetectProto, lpszDetectModel, lpszSrProto, lpszSrModel, nDeviceID, nTimeout);
}