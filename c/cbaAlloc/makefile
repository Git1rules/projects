DEBUG=-O3
CC=/usr/vac/bin/xlc_r ${DEBUG}
PROJECT_NAME=cbaAlloc
PROJECT_HOME=${HOME}/projects/c
PROJECT_DIR=${PROJECT_HOME}/${PROJECT_NAME}
OBJ_DIR=${PROJECT_DIR}/obj
SRC_DIR=${PROJECT_DIR}/src
INCLUDE_DIR=${PROJECT_DIR}/include
LIBS_DIR=${PROJECT_DIR}/lib


INCLUDES=-I${INCLUDE_DIR}

LIBS=-L${LIBS_DIR} -lm -lcbaAlloc

default: ${PROJECT_NAME}


${PROJECT_NAME}: ${SRC_DIR}/${PROJECT_NAME}.c
	${CC} ${INCLUDES} -c -o ${OBJ_DIR}/${PROJECT_NAME}.o ${SRC_DIR}/${PROJECT_NAME}.c

cbaAlloctest:  ${SRC_DIR}/cbaAlloctest.c ${SRC_DIR}/${PROJECT_NAME}.c
	${CC} -o $@ ${INCLUDES} ${OBJ_DIR}/${PROJECT_NAME}.o ${SRC_DIR}/$@.c

libcbaAlloc: ${OBJ_DIR}/${PROJECT_NAME}.o
	${CC} -G -o ${LIBS_DIR}/libcbaAlloc.so ${OBJ_DIR}/${PROJECT_NAME}.o 

libtest: ${SRC_DIR}/cbaAlloctest.c
	${CC} -brtl -o $@ ${INCLUDES} ${LIBS} ${SRC_DIR}/cbaAlloctest.c
