
#include "lines.h"

void	freeing_memory(t_board *board)
{
	int y;

	y = -1;
	while (++y < board->max_y)
		free(board->intmap.map[y]);	
	free(board->intmap.map);
	y = -1;
	while (++y < board->max_y)
		free(board->map[y]);	
	free(board->map);
	free(board->result);
}
