#include "sort.h"

/**
 * lomuto_partition - partitions an array using the Lomuto scheme
 *
 * @array: pointer to the array of integers
 * @low: starting index of the partition
 * @high: ending index of the partition (pivot)
 * @size: size of the array (for printing)
 *
 * Return: index of the pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, temp, i, j;

	/* Le pivot est toujours le dernier élément */
	pivot = array[high];

	/* i marque la frontière des éléments < pivot */
	i = low - 1;

	/* Parcourt tous les éléments sauf le pivot */
	for (j = low; j < high; j++)
	{
		/* Si l'élément est plus petit que le pivot */
		if (array[j] <= pivot)
		{
			i++;
			/* Swap array[i] et array[j] seulement si différents */
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	/* Place le pivot à sa position finale (i + 1) */
	if ((i + 1) != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_rec - sorts an array recursively using Quick sort
 *
 * @array: pointer to the array of integers
 * @low: starting index
 * @high: ending index
 * @size: size of the array (for printing)
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot;

	/* On continue seulement si la partition a plus d'1 élément */
	if (low < high)
	{
		/* Partitionne le tableau et récupère la position du pivot */
		pivot = lomuto_partition(array, low, high, size);

		/* Trie récursivement la partie GAUCHE (avant le pivot) */
		quick_sort_rec(array, low, pivot - 1, size);

		/* Trie récursivement la partie DROITE (après le pivot) */
		quick_sort_rec(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme
 *
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	/* Si le tableau est NULL ou a moins de 2 éléments, rien à trier */
	if (array == NULL || size < 2)
		return;

	/* Lance le tri récursif sur tout le tableau (index 0 à size-1) */
	quick_sort_rec(array, 0, (int)(size - 1), size);
}
