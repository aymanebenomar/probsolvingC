#include <unistd.h>

void	rev(char *s, int first, int last)
{
	char temp;

	while (first < last)
	{
		temp = s[first];
		s[first] = s[last];
		s[last] = temp;
		first++;
		last--;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write (1, "wrong number of arguments\n", 26);
		return (0);
	}
	int i = 0;
	int first;
	int last;
	while (argv[1][i])
		i++;
	i--;
	first = 0;
	last = i;
	rev(argv[1], first, last);
	i = 0;
	while (argv[1][i])
	{
		while (argv[1][i] && ((argv[1][i] >= 9 && argv[1][i] <= 13) || argv[1][i] == ' '))
			i++;
		first = i;
		while (argv[1][i] && !((argv[1][i] >= 9 && argv[1][i] <= 13) || argv[1][i] == ' '))
			i++;
		last = i - 1;
		rev(argv[1], first, last);
	}
	i = 0;
	while (argv[1][i])
		write (1, &argv[1][i++], 1);
	write(1, "\n", 1);
	return (0);
}
