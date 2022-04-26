RELEASE = 0
UNICODE = 0

FLAGS = RELEASE=$(RELEASE)
#图像库
IMAGE_INFO_PATH = ./IEngine_ImageInformation
IAMGE_RECOGNITION_PATH = ./IEngine_ImageRecognition

#编译集合
NETENGINE_LIB = libIEngine_ImageInformation.so libIEngine_ImageRecognition.so 

.PHONY:MakeAll 
MakeAll:$(NETENGINE_LIB)

libIEngine_ImageInformation.so:
	make -C $(IMAGE_INFO_PATH) $(FLAGS)
libIEngine_ImageRecognition.so:
	make -C $(IAMGE_RECOGNITION_PATH) $(FLAGS)

SetFlags_Install:
	export FLAGS=InstallAll
InstallAll:SetFlags_Install $(NETENGINE_LIB) 
   
SetFlags_Clean:
	export FLAGS=CleanAll
CleanAll:SetFlags_Clean $(NETENGINE_LIB) 