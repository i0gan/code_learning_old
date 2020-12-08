# This is a makefile for cspotify
# Create time: 2020-11-17
CC      := gcc
CFLAGS   := -std=c99
TARGET  := cspotify
TEST_TARGET  := test
RM := rm -f 
BUILD_PATH := .

# src path
MAIN_PATH   := ./src
TEST_PATH   := ./src

#---------------------OBJ-------------------------
# main
OBJS :=
MAIN_SRC := $(MAIN_PATH)/main.c
MAIN_SRC += $(MAIN_PATH)/cspotify.c
MAIN_OBJ := $(patsubst %.c, %.o, $(MAIN_SRC)) 
OBJS += $(MAIN_OBJ)

TEST_SRC  := $(TEST_PATH)/capture.c
TEST_SRC  += $(MAIN_PATH)/cspotify.c
TEST_SRC  += $(TEST_PATH)/test_main.c
TEST_SRC  += $(TEST_PATH)/test_cspotify.c

TEST_OBJS :=
TEST_OBJ  := $(patsubst %.c, %.o, $(TEST_SRC)) 
TEST_OBJS += $(TEST_OBJ)

# complie
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)/$@

$(OBJS):%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

print:
	@echo $(MAIN_SRC)

$(TEST_TARGET):$(TEST_OBJS)
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)/$@

$(TEST_OBJS):%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY:clean
clean:
	$(RM) $(BUILD_PATH)/$(TARGET) $(OBJS)
	$(RM) $(BUILD_PATH)/$(TEST_TARGET) $(TEST_OBJS)

