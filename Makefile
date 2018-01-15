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
.PHONY: Test_Polynomial Demos
Test_Polynomial : $(BINDIR)/Test_Polynomial
Demos : $(BINDIR)/demo
## test executables rules
$(BINDIR)/Test_Polynomial : $(OBJDIR)/Test_Polynomial.o $(OBJDIR)/Polynomial.o $(OBJDIR)/PolynomialMultiplicationSimple.o
	$(LD) $(LDFLAGS) $^ $(LIB_GTEST) -o $@


## Object file rules
# Unit object files
$(OBJDIR)/Polynomial.o : Polynomial.cpp Polynomial.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/PolynomialMultiplicationSimple.o : PolynomialMultiplicationSimple.cpp PolynomialMultiplicationSimple.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#test object files
$(OBJDIR)/Test_Polynomial.o : Test_Polynomial.cpp Polynomial.hpp PolynomialMultiplicationSimple.hpp PolynomialMultiplicationSimple.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# demos
$(OBJDIR)/demo.o : demo.cpp Polynomial.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BINDIR)/demo : $(OBJDIR)/demo.o $(OBJDIR)/Polynomial.o
	$(LD) $(LDFLAGS) $^ -o $@

# doc
#
.PHONY: Doc
Doc : doc/doc.config include/*.hpp src/*.cpp
	doxygen doc/doc.config
