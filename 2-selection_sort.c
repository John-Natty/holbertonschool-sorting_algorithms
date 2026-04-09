#include "sort.h"
/**
 * selection_sort - Sort an array of integers in ascending
 * order using the Selection Sort algorithm
 * @array: pointer to the array to be sorted
 * @size: number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min_index;
	int temp;

	/* sécurité : si tableau NULL ou taille < 2, rien à trier */
	if (array == NULL || size < 2)
		return;

	/* boucle principale : on parcourt chaque position du tableau */
	for (i = 0; i < size - 1; i++)
	{
		/* on suppose que le minimum est à la position actuelle */
		min_index = i;

		/* on cherche le plus petit élément dans la partie non triée */
		for (j = i + 1; j < size; j++)
		{
			/* si on trouve plus petit que le minimum actuel */
			if (array[j] < array[min_index])
				min_index = j;
		}

		/* si un nouveau minimum a été trouvé, on échange */
		if (min_index != i)
		{
			/* sauvegarde temporaire de la valeur à la position i */
			temp = array[min_index];

			/* on place la valeur de i à la place du minimum */
			array[min_index] = array[i];

			/* on place la valeur minimum à la position i */
			array[i] = temp;

			/* afficher le tableau après chaque swap */
			print_array(array, size);
		}
	}
}
