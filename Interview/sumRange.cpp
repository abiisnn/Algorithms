

bool sum(vector<int> &a, int k) {
	int l = 0, r = 0;
	bool ans = false;
	sum = a[0];
	// k = 0
	// [1, 2, 3, 4]
	while((l < a.size()) && (r < a.size())) {
		if(sum == k) {
			ans = true;
			break;
		}
		if(sum > k) {
			ans -= a[l];
			l++;
		} 
		if(sum < k) {
			ans += a[r];
			r++;
		}
	}
}