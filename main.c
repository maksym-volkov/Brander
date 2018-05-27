
#include "lines.h"

int				main(int ac, char **av)
{
	t_board		board;

	bzero(&board, sizeof(t_board));
	if (ac != 2)
	{
		printf("ERROR\n");
		exit(1);
	}
	reading(av[1], &board);
	initialization(&board);
	solution(&board);
	print_result(&board);
	freeing_memory(&board);
	return (0);
}
