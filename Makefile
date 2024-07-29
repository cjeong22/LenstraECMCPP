CXX=g++
CXXFLAGS= -g -Wall -std=c++17
SRC = src/main.cpp src/inverseException.cpp src/ecmPoint.cpp src/ecmCurve.cpp src/LenstraECM.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = LenstraECM
all: $(EXEC)
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)
clean:
	rm -f $(OBJ) $(EXEC)