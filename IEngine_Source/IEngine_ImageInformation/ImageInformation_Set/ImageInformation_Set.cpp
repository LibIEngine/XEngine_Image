#include "pch.h"
#include "ImageInformation_Set.h"
/********************************************************************
//    Created:     2022/04/26  10:56:43
//    File Name:   D:\IEngine_Image\IEngine_Source\IEngine_ImageInformation\ImageInformation_Set\ImageInformation_Set.cpp
//    File Path:   D:\IEngine_Image\IEngine_Source\IEngine_ImageInformation\ImageInformation_Set
//    File Base:   ImageInformation_Set
//    File Ext:    cpp
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     图像信息修改
//    History:
*********************************************************************/
CImageInformation_Set::CImageInformation_Set()
{
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);
}
CImageInformation_Set::~CImageInformation_Set()
{
}
//////////////////////////////////////////////////////////////////////////
//                        公有函数
//////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：ImageInfo_Set_FileResolution
函数功能：文件分辨率调整
 参数.一：lpszSrcFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入原始文件
 参数.二：nWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：输入调整后的宽
 参数.三：nHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：输入调整后的高
 参数.四：lpszDstFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入目标文件,如果为NULL,修改原始文件
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CImageInformation_Set::ImageInfo_Set_FileResolution(LPCTSTR lpszSrcFile, int nWidth, int nHeight, LPCTSTR lpszDstFile /* = NULL */)
{
	Image_IsErrorOccur = FALSE;

	if (NULL == lpszSrcFile)
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_PARAMENT;
		return FALSE;
	}
	//读取文件
#ifdef _UNICODE
	USES_CONVERSION;
	cv::Mat m_SrcFrame = cv::imread(W2A(lpszSrcFile), cv::IMREAD_UNCHANGED);
#else
	cv::Mat m_SrcFrame = cv::imread(lpszSrcFile, cv::IMREAD_UNCHANGED);
#endif
	cv::Mat m_DstFrame;
	if (m_SrcFrame.empty())
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_OPEN;
		return FALSE;
	}
	//调整分辨率
	cv::resize(m_SrcFrame, m_DstFrame, cv::Size(nWidth, nHeight));

	if (NULL == lpszDstFile)
	{
#ifdef _UNICODE
		USES_CONVERSION;
		if (!cv::imwrite(W2A(lpszSrcFile), m_DstFrame))
#else
		if (!cv::imwrite(lpszSrcFile, m_DstFrame))
#endif
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE;
			return FALSE;
		}
	}
	else
	{
#ifdef _UNICODE
		USES_CONVERSION;
		if (!cv::imwrite(W2A(lpszDstFile), m_DstFrame))
#else
		if (!cv::imwrite(lpszDstFile, m_DstFrame))
#endif
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE;
			return FALSE;
		}
	}
	return TRUE;
}
/********************************************************************
函数名称：ImageInfo_Set_FileFlip
函数功能：图像翻转
 参数.一：lpszSrcFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入原始文件
 参数.二：nOPMethod
  In/Out：In
  类型：整数型
  可空：N
  意思：输入图像翻转方式,0:上下,1:左右,-1:上下左右同时
 参数.三：lpszDstFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入目标文件,如果为NULL,修改原始文件
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CImageInformation_Set::ImageInfo_Set_FileFlip(LPCTSTR lpszSrcFile, int nOPMethod, LPCTSTR lpszDstFile /* = NULL */)
{
	Image_IsErrorOccur = FALSE;

	if (NULL == lpszSrcFile)
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_PARAMENT;
		return FALSE;
	}
	//读取文件
#ifdef _UNICODE
	USES_CONVERSION;
	cv::Mat m_SrcFrame = cv::imread(W2A(lpszSrcFile), cv::IMREAD_UNCHANGED);
#else
	cv::Mat m_SrcFrame = cv::imread(lpszSrcFile, cv::IMREAD_UNCHANGED);
#endif
	cv::Mat m_DstFrame;
	if (m_SrcFrame.empty())
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_OPEN;
		return FALSE;
	}
	//调整分辨率
	cv::flip(m_SrcFrame, m_DstFrame, nOPMethod);

	if (NULL == lpszDstFile)
	{
#ifdef _UNICODE
		USES_CONVERSION;
		if (!cv::imwrite(W2A(lpszSrcFile), m_DstFrame))
#else
		if (!cv::imwrite(lpszSrcFile, m_DstFrame))
#endif
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE;
			return FALSE;
		}
	}
	else
	{
#ifdef _UNICODE
		USES_CONVERSION;
		if (!cv::imwrite(W2A(lpszDstFile), m_DstFrame))
#else
		if (!cv::imwrite(lpszDstFile, m_DstFrame))
#endif
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE;
			return FALSE;
		}
	}
	return TRUE;
}
/********************************************************************
函数名称：ImageInfo_Set_FileColorCvt
函数功能：色彩空间转换
 参数.一：lpszSrcFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入原始文件
 参数.二：enColorInfo
  In/Out：In
  类型：枚举型
  可空：N
  意思：输入要转换的类型
 参数.三：lpszDstFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入目标文件,如果为NULL,修改原始文件
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CImageInformation_Set::ImageInfo_Set_FileColorCvt(LPCTSTR lpszSrcFile, ENUM_XENGINE_IMAGE_COLOR_INFO enColorInfo, LPCTSTR lpszDstFile /* = NULL */)
{
	Image_IsErrorOccur = FALSE;

	if (NULL == lpszSrcFile)
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_PARAMENT;
		return FALSE;
	}
	//读取文件
#ifdef _UNICODE
	USES_CONVERSION;
	cv::Mat m_SrcFrame = cv::imread(W2A(lpszSrcFile), cv::IMREAD_UNCHANGED);
#else
	cv::Mat m_SrcFrame = cv::imread(lpszSrcFile, cv::IMREAD_UNCHANGED);
#endif
	cv::Mat m_DstFrame;
	if (m_SrcFrame.empty())
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_OPEN;
		return FALSE;
	}
	cv::cvtColor(m_SrcFrame, m_DstFrame, enColorInfo);
	//写到文件
	if (NULL == lpszDstFile)
	{
#ifdef _UNICODE
		USES_CONVERSION;
		if (!cv::imwrite(W2A(lpszSrcFile), m_DstFrame))
#else
		if (!cv::imwrite(lpszSrcFile, m_DstFrame))
#endif
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE;
			return FALSE;
		}
	}
	else
	{
#ifdef _UNICODE
		USES_CONVERSION;
		if (!cv::imwrite(W2A(lpszDstFile), m_DstFrame))
#else
		if (!cv::imwrite(lpszDstFile, m_DstFrame))
#endif
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE;
			return FALSE;
		}
	}
	return TRUE;
}
/********************************************************************
函数名称：ImageInfo_Set_FileLigth
函数功能：亮度与对比度调整
 参数.一：lpszSrcFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入原始文件
 参数.二：nGamma
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要调整的值
 参数.三：lpszDstFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入目标文件,如果为NULL,修改原始文件
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CImageInformation_Set::ImageInfo_Set_FileLigth(LPCTSTR lpszSrcFile, int nGamma, LPCTSTR lpszDstFile /* = NULL */)
{
	Image_IsErrorOccur = FALSE;

	if (NULL == lpszSrcFile)
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_PARAMENT;
		return FALSE;
	}
	//读取文件
#ifdef _UNICODE
	USES_CONVERSION;
	cv::Mat m_SrcFrame = cv::imread(W2A(lpszSrcFile), cv::IMREAD_UNCHANGED);
#else
	cv::Mat m_SrcFrame = cv::imread(lpszSrcFile, cv::IMREAD_UNCHANGED);
#endif
	cv::Mat m_DstFrame = cv::Mat::zeros(m_SrcFrame.size(), m_SrcFrame.type());
	if (m_SrcFrame.empty())
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_OPEN;
		return FALSE;
	}
	//配置
	cv::Mat m_MatScalar = cv::Mat::zeros(m_SrcFrame.size(), m_SrcFrame.type());
	cv::addWeighted(m_SrcFrame, 1.0, m_MatScalar, 0, nGamma, m_DstFrame);
	//写到文件
	if (NULL == lpszDstFile)
	{
#ifdef _UNICODE
		USES_CONVERSION;
		if (!cv::imwrite(W2A(lpszSrcFile), m_DstFrame))
#else
		if (!cv::imwrite(lpszSrcFile, m_DstFrame))
#endif
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE;
			return FALSE;
		}
	}
	else
	{
#ifdef _UNICODE
		USES_CONVERSION;
		if (!cv::imwrite(W2A(lpszDstFile), m_DstFrame))
#else
		if (!cv::imwrite(lpszDstFile, m_DstFrame))
#endif
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE;
			return FALSE;
		}
	}
	return TRUE;
}
/********************************************************************
函数名称：ImageInfo_Set_FileChannle
函数功能：多文件通道操作
 参数.一：lpszSrcFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的文件
 参数.二：ppptszDstFile
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入要操作的目标文件,由用户管理内存
 参数.三：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入文件个数
 参数.四：bCombo
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：组合还是分离,组合参数二输入要组合的文件列表,分离参数二输入分离的文件
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CImageInformation_Set::ImageInfo_Set_FileChannle(LPCTSTR lpszSrcFile, TCHAR*** ppptszDstFile, int nListCount, BOOL bCombo /* = FALSE */)
{
	Image_IsErrorOccur = FALSE;

	if (NULL == lpszSrcFile)
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_PARAMENT;
		return FALSE;
	}
	//读取文件
	if (bCombo)
	{
		//合并通道
		cv::Mat *pm_SrcFrame = new cv::Mat[nListCount];
		if (NULL == pm_SrcFrame)
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_MALLOC;
			return FALSE;
		}
		for (int i = 0; i < nListCount; i++)
		{
#ifdef _UNICODE
			USES_CONVERSION;
			pm_SrcFrame[i] = cv::imread(W2A((*ppptszDstFile)[i]), cv::IMREAD_UNCHANGED);
#else
			pm_SrcFrame[i] = cv::imread((*ppptszDstFile)[i], cv::IMREAD_UNCHANGED);
#endif
		}
		cv::Mat m_DstFrame;
		cv::merge(pm_SrcFrame, nListCount, m_DstFrame);
		delete[]pm_SrcFrame;
		pm_SrcFrame = NULL;
		//写到文件
#ifdef _UNICODE
		USES_CONVERSION;
		if (!cv::imwrite(W2A(lpszSrcFile), m_DstFrame))
#else
		if (!cv::imwrite(lpszSrcFile, m_DstFrame))
#endif
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE;
			return FALSE;
		}
	}
	else
	{
#ifdef _UNICODE
		USES_CONVERSION;
		cv::Mat m_SrcFrame = cv::imread(W2A(lpszSrcFile), cv::IMREAD_UNCHANGED);
#else
		cv::Mat m_SrcFrame = cv::imread(lpszSrcFile, cv::IMREAD_UNCHANGED);
#endif
		cv::Mat *pm_DstFrame = new cv::Mat[nListCount];
		if (NULL == pm_DstFrame)
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_MALLOC;
			return FALSE;
		}
		if (m_SrcFrame.empty())
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_OPEN;
			return FALSE;
		}
		//分离通道
		cv::split(m_SrcFrame, pm_DstFrame);
		//写到文件
		for (int i = 0; i < nListCount; i++)
		{
#ifdef _UNICODE
			USES_CONVERSION;
			if (!cv::imwrite(W2A(lpszSrcFile), pm_DstFrame[i]))
#else
			if (!cv::imwrite(lpszSrcFile, pm_DstFrame[i]))
#endif
			{
				Image_IsErrorOccur = TRUE;
				Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_WRITE;
				return FALSE;
			}
		}
		delete[] pm_DstFrame;
		pm_DstFrame = NULL;
	}
	return TRUE;
}
/********************************************************************
函数名称：ImageInfo_Set_MemoryResolution
函数功能：内存分辨率调整
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入原始图像
 参数.二：nWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：输入调整后的宽
 参数.三：nHeight
  In/Out：In
  类型：整数型
  可空：N
  意思：输入调整后的高
 参数.四：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入原始图像内存大小,输出调整后的内存大小
 参数.五：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出调整后的图像内存
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CImageInformation_Set::ImageInfo_Set_MemoryResolution(LPCTSTR lpszMsgBuffer, int nWidth, int nHeight, int* pInt_MsgLen, TCHAR* ptszMsgBuffer)
{
	Image_IsErrorOccur = FALSE;

	if ((NULL == lpszMsgBuffer) || (NULL == pInt_MsgLen) || (NULL == ptszMsgBuffer))
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_INFORMATION_SET_PARAMENT;
		return FALSE;
	}
	//读取到内存
#ifdef _UNICODE
	USES_CONVERSION;
	cv::_InputArray m_InputArray(W2A(lpszMsgBuffer), *pInt_MsgLen);
#else
	cv::_InputArray m_InputArray(lpszMsgBuffer, *pInt_MsgLen);
#endif
	cv::Mat m_SrcFrame = cv::imdecode(m_InputArray, cv::IMREAD_UNCHANGED);
	cv::Mat m_DstFrame;
	//调整分辨率
	cv::resize(m_SrcFrame, m_DstFrame, cv::Size(nWidth, nHeight));

	return TRUE;
}