#ifndef _DLIST_H_
#define _DLIST_H_
#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
	int value;
	struct node* prev;
	struct node* next;
};
struct dbl_linked_list
{
	size_t size;
	struct node* head;
	struct node* tail;
};
struct dbl_linked_list* dbl_linked_list_init();
void dbl_linked_list_delete(struct dbl_linked_list** list);
void dbl_linked_list_push_front(struct dbl_linked_list* list, int value);
void dbl_linked_list_push_back(struct dbl_linked_list* list, int value);
void dbl_linked_list_pop_front(struct dbl_linked_list* list);
void dbl_linked_list_pop_back(struct dbl_linked_list* list);
struct node* dbl_linked_list_get_item(struct dbl_linked_list* list, size_t idx);
void dbl_linked_list_insert(struct dbl_linked_list* list, size_t idx, int value);
void dbl_linked_list_erase(struct dbl_linked_list* list, size_t idx);
void dbl_linked_list_print(struct dbl_linked_list* list);
int dbl_linked_list_isnull(struct dbl_linked_list* list);
#endif

