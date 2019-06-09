XX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#LDFLAGS = -lboost_date_time

OBJS = main.o getInput.o functions.o 

SRCS = main.cpp getInput.cpp functions.cpp 

HEADERS = getInput.hpp functions.hpp 

TARGET = main

${TARGET}: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${TARGET}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
clean:
	$(RM) ${TARGET} ${OBJS}
