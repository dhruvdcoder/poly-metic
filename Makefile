VPATH=src:obj:include:test
LIB_GTEST=-lgtest
CC = g++
CFLAGS = -g -Wall -std=c++17 
CXX=g++
CXXFLAGS=-g -Wall -std=c++17 
LD=g++
LDFLAGS=-g

OBJDIR=obj
BINDIR=bin

# Intrusive testing 
ifeq ($(strip $(T)),ON)
CXXFLAGS += -D INTRUSIVE_TESTS
endif
# Printing calls 
ifeq ($(strip $(V)),ON)
CXXFLAGS += -D VERBOSE
endif
.PHONY: Test_Polynomial
Test_Polynomial : $(BINDIR)/Test_Polynomial
## test executables rules
$(BINDIR)/Test_Polynomial : $(OBJDIR)/Test_Polynomial.o $(OBJDIR)/Polynomial.o
	$(LD) $(LDFLAGS) $^ $(LIB_GTEST) -o $@


## Object file rules
# Unit object files
$(OBJDIR)/Polynomial.o : Polynomial.cpp Polynomial.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#test object files
$(OBJDIR)/Test_Polynomial.o : Test_Polynomial.cpp Polynomial.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# doc
#
.PHONY: Doc
Doc : doc/doc.config
	doxygen doc/doc.config
