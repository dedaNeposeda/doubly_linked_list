#include"dlist.h"
struct dbl_linked_list* dbl_linked_list_init()
{
	struct dbl_linked_list* list = (struct dbl_linked_list*)malloc(sizeof(struct dbl_linked_list));
	list->size = 0;
	list->head = list->tail = NULL;
	return list;
}
void dbl_linked_list_delete(struct dbl_linked_list** list)
{
	if (dbl_linked_list_isnull(*list))
	{
		return;
	}
	struct node* tmp = (*list)->head;
	struct node* next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list) = NULL;
}
void dbl_linked_list_push_front(struct dbl_linked_list* list, int value)
{
	if (dbl_linked_list_isnull(list))
	{
		return;
	}
	struct node *item = (struct node*)malloc(sizeof(struct node));
	if(list->head)
		list->head->prev = item;
	item->value = value;
	item->prev = NULL;
	item->next = list->head;
	list->head = item;

	if (list->tail == NULL)
		list->tail = item;
	list->size++;
}
void dbl_linked_list_push_back(struct dbl_linked_list* list, int value)
{
	if (dbl_linked_list_isnull(list))
	{
		return;
	}
	struct node* item = (struct node*)malloc(sizeof(struct node));
	if (list->tail)
		list->tail->next = item;
	item->value = value;
	item->prev = list->tail;
	item->next = NULL;
	list->tail = item;

	if (list->head == NULL)
		list->head = item;
	list->size++;
}
void dbl_linked_list_pop_front(struct dbl_linked_list* list)
{
	if (dbl_linked_list_isnull(list))
	{
		return;
	}
	if (list->head == NULL)
		return;
	struct node* p_head;
	p_head = list->head;
	list->head = list->head->next;
	if (list->head)
		list->head->prev = NULL;
	if (p_head == list->tail)
		list->tail = NULL;
	free(p_head);
	list->size--;
}
void dbl_linked_list_pop_back(struct dbl_linked_list* list)
{
	if (dbl_linked_list_isnull(list))
	{
		return;
	}
	if (list->tail == NULL)
		return;
	struct node* p_tail;
	p_tail = list->tail;
	list->tail = list->tail->prev;
	if (list->tail)
		list->tail->next = NULL;
	if (p_tail == list->head)
		list->head = NULL;
	free(p_tail);
	list->size--;
}
struct node* dbl_linked_list_get_item(struct dbl_linked_list* list, size_t idx)
{
	if (dbl_linked_list_isnull(list))
	{
		return NULL;
	}
	struct node* tmp = list->head;
	size_t i = 0;
	while (tmp && i < idx)
	{
		tmp = tmp->next;
		i++;
	}
	return tmp;
}
void dbl_linked_list_insert(struct dbl_linked_list* list, size_t idx, int value)
{
	if (dbl_linked_list_isnull(list))
	{
		return;
	}
	struct node* elem = NULL;
	struct node* item = NULL;
	elem = dbl_linked_list_get_item(list, idx);
	if (elem == NULL)
		return;
	item = (struct node*)malloc(sizeof(struct node));
	item->value = value;
	item->prev = elem;
	item->next = elem->next;
	if (elem->next)
		elem->next->prev = item;
	elem->next = item;
	if (item->next == NULL)
		list->tail = item;
	list->size++;
}
void dbl_linked_list_erase(struct dbl_linked_list* list, size_t idx)
{
	if (dbl_linked_list_isnull(list))
	{
		return;
	}
	struct node* elem = NULL;
	elem = dbl_linked_list_get_item(list, idx);
	if (elem == NULL)
		return;
	if (elem->prev != NULL)
	{
		if (elem->next != NULL)
		{
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
		}
		else
		{
			elem->prev->next = NULL;
			list->tail = elem->prev;
		}
	}
	else
	{
		if (elem->next != NULL)
		{
			elem->next->prev = NULL;
			list->head = elem->next;
		}
	}
	free(elem);
	list->size--;
}
void dbl_linked_list_print(struct dbl_linked_list* list)
{
	if (dbl_linked_list_isnull(list))
	{
		return;
	}
	struct node* tmp = list->head;
	while (tmp)
	{
		printf("%d ",tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}
int dbl_linked_list_isnull(struct dbl_linked_list* list)
{
	if (list == NULL)
	{
		printf("Empty list!\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

