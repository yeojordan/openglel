CC = g++
CFLAGS = -Wall
PROG = cube

SRCS = main.cpp imageloader.cpp anchor.cpp

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lglut -lGL -lGLU
endif

all: $(PROG)
	./$(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
