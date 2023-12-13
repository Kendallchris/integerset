CFLAGS = -std=c++14 -Wall -g

main:	main.o set.o
	g++ main.o set.o -o set $(CFLAGS)

main.o:	main.cpp integer_set.h
	g++ -c main.cpp -o main.o $(CFLAGS)

set.o:	integer_set.cpp integer_set.h
	g++ -c integer_set.cpp -o set.o $(CFLAGS)

test: test.o set.o
	g++ test.o set.o -o test $(CFLAGS)

test.o:	test.cpp integer_set.h
	g++ -c test.cpp -o test.o $(CFLAGS)

clean:
	rm -f test set *.o