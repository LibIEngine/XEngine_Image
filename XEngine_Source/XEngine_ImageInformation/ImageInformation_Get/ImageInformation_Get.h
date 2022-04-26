#pragma once
/********************************************************************
//    Created:     2022/04/18  11:17:59
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageInformation\ImageInformation_Get\ImageInformation_Get.h
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageInformation\ImageInformation_Get
//    File Base:   ImageInformation_Get
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     图像信息获取
//    History:
*********************************************************************/


class CImageInformation_Get
{
public:
	CImageInformation_Get();
	~CImageInformation_Get();
public:
	BOOL ImageInfo_Get_Attr(LPCTSTR lpszFile, IMAGEINFO_BASEATTR* pSt_BaseInfo = NULL, IMAGEINFO_EXTENDATTR* pSt_ExtAttr = NULL);
protected:
private:
};