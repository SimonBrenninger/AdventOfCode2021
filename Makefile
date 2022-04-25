PROG := main

SRC_DIR := ./src
BUILD_DIR := ./build

# include path for gcc
INCLUDES := -I$(SRC_DIR)

# let make search for all .c files
C_FILES := $(wildcard $(SRC_DIR)/*.c)

# store all object files
OBJECTS := $(addprefix $(BUILD_DIR)/, $(notdir $(C_FILES:.c=.o)))
vpath %.c $(dir $(C_FILES))

CC := gcc

C_FLAGS := -g3 -O0 -Wall

# compile the .o files
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR)
	gcc -c $(C_FLAGS) $< -o $@

# generate the exe
$(BUILD_DIR)/$(PROG) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# create the build dir if its not created yet
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

.DEFAULT_GOAL = all

all : $(BUILD_DIR)/$(PROG)

# run exe; varible 'day' and 'data' should be created in terminal
# eg: "make run day=1 data=test"
run : $(BUILD_DIR)/$(PROG)
	$< $(day) $(data)

debug:
	gdb $(BUILD_DIR)/$(PROG)

clean:
	rm $(BUILD_DIR)/$(PROG)

fullclean:
	rm -rf $(BUILD_DIR)