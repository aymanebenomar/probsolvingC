#include <unistd.h>

int countwd (char *s)
{
	int count = 0;
	int i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] && s[i] != '\0')
		{
			count++;
			while (s[i] && s[i] != ' ')
				i++;
		}
	}
	return (count);
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

	while (argv[1][i] && argv[1][i] == ' ')
		i++;
	first = i;
	while (argv[1][i] && argv[1][i] != ' ')
		i++;
	last = i - 1;

	int flag = 0;

	while (argv[1][i] && argv[1][i] == ' ')
		i++;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			flag = 1;
		else
		{
			if (flag == 1)
			{
				write (1, " ", 1);
				flag = 0;
			}
			write (1, &argv[1][i], 1);
		}
		i++;
	}

	if (countwd(argv[1]) != 1)
		write(1, " ", 1);

	while (first <= last)
		write (1, &argv[1][first++], 1);
	
	write(1, "\n", 1);
	return (0);
}