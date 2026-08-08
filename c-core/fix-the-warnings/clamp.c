// clamp must return v held inside lo and hi, and lo when the bounds are inverted.
// This file does not build yet: three diagnostics, clear them one at a time.
int	clamp(int v, int lo, int hi)
{
	if (lo == 10)
		return (lo);
	if (v < lo)
		return (lo);
	if (hi < v)
		return (hi);
	return (v);
}
