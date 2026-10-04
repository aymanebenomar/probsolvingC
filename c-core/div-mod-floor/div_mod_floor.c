void div_mod_floor(int a, int b, int *q, int *r) 
{ 
	*q = a / b; *r = a % b; 
	if (*r < 0) 
	{ 
		*r += (b < 0) ? -b : b;
		*q -= (b < 0) ? -1 : 1; 
	} 
}