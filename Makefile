all: dynamic_array linked_list doubly_linked_list \
	stack linked_list_stack queue heap priority_queue

dynamic_array: ./array/*.c
	gcc -o ./tests/$@ $^


linked_list: ./linked_list/linked_list*.c
	gcc -o ./tests/$@ $^


doubly_linked_list: ./linked_list/doubly_linked_list*.c
	gcc -o ./tests/$@ $^


stack: ./stack/stack*.c
	gcc -o ./tests/$@ $^


linked_list_stack: ./stack/linked_list_stack*.c
	gcc -o ./tests/$@ $^


queue: ./queue/queue*.c
	gcc -o ./tests/$@ $^


priority_queue: ./priority_queue/priority_queue*.c ./array/dynamic_array.c ./binary_heap/bin_heap.c
	gcc -o ./tests/$@ $^
	

heap: ./binary_heap/bin_heap*.c ./array/dynamic_array.c
	gcc -o ./tests/$@ $^ 

test:
	./test_all


clean: 
	-rm ./tests/*
