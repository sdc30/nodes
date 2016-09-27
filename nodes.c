#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "nodes.h"


int main(int argc, char **argv) {
	char *buffer;

	assert(argv[1] != '\0');
		buffer = argv[1];
		list_size = atoi(buffer);

	head = (struct node *) calloc(list_size, sizeof(struct node));
	assert(head != NULL);
		
		create_list(head);

		print_list(head);
		remove_from_list(head, 2);
		remove_from_list(head, 4);
		//append_to_list(head);

		print_list(head);
		//printf("node in order[%d]. id# %d | previous: %d | next: %d \n", 2, head[2].unique_id, head[2].previous->unique_id, head[2].next->unique_id);
			
		destroy_list(head);
	return 0;
}

