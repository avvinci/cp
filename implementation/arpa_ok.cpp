// God & me
// Fly ...
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 17;

int n, a[maxn];
map<int, int> dp, mark, mask;
int cut(int mask, int i){
	return (mask >> i) | (mask & ((1 << i) - 1));
}
int get(int mask){
	if(mask == 0) 
		return 0;
	if(dp.count(mask))
		return dp[mask];
	int mxbit = 32 - __builtin_clz(mask);
	vector<int> tmp;
	for(int i = 1; i < mxbit; i++)
		if(cut(mask, i) != mask)
			tmp.push_back(get(cut(mask, i)));
	for(auto x : tmp)
		mark[x] = mask;
	while(mark[ dp[mask] ] == mask)
		dp[mask]++;
	return dp[mask];
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int j = 2; j * j <= x; j++)
			if(x % j == 0){
				int cnt = 0;
				while(x % j == 0){
					x /= j;
					cnt++;
				}
				mask[j] |= 1 << cnt;
			}
		if(x > 1)
			mask[x] |= 1 << 1;
	}
	int ans = 0;
	for(auto p : mask)
		ans ^= get(p.second | 1);
	cout << (ans ? "Mojtaba" : "Arpa") << '\n';
	return 0;
}
