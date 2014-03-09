COMPILER=g++
HPPDIR=../include
INCLUDE= -I $(HPPDIR)/
OBJDIR := ../obj
OBJS := $(addprefix $(OBJDIR)/,\
			frontend/ArrayGameMap.o frontend/GameMapEntry.o frontend/UIState.o\
			ui/SimpleUI.o\
			runner/SimpleRunner.o)
BINDIR=../bin
CFLAGS= -Wall
OBJFLAGS= -c
DEF=
test: simplegame

simplegame: simplegame.cpp objects
	g++ simplegame.cpp -o $(BINDIR)/simplegame $(OBJDIR)/runner/*.o $(OBJDIR)/frontend/*.o $(OBJDIR)/ui/*.o $(INCLUDE) $(CFLAGS) $(DEF)

hello: helloworld.cpp 
	g++ helloworld.cpp -o $(BINDIR)/helloworld $(CFLAGS) $(DEF)
boost: boosttest.cpp
	g++ boosttest.cpp -o $(BINDIR)/boosttest $(CFLAGS) $(DEF)
clean:
	rm -rf $(BINDIR)/*
	rm -rf $(OBJDIR)/*

$(OBJDIR)/%.o : %.cpp
	$(COMPILER) $(INCLUDE) $(CFLAGS) $(OBJFLAGS) $(DEF) -o $@ $<

objects: $(OBJS)

$(OBJS): | $(OBJDIR)/frontend $(OBJDIR)/ui $(OBJDIR)/runner

$(OBJDIR)/frontend:
	mkdir $(OBJDIR)/frontend
$(OBJDIR)/runner:
	mkdir $(OBJDIR)/runner
$(OBJDIR)/ui:
	mkdir $(OBJDIR)/ui
