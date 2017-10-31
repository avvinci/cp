int LIS(vi &a) {
	if(SZ(a) == 0) return 0;
	vi L; L.pb(a[0]);
	for(int i = 1; i < SZ(a); i++) {
		auto ind = lower_bound(ALL(L), a[i]);
		if(ind == L.end()) {
			L.pb(a[i]);
		} else {
			*ind = min(a[i], *ind);
		}
	}
	return SZ(L);
}

// with parent array, refer to this link for the tutorial
// https://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
ii LIS(vector<card> &a, vi& parent) {
	if(SZ(a) == 0) return ii(0, -1);
	int n = a.size(); parent.assign(n, -1); 
	vi dp(n, 1); // dp[i] = length of LIS ending at index i
	int best_end = 0, max_length = 1;

	for(int i = 1; i < n; i++) {
		parent[i] = -1;
		dp[i] = 1;
		for(int j = i - 1; j >= 0; j--) {
			if(less_than(a[j], a[i])) {
				if(dp[i] < dp[j] + 1) {
					parent[i] = j;
					dp[i] = dp[j] + 1;
				}
			}
		}
		if(dp[i] > max_length) {
			max_length = dp[i];
			best_end = i;
		}
	}
	return ii(max_length, best_end);
}