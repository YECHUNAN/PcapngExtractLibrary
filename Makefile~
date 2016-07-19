PATH := /usr/um/gcc-4.8.2/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-4.8.2/lib64
LD_RUN_PATH := /usr/um/gcc-4.8.2/lib64

# TODO
# Change EXECUTABLE to match the command name given in the project spec.
EXECUTABLE 	= pcapngToCsvExe

# designate which compiler to use
CXX			= g++

# list of sources used in project
SOURCES 	= $(wildcard *.cpp)
SOURCES     := $(filter-out $(TESTSOURCES), $(SOURCES))
# list of objects used in project
OBJECTS		= $(SOURCES:%.cpp=%.o)


# TODO
# If main() is in another file delete the line above, edit and uncomment below
PROJECTFILE = pcapngToCsv.cpp


#Default Flags
CXXFLAGS = -std=c++11 -Wall -Werror -Wextra -pedantic 

# highest target; sews together all objects into executable
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
ifeq ($(EXECUTABLE), executable)
	@echo Edit EXECUTABLE variable in Makefile.
	@echo Using default a.out.
	$(CXX) $(CXXFLAGS) $(OBJECTS)
else
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)
endif


# rule for creating objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

# make clean - remove .o files, executables, tarball
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TESTS) $(PARTIAL_SUBMITFILE) $(FULL_SUBMITFILE)


lib.o: lib.cpp
pcapngToCsv.o: pcapngToCsv.cpp
