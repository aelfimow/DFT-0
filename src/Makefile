CXXFLAGS  = -mwindows
CXXFLAGS += -mthreads
CXXFLAGS += -D_MT
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17
CXXFLAGS += -O2
CXXFLAGS += -m64

OBJ_FILES  = a.o
OBJ_FILES += b.o
OBJ_FILES += c.o

all:
	c++ -c MainWindow.cpp -o c.o ${CXXFLAGS}
	c++ -c DiscreteFourierTransform.cpp -o b.o ${CXXFLAGS}
	c++ -c main.cpp -o a.o ${CXXFLAGS}
	c++ ${OBJ_FILES} -o DFT-0.exe ${CXXFLAGS}
