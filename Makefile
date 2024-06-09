
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wall -I./include

INCLUDEDIR = include
LFLAGS = -L./files
SRCDIR = src
SERVERDIR = server
UTILSDIR = utils
OBJDIR = obj
BINDIR = .
EXECUTABLE = $(BINDIR)/utms.out
MEDIA_PATH = ./files/

SOURCES := $(shell find $)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

SRCS=$(shell find ${SRC_DIR} -type f \( -name "*.cpp" \)) $(shell find ${SERVERDIR} -type f \( -name "*.cpp" \)) $(shell find ${UTILSDIR} -type f \( -name "*.cpp" \))
HEADERS=$(shell find ${SRC_DIR} -type f \( -name "*.hpp" \))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(wildcard $(INCLUDEDIR)/*.hpp)
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(MEDIA_PATH)

clean:
	rm -rf $(OBJDIR)/*.o $(EXECUTABLE)
