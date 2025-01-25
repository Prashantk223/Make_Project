MODULE_NAME = mod4

TARGET_DIR = ../../libs
TARGET_NAME = lib$(MODULE_NAME).a
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

OBJ_DIR = ../../objs
OBJ1 = $(OBJ_DIR)/$(MODULE_NAME).o

CFLAGS = -fpic -Wall -fpic
LDFLAGS =

$(TARGET): $(OBJ1) install
	@echo "Linking $@ ..."
	ar rcs $@ -o $^

$(OBJ1): $(MODULE_NAME).c
	@echo "Compiling $< ..."
	g++ $(CFLAGS) -c $< -o $@

install:
	cp *.h ../../shared-header
	
test:
	g++ test_mod4.c -o ../../bins/test4 -L ../../libs -lmod4
clean:
	@echo "Cleaning $(MODULE_NAME) ..."
	@rm -f $(OBJ1) $(TARGET)