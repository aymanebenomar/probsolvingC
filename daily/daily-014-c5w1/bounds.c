// Return arr[idx], but only when idx is in [0, len). Out of range, return -1.
int	read_at(int *arr, int len, int idx)
{
	if (idx >= 0 && idx < len)
		return (arr[idx]);
	return (-1);
}
