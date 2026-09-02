#include <unistd.h>

#define MAX_LEN 65536

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	count_removals(char *s, int n, int *left_rem, int *right_rem)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	*right_rem = 0;
	while (i < n)
	{
		if (s[i] == '(')
			open++;
		else if (open > 0)
			open--;
		else
			(*right_rem)++;
		i++;
	}
	*left_rem = open;
}

static void	print_buf(char *buf, int n)
{
	write(1, buf, n);
	write(1, "\n", 1);
}

static void	solve(char *s, int n, int i, int open_count,
		int left_rem, int right_rem, char *buf)
{
	if (i == n)
	{
		if (left_rem == 0 && right_rem == 0 && open_count == 0)
			print_buf(buf, n);
		return ;
	}
	if (s[i] == '(')
	{
		if (left_rem > 0)
		{
			buf[i] = ' ';
			solve(s, n, i + 1, open_count, left_rem - 1, right_rem, buf);
		}
		buf[i] = '(';
		solve(s, n, i + 1, open_count + 1, left_rem, right_rem, buf);
	}
	else
	{
		if (right_rem > 0)
		{
			buf[i] = ' ';
			solve(s, n, i + 1, open_count, left_rem, right_rem - 1, buf);
		}
		if (open_count > 0)
		{
			buf[i] = ')';
			solve(s, n, i + 1, open_count - 1, left_rem, right_rem, buf);
		}
	}
}

int	main(int argc, char **argv)
{
	int		n;
	int		left_rem;
	int		right_rem;
	char	buf[MAX_LEN];

	if (argc != 2)
		return (1);
	n = ft_strlen(argv[1]);
	if (n >= MAX_LEN)
		return (1);
	count_removals(argv[1], n, &left_rem, &right_rem);
	solve(argv[1], n, 0, 0, left_rem, right_rem, buf);
	return (0);
}