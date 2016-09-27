




#ifndef node_header
#define node_header

struct node {
	int unique_id;
	int random_contents;
	struct node *next, *previous;
	
} node;

struct node *head, *tail;
int list_size;

void create_list(struct node *);
void destroy_list(struct node *);
void insert_into_before(struct node *, int);
void insert_into_after(struct node *, int);
void append_to_list(struct node *);
void remove_from_list(struct node *, int);
void print_list(struct node *);
int create_node(struct node **);


void create_list(struct node * h) {
	
	for(int i = 0; i < list_size; i++) { 
	
		head[i].unique_id = i;
		
		if(i == list_size - 1) {
			 
			head[i].next = &head[0];
			tail = head[0].previous = &head[i];
		}
		
		if(i < list_size - 1) {
			head[i].next = &head[i+1];
		}
		if(i > 0) {
			head[i].previous = &head[i-1];
		}
		
	
	}
	
	
}

void destroy_list(struct node *h) {
	
	if(h != NULL)
		free(h);
}

void insert_into_before(struct node *h, int index) {
	if(h != NULL) {
		struct node * new;
		int check;
		if( (check = create_node(&new) ) == 0) {
			
			for(int j = 1; j < index; j++) {
				h = h->next;
			}
			
			new->unique_id = list_size;
			new->previous = h->previous;
			new->next = h;
			
			h->previous->next = new;
				h->previous = new;
			
		list_size++;

	    }
	}
}

void insert_into_after(struct node *h, int index) {
	if(h != NULL) {
		struct node * new;
		int check;
		if( (check = create_node(&new) ) == 0) {
			
			for(int j = 1; j < index; j++) {
				h = h->next;
			}
			
			new->unique_id = list_size;
			new->previous = h;
			new->next = h->next;
			
			h->next->previous = new;
				h->next = new;
			
		list_size++;
	   }
    }
}



void append_to_list(struct node *h) {
	if(h != NULL) {
		struct node * new;
		int check;
		if( (check = create_node(&new) ) == 0) {
			
		new->unique_id = list_size;
		new->previous = &h[list_size - 1]; 
		new->next = &h[0];
		
		h[list_size - 1].next = new;
		h[0].previous = new;
		
		list_size++;

		}
	}
}

void remove_from_list(struct node *h, int index) {
	if(h != NULL) {
		for(int j = 1; j < index; j++) {
			h = h->next;
		}
		
		
		h->previous->next = h->next;
		h->next->previous = h->previous;
		
		
		h->unique_id = -9;
			
		
		list_size--;

	}
	
}

void print_list(struct node *h) {
	printf("Print List\n");
	//printf("List Size: %d\n", list_size);
	for(int j = 0; j < list_size; j++) {
		//printf("node in order[%d]. id# %d | previous: %d | next: %d \n", j, head[j].unique_id, head[j].previous->unique_id, head[j].next->unique_id);
		
		printf("id #: %d -- prime: %d\n", h->unique_id, h->random_contents);
		h = h->next;
	}
}

int create_node(struct node ** new) {
	assert(new != NULL);
 	*new = NULL;
	if( (*new = (struct node *) calloc(1, sizeof(struct node))) != NULL) {
		printf("not null: create_node, %p\n", *new);
		return 0;
	}
	else
		return -1;
}


#endif