#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle.
  * @list: list to check.
  * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *hare, *turtle;

	hare = turtle = list;

	while (hare && hare->next)
	{
		hare = hare->next->next;
		turtle = turtle->next;
		if (hare == turtle)
			return (1);
	}
	return (0);
}
