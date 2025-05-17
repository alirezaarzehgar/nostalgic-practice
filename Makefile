CC := cc

LIBS := pda.c

SRC := main.c ${LIBS}
OBJ := $(SRC:.c=.o)
OUT_NAME := pda
CFLAGS :=

SRC_TEST := pda_test.c ${LIBS}
OBJ_TEST := $(SRC_TEST:.c=.o)
TEST_NAME := tests
TEST_CFLAGS := -lcunit

all: build build-test

build: ${OBJ}
	${CC} ${OBJ} -o ${OUT_NAME}

build-test: ${OBJ_TEST}
	${CC} ${OBJ_TEST} -o ${TEST_NAME} ${TEST_CFLAGS}

clean:
	rm -rf ${OBJ} ${OBJ_TEST}
