#pragma once
/********************************************************************
//    Created:     2022/04/26  14:56:07
//    File Name:   D:\IEngine_Image\IEngine_Source\IEngine_CommHdr.h
//    File Path:   D:\IEngine_Image\IEngine_Source
//    File Base:   IEngine_CommHdr
//    File Ext:    h
//    Project:     XEngine(网络通信引擎)
//    Author:      qyt
//    Purpose:     公用头文件-必须加载
//    History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////
//                          导出宏定义
///////////////////////////////////////////////////////////////////////////
#define IENGINE_USED_DEFINE 1             //使用标志
//版本
#define IENGINE_VERSION_KERNEL 1
#define IENGINE_VERSION_MAIN 0
#define IENGINE_VERSION_SUB 0
#define IENGINE_VERSION_FIX 1001
#define IENGINE_VERSION_STR "1.0.0.1001"
#define IENGINE_VERSION_BIT 1000001001
///////////////////////////////////////////////////////////////////////////
//                  自定义类型
///////////////////////////////////////////////////////////////////////////
#ifndef XENGINE_USED_DEFINE
typedef short int (SHOT);                                              //有符号短整数型
typedef int XHTHREAD;
typedef void* XHANDLE;
typedef void* XNETSTRUCT;
typedef void* XNETEVENT;
typedef unsigned long long XNETHANDLE;                                 //网络句柄
typedef unsigned long long* (PXNETHANDLE);                             //网络句柄指针
typedef long long (__int64x);                                          //64位数值
typedef unsigned long long(__int64u);                                  //无符号64位数值
typedef void** XPPMEM;
typedef void*** XPPPMEM;
#ifndef _MSC_BUILD
typedef unsigned long int (DWORD);                                     //双字
typedef unsigned short (WORD);                                         //无符号短整数型
typedef unsigned char (BYTE);                                          //无符号字符
typedef int BOOL;                                                      //逻辑型
typedef int (HFILE);                                                   //文件句柄
typedef int (HDEVICE);                                                 //设备句柄
typedef void (VOID);                                                   //无类型
typedef void* (LPVOID);                                                //无类型指针
#ifndef SOCKET
typedef int (SOCKET);                                                  //网络套接字句柄 
#endif
typedef unsigned long int (HANDLE);                                    //线程句柄
typedef void * (HMODULE);                                              //模块句柄
typedef unsigned int (UINT);                                           //无符号整数型
typedef char (CHAR);                                                   //字符
typedef unsigned char (UCHAR);                                         //无符号字符型
typedef wchar_t (WCHAR);                                               //宽字符
typedef const char* (LPCSTR);                                          //常量字符指针
typedef const wchar_t* (LPCWSTR);                                      //常量宽字符指针
typedef unsigned short int (USHORT);                                   //无符号短整数型
typedef unsigned long* DWORD_PTR,*PDWORD_PTR;                          //双字指针
///////////////////////////////////////////////////////////////////////
//                  自定义定义
///////////////////////////////////////////////////////////////////////
#define INVALID_HANDLE_VALUE -1                                        //失败的文件句柄
#define INVALID_SOCKET -1                                              //失败的SOCKET句柄
#define SOCKET_ERROR -1                                                //错误的SOCKET处理
#ifndef FALSE
#define FALSE   0
#endif
#ifndef TRUE
#define TRUE    1
#endif
#define MAX_PATH 260                                                   //文件夹最大深度
#define __stdcall
#define CALLBACK
#define WINAPI
///////////////////////////////////////////////////////////////////////
//                  自定义预处理
///////////////////////////////////////////////////////////////////////
#ifdef _UNICODE
typedef const wchar_t* LPCTSTR;
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
typedef const char* LPCTSTR;
typedef const void* LPCVOID;
#endif
#ifdef _UNICODE
#define _T(x)      L ## x
#else
#define _T(x)      x
#endif
#endif
#endif