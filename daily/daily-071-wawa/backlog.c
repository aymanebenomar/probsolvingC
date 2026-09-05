int	backlog(const int *arrivals, int n, int rate)
{
	int waiting;
	int i;

	waiting = 0;
	for (i = 0; i < n; i++) 
	{
		waiting += arrivals[i];
		if (waiting >= rate) 
			waiting -= rate; 
		else
			waiting = 0;
	}
	return (waiting);
}
