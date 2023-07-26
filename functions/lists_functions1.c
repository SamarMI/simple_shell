#include "shell.h"

/*
 * add_node - dds a new node at the beginning of a list_t list.
 * @head: pointer to head pointer of list.
 * @str: pointer to string data of node.
 * @num: node index used by history
 *
 * Return: the address of the new element, or NULL if it failed.
 */

list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;

	new_node->str = strdup(str);

	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}

	new_node->next = *head;
	(*head) = new_node;

	return (new_node);

}


/**
 * add_node_end - dds a new node at the end of a list_t list.
 * @head: pointer to head pointer of list.
 * @str: pointer to string data of node.
 * @num: node index used by history
 * Return: the address of the new element, or NULL if it failed.
 */

list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *tail_ptr;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;

	tail_ptr = (*head);

	new_node->str = strdup(str);

	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (tail_ptr)
	{
		while (tail_ptr->next)
			tail_ptr = tail_ptr->next;
		tail_ptr->next = new_node;
	}
	else
		*(head) = new_node;

	return (new_node);

}


/**
 * delete_nodeint_at_index - function that deletes the node at
 * index index of a listint_t linked list.
 * @head: pointer to head pointer of list.
 * @index: index of of node will be delete.
 *
 * Return: Returns: 1 if it succeeded, -1 if it failed.
 */

int delete_nodeint_at_index(list_t **head, unsigned int index)
{
	list_t *temp, *deleted_node;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);
	temp = (*head);
	deleted_node = NULL;
	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (i < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		i++;
	}


	deleted_node = temp->next;
	temp->next = deleted_node->next;
	free(deleted_node);

	return (1);
}

/**
 * free_list - free list.
 * @head: pointer to head of list.
 *
 */

void free_list(list_t **head)
{
	list_t *ptr;

	if (!head || !*head)
		return;

	while (*head)
	{
		ptr = (*head)->next;
		free((*head)->str);
		free(*head);
		(*head) = ptr;
	}
	(*head) = NULL;

}
