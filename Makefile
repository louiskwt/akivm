SRC_FILE = aki.c
CC_FLAGS = -Wall -Wextra -g -std=c11
CC = gcc

all:
	${CC} ${SRC_FILE} ${CC_FLAGS} -o aki
