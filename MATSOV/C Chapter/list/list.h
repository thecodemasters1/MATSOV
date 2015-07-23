#include <stdlib.h>

#if !defined(ERROR)
#define ERROR (-1)
#endif

typedef struct struct_node {
	struct struct_node* prev;
	double content;
	struct struct_node* next;
} Node;

typedef struct struct_list {
	Node* first;
	Node* last;
	unsigned int length;
	long double sum;
} List;

Node* create_node(double content);
List* create_list(double content);
int destroy(List* list);
Node* add(List* list, double content);
int remove_node(List* list, Node* node);
int get_length(List* list);
Node* get_first(List* list);
Node* get_last(List* list);
Node* get_prev(Node* node);
Node* get_next(Node* node);
double get_content(Node* node);
double get_average(List* list);

Node* create_node(double content) /* Creates a node with a content given */
{
	Node* temp_node = malloc(sizeof(Node));
	if(temp_node == NULL) {
		return NULL;
	}
	temp_node->prev = NULL;
	temp_node->content = content;
	temp_node->next = NULL;
	return temp_node;
}

List* create_list(double content) /* Creates a list with one node only */
{
	List* list = malloc(sizeof(List));
	if(list == NULL) {
		return NULL;
	}
	list->length = 0;
	list->sum = 0;
	Node* new_node = create_node(content);

	new_node->prev = NULL; /* Setting the node to be the only one in the list */
	new_node->next = NULL;
	list->first = new_node;
	list->last = new_node;

	++(list->length);
	list->sum += new_node->content;

	return list;
}

int destroy(List* list)
{
	if(list == NULL) {
		return ERROR;
	}
	Node* cur_node = list->first;
	Node* next_node = cur_node->next;
	while(cur_node != list->last)
	{
		remove_node(list, cur_node);
		cur_node = next_node;
		next_node = cur_node->next;
	}
	remove_node(list, cur_node); /* removes the last node of the list */
	free(list);
	return 0;
}

Node* add(List* list, double content)  /* Creates and adds a node with a content given */
{									/* at the end of the list */
	if(list == NULL) {
		return NULL;
	}
	Node* new_node = create_node(content);
	list->last->next = new_node;

	new_node->prev = list->last;
	list->last = new_node;
	++(list->length);
	list->sum += new_node->content;

	return new_node;
}

int remove_node(List* list, Node* node)
{
	if(list == NULL || node == NULL) {
		return ERROR;
	}
	if(node == list->first) { /* deletes the first node */
		node->next->prev = NULL;
		list->first = node->next;
	} else if(node == list->last) { /* deletes the last node */
		node->prev->next = NULL;
		list->last = node->prev;
	} else { /* deletes a central node */
		node->next->prev = node->prev; /* Connects the next and the previous node */
		node->prev->next = node->next;
	}
	free(node);
	--(list->length);
	return 0;
}

int get_length(List* list)
{
	if(list != NULL) {
		return list->length;
	}
	return ERROR;
}

Node* get_first(List* list)
{
	if(list != NULL) {
		return list->first;
	}
	return NULL;
}

Node* get_last(List* list)
{
	if(list != NULL) {
		return list->last;
	}
	return NULL;
}

Node* get_next(Node* node)
{
	if(node != NULL) {
		return node->next;
	}
	return NULL;
}

Node* get_prev(Node* node)
{
	if(node != NULL) {
			return node->prev;
		}
	return NULL;
}

double get_content(Node* node)
{
	if(node != NULL) {
		return node->content;
	}
	return ERROR;
}

double get_average(List* list)
{
	double average = (double)(list->sum / list->length);
	return average;
}
