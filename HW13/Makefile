TARGET = main
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw13.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_DIV -DTEST_SPLIT

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log main inputs/test1.txt

test1: main
	./main inputs/test4.txt > output1
	diff output1 expected/expected4.txt
	#perform diff between output1 and expected/expected1

test2: main
	./shuf 4 3 | sort > output2
	#perform diff between output2 and expected/expected2

test3: main
	./shuf 7 2 | sort > output3
	#perform diff between output3 and expected/expected3	

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
