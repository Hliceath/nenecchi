C   := clang
CPP := clang++

CFLAGS := -Wall -Wshadow -Iinclude --std=c23
CFLAGS += --write-user-dependencies -MP

OBJ_DIR := build
SRC_DIR := source
OUTPUT  := bin/nenecchi

SRCS_C   := $(shell find $(SRC_DIR) -name *.c)
SRCS_CPP := $(shell find $(SRC_DIR) -name *.cpp)

OBJS := $(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS_C:.c=.o))
OBJS += $(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS_CPP:.cpp=.o))
DEPS := $(OBJS:.o=.d)

-include $(DEPS)

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CPP) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(C) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS) $(OUTPUT)

rebuild: clean .WAIT all
