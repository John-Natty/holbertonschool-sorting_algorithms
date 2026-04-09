#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: pointer to pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	/* On utilise des pointeurs de nœuds, pas des int/temp */
	listint_t *current, *tmp;

	/* Vérifie que la liste existe et a au moins 2 éléments */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* On commence au 2e nœud (le 1er est déjà "trié") */
	current = (*list)->next;

	/* Parcourt chaque nœud de la liste */
	while (current != NULL)
	{
		/* Sauvegarde le suivant avant de potentiellement bouger current */
		tmp = current;
		current = current->next;

		/* Tant que tmp est plus petit que son prédécesseur, on swap */
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			/* --- Swap de tmp et tmp->prev --- */

			/* Le prev de tmp récupère le next de tmp */
			tmp->prev->next = tmp->next;

			/* Si tmp a un voisin après, son prev pointe vers l'ancien prev */
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;

			/* tmp passe devant : son next devient son ancien prev */
			tmp->next = tmp->prev;

			/* tmp->prev devient le prev de l'ancien prev */
			tmp->prev = tmp->prev->prev;

			/* L'ancien prev (maintenant tmp->next) pointe vers tmp */
			tmp->next->prev = tmp;

			/* Si tmp est maintenant en tête, on met à jour *list */
			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			/* Affiche la liste après chaque swap */
			print_list(*list);
		}
	}
}
