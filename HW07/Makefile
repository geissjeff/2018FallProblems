# ***
# *** Please modify this file as required
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MERGE -DTEST_MERGESORT -DTEST_MERGESSORT 

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

hw07: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o hw07
	
testmemory: $(TARGET)
	$(VAL) ./hw07 Input/Test1 output
# Test memory leaks for all inputs and outputs

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

test1: hw07
	./hw07 Input/Test1 output
	diff output Expected/Expected1
	#run diff between output1.bin and expected/expected1.bin

test2: hw07
	./hw07 Input/Test2 output
	 diff output Expected/Expected2
	 #run diff between output2.bin and expected/expected2.bin

test3: hw07
	./hw07 Input/Test3 output
	 diff output Expected/Expected3
	#run diff between output3.bin and expected/expected3.bin

clean: # remove all machine generated files
