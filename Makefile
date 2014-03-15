COMPILER=g++
HPPDIR=include
INCLUDE= -I $(HPPDIR)/
OBJDIR :=obj
OBJS := $(addprefix $(OBJDIR)/,\
			frontend/ArrayGameMap.o frontend/GameMapEntry.o frontend/UIState.o\
			ui/SimpleUI.o\
			runner/SimpleRunner.o)
BINDIR=bin
SRCDIR=src
CFLAGS= -Wall -g
OBJFLAGS= -c
DEF=
test: simplegame

simplegame: $(SRCDIR)/simplegame.cpp objects
	g++ $(SRCDIR)/simplegame.cpp -o $(BINDIR)/simplegame $(OBJDIR)/runner/*.o $(OBJDIR)/frontend/*.o $(OBJDIR)/ui/*.o $(INCLUDE) $(CFLAGS) $(DEF)

hello: $(SRCDIR)/helloworld.cpp
	g++ $(SRCDIR)/helloworld.cpp -o $(BINDIR)/helloworld $(CFLAGS) $(DEF)
boost: $(SRCDIR)/boosttest.cpp
	g++ $(SRCDIR)/boosttest.cpp -o $(BINDIR)/boosttest $(CFLAGS) $(DEF)
clean:
	rm -rf $(BINDIR)/*
	rm -rf $(OBJDIR)/*

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(COMPILER) $(INCLUDE) $(CFLAGS) $(OBJFLAGS) $(DEF) -o $@ $<

objects: $(OBJS)

$(OBJS): | $(OBJDIR)/frontend $(OBJDIR)/ui $(OBJDIR)/runner

$(OBJDIR)/frontend:
	mkdir $(OBJDIR)/frontend
$(OBJDIR)/runner:
	mkdir $(OBJDIR)/runner
$(OBJDIR)/ui:
	mkdir $(OBJDIR)/ui
