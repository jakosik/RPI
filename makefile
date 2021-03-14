OBJDIR=build
INCLUDEDIRECTORY=include
gcc_croise =  g++
CXXFLAGS = -std=c++11
HEADERS = $(wildcard include/*.h)
OBJECTS = $(wildcard $(OBJDIR)/*.o)
SRC= src
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
 