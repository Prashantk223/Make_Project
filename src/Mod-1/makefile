MODULE_NAME = mod1
TARGET_NAME = mod1_bin
TARGET_DIR = ../../libs
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

OBJ_DIR = ../../objs
OBJ1 = $(OBJ_DIR)/$(MODULE_NAME).o

CFLAGS = -Wall -Werror
LIBS_PATH = ../../libs
LDFLAGS = -L$(LIBS_PATH) -lmod2

$(TARGET): $(OBJ1)
	@echo "Linking $@ ..."
	g++ $< -o $@ $(LDFLAGS)

$(OBJ1): $(MODULE_NAME).c
	@echo "Compiling $< ..."
	g++ $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning $(MODULE_NAME) ..."
	@rm -f $(OBJ1) $(TARGET)