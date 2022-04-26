RELEASE = 0
UNICODE = 0

FLAGS = RELEASE=$(RELEASE)
#图像库
IMAGE_INFO_PATH = ./XEngine_Image/XEngine_ImageInformation
IAMGE_RECOGNITION_PATH = ./XEngine_Image/XEngine_ImageRecognition

#编译集合
NETENGINE_LIB = libXEngine_ImageInformation.so libXEngine_ImageRecognition.so 

.PHONY:MakeAll 
MakeAll:$(NETENGINE_LIB)

libXEngine_ImageInformation.so:
	make -C $(IMAGE_INFO_PATH) $(FLAGS)
libXEngine_ImageRecognition.so:
	make -C $(IAMGE_RECOGNITION_PATH) $(FLAGS)

SetFlags_Install:
	export FLAGS=InstallAll
InstallAll:SetFlags_Install $(NETENGINE_LIB) 
   
SetFlags_Clean:
	export FLAGS=CleanAll
CleanAll:SetFlags_Clean $(NETENGINE_LIB) 