VPATH=src:obj:include:test
LIB_GTEST=-lgtest
LIB_GMPCXX=-lgmpxx -lgmp
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
.PHONY: Test_Polynomial Demos Polynomial
# top-leve targets
Test_Polynomial : $(BINDIR)/Test_Polynomial
Test_PolynomialMPZ : $(BINDIR)/Test_Polynomial_gmpz
Test_Matrix : $(BINDIR)/Test_Matrix_Operations
Polynomial : $(OBJDIR)/Polynomial.o

Demos : $(BINDIR)/demo
## test executables rules
$(BINDIR)/Test_Polynomial : $(OBJDIR)/Test_Polynomial.o 
	$(LD) $(LDFLAGS) $^ $(LIB_GTEST) -o $@

$(BINDIR)/Test_Polynomial_gmpz : $(OBJDIR)/Test_Polynomial_gmpz.o $(OBJDIR)/Polynomial.o 
	$(LD) $(LDFLAGS) $^ $(LIB_GTEST) -o $@ $(LIB_GMPCXX)

$(BINDIR)/Test_Matrix_Operations : $(OBJDIR)/Test_Matrix_Operations.o 
	$(LD) $(LDFLAGS) $^ $(LIB_GTEST) -o $@ $(LIB_GMPCXX)

## Object file rules
# Unit object files
$(OBJDIR)/Polynomial.o : Polynomial.cpp Polynomial.hpp Polynomial.ipp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/PolynomialMultiplicationSimple.o : PolynomialMultiplicationSimple.cpp PolynomialMultiplicationSimple.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#test object files
$(OBJDIR)/Test_Polynomial.o : Test_Polynomial.cpp Polynomial.ipp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Test_Polynomial_gmpz.o : Test_Polynomial_gmpz.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Test_Matrix_Operations.o : Test_Matrix_Operations.cpp Polynomial.ipp Matrix.hpp
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
