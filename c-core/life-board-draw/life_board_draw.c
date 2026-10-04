#include <unistd.h>
#include <stdlib.h>

static int	ft_atoi(char *s, int *ok)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (!s[0])
	{
		*ok = 0;
		return (0);
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			*ok = 0;
			return (0);
		}
		if (n > (2147483647 - (s[i] - '0')) / 10)
		{
			*ok = 0;
			return (0);
		}
		n = n * 10 + (s[i] - '0');
		i++;
	}
	*ok = 1;
	return (n);
}

static int	count_neighbors(char *board, int width, int height, int row, int col)
{
	int	count;
	int	dr;
	int	dc;
	int	nr;
	int	nc;

	count = 0;
	dr = -1;
	while (dr <= 1)
	{
		dc = -1;
		while (dc <= 1)
		{
			if (dr != 0 || dc != 0)
			{
				nr = row + dr;
				nc = col + dc;
				if (nr >= 0 && nr < height
					&& nc >= 0 && nc < width
					&& board[nr * width + nc])
					count++;
			}
			dc++;
		}
		dr++;
	}
	return (count);
}

static void	life_step(char *board, char *next, int width, int height)
{
	int	row;
	int	col;
	int	n;
	int	index;

	row = 0;
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			index = row * width + col;
			n = count_neighbors(board, width, height, row, col);
			if (board[index])
			{
				if (n == 2 || n == 3)
					next[index] = 1;
				else
					next[index] = 0;
			}
			else
			{
				if (n == 3)
					next[index] = 1;
				else
					next[index] = 0;
			}
			col++;
		}
		row++;
	}
}

static void	print_board(char *board, int width, int height)
{
	char	*line;
	int		row;
	int		col;

	line = malloc(width);
	if (!line)
		return ;
	row = 0;
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			if (board[row * width + col])
				line[col] = '@';
			else
				line[col] = '.';
			col++;
		}
		write(1, line, width);
		write(1, "\n", 1);
		row++;
	}
	free(line);
}

int	main(int argc, char **argv)
{
	int		width;
	int		height;
	int		iterations;
	int		ok;
	char	*board;
	char	*next;
	char	buffer[1024];
	int		nread;
	int		i;
	int		row;
	int		col;
	int		pen;
	int		temp;
	char	c;
	char	*swap;

	if (argc != 4)
		return (1);
	width = ft_atoi(argv[1], &ok);
	if (!ok || width <= 0)
		return (1);
	height = ft_atoi(argv[2], &ok);
	if (!ok || height <= 0)
		return (1);
	iterations = ft_atoi(argv[3], &ok);
	if (!ok)
		return (1);
	if (height > 2147483647 / width)
		return (1);
	board = calloc(width * height, sizeof(char));
	if (!board)
		return (1);
	next = calloc(width * height, sizeof(char));
	if (!next)
	{
		free(board);
		return (1);
	}
	row = 0;
	col = 0;
	pen = 0;
	while ((nread = read(0, buffer, sizeof(buffer))) > 0)
	{
		i = 0;
		while (i < nread)
		{
			c = buffer[i];
			if (c == 'p')
			{
				pen = !pen;
				if (pen)
					board[row * width + col] = 1;
			}
			else if (c == 'u')
			{
				if (row > 0)
					row--;
				if (pen)
					board[row * width + col] = 1;
			}
			else if (c == 'd')
			{
				if (row < height - 1)
					row++;
				if (pen)
					board[row * width + col] = 1;
			}
			else if (c == 'l')
			{
				if (col > 0)
					col--;
				if (pen)
					board[row * width + col] = 1;
			}
			else if (c == 'r')
			{
				if (col < width - 1)
					col++;
				if (pen)
					board[row * width + col] = 1;
			}
			i++;
		}
	}
	if (nread < 0)
	{
		free(board);
		free(next);
		return (1);
	}
	temp = 0;
	while (temp < iterations)
	{
		life_step(board, next, width, height);
		swap = board;
		board = next;
		next = swap;
		temp++;
	}
	print_board(board, width, height);
	free(board);
	free(next);
	return (0);
}

