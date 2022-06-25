#pragma once
/********************************************************************
//    Created:     2022/04/26  10:59:34
//    File Name:   D:\IEngine_Image\IEngine_Source\IEngine_ImageRecognition\ImageRecognition_Define.h
//    File Path:   D:\IEngine_Image\IEngine_Source\IEngine_ImageRecognition
//    File Base:   ImageRecognition_Define
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     图像识别导出函数
//    History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                            导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD ImageRecognition_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                          图像识别帮助函数                            */
/************************************************************************/
/********************************************************************
函数名称：ImageRecognition_Help_QREncodec
函数功能：二维码生成器
 参数.一：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要生成的图片位置
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要编码的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ImageRecognition_Help_QREncodec(LPCTSTR lpszFileName, LPCTSTR lpszMsgBuffer);
/********************************************************************
函数名称：ImageRecognition_Help_QRDecodecFile
函数功能：QR二维码解析器
 参数.一：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的图片地址
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出识别到的内容
 参数.三：lpszDetectProto
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：学习模型地址,参考示例
 参数.四：lpszDetectModel
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：学习模型地址,参考示例
 参数.五：lpszSrProto
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：学习模型地址,参考示例
 参数.六：lpszSrModel
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：学习模型地址,参考示例
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ImageRecognition_Help_QRDecodecFile(LPCTSTR lpszFileName, TCHAR * ptszMsgBuffer, LPCTSTR lpszDetectProto, LPCTSTR lpszDetectModel, LPCTSTR lpszSrProto, LPCTSTR lpszSrModel);

extern "C" BOOL ImageRecognition_Help_QRDecodecMemory(LPCSTR lpszMsgBuffer, int nMsgLen, TCHAR* ptszMsgBuffer, LPCTSTR lpszDetectProto, LPCTSTR lpszDetectModel, LPCTSTR lpszSrProto, LPCTSTR lpszSrModel);
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
extern "C" BOOL ImageRecognition_Help_QRCamera(TCHAR* ptszMsgBuffer, LPCTSTR lpszDetectProto, LPCTSTR lpszDetectModel, LPCTSTR lpszSrProto, LPCTSTR lpszSrModel, int nDeviceID = 0, int nTimeout = 3);