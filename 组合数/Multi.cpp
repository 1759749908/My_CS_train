int Multi(int m, int n) {
	if (n == m) return 1;
	int temp = 1;
	n++;
	if (m == 0) m++;
	//0�Ľ׳���1
	for (; n <= m; n++) {
		temp *= n;
	}
	return temp;
}