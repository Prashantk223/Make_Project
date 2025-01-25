MODULE_NAME = mod2
TEST_MODULE = test_mod2.c
TEST_BIN_DIR = ../../test_build

TARGET_DIR = ../../libs
TARGET_NAME = lib$(MODULE_NAME).so
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

OBJ_DIR = ../../objs
OBJ1 = $(OBJ_DIR)/$(MODULE_NAME).o

CFLAGS = -Wall -fpic
LDFLAGS =

$(TARGET): $(OBJ1) $(install)
	@echo "Linking $@ ..."
	g++ -shared $< -o $@ $(LDFLAGS)

$(OBJ1): $(MODULE_NAME).c
	@echo "Compiling $< ..."
	g++ $(CFLAGS) -c $< -o $@

test: $(TARGET) $(TEST_MODULE)
	@echo "Compiling $< ..."
	g++ $(TEST_MODULE) -o $(TEST_BIN_DIR)/$(MODULE_NAME) -L$(TARGET_DIR) -l$(MODULE_NAME)

build_dir:
	mkdir -p $(TEST_BIN_DIR)
	
install:
	cp *.h ../../shared-header
	export LD_LIBRARY_PATH=../../libs
clean:
	@echo "Cleaning $(MODULE_NAME) ..."
	@rm -f $(OBJ1) $(TARGET)