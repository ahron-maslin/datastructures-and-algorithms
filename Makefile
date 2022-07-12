TARGETS= dynamic_array linked_list doubly_linked_list \
	stack linked_list_stack queue heap priority_queue \
	heapmin union_find binary_tree


all: $(TARGETS)


dynamic_array: ./array/*.c

linked_list: ./linked_list/linked_list*.c

doubly_linked_list: ./linked_list/doubly_linked_list*.c

stack: ./stack/stack*.c

linked_list_stack: ./stack/linked_list_stack*.c

queue: ./queue/queue*.c

priority_queue: ./priority_queue/priority_queue*.c ./array/dynamic_array.c ./binary_heap/bin_heap.c

heap: ./binary_heap/bin_heap*.c ./array/dynamic_array.c

heapmin: ./heap_min/heap_min*.c ./array/dynamic_array.c

union_find: ./union_find/union_find*.c

binary_tree: DEFS=-DDATATYPE="struct BINARY_TREE_NODE *"
binary_tree: ./binary_search_tree/binary_search_tree*.c ./queue/queue.c


$(TARGETS):
	gcc $^ -o ./tests/$@ $(DEFS)


test:
	./runtests


clean: 
	-rm ./tests/*
