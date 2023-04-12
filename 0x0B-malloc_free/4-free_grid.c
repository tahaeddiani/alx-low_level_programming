#include <stdlib.h>

/**
 * free_grid - frees a two dimensional grid previously created by alloc_grid
 * @grid: pointer to a two dimensional grid of integers
 * @height: height of the grid
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
