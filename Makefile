CC   := clang

CFLAGS := -Wall -Wshadow -Iinclude --std=c23
CFLAGS += --write-user-dependencies -MP

OBJ_DIR := build
SRC_DIR := source
OUTPUT  := bin/nenecchi

SRCS_C   := $(shell find $(SRC_DIR) -name *.c)

OBJS := $(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS_C:.c=.o))
DEPS := $(OBJS:.o=.d)

-include $(DEPS)

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS) $(OUTPUT)

rebuild: clean .WAIT all
