#include "pch.h"
#include "ImageInformation_Get.h"
/********************************************************************
//    Created:     2022/04/26  10:56:37
//    File Name:   D:\IEngine_Image\IEngine_Source\IEngine_ImageInformation\ImageInformation_Get\ImageInformation_Get.cpp
//    File Path:   D:\IEngine_Image\IEngine_Source\IEngine_ImageInformation\ImageInformation_Get
//    File Base:   ImageInformation_Get
//    File Ext:    cpp
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     图像信息获取
//    History:
*********************************************************************/
CImageInformation_Get::CImageInformation_Get()
{
}
CImageInformation_Get::~CImageInformation_Get()
{
}
//////////////////////////////////////////////////////////////////////////
//                        公有函数
//////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：ImageInfo_Get_Attr
函数功能：获取图像属性
 参数.一：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入图像地址
 参数.二：pSt_BaseInfo
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出图像基本信息
 参数.三：pSt_ExtAttr
  In/Out：Out
  类型：数据结构指针
  可空：Y
  意思：输出图像扩展信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CImageInformation_Get::ImageInfo_Get_Attr(LPCTSTR lpszFile, IMAGEINFO_BASEATTR* pSt_BaseInfo /* = NULL */, IMAGEINFO_EXTENDATTR* pSt_ExtAttr /* = NULL */)
{
	Image_IsErrorOccur = FALSE;

	if (NULL == lpszFile)
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_GET_PARAMENT;
		return FALSE;
	}
	//读取文件
#ifdef _UNICODE
	USES_CONVERSION;
	cv::Mat m_Frame = cv::imread(W2A(lpszFile), cv::IMREAD_UNCHANGED);
#else
	cv::Mat m_Frame = cv::imread(lpszFile, cv::IMREAD_UNCHANGED);
#endif
	if (m_Frame.empty())
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_GET_OPEN;
		return FALSE;
	}
	//获取信息
	if (NULL != pSt_BaseInfo)
	{
		pSt_BaseInfo->nWidth = m_Frame.rows;
		pSt_BaseInfo->nHeigth = m_Frame.cols;
		pSt_BaseInfo->nChannel = m_Frame.channels();
	}
	//获取其他信息
	if (NULL != pSt_ExtAttr)
	{
		pSt_ExtAttr->nItem = m_Frame.elemSize();
		pSt_ExtAttr->nDepth = m_Frame.depth();
		pSt_ExtAttr->nType = m_Frame.type();
	}
	return TRUE;
}