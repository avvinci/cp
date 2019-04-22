#include <bits/stdc++.h>

#define MOD 1000000007
#define LINF (1LL<<60)
#define INF 2147483647
#define PI 3.1415926535897932384626433
#define ll long long
#define pii pair<int,int>
#define mp(x,y) make_pair((x),(y))

using namespace std;

string itos(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}

int n, k;
ll cnt[10000010], tt[10000010], now;

int main(){
	freopen("inp.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
	for(int i = 10000000; i; i--){
		now += cnt[i];
		now -= tt[i]; // deducting repeatedly counted larger stuff
		if(now >= k){
			cout << i << endl;
			return 0;
		}
		tt[(i+1)/2] += cnt[i];
		cnt[i/2] += cnt[i];
		cnt[(i+1)/2] += cnt[i];
	}
	cout << -1 << endl;
	return 0;
}
