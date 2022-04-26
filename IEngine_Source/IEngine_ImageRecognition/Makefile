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
LIBINCLUDE = ImageRecognition_Help.o pch.o

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
	$(CC) $(DEBUG) $(LIBINCLUDE) -o libIEngine_ImageRecognition.so -shared $(LOADBIN) $(LIB) $(LIBEX) $(LOADSO) $(INCLUDE)

ImageRecognition_Help.o:./ImageRecognition_Help/ImageRecognition_Help.cpp                                 
	$(CC) $(DEBUG) $(FLAGS) $(UNICODE) $(INCLUDE) ./ImageRecognition_Help/ImageRecognition_Help.cpp  
					
pch.o:pch.cpp             
	$(CC) $(DEBUG) $(FLAGS) $(UNICODE) $(INCLUDE) pch.cpp


InstallAll:InstallSo InstallHeader
InstallSo:./libIEngine_ImageRecognition.so
ifeq ($(FILECENTOS), $(wildcard $(FILECENTOS)))
	cp ./libIEngine_ImageRecognition.so ../../IEngine_Release/IEngine_Linux/Centos/libIEngine_ImageRecognition.so
else
	cp ./libIEngine_ImageRecognition.so ../../IEngine_Release/IEngine_Linux/Ubuntu/libIEngine_ImageRecognition.so
endif 
InstallHeader:./ImageRecognition_Define.h ./ImageRecognition_Error.h
	cp ./ImageRecognition_Define.h ../../IEngine_Release/IEngine_Include/ImageRecognition_Define.h
	cp ./ImageRecognition_Error.h ../../IEngine_Release/IEngine_Include/ImageRecognition_Error.h

CleanAll:CleanObj CleanMk
CleanObj:
	rm *.o                                           
CleanMk:
	rm *.so                                       
