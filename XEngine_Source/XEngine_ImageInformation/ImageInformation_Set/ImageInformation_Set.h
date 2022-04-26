#pragma once
/********************************************************************
//    Created:     2022/04/18  11:13:59
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageInformation\ImageInformation_Set\ImageInformation_Set.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageInformation\ImageInformation_Set
//    File Base:   ImageInformation_Set
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     图像信息修改
//    History:
*********************************************************************/


class CImageInformation_Set
{
public:
	CImageInformation_Set();
	~CImageInformation_Set();
public:
	BOOL ImageInfo_Set_FileResolution(LPCTSTR lpszSrcFile, int nWidth, int nHeight, LPCTSTR lpszDstFile = NULL);
	BOOL ImageInfo_Set_FileFlip(LPCTSTR lpszSrcFile, int nOPMethod, LPCTSTR lpszDstFile = NULL);
	BOOL ImageInfo_Set_FileColorCvt(LPCTSTR lpszSrcFile, ENUM_XENGINE_IMAGE_COLOR_INFO enColorInfo, LPCTSTR lpszDstFile = NULL);
	BOOL ImageInfo_Set_FileLigth(LPCTSTR lpszSrcFile, int nGamma, LPCTSTR lpszDstFile = NULL);
	BOOL ImageInfo_Set_FileChannle(LPCTSTR lpszSrcFile, TCHAR*** ppptszDstFile, int nListCount, BOOL bCombo = FALSE);
	BOOL ImageInfo_Set_MemoryResolution(LPCTSTR lpszMsgBuffer, int nWidth, int nHeight, int* pInt_MsgLen, TCHAR* ptszMsgBuffer);
protected:
private:
};