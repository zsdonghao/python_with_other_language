ifdef CROSS_COMPILE
    CC=${CROSS_COMPILE}gcc
else
    CC=gcc
endif

CLFAGS=-O2 -fPIC
OBJS=
INCPATH=-I/usr/include/python3.5/
LIBPATH=-L/usr/lib
LIBS=


all:shared_lib
	@echo "make all finish"

install:
	@echo "make install finish"

clean:
	rm -rf *.o *.so
	@echo "make clean finish"

shared_lib:
	${CC} ${CLFAGS} -c CtypeTest.c
	${CC} -shared CtypeTest.o ${LIBPATH} ${LIBS} -o CtypeTest.so

