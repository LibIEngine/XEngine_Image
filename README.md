[中文](README.md) ||  [English](README.en.md)  
# XEngine_Image
本仓库有开发和主分支,如果要使用,请使用master分支下的代码  

## 介绍
c c++ 图像识别库 图像处理库  
c c++ image recognition library  image processing library  
这是图像识别与图像算法库,主要基于OPENCV库实现,也包含了一些其他的第三方库.  
这个开源库主要以动态库的方式提供服务,方便大家使用.  

## 软件特性
1. 支持图像信息修改和获取
2. 支持二维码识别和创建

## 安装教程

#### 版本需求
支持WINDOWS 7SP1和LINUX(UBUNT20.04,CENTOS8)以上系统  

#### Windows
使用VS打开并且编译

###### 安装环境
需要vcpkg配置环境:https://github.com/microsoft/vcpkg,安装好后执行下面的命令安装  
vcpkg integrate install  
vcpkg.exe install opencv libqrencode opencv:x64-windows libqrencode:x64-windows  

#### Linux
Linux使用Makefile编译  
UBUNTU20.04 x64或者CENTOS8 x64均可  

###### 安装环境
ubuntu:sudo apt install libopencv-dev libqrencode-dev -y  
centos:sudo dnf install opencv-devel qrencode-devel -y  

##### 编译命令
在XEngine_Source目录下执行命令  
make 编译  
make FLAGS=InstallAll 安装库程序  
make FLAGS=CleanAll 清理编译    

#### 使用说明

1.  切换到MASTER分支
2.  下载代码
3.  编译
4.  安装
5.  运行

## 目录结构
- XEngine_Docment    文档目录结构  
- XEngine_Release    安装目录结构  
- XEngine_Source     源代目录结构  

## 当前任务

## 其他问题  
你可以参考docment目录下的文档.里面包含了API协议和服务说明.

## 参与贡献
希望大家多多提交代码参与贡献  

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request  

## 关注我们
如果你觉得这个软件对你有帮助,请你给我们一个START吧

## 提交问题

如果你有问题或者发现程序有BUG和意见,可以在issues中提交  