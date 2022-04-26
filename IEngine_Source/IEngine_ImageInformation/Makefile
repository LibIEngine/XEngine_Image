CC = g++ -Wall -std=c++17 -fPIC 
RELEASE = 0
UNICODE = 0
INCLUDE = -I ./ -I /usr/include/opencv4
FILECENTOS = /etc/redhat-release
LOADBIN = -L ../../../XEngine_Release/XEngine_Release/XEngine_LibEx
ifeq ($(FILECENTOS), $(wildcard $(FILECENTOS)))
	LIB = -lopencv_core -lopencv_imgcodecs -lopencv_imgproc
else
	LIB = -llzma -lpng16 -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -ltiff
endif 
LIBEX = -static-libgcc -lrt -ldl -lpthread
LOADSO = -Wl,-rpath=../XEngine_LibEx,--disable-new-dtags
LIBINCLUDE = ImageInformation_Get.o ImageInformation_Set.o pch.o

ifeq ($(RELEASE),1)
FLAGS = -c -O2 
DEBUG = 
else
FLAGS = -c -lc_p
DEBUG = -g -pg 
endif

ifeq ($(UNICODE),1)
UNICODE = -D _UNICODE
else
UNICODE = 
endif

all:$(LIBINCLUDE)
	$(CC) $(DEBUG) $(LIBINCLUDE) -o libIEngine_ImageInformation.so -shared $(LOADBIN) $(LIB) $(LIBEX) $(LOADSO) $(INCLUDE)

ImageInformation_Get.o:./ImageInformation_Get/ImageInformation_Get.cpp                                 
	$(CC) $(DEBUG) $(FLAGS) $(UNICODE) $(INCLUDE) ./ImageInformation_Get/ImageInformation_Get.cpp   
ImageInformation_Set.o:./ImageInformation_Set/ImageInformation_Set.cpp                                 
	$(CC) $(DEBUG) $(FLAGS) $(UNICODE) $(INCLUDE) ./ImageInformation_Set/ImageInformation_Set.cpp
					
pch.o:pch.cpp             
	$(CC) $(DEBUG) $(FLAGS) $(UNICODE) $(INCLUDE) pch.cpp


InstallAll:InstallSo InstallHeader
InstallSo:./libIEngine_ImageInformation.so
ifeq ($(FILECENTOS), $(wildcard $(FILECENTOS)))
	cp ./libIEngine_ImageInformation.so ../../IEngine_Release/IEngine_Linux/Centos/libIEngine_ImageInformation.so
else
	cp ./libIEngine_ImageInformation.so ../../IEngine_Release/IEngine_Linux/Ubuntu/libIEngine_ImageInformation.so
endif 
InstallHeader:./ImageInfo_Define.h ./ImageInfo_Error.h
	cp ./ImageInfo_Define.h ../../IEngine_Release/IEngine_Include/ImageInfo_Define.h
	cp ./ImageInfo_Error.h ../../IEngine_Release/IEngine_Include/ImageInfo_Error.h

CleanAll:CleanObj CleanMk
CleanObj:
	rm *.o                                           
CleanMk:
	rm *.so                                       
