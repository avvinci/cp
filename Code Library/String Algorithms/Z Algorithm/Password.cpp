/*
 *  Author: Tara Prasad	
 *  Problem: http://codeforces.com/problemset/problem/126/B
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
#define SZ(x) (int)x.size()
#define CONTAINS(cont, val) (cont.find(val) != cont.end())
#define endl '\n'
#define what_is(x) cout << #x << " = " << x << endl
#define IO_SPEED_UP ios::sync_with_stdio(false);cin.tie(NULL)
#define FOR(i, st, ed, inc) for(ll i = st; i < ed; i += inc)

typedef long long ll;typedef pair<ll, ll> ii;
typedef vector<ll> vi;typedef vector<bool> vb;
typedef vector<ii> vii;typedef vector<vi> vvi;

const ll PINF = numeric_limits<ll>::max();
const ll NINF = numeric_limits<ll>::min();
const ll M = 1E9 + 7;
const double EPS = 1E-9;

vi z_function(string s) {
	int n = (int) s.length();
	vi z(n, 0);
	int L = 0, R = 0;  
	for(int i = 1; i < n; ++i) {
		if (i <= R)
			z[i] = min (R - i + 1, (int)z[i - L]);

		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];

        if (i + z[i] - 1 > R) // need to update [L, R]
        	L = i, R = i + z[i] - 1;
    }
    return z;
}

int main() {
	IO_SPEED_UP;
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s; cin >> s; ll n = SZ(s);
	vi z = z_function(s);

	ll suffix_ind  = -1, best_in_middle = -1;

	/* Search for all suffixes which are also prefix. See if it's also in the middle.*/
	for(int i = 1; i < n; i++) {
		if(z[i] + i == n) {
			// the substring of length z[i] is a suffix and also a prefix, now we need to check whether it's contained somewhere in the middle
			
			if(z[i] <= best_in_middle) { /* in the middle, a substring matches with prefix and has length mx
			the substring at i-th position has less or equal length to the middle one and is also a prefix, 
			hence this substring is also contained in that middle substring. */
				suffix_ind = i; 
				break;
			}
		}
		best_in_middle = max(best_in_middle, z[i]);
	}

	if(suffix_ind == -1) {
		cout << "Just a legend" << "\n";
	} else {
		cout << s.substr(suffix_ind, z[suffix_ind]) << "\n";
	}
	return 0;
}
