#include <unistd.h>

// greet prints three fixed lines and ignores its command line.
// The lines are already correct: make the file build.
int	main()
{
	write(1, "hello, world\n", 13);
	write(1, "greet v1.0\n", 11);
	write(1, "ready\n", 6);

	return (0);
}
