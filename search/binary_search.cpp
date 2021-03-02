int binary_search(int* a, int size, int target)
{
	if (a == nullptr) return -1;
	if (size == 0) return -1;
	
	int l = 0;
	int r = size - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (target == a[mid]) {
			return mid;
		}
		else if (target < a[mid]) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}
