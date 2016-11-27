ifdef CROSS_COMPILE
    CC=${CROSS_COMPILE}gcc
else
    CC=gcc
endif

CLFAGS=-O2 -fPIC
OBJS_BIN=
OBJS_LIB_SHARE=pipe_service.so
INCPATH=
LIBPATH=
LIBS=


all:pipe_shared_lib pipe_bin
	@echo "make all finish"

install:
	@echo "make install finish"

clean:
	rm -rf *.o *.so pipe_service 
	@echo "make clean finish"

pipe_shared_lib:
	${CC} ${CLFAGS} -c pipe_service.c
	${CC} -shared pipe_service.o ${LIBPATH} ${LIBS} -o ${OBJS_LIB_SHARE}
	
pipe_bin:
	${CC} ${CLFAGS} -c pipe_service.c
	${CC} ${CLFAGS} -c pipe_main.c
	${CC} -o pipe_service ${LIBPATH} ${LIBS} pipe_service.o pipe_main.o
	
