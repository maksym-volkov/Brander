
#include "lines.h"

static	void	error_exit()
{
	printf("Error in file\n");
	exit(1);
}

static	void	mem_aloc_map(t_board *board)
{
	int y;

	y = -1;
	board->map = (char**)malloc(sizeof(char*) * (board->max_y + 1));
	while (++y < board->max_y)
		board->map[y] = (char*)malloc(sizeof(char) * (board->max_x + 1));
}

static	void	read_map(t_board *board, size_t len, char *line, FILE *stream)
{
	int x;
	int y;
	int i;

	y = -1;
	while (++y < board->max_y)
	{
		x = -1;
		i = 0;
		if ((getline(&line, &len, stream)) == -1)
			error_exit();
		while (++x < board->max_x)
		{
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			if (line[i] != '1' && line[i] != '0')
				error_exit();
			board->map[y][x] = line[i++];
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\0' && line[i] != '\n')
				error_exit();
		}
		board->map[y][x] = '\0';
	}
	board->map[y] = NULL;
	free(line);
}

static int		length_num(int num)
{
	int len;

	len = 1;
	while (num /= 10)
		len++;
	return len;
}

static	void	valid_coord(char *line, int i)
{
	i = 0;
	if (line[i++] != '(')
		error_exit();
	if (!isdigit(line[i]))
		error_exit();
	while (isdigit(line[i]))
		i++;
	if (line[i++] != ',')
		error_exit();
	if (!isdigit(line[i]))
		error_exit();
	while (isdigit(line[i]))
		i++;
	if (line[i++] != ')')
		error_exit();
	if (line[i++] != '\n')
		error_exit();
}

void			reading(char *file, t_board *board)
{
	char	*line = NULL;
	FILE 	*stream;
	size_t 	len = 0;
	int		i;

	stream = fopen(file, "r");
	i = -1;
	if (!stream)
		error_exit();
	if ((getline(&line, &len, stream)) == -1)
			error_exit();
	while (line[++i])
		if (!isdigit(line[i]) && line[i] != '\n')
			error_exit();
	board->max_y = atoi(line);

	i = -1;
	if ((getline(&line, &len, stream)) == -1)
			error_exit();
	while (line[++i])
		if (!isdigit(line[i]) && line[i] != '\n')
			error_exit();
	board->max_x = atoi(line);

	if ((getline(&line, &len, stream)) == -1)
			error_exit();
	valid_coord(line, i);
	board->start[0] = atoi(&line[1]);
	board->start[1] = atoi(&line[2 + length_num(board->start[0])]);

	if ((getline(&line, &len, stream)) == -1)
			error_exit();
	valid_coord(line, i);
	board->end[0] = atoi(&line[1]);
	board->end[1] = atoi(&line[2 + length_num(board->end[0])]);

	if (board->end[0] > board->max_x - 1 || board->start[0] > board->max_x - 1\
	 || board->end[1] > board->max_y - 1 || board->start[1] > board->max_y - 1\
	 || board->end[0] < 0 || board->end[1] < 0 || board->start[0] < 0 || board->start[1] < 0)
		error_exit();
	mem_aloc_map(board);
	read_map(board, len, line, stream);
	fclose(stream);
}
