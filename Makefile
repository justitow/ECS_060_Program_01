OBJS = timetest.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -ansi $(DEBUG)
LFLAGS = -Wall -ansi $(DEBUG)

a.out: timetest.o
	g++ $(LFLAGS) -o a.out timetest.o
timetest.o: timetest.cpp CursorList.h CursorList.cpp LinkedList.h LinkedList.cpp QueueAr.h QueueAr.cpp QueueLL.h QueueLL.cpp SkipList.h SkipList.cpp StackAr.h StackAr.cpp StackLi.h StackLi.cpp vector.h vector.cpp CPUTimer.h
	g++ $(CFLAGS) -o timetest.o timetest.cpp

clean:
	rm -f *.o a.out

tar:
	tar cfv p1.tar Movie.h Movie.cpp Name.h Name.cpp NameList.h \
		NameList.cpp  Iterator.cpp Iterator.h