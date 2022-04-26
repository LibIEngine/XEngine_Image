#include "pch.h"
#include "ImageInformation_Set/ImageInformation_Set.h"
#include "ImageInformation_Get/ImageInformation_Get.h"
/********************************************************************
//    Created:     2022/04/18  11:15:34
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageInformation\pch.cpp
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageInformation
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
CImageInformation_Set m_ImageSet;
CImageInformation_Get m_ImageGet;
//////////////////////////////////////////////////////////////////////////
//                          导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD ImageInfo_GetLastError(int* pInt_SysError)
{
	if (NULL != pInt_SysError)
	{
		*pInt_SysError = errno;
	}
	return Image_dwErrorCode;
}
/************************************************************************/
/*                          图像信息修改函数                            */
/************************************************************************/
extern "C" BOOL ImageInfo_Set_FileResolution(LPCTSTR lpszSrcFile, int nWidth, int nHeight, LPCTSTR lpszDstFile)
{
	return m_ImageSet.ImageInfo_Set_FileResolution(lpszSrcFile, nWidth, nHeight, lpszDstFile);
}
extern "C" BOOL ImageInfo_Set_FileFlip(LPCTSTR lpszSrcFile, int nOPMethod, LPCTSTR lpszDstFile)
{
	return m_ImageSet.ImageInfo_Set_FileFlip(lpszSrcFile, nOPMethod, lpszDstFile);
}
extern "C" BOOL ImageInfo_Set_FileColorCvt(LPCTSTR lpszSrcFile, ENUM_XENGINE_IMAGE_COLOR_INFO enColorInfo, LPCTSTR lpszDstFile)
{
	return m_ImageSet.ImageInfo_Set_FileColorCvt(lpszSrcFile, enColorInfo, lpszDstFile);
}
extern "C" BOOL ImageInfo_Set_FileLigth(LPCTSTR lpszSrcFile, int nGamma, LPCTSTR lpszDstFile)
{
	return m_ImageSet.ImageInfo_Set_FileLigth(lpszSrcFile, nGamma, lpszDstFile);
}
extern "C" BOOL ImageInfo_Set_FileChannle(LPCTSTR lpszSrcFile, TCHAR * **ppptszDstFile, int nListCount, BOOL bCombo)
{
	return m_ImageSet.ImageInfo_Set_FileChannle(lpszSrcFile, ppptszDstFile, nListCount, bCombo);
}
extern "C" BOOL ImageInfo_Set_MemoryResolution(LPCTSTR lpszMsgBuffer, int nWidth, int nHeight, int* pInt_MsgLen, TCHAR * ptszMsgBuffer)
{
	return m_ImageSet.ImageInfo_Set_MemoryResolution(lpszMsgBuffer, nWidth, nHeight, pInt_MsgLen, ptszMsgBuffer);
}
/************************************************************************/
/*                          图像信息修改函数                            */
/************************************************************************/
extern "C" BOOL ImageInfo_Get_Attr(LPCTSTR lpszFile, IMAGEINFO_BASEATTR * pSt_BaseInfo, IMAGEINFO_EXTENDATTR * pSt_ExtAttr)
{
	return m_ImageGet.ImageInfo_Get_Attr(lpszFile, pSt_BaseInfo, pSt_ExtAttr);
}