INCLUDE_DIR = include

SRCS= src/account.cpp src/client.cpp src/main.cpp
OBJS= obj/account.o obj/client.o obj/main.o

CXX = g++
CXX_FLAGS = -I$(INCLUDE_DIR)

prog : $(OBJS)
	mkdir -p out
	$(CXX) $(OBJS) -o out/$@

obj/account.o : src/account.cpp include/account.hpp
	mkdir -p obj 
	$(CXX) $(CXX_FLAGS) -c src/account.cpp -o $@

obj/main.o : src/main.cpp include/account.hpp
	mkdir -p obj 
	$(CXX) $(CXX_FLAGS) -c src/main.cpp -o $@

obj/client.o : src/client.cpp include/client.hpp include/account.hpp
	mkdir -p obj
	$(CXX) $(CXX_FLAGS) -c src/client.cpp -o $@

.PHONY: clean
clean:
	rm -rf obj out
