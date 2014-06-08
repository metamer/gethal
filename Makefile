COMPILER=g++
HPPDIR=include
INCLUDE= -I $(HPPDIR)/ -I /usr/include/noteye
OBJDIR :=obj
OBJS := $(addprefix $(OBJDIR)/,\
			frontend/ArrayGameMap.o frontend/GameMapEntry.o frontend/UIState.o frontend/GameMessageContainer.o frontend/GameStatusEntry.o frontend/GameNumericStatusEntry.o frontend/GameStatusEntryContainer.o frontend/ColoredString.o frontend/ColoredTextObject.o frontend/ColorMapperUtil.o\
			ui/SimpleUI.o ui/NotEyeUI.o ui/CursesUI.o ui/Spacer.o ui/CursesColorMap.o\
			all/GameMessage.o all/Coordinate.o\
			runner/SimpleRunner.o)
BINDIR=bin
SRCDIR=src
CFLAGS= -Wall -g -std=c++11
OBJFLAGS= -c
LIBS= -L/usr/lib/noteye 

all: simplegame graphicalgame consolegame

simplegame: $(SRCDIR)/simplegame.cpp objects
	$(COMPILER) $(SRCDIR)/simplegame.cpp -o $(BINDIR)/simplegame $(OBJDIR)/runner/SimpleRunner.o $(OBJDIR)/all/*.o $(OBJDIR)/frontend/*.o $(OBJDIR)/ui/SimpleUI.o $(INCLUDE) $(CFLAGS) $(DEF) $(LIBS)

graphicalgame: $(SRCDIR)/graphicalgame.cpp objects
	$(COMPILER) $(SRCDIR)/graphicalgame.cpp -o $(BINDIR)/graphicalgame $(OBJDIR)/runner/SimpleRunner.o $(OBJDIR)/all/*.o $(OBJDIR)/frontend/*.o $(OBJDIR)/ui/NotEyeUI.o $(INCLUDE) $(CFLAGS) $(DEF) $(LIBS) -lz -lcurses -lnoteye 

consolegame: $(SRCDIR)/consolegame.cpp objects
	$(COMPILER) $(SRCDIR)/consolegame.cpp -o $(BINDIR)/consolegame $(OBJDIR)/runner/SimpleRunner.o $(OBJDIR)/all/*.o $(OBJDIR)/frontend/*.o $(OBJDIR)/ui/Spacer.o $(OBJDIR)/ui/CursesColorMap.o $(OBJDIR)/ui/CursesUI.o $(INCLUDE) $(CFLAGS) $(DEF) $(LIBS) -lncurses

hello: $(SRCDIR)/helloworld.cpp
	$(COMPILER) $(SRCDIR)/helloworld.cpp -o $(BINDIR)/helloworld $(CFLAGS) $(DEF)
boost: $(SRCDIR)/boosttest.cpp
	$(COMPILER) $(SRCDIR)/boosttest.cpp -o $(BINDIR)/boosttest $(CFLAGS) $(DEF)
clean:
	rm -rf $(BINDIR)/*
	rm -rf $(OBJDIR)/*

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(COMPILER) $(INCLUDE) $(CFLAGS) $(OBJFLAGS)  $(DEF) -o $@ $<

objects: $(OBJS)

$(OBJS): | $(OBJDIR)/frontend $(OBJDIR)/ui $(OBJDIR)/runner $(OBJDIR)/all

$(OBJDIR)/all:
	mkdir $(OBJDIR)/all
$(OBJDIR)/frontend:
	mkdir $(OBJDIR)/frontend
$(OBJDIR)/runner:
	mkdir $(OBJDIR)/runner
$(OBJDIR)/ui:
	mkdir $(OBJDIR)/ui
