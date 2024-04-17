CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Test files
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(BUILD_DIR)/%.o)

# Main executable
MAIN = test_program

.PHONY: all clean run

all: $(MAIN)

$(MAIN): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)/$@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

run: $(MAIN)
	./$(BUILD_DIR)/$(MAIN)
