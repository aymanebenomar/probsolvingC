#include <stddef.h>
#include <stdio.h>

// Print the count and the total on one line, separated by a single space.
// The specifiers below both claim an int. The compiler will tell you otherwise.
void	print_pair(size_t count, long total)
{
	printf("%zu %ld\n", count, total);
}
