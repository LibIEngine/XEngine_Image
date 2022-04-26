#include "pch.h"
#include "ImageRecognition_Help.h"
/********************************************************************
//    Created:     2022/04/14  14:23:42
//    File Name:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageRecognition\ImageRecognition_Help\ImageRecognition_Help.cpp
//    File Path:   D:\XEngine\XEngine_SourceCode\XEngine_Image\XEngine_ImageRecognition\ImageRecognition_Help
//    File Base:   ImageRecognition_Help
//    File Ext:    cpp
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     图像识别帮助库
//    History:
*********************************************************************/
CImageRecognition_Help::CImageRecognition_Help()
{
	cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);
}
CImageRecognition_Help::~CImageRecognition_Help()
{
}
//////////////////////////////////////////////////////////////////////////
//                        公有函数
//////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：ImageRecognition_Help_QRDecodec
函数功能：QR二维码解析器
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入文件或者内存
 参数.二：pInt_MsgLen
  In/Out：In/Out
  类型：整数型指针
  可空：Y
  意思：如果为NULL,参数一表示文件路径,否则输入内存大小,并且输出二维码字符串大小
 参数.三：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出识别到的内容
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
BOOL CImageRecognition_Help::ImageRecognition_Help_QRDecodec(LPCTSTR lpszMsgBuffer, int* pInt_MsgLen, TCHAR* ptszMsgBuffer)
{
	Image_IsErrorOccur = FALSE;

	if ((NULL == lpszMsgBuffer) || (NULL == ptszMsgBuffer))
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_RECOGNITION_HELP_PARAMENT;
		return FALSE;
	}
	cv::Mat m_Frame;
	if (NULL != pInt_MsgLen)
	{
		//读取到内存
		cv::_InputArray m_InputArray(lpszMsgBuffer, *pInt_MsgLen);
		m_Frame = cv::imdecode(m_InputArray, cv::IMREAD_UNCHANGED);
	}
	else
	{
		//读取文件
		m_Frame = cv::imread(lpszMsgBuffer);
	}
	//是否成功
	if (m_Frame.empty())
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_RECOGNITION_HELP_EMPTY;
		return FALSE;
	}
	//QR检测
	cv::QRCodeDetector m_QRCodeDetector;
	std::vector<cv::Point> stl_VectorPoint;
	cv::Mat m_ImgStart;

	std::string m_QRText = m_QRCodeDetector.detectAndDecode(m_Frame, stl_VectorPoint, m_ImgStart);
	if (NULL != pInt_MsgLen)
	{
		*pInt_MsgLen = m_QRText.length();
	}
	_tcscpy(ptszMsgBuffer, m_QRText.c_str());
	return TRUE;
}
/********************************************************************
函数名称：ImageRecognition_Help_QRCamera
函数功能：识别摄像头的二维码
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出识别到的内容
 参数.二：nDeviceID
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入摄像头的索引,一个就填写0
 参数.三：nTimeout
  In/Out：In
  类型：整数型
  可空：Y
  意思：超时时间,单位秒
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数会死锁直到识别或者超时
*********************************************************************/
BOOL CImageRecognition_Help::ImageRecognition_Help_QRCamera(TCHAR* ptszMsgBuffer, int nDeviceID /* = 0 */, int nTimeout /* = 3 */)
{
	Image_IsErrorOccur = FALSE;

	if (NULL == ptszMsgBuffer)
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_RECOGNITION_HELP_PARAMENT;
		return FALSE;
	}
	cv::VideoCapture m_VideoCapture;
	m_VideoCapture.open(nDeviceID);
	//是否打开
	if (!m_VideoCapture.isOpened())
	{
		Image_IsErrorOccur = TRUE;
		Image_dwErrorCode = ERROR_XENGINE_IMAGE_RECOGNITION_HELP_OPEN;
		return FALSE;
	}
	cv::Mat m_Frame;
	time_t nTimeStart = time(NULL);
	__int64 nTimeCheck = clock();
	while (m_VideoCapture.read(m_Frame))
	{
		if (m_Frame.empty())
		{
			Image_IsErrorOccur = TRUE;
			Image_dwErrorCode = ERROR_XENGINE_IMAGE_RECOGNITION_HELP_EMPTY;
			return FALSE;
		}
		//每500毫秒读取一次
		if ((nTimeCheck - clock()) > 500)
		{
			cv::QRCodeDetector m_QRCodeDetector;
			std::vector<cv::Point> stl_VectorPoint;
			cv::Mat m_ImgStart;
			//识别
			std::string m_QRText = m_QRCodeDetector.detectAndDecode(m_Frame, stl_VectorPoint, m_ImgStart);
			if (!m_QRText.empty())
			{
				_tcscpy(ptszMsgBuffer, m_QRText.c_str());
				break;
			}
			nTimeCheck = clock();
		}
		//是否超时
		time_t nTimeEnd = time(NULL);
		if ((nTimeEnd - nTimeStart) > nTimeout)
		{
			break;
		}
	}
	m_VideoCapture.release();
	return TRUE;
}
