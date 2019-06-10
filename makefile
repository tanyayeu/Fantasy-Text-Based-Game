XX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#LDFLAGS = -lboost_date_time

OBJS = main.o getInput.o Forest.o Town.o Dungeon.o Character.o Knight.o Space.o Die.o Game.o

SRCS = main.cpp getInput.cpp Forest.cpp Town.cpp Character.cpp Knight.cpp Space.cpp Die.cpp Game.cpp

HEADERS = getInput.hpp Forest.hpp Space.hpp Town.hpp Character.hpp Knight.hpp Dungeon.hpp Die.hpp Game.hpp

TARGET = main

${TARGET}: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${TARGET}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
clean:
	$(RM) ${TARGET} ${OBJS}
