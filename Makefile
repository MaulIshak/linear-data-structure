CC = gcc
CFLAGS = -Wall -g -Wno-unused-variable

# Target default
all: test_linked_list test_stack test_queue bin_to_dec dec_to_bin done

# Linked List
test_linked_list: linked_list/test_linked_list.c linked_list/linked_list.c
	@echo "Compiling test_linked_list"
	@$(CC) $(CFLAGS) -o test_linked_list linked_list/test_linked_list.c linked_list/linked_list.c

# Stack
test_stack: stack/test_stack.c stack/stack.c linked_list/linked_list.c
	@echo "Compiling test_stack"
	@$(CC) $(CFLAGS) -o test_stack stack/test_stack.c stack/stack.c linked_list/linked_list.c

# Queue
test_queue: queue/test_queue.c queue/queue.c linked_list/linked_list.c
	@echo "Compiling test_queue"
	@$(CC) $(CFLAGS) -o test_queue queue/test_queue.c queue/queue.c linked_list/linked_list.c

bin_to_dec: stack/case_studies/bin_to_dec.c stack/stack.c linked_list/linked_list.c
	@echo "Compiling bin_to_dec"
	@$(CC) $(CFLAGS) -o bin_to_dec stack/case_studies/bin_to_dec.c stack/stack.c linked_list/linked_list.c

dec_to_bin: stack/case_studies/dec_to_bin.c stack/stack.c linked_list/linked_list.c
	@echo "Compiling dec_to_bin"
	@$(CC) $(CFLAGS) -o dec_to_bin stack/case_studies/dec_to_bin.c stack/stack.c linked_list/linked_list.c

done:
	@echo "Done"
	
# clean file
clean:
	@rm -f test_linked_list test_stack test_queue bin_to_dec
