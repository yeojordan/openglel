CC = g++
CFLAGS = -Wall
PROG = cube
DEPRECATED=-Wno-deprecated-declarations
SRCS = *.cpp #main.cpp imageloader.cpp anchor.cpp axis.cpp

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lglut -lGL -lGLU
endif

all: $(PROG)
	./$(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS) $(DEPRECATED)

clean:
	rm -f $(PROG); clear
