long fib(int n) {
	long a = 0;
	long b = 1;
	if (n < 0) return -1;
	if (n <= 1) return n;
	for (int i = 2; i <= n; i++) {
		long c = a + b;
		a = b;
		b = c;
	}
	return b;
}

long fib2(int n) {
	if (n <= 1) return n;
	return fib2(n - 1) + fib2(n - 2);
}