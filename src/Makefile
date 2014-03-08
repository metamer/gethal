CFLAGS=
CFLAGS=
DEF=

test:  simplegame

simplegame: simplegame.cpp
	g++ simplegame.cpp -o ../bin/simplegame -I ../include/ $(CFLAGS) $(DEF)

hello: helloworld.cpp 
	g++ helloworld.cpp -o ../bin/helloworld $(CFLAGS) $(DEF)
boost: boosttest.cpp
	g++ boosttest.cpp -o ../bin/boosttest $(CFLAGS) $(DEF)
clean:
	rm -rf ../bin/*
