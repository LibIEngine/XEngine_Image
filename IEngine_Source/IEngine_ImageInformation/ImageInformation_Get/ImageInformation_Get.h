#pragma once
/********************************************************************
//    Created:     2022/04/26  10:56:02
//    File Name:   D:\IEngine_Image\IEngine_Source\IEngine_ImageInformation\ImageInformation_Get\ImageInformation_Get.h
//    File Path:   D:\IEngine_Image\IEngine_Source\IEngine_ImageInformation\ImageInformation_Get
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