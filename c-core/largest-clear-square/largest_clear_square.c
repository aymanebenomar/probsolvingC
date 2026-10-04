
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r');
}

static int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

static int	read_input(char **out, int *size)
{
	char	buf[1024];
	char	*data;
	char	*tmp;
	int		len;
	int		n;

	data = NULL;
	len = 0;
	while ((n = read(0, buf, sizeof(buf))) > 0)
	{
		tmp = realloc(data, len + n + 1);
		if (!tmp)
		{
			free(data);
			return (0);
		}
		data = tmp;
		for (int i = 0; i < n; i++)
			data[len + i] = buf[i];
		len += n;
	}
	if (n < 0)
	{
		free(data);
		return (0);
	}
	if (!data)
	{
		data = malloc(1);
		if (!data)
			return (0);
	}
	data[len] = '\0';
	*out = data;
	*size = len;
	return (1);
}

static int	parse_number(char **p, int *value)
{
	int	n;
	int	d;

	n = 0;
	if (**p < '0' || **p > '9')
		return (0);
	while (**p >= '0' && **p <= '9')
	{
		d = **p - '0';
		if (n > (2147483647 - d) / 10)
			return (0);
		n = n * 10 + d;
		(*p)++;
	}
	*value = n;
	return (1);
}

static int	parse_header(char **p, int *rows, char *empty,
		char *obstacle, char *fill)
{
	char	*start;

	while (is_space(**p))
		(*p)++;
	if (!parse_number(p, rows) || *rows <= 0)
		return (0);
	if (**p != ' ')
		return (0);
	while (is_space(**p))
		(*p)++;
	if (!is_printable(**p))
		return (0);
	*empty = **p;
	(*p)++;

	if (**p != ' ')
		return (0);
	while (is_space(**p))
		(*p)++;
	if (!is_printable(**p))
		return (0);
	*obstacle = **p;
	(*p)++;

	if (**p != ' ')
		return (0);
	while (is_space(**p))
		(*p)++;
	if (!is_printable(**p))
		return (0);
	*fill = **p;
	(*p)++;

	if (*empty == *obstacle || *empty == *fill || *obstacle == *fill)
		return (0);

	start = *p;
	while (**p != '\n' && **p != '\0')
	{
		if (!is_space(**p))
			return (0);
		(*p)++;
	}
	if (**p == '\n')
		(*p)++;
	else if (*p == start)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*input;
	char	*p;
	char	*map;
	int		*dp;
	int		rows;
	int		cols;
	int		len;
	int		empty_count;
	int		best_size;
	int		best_row;
	int		best_col;
	int		prev;
	int		cur;
	int		j;
	char	empty;
	char	obstacle;
	char	fill;

	(void)argv;
	if (argc != 1)
		return (1);

	if (!read_input(&input, &len))
	{
		printf("map error\n");
		return (1);
	}

	p = input;
	if (!parse_header(&p, &rows, &empty, &obstacle, &fill))
	{
		free(input);
		printf("map error\n");
		return (1);
	}

	cols = 0;
	while (p[cols] != '\n' && p[cols] != '\0')
	{
		if (p[cols] != empty && p[cols] != obstacle)
		{
			free(input);
			printf("map error\n");
			return (1);
		}
		cols++;
	}
	if (cols == 0)
	{
		free(input);
		printf("map error\n");
		return (1);
	}

	map = malloc(rows * cols);
	if (!map)
	{
		free(input);
		printf("map error\n");
		return (1);
	}

	empty_count = 0;
	for (int i = 0; i < rows; i++)
	{
		int width;

		width = 0;
		while (p[width] != '\n' && p[width] != '\0')
		{
			if (p[width] != empty && p[width] != obstacle)
			{
				free(map);
				free(input);
				printf("map error\n");
				return (1);
			}
			if (p[width] == empty)
				empty_count++;
			width++;
		}
		if (width != cols)
		{
			free(map);
			free(input);
			printf("map error\n");
			return (1);
		}
		for (int j2 = 0; j2 < cols; j2++)
			map[i * cols + j2] = p[j2];

		p += width;
		if (*p == '\n')
			p++;
		else if (i != rows - 1)
		{
			free(map);
			free(input);
			printf("map error\n");
			return (1);
		}
	}
	while (*p == '\r')
		p++;
	if (*p != '\0')
	{
		free(map);
		free(input);
		printf("map error\n");
		return (1);
	}

	if (empty_count == 0)
	{
		for (int i = 0; i < rows; i++)
			printf("%.*s\n", cols, map + i * cols);
		free(map);
		free(input);
		return (0);
	}
	dp = malloc((cols + 1) * sizeof(int));
	if (!dp)
	{
		free(map);
		free(input);
		printf("map error\n");
		return (1);
	}

	for (int i = 0; i <= cols; i++)
		dp[i] = 0;

	best_size = 0;
	best_row = 0;
	best_col = 0;

	for (int i = 0; i < rows; i++)
	{
		prev = 0;
		for (j = 1; j <= cols; j++)
		{
			cur = dp[j];

			if (map[i * cols + (j - 1)] == empty)
			{
				if (dp[j] < dp[j - 1])
					dp[j] = dp[j];
				else
					dp[j] = dp[j - 1];

				if (prev < dp[j])
					dp[j] = prev;

				dp[j]++;
			}
			else
				dp[j] = 0;

			if (dp[j] > best_size)
			{
				best_size = dp[j];
				best_row = i - best_size + 1;
				best_col = j - best_size;
			}
			prev = cur;
		}
	}
	for (int i = best_row; i < best_row + best_size; i++)
	{
		for (int k = best_col; k < best_col + best_size; k++)
			map[i * cols + k] = fill;
	}

	for (int i = 0; i < rows; i++)
		printf("%.*s\n", cols, map + i * cols);

	free(dp);
	free(map);
	free(input);
	return (0);
}

