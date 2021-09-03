CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -pedantic
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
EXEC = sfml-app
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^ $(SFMLFLAGS)

clean :
	rm *.o && rm $(EXEC)