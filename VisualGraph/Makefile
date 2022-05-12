# VisualGraph Makefile

# Compiler
CXX			= g++
# Compiler Options
CXXFLAGS	=
# SFML Include Path
INC_PATH	=
# SFML Library Path
LIB_PATH	=
# Linker Options
LINK		= -lsfml-graphics -lsfml-window -lsfml-system

main:
	$(CXX) $(CXXFLAGS) src/*.cpp $(INC_PATH) -o VisualGraph $(LIB_PATH) $(LINK)

debug: CXXFLAGS += -g
debug: main