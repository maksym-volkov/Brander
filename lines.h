
#ifndef LINES_H
# define LINES_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>
# include <ctype.h>

typedef struct		s_intmap
{
	int				**map;
	int				end;
	int				cur_x;
	int				cur_y;
}					t_intmap;

typedef struct		s_board
{
	int				max_x;
	int				max_y;
	int				start[2];
	int				end[2];
	char			**map;
	char			*result;
	t_intmap		intmap;
}					t_board;

int					main(int ac, char **av);
void				reading(char *file, t_board *board);
void				initialization(t_board *board);
void				solution(t_board *board);
void				print_result(t_board *board);
void				freeing_memory(t_board *board);
#endif
