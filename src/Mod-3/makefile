MODULE_NAME = mod3

TARGET_DIR = ../../bins
TARGET_NAME = mod3_bin
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

OBJ_DIR = ../../objs
OBJ1 = $(OBJ_DIR)/$(MODULE_NAME).o

INC_PATH = ../../shared-header
WARN_FLAGS = -Wall -Werror
CFLAGS = $(WARN_FLAGS) -I$(INC_PATH)

LIBS_PATH = ../../libs
LDFLAGS = -L$(LIBS_PATH) -lmod2

$(TARGET): $(OBJ1) install
	@echo "Linking $@ ..."
	g++ $< -o $@ $(LDFLAGS)

$(OBJ1): $(MODULE_NAME).c
	@echo "Compiling $< ..."
	g++ $(CFLAGS) -c $< -o $@

install:
	@echo "installing shared lib"
	export LD_LIBRARY_PATH=../../libs

clean:
	@echo "Cleaning $(MODULE_NAME) ..."
	@rm -f $(OBJ1) $(TARGET)