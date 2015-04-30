CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = bb7k
OBJECTS = main.o board.o square.o unownable.o ownable.o residence.o academic.o gym.o player.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
