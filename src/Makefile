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
OBJ_FILES += d.o
OBJ_FILES += e.o
OBJ_FILES += f.o
OBJ_FILES += g.o
OBJ_FILES += h.o
OBJ_FILES += i.o
OBJ_FILES += j.o
OBJ_FILES += k.o

all:
	c++ -c PCM24LE_to_FP.cpp -o k.o ${CXXFLAGS}
	c++ -c DFT_File.cpp -o j.o ${CXXFLAGS}
	c++ -c WM_CREATE_Handler.cpp -o i.o ${CXXFLAGS}
	c++ -c WM_PAINT_Handler.cpp -o h.o ${CXXFLAGS}
	c++ -c WM_TIMER_Handler.cpp -o g.o ${CXXFLAGS}
	c++ -c WM_COMMAND_Handler.cpp -o f.o ${CXXFLAGS}
	c++ -c WM_DESTROY_Handler.cpp -o e.o ${CXXFLAGS}
	c++ -c FileReader.cpp -o d.o ${CXXFLAGS}
	c++ -c MainWindow.cpp -o c.o ${CXXFLAGS}
	c++ -c DiscreteFourierTransform.cpp -o b.o ${CXXFLAGS}
	c++ -c main.cpp -o a.o ${CXXFLAGS}
	c++ ${OBJ_FILES} -o DFT-0.exe ${CXXFLAGS}
