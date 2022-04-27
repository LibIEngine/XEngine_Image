#pragma once
/********************************************************************
//    Created:     2022/04/26  10:59:27
//    File Name:   D:\IEngine_Image\IEngine_Source\IEngine_ImageRecognition\ImageRecognition_Help\ImageRecognition_Help.h
//    File Path:   D:\IEngine_Image\IEngine_Source\IEngine_ImageRecognition\ImageRecognition_Help
//    File Base:   ImageRecognition_Help
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     图像识别帮助库
//    History:
*********************************************************************/


class CImageRecognition_Help
{
public:
	CImageRecognition_Help();
	~CImageRecognition_Help();
public:
	BOOL ImageRecognition_Help_QREncodec(LPCTSTR lpszFileName, LPCTSTR lpszMsgBuffer);
	BOOL ImageRecognition_Help_QRDecodec(LPCSTR lpszMsgBuffer, int* pInt_MsgLen, TCHAR* ptszMsgBuffer, LPCTSTR lpszDetectProto, LPCTSTR lpszDetectModel, LPCTSTR lpszSrProto, LPCTSTR lpszSrModel);
	BOOL ImageRecognition_Help_QRCamera(TCHAR* ptszMsgBuffer, LPCTSTR lpszDetectProto, LPCTSTR lpszDetectModel, LPCTSTR lpszSrProto, LPCTSTR lpszSrModel, int nDeviceID = 0, int nTimeout = 3);
protected:
private:
};