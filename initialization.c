
#include "lines.h"

static void		init_int_map(t_board *board)
{
	int y;
	int x;

	y = -1;
	while (++y < board->max_y)
	{
		x = 0;
		while (++x < board->max_x)
		{
			if (board->map[y][x] == '1')
				board->intmap.map[y][x] = -1;
			else
				board->intmap.map[y][x] = 0;
		}
	}
	board->intmap.map[board->start[1]][board->start[0]] = 1;
}

static	void	mem_aloc_int_map(t_board *board)
{
	int y;

	y = -1;
	board->intmap.map = (int**)malloc(sizeof(int*) * (board->max_y + 1));
	while (++y < board->max_y)
		board->intmap.map[y] = (int*)malloc(sizeof(int) * (board->max_x + 1));
}

void		initialization(t_board *board)
{
	mem_aloc_int_map(board);
	init_int_map(board);
}
