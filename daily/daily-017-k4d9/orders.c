// Normal mode (is_test 0) returns shares. Test mode (is_test 1) must send
// nothing: return 0. The line below fires a runaway order instead. Fix it.
int	orders_to_send(int shares, int is_test)
{
	if (is_test == 0)
		return (shares);
	return (0);
}
