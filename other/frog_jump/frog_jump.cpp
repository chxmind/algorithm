long frog_jump(int n) {
	int a = 1;
	int b = 2;
	if (n <= 0) return -1;
	if (n <= 2) return n;

	for (size_t i = 3; i <= n; i++)
	{
		int c = a + b;
		a = b;
		b = c;
	}
	return b;
}
