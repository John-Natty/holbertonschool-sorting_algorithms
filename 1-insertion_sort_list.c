#include "sort.h"

/**
 * insertion_sort_list - trie une liste doublement chaînée d'entiers
 * en ordre croissant avec l'algorithme Insertion sort
 *
 * @list: adresse du pointeur vers le premier nœud de la liste
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *tmp;

	/* Vérifie que la liste existe et contient au moins 2 éléments */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Commence au deuxième nœud, le premier étant déjà considéré trié */
	current = (*list)->next;

	/* Parcourt chaque nœud de la liste */
	while (current != NULL)
	{
		/* Sauvegarde le nœud courant avant de le déplacer si nécessaire */
		tmp = current;

		/* Sauvegarde le prochain nœud à traiter */
		current = current->next;

		/* Déplace tmp vers la gauche tant qu'il est plus petit que son précédent */
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			/* Relie l'ancien précédent de tmp au nœud après tmp */
			tmp->prev->next = tmp->next;

			/* Si tmp n'est pas le dernier, met à jour le prev du nœud suivant */
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;

			/* Place tmp avant son ancien précédent */
			tmp->next = tmp->prev;

			/* tmp récupère le précédent de son ancien précédent */
			tmp->prev = tmp->prev->prev;

			/* L'ancien précédent pointe maintenant vers tmp */
			tmp->next->prev = tmp;

			/* Relie tmp à la partie gauche de la liste ou met tmp en tête */
			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			/* Affiche la liste après chaque échange */
			print_list(*list);
		}
	}
}
