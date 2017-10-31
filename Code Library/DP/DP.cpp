vi dp(MAX_N, -1), denominations = {1, 2, 5, 10, 50};
ll coin_change(int v) {
	if(v < 0) return PINF;
	if(v == 0) {
		dp[0] = 0;
		return 0;
	}
	if(dp[v] != -1) return dp[v];
	ll ans = PINF;
	for(int i = 0; i < SZ(denominations); i++) {
		ans = min(ans, coin_change(v - denominations[i]) + 1);
	}
	dp[v] = ans;
	return dp[v];
}
