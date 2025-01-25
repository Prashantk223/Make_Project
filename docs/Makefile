#******************************************************************************
#  SAMPLE MAKEFILE FOR TARGET = BINARY
# # NOTES:
# We may have to modify following attributes

#******************************************************************************
BUILD_TYPE = $(RELEASE)
#BUILD_TYPE = $(DEBUG)
MODULE_NAME = 
TARGET_NAME = 

PROJ_ROOT_DIR = ../..
OBJ_DIR = $(PROJ_ROOT_DIR)/objs/$(MODULE_NAME)

#*******DONT MODIFY BELOW ATTRIBUTES******#
BUILD_TIMESTAMP = $(shell date +'%d-%m-%Y.%H-%M-%S.%N')

INSTALLATION_PATH = $(shell echo $$INSTALLATION_PATH)
ifeq ($(INSTALLATION_PATH), )
	INSTALLATION_PATH = $(PROJ_ROOT_DIR)
#	INSTALLATION_PATH = /usr/local/mycustombuild

endif

TARGET_DIR = $(INSTALLATION_PATH)/bins
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

LIBRARY_DIR = $(INSTALLATION_PATH)/libs

#c compiler
#$$ is export INSTALLATION_PATH of cross copilation
CC = $(shell echo $$CC)
ifeq ($(CC),)
CC = g++
endif

# c loader
LDC = $(shell echo $$CC)
ifeq ($(LDC),)
LDC = g++
endif

STDFLAG = -std=c++17

#**********DONT MODIFY ABOVE ATTRIBUTES*********#
MAIN_OBJ = $(OBJ_DIR)/main.obj

SOURCE_1 = $(MODULE_NAME)
OBJ_1 = $(OBJ_DIR)/$(SOURCE_1).obj

#MAY NEED TO ADD MORE DEPENDENCIES AS PER REQUIREMENT.\
	1. DONT ADD EXTENSION C/CPP AS IT MAKES EASIER TO CREATER .O FILE \
	OTHERWISE IT'LL CREATE *.CPP.O WHICH IS OK!\
	2. ADD *.O IN ALL_OBJS. \
	3. ADD INSTRUCITON TO BUILD TARGET(.O)

#SOURCE_2 = 
#OBJ_2 = $(OBJ_DIR)/$(SOURCE_2).o

#SOURCE_3 = MODULE-NAME
#OBJ_3 = $(OBJ_DIR)/$(SOURCE_3).o

#ADD OBJ_* IN THE BEGINING IF REQUIRED
ALL_OBJS = $(OBJ_1) $(MAIN_OBJ)

INC = -I./ -I$(PROJ_ROOT_DIR)/shared-header


#CHOOSE RELEASE/DEBUG
DEBUG = -pipe -g -Wall -W -fPIC
#RELEASE =-DNDEBUG -W -fPIC
RELEASE = -pipe -O3 -Wall -fPIC
# -D stands for DEFINE. if want to define any\
	macro which is used in code for timestamp for git revision etc, can use in\
	this way
DEFINES = -DBUILD_TIMESTAMP_STR=\"$(BUILD_STAMP)\" \
			-DINSTALLATION_PATH_STR=\"$(INSTALLATION_PATH)"

#UNCOMMENT IF LIKE TO SEE FOLLOWING WARNINGS. ATLEASE ONCE THIS NEEDS TO BE \
	RUN FOR EACH MODULE

WARN = -Wall Wextra -Werror -Wwrite-strings -Wno-parentheses -pedantic \
	-Warray-bounds -Wno-unused-variable -Wno-unused-function \
	-Wno-unused-parameter -Wno-unused-result

CFLAGS = $(STDFLAGS) $(BUILD_TYPE) $(DEFINES) $(WARN) $(INC)

#Add dependency library here by separating them with space. below example is \
# to add libzmq, libm and libcustomlib

#Note: Add the "<path-to-library> -llibaryname" by keeping space in between as \
	shown below. If library is present in the current directory, \
	we can use path as L

#DEP_LIBS = -lzmq -lm -L$(LIBRARY_DIR) -libcustomlib -L -lnewlibincurrentdir

#RPATH IS USED FOR LINKING LIBS IN SPECIFIC PATH
#RPATH="-Wl, -rpath, $(LIBRARY_PATH):$(THIRD_PARTY_LIB_DIR)"
RPATH="-Wl, -rpath, $(LIBRARY_PATH)"

#LDFLAGS = $(DEBUG) $(PORF) -L$(LIBRARY_DIR) -L(THIRD_PARTY_LIB_DIR) -fpic\
	-lpthread $(DEP_LIBS) $(RPATH)

LDFLAGS = $(DEP_LIBS) $(RPATH)

all:$(TARGET)

$(TARGET): $(ALL_OBJS)
		$(LDC) $(LD_OPT) -o $@ $^ $(LDFLAGS)

$(MAIN_OBJ): main.c
	$(CC) $(CCFLAGS) -o $@ -c $<

$(OBJ_1): $(SOURCE_1).c 
	$(CC) $(CCFLAGS) -o $@ -c $<

build_dir:
	@echo Cretaing object directory if not exist
	mkdir -p $(OBJ_DIR)

clean:
	@echo clean build_dir
	-rm $(ALL_OBJS)
	-rm $(TARGET)

