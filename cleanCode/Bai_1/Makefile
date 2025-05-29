CC = gcc
CFLAGS = -Wall -Wextra -Ibook_management -Iuser_management -Iborrow

SRC = main.c \
      book_management/book.c \
      user_management/user.c \
      borrow/borrow.c

OBJ = $(SRC:.c=.o)

TARGET = library_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
