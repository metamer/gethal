COMPILER=g++
HPPDIR=include
INCLUDE= -I $(HPPDIR)/ -I /usr/include/noteye
OBJDIR :=obj
OBJS := $(addprefix $(OBJDIR)/,\
			frontend/ArrayGameMap.o frontend/GameMapEntry.o frontend/UIState.o\
			ui/SimpleUI.o ui/NotEyeUI.o\
			runner/SimpleRunner.o)
BINDIR=bin
SRCDIR=src
CFLAGS= -Wall -g
OBJFLAGS= -c
DEF= -DCPLUSPLUS 
LIBS= -L/usr/lib/noteye

all: simplegame graphicalgame

simplegame: $(SRCDIR)/simplegame.cpp objects
	$(COMPILER) $(SRCDIR)/simplegame.cpp -o $(BINDIR)/simplegame $(OBJDIR)/runner/SimpleRunner.o $(OBJDIR)/frontend/*.o $(OBJDIR)/ui/SimpleUI.o $(INCLUDE) $(CFLAGS) $(DEF) $(LIBS)

graphicalgame: $(SRCDIR)/graphicalgame.cpp objects
	$(COMPILER) $(SRCDIR)/graphicalgame.cpp -o $(BINDIR)/graphicalgame $(OBJDIR)/runner/SimpleRunner.o $(OBJDIR)/frontend/*.o $(OBJDIR)/ui/NotEyeUI.o $(INCLUDE) $(CFLAGS) $(DEF) $(LIBS) -lnoteye -lz -lcurses

hello: $(SRCDIR)/helloworld.cpp
	$(COMPILER) $(SRCDIR)/helloworld.cpp -o $(BINDIR)/helloworld $(CFLAGS) $(DEF)
boost: $(SRCDIR)/boosttest.cpp
	$(COMPILER) $(SRCDIR)/boosttest.cpp -o $(BINDIR)/boosttest $(CFLAGS) $(DEF)
clean:
	rm -rf $(BINDIR)/*
	rm -rf $(OBJDIR)/*

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(COMPILER) $(INCLUDE) $(CFLAGS) $(OBJFLAGS) $(LIBS) $(DEF) -o $@ $<

objects: $(OBJS)

$(OBJS): | $(OBJDIR)/frontend $(OBJDIR)/ui $(OBJDIR)/runner

$(OBJDIR)/frontend:
	mkdir $(OBJDIR)/frontend
$(OBJDIR)/runner:
	mkdir $(OBJDIR)/runner
$(OBJDIR)/ui:
	mkdir $(OBJDIR)/ui
