
#include "lines.h"

void		filling_char_map(t_board *board)
{
	int cur;

	cur = board->intmap.end;
	board->intmap.cur_x = board->end[0];
	board->intmap.cur_y = board->end[1];
	board->map[board->end[1]][board->end[0]] = 'F';
	board->result = (char*)malloc(sizeof(char) * cur);
	board->result[cur - 1] = '\0';
	while (cur > 1)
	{
		if (board->intmap.cur_x + 1 < board->max_x && board->intmap.map[board->intmap.cur_y][board->intmap.cur_x + 1] == cur - 1)
		{
			board->map[board->intmap.cur_y][board->intmap.cur_x + 1] = 'L';
			board->intmap.cur_x++;
		}
		else if (board->intmap.cur_y + 1 < board->max_y && board->intmap.map[board->intmap.cur_y + 1][board->intmap.cur_x] == cur - 1)
		{
			board->map[board->intmap.cur_y + 1][board->intmap.cur_x] = 'U';
			board->intmap.cur_y++;
		}
		else if (board->intmap.cur_x - 1 > -1 && board->intmap.map[board->intmap.cur_y][board->intmap.cur_x - 1] == cur - 1)
		{
			board->map[board->intmap.cur_y][board->intmap.cur_x - 1] = 'R';
			board->intmap.cur_x--;
		}
		else if (board->intmap.cur_y - 1 > -1 && board->intmap.map[board->intmap.cur_y - 1][board->intmap.cur_x] == cur - 1)
		{
			board->map[board->intmap.cur_y - 1][board->intmap.cur_x] = 'D';
			board->intmap.cur_y--;
		}
		cur--;
		board->result[cur - 1] = board->map[board->intmap.cur_y][board->intmap.cur_x];
	}
}

static	void	check_neighbors(t_board *board, int x, int y, int num)
{
	if (x + 1 < board->max_x && board->intmap.map[y][x + 1] == 0)
		board->intmap.map[y][x + 1] = num + 1;
	if (y + 1 < board->max_y && board->intmap.map[y + 1][x] == 0)
		board->intmap.map[y + 1][x] = num + 1;
	if (x - 1 > -1 && board->intmap.map[y][x - 1] == 0)
		board->intmap.map[y][x - 1] = num + 1;
	if (y - 1 > -1 && board->intmap.map[y - 1][x] == 0)
		board->intmap.map[y - 1][x] = num + 1;
}

void		filling_int_map(t_board *board)
{
	int cur;
	int x;
	int y;

	cur = 1;
	y = -1;
	while (++y < board->max_y)
	{
		x = -1;
		while (++x < board->max_x)
		{
			if (board->intmap.map[y][x] == cur)
				check_neighbors(board, x, y, cur);
		}
		if (y == board->max_y - 1 && cur < board->max_x + board->max_y)
		{
			cur++;
			y = -1;
			continue ;
		}
	}
	board->intmap.end = board->intmap.map[board->end[1]][board->end[0]];
	if (board->intmap.end == 0)
	{
		printf("%s\n", "there is no path");
		exit(1);
	}
}

void		solution(t_board *board)
{
	filling_int_map(board);
	filling_char_map(board);
}
