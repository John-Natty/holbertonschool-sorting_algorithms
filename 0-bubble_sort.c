#include "sort.h"
/**
 * bubble_sort - trie un tableau d'entiers par ordre croissant
 * en utilisant l'algorithme Bubble Sort
 *
 * @array: pointeur vers le tableau d'entiers
 * @size: nombre d'éléments dans le tableau
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;

	/* Vérifie si le tableau est valide */
	if (array == NULL || size < 2)
		return;

	/* Boucle principale : nombre de passages dans le tableau */
	for (i = 0; i < size - 1; i++)
	{
		/* Compare chaque paire d'éléments adjacents */
		for (j = 0; j < size - i - 1; j++)
		{
			/* Si les éléments sont dans le mauvais ordre */
			if (array[j] > array[j + 1])
			{
				/* Échange des deux valeurs */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Affiche le tableau après chaque échange */
				print_array(array, size);
			}
		}
	}
}
