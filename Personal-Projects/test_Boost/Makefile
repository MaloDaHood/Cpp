CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -pedantic
BOOSTFLAGS = -static -lboost_log -lboost_log_setup -lboost_thread -lboost_system -lpthread
EXEC = boost-app
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(EXEC) : $(OBJ)
	$(CXX) -o $@ $^ $(BOOSTFLAGS)

clean :
	rm *.o && rm $(EXEC)