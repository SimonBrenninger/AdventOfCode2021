PROG := main

SRC_DIR := ./src
BUILD_DIR := ./build

# include path for gcc
INCLUDES := -I$(SRC_DIR)

# let make search for all .c files
C_FILES := $(wildcard $(SRC_DIR)/*.c)

# store the executable inside the build dir
O_FILE := $(BUILD_DIR)/$(PROG)

CC := gcc

C_FLAGS := -g -O0 -Wall

# generate the exe
$(O_FILE) : $(C_FILES) | $(BUILD_DIR)
	$(CC) $(C_FLAGS) $(C_FILES) -o $@

# create the build dir if its not created yet
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

.DEFAULT_GOAL = all

all : $(O_FILE)

run : $(O_FILE)
	$<

clean:
	rm $(O_FILE)

fullclean:
	rm -rf $(BUILD_DIR)