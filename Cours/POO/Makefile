CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -pedantic
EXEC = poo
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^

clean :
	rm *.o && rm $(EXEC)

run :
	make && ./$(EXEC)