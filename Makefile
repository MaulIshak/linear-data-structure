CC = gcc
CFLAGS = -Wall -g

# Target default
all: test_linked_list test_stack test_queue done

# Linked List
test_linked_list: linked_list/test_linked_list.c linked_list/linked_list.c
	@echo "Compiling test_linked_list"
	@$(CC) $(CFLAGS) -o test_linked_list linked_list/test_linked_list.c linked_list/linked_list.c

# Stack
test_stack: stack/test_stack.c stack/stack.c
	@echo "Compiling test_stack"
	@$(CC) $(CFLAGS) -o test_stack stack/test_stack.c stack/stack.c

# Queue
test_queue: queue/test_queue.c queue/queue.c
	@echo "Compiling test_queue"
	@$(CC) $(CFLAGS) -o test_queue queue/test_queue.c queue/queue.c

done:
	@echo "Done"
	
# clean file
clean:
	@rm -f test_linked_list test_stack test_queue
