all: dynamic_array linked_list doubly_linked_list stack linked_list_stack queue

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


queue: ./queue/queue*c
	gcc -o ./tests/$@ $^

test:
	./test_all


clean: 
	-rm ./tests/*
