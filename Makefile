CXX=g++
CXXFLAGS= -g -Wall -std=c++17
SRC = src/main.cpp src/inverseException.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = LenstraECM
all: $(EXEC)
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(EXEC)