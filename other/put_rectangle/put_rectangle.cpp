int put_rectangle(int n)
{
	if (n <= 0) return -1;
	if (n <= 2) return n;
	return put_rectangle(n - 1) + put_rectangle(n - 2);
}