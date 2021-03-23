OBJDIR=build
INCLUDEDIRECTORY=include
gcc_croise =  /home/jako/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-c++
CXXFLAGS = -std=c++11 -pthread -I$(INCLUDEDIRECTORY) -I/home/jako/RPI/wiringfPi/target_wpi/include -I/home/jako/RPI/wiringfPi/ -I/home/jako/RPI/ncurses/target_nc_pi/include/ -I/home/jako/RPI/ncurses/target_nc_pi/include/ncurses/
LDLIBS = -L/home/jako/RPI/wiringfPi/target_wpi/lib -L /home/jako/RPI/ncurses/target_nc_pi/lib -lwiringPi -lwiringPiDev -lncurses
WIRINGPI= -L /home/jako/RPI/wiringfPi/target_wpi/include/wiringPi.h -L /home/jako/RPI/ncurses/target_nc_pi/include/ncurses/ncurses.h
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
	-rm -f  ${SRC}/*.o
	-rm -f bin/main
