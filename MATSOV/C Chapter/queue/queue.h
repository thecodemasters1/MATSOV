#include <stdlib.h>

#if !defined(ERROR)
#define ERROR (-1)
#endif

Node* create_node(double content);
Queue* create_queue(double content);
int destroy(Queue* queue);
Queue* add(Queue* queue, Node* node);
double top(Queue* queue);
Node* pop(Queue* queue);
int get_length(Queue* queue);

typedef struct struct_node {
	double content;
	struct struct_node* next;
} Node;

typedef struct struct_queue {
	Node* first_node;
	Node* last_node;
	int length;
} Queue;

Node* create_node(double content)
{
	Node* node = malloc(sizeof(Node));
	if(node == NULL) {
		return NULL; // no available memory
	}
	node->content = content;
	node->next = NULL;
	return node;
}

Queue* create_queue(double content)
{
	Queue* queue = malloc(sizeof(Queue));
	if(queue == NULL) {
		return NULL; // no available memory
	}
	queue->first_node = create_node(content);
	if(queue->first_node == NULL) { // T: free queue memory
		return NULL;
	} // T: first node will be also the last node
	queue->length = 1;
	return queue;
}

int destroy(Queue* queue) {
	if(queue == NULL) {
		return ERROR;
	}
	while(queue->first_node->next != NULL) {
		pop(queue);
	}
	pop(queue); /* removes the last node of the queue */
	free(queue);
	return 0;
}

Queue* add(Queue* queue, Node* node) {
	if(node == NULL) { T: check queue is not null
		return NULL;
	}
	queue->last_node->next = node;
	queue->last_node = node;
	++(queue->length); // T: notice when queue is empty then this added node is false the first node
	return queue;
}

double top(Queue* queue) { /* returns the first node of the queue without removing it */
	if(queue == NULL) {
		return NULL;
	}
	return queue->first_node; // T: should return the content, not the node
}

double pop(Queue* queue) { /* returns the first node of the queue and removes it */
	if(queue == NULL) {
		return NULL;
	}
	Node* top_node = queue->first_node;
	queue->first_node = top_node->next;
	--(queue->length);

	double cont = top_node->content;
	free(top_node); // T: if it was the last node then last node should be null
	return cont;
}

int get_length(Queue* queue) {
	if(queue == NULL) {
		return NULL;
	}
	return queue->length;
}
