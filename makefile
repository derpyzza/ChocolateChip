CC = gcc
TARGET = debug

ifeq ($(TARGET), debug)

CFLAGS = -Wall -Wextra -Wpedantic -ggdb -DDEBUG=1

else

CFLAGS = -Wall -Wextra -Wpedantic -Oz

endif

SRC = chip
BIN = bin
EXEC = $(SRC)

$(EXEC): $(SRC)/*.c
ifeq ($(TARGET), debug)
	@printf "\033[33mBuilding [ DEBUG MODE ] ...\033[m\n"
else
	@printf "\033[33mBuilding ...\033[m\n"
endif
	$(CC) $^ -o $(BIN)/$(SRC) $(CFLAGS) 


run: $(EXEC)
	$(BIN)/$(EXEC)

clean:
	@echo "cleaning"
	rm $(BIN)/*
