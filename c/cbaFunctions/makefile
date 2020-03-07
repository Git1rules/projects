DEBUG=-O3
#CC=/usr/vac/bin/xlc_r ${DEBUG}
CC=cc
PROJECT_NAME=cbaFunctions
PROJECT_HOME=${HOME}/projects/c
PROJECT_DIR=${PROJECT_HOME}/${PROJECT_NAME}
OBJ_DIR=${PROJECT_DIR}/obj
SRC_DIR=${PROJECT_DIR}/src
INCLUDE_DIR=${PROJECT_DIR}/include
LIBS_DIR=${PROJECT_DIR}/lib


INCLUDES=-I${INCLUDE_DIR}

LIBS=-L${LIBS_DIR} -lm -lcbaFunctions

default: ${PROJECT_NAME}


${PROJECT_NAME}: ${SRC_DIR}/${PROJECT_NAME}.c
	${CC} ${INCLUDES} -c -o ${OBJ_DIR}/${PROJECT_NAME}.o ${SRC_DIR}/${PROJECT_NAME}.c

cbaFunctionstest:  ${SRC_DIR}/cbaFunctionstest.c
	${CC} -o $@ ${INCLUDES} ${OBJ_DIR}/${PROJECT_NAME}.o ${SRC_DIR}/$@.c

libcbaFunctions: ${OBJ_DIR}/${PROJECT_NAME}.o
	${CC} -G -o ${LIBS_DIR}/libcbaFunctions.so ${OBJ_DIR}/${PROJECT_NAME}.o 

libtest: ${SRC_DIR}/cbaFunctionstest.c
	${CC} -brtl -o $@ ${INCLUDES} ${LIBS} ${SRC_DIR}/cbaFunctionstest.c
