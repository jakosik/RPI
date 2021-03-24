INCLUDEDIRECTORY=include
gcc_croise =  g++ 
CXXFLAGS = -std=c++11 -pthread 
HEADERS = $(wildcard include/*.h)
OBJECTS = $(wildcard $(SRC)/*.o)
SRC= src
LDLIBS= -lncurses -lncursesw -lwiringPi
PRJSRC= $(wildcard $(SRC)/*.cpp)
CPPFILES=$(filter %.cpp, $(PRJSRC))
OBJDEPS=$(CPPFILES:.cpp=.o)
EXECDIR=bin
default: ${EXECDIR}/main

${EXECDIR}/main: $(OBJDEPS)
	$(gcc_croise) $(CXXFLAGS) $^ $(LDLIBS) -o $@
${SRC}/%.o: ${SRC}/%.cpp
	$(gcc_croise) $(CXXFLAGS)  ${WIRINGPI} -c -o $@  $< 

$(OBJECTS): $(HEADERS)

clean:
	-rm -f $(OBJECTS)
	-rm -f main
 
