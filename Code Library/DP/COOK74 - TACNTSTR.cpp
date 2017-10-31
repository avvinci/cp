// SOLUTION-1
void solution1() {
	string s; cin >> s;
	int n = s.length();
	s = ' ' + s;

	// dp1[n] = no. of ways s > t till first n positions
	// dp2[n] = no. of ways t > s and reverse(t) > reverse(s) till first n positions
	int dp1[n + 1] = {0}, dp2[n + 1] = {0};
	for (int i = 1; i <= n; ++i) {
		ll greater = 'Z' - s[i];
		dp2[i] = greater; 						// if s = t for [1, i - 1] and [i + 1, n]
		dp2[i] += dp2[i - 1];					// if t[i] = s[i] and s = t for [i + 1, n]
		dp2[i] += (greater * dp1[i - 1]) % M; 	// t[i] > s[i]
		// if t > s till i - 1, to make reverse(t) > reverse(s),
		// the ith(last in this substring) has to be equal or greater

		dp2[i] %= M;

		dp1[i] = greater; // if s = t for first i - 1
		dp1[i] += (26LL * dp1[i - 1]) % M; // if previous is greater then current can be any of the 26
	}
	cout << dp2[n] << endl;
}

// SOLUTION-2
int dp[112435][2][2];
string s; int n;

int main() {
	IO_SPEED_UP;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	cin >> s; n = s.length();

	/*
	 * dp[pos][ok1][ok2]: DEFINITION
	 * for the first pos - 1 positions, i.e. s[0..pos-1] & t[0..pos-1]
	 * 		| 	  0	   |	 1	 |
	 * ---------------------------
	 * 	ok1	|    s=t   |	t>s	 |
	 * 	ok2	|R(t)<=R(s)|R(t)>R(s)|
	 */

	// valid if: ok1 = 1, for first n - 1 t > s and ok2 = 1, for first n - 1 rev(t) > rev(s)
	// if(ok1 = 0 or ok2 = 0): invalid
	for (int ok1 = 0; ok1 <= 1; ++ok1) {
		for (int ok2 = 0; ok2 <= 1; ++ok2) {
			dp[n][ok1][ok2] = ok1 & ok2;
		}
	}
	for (int pos = n - 1; pos >= 0; --pos) {
		for (int ok1 = 0; ok1 <= 1; ++ok1) {
			for (int ok2 = 0; ok2 <= 1; ++ok2) {
				char c = 'A'; // if ok1 = 1
				if(ok1 == 0) { // for first pos - 1 positions t = s
					c = s[pos]; // now if c < s[pos] t < s for first pos positions, so start with c = s[pos]
				}
				for (; c <= 'Z'; ++c) {
					int nextOk1 = 0; // s = t till pos positions since ok1 = 0 till now and c = s[pos]
					if(ok1 == 1 || c > s[pos]) { // already greater or current addition makes it greater
						nextOk1 = 1;
					}
					int nextOk2;
					if(s[pos] == c) {
						nextOk2 = ok2;
					} else if(c > s[pos]){
						nextOk2 = 1; // in the reversed string pos is the first position
						// hence, for t > s, c has to be greater than s[pos]
					} else if(c < s[pos]) { // allowed if ok1 = 1
						nextOk2 = 0;
					}
					dp[pos][ok1][ok2] += dp[pos + 1][nextOk1][nextOk2];
					dp[pos][ok1][ok2] %= M;
				}
			}
		}
	}
	cout << dp[0][0][0] << endl; // answer after filling the 0th position
	return 0;
}
	