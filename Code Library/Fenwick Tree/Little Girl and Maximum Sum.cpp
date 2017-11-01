/*
 *  Author: Tara Prasad	
 *  Problem: http://codeforces.com/problemset/problem/276/C
 */
#include <bits/stdc++.h>
// #define DEBUG
#ifdef DEBUG
	#include "printcpp11.h" 
#endif
using namespace std;

#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define REV_ALL(x) x.rbegin(), x.rend()
#define REV(x) reverse(x.begin(), x.end())
#define SORT(x) sort(x.begin(), x.end())
#define REV_SORT(x) sort(x.rbegin(), x.rend())
#define SZ(x) (int)x.size()
#define CONTAINS(cont, val) cont.find(val) != cont.end()
#define endl '\n'
#define what_is(x) cout << #x << " = " << x << endl
#define IO_SPEED_UP ios::sync_with_stdio(false);cin.tie(NULL)

typedef long long ll;
typedef pair<int, int> ii;typedef pair<ll, ll> pll;
typedef vector<int> vi;typedef vector<bool> vb;typedef vector<ll> vll;
typedef vector<ii> vii;typedef vector<pll> vpl;
typedef vector<vi> vvi;typedef vector<vll> vvll;

const int PINF = numeric_limits<int>::max();
const int NINF = numeric_limits<int>::min();
const ll M = 1E9 + 7;

#define last_one(S) (S & (-S))

class fenwick_tree {
private:
	vi ft;
public:
	fenwick_tree(int n) { 
		ft.assign(n + 1, 0);
	}
	int sum_first(int b) {
		int sum = 0; 
		for (; b != 0; b -= last_one(b)) 
			sum += ft[b];
		return sum; 
	}
	int sum_between(int a, int b) {
		return sum_first(b) - (a == 1 ? 0 : sum_first(a - 1)); 
	}
	void update(int k, int v) {
		for (; k < SZ(ft); k += last_one(k)) 
			ft[k] += v; 
	}
};

int main() {
	IO_SPEED_UP;
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	vi a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	fenwick_tree ft(n);
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		ft.update(l, 1);
		ft.update(r + 1, -1);
	}

	vi freq(n + 1);
	for(int i = 1; i <= n; i++) {
		freq[i] = ft.sum_first(i);
	}

	sort(freq.rbegin(), freq.rend() - 1);
	sort(a.rbegin(), a.rend() - 1);

	ll sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += (ll)freq[i] * (ll)a[i];
	}
	cout << sum << "\n";
	return 0;
}