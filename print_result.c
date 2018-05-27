
#include "lines.h"

void	print_result(t_board *board)
{
	int y;
	int x;

	y = -1;
	while (++y < board->max_y)
	{
		x = -1;
		while (++x < board->max_x)
		{
			if (board->map[y][x] == '0')
				printf(". ");
			else if (board->map[y][x] == '1')
				printf("O ");
			else
				printf("%c ", board->map[y][x]);
		}
		printf("\n");
	}
	x = -1;
	printf("Shortest way: ");
	while (board->result[++x])
	{
		if (board->result[x + 1] != '\0')
			printf("%c ", board->result[x]);
		else
			printf("%c\n", board->result[x]);
	}
	printf("Number of steps: %lu\n", strlen(board->result));
}
