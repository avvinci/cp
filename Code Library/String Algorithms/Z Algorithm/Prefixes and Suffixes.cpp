/*
 *  Author: sleepify
 */
#include <bits/stdc++.h>
// #include "prettyprint.h"
using namespace std;

#define LOG(x) cerr << "*** " << x << " ***" << endl;
#define wi(x) what_is(x, '\n')
#define wisp(x) what_is(x, ", ")
#define what_is(x, terminator) cerr << #x << " = " << x << terminator;

#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define REV_ALL(x) x.rbegin(), x.rend()
#define SZ(x) (int)x.size()
#define CONTAINS(cont, val) (cont.find(val) != cont.end())
#define endl '\n'
#define IO_SPEED_UP ios::sync_with_stdio(false);cin.tie(NULL)
#define FOR(i, s, e) for(ll i = s; i < e; i++)
#define leftmost_set(x) __builtin_clzll(x)
#define TWO_POWER(n) (1LL << (n))

// When root of a binary tree is 1
#define PARENT(n) ((n) >> 1LL)
#define LCHILD(n) ((n) << 1LL)
#define RCHILD(n) (((n) << 1LL) + 1LL)

typedef long long ll;typedef pair<ll, ll> ii;
typedef vector<ll> vi;typedef vector<bool> vb;
typedef vector<ii> vii;typedef vector<vi> vvi;

const int INF32 = 1E9;
const long long INF64 = 4E18;
const ll M = 1E9 + 7;
const double EPS = 1E-9;
const double PI = 2 * acos(0);

template <typename T> ostream& operator<<(ostream& os, const vector<T> &p){os << "[ "; for (T x: p) os << x << " "; os << "]" << endl; return os;}
template <typename T> ostream& operator<<(ostream& os, const set<T> &p){os << "{ "; for (T x: p) os << x << " "; os << "}" << endl; return os;}
template <typename Tk, typename Tv> ostream& operator<<(ostream& os, const map<Tk, Tv> &p){os << "{ "; for (pair<Tk, Tv> x: p) os << x << " "; os << "}" << endl; return os;}
template <typename Tk, typename Tv> ostream& operator<<(ostream& os, const pair<Tk, Tv> &p){os << "{" << p.first << ',' << p.second << "}";return os;}

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
	IO_SPEED_UP; // Turn Off for Interactive Problems
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	string s; cin >> s; ll n = SZ(s);
	vi z = z_function(s);
	z[0] = n;

	// Search for all suffixes which are also prefix.
	vi prefixes;
	for(int i = 0; i < n; i++) {
		if(z[i] + i == n) {
			prefixes.pb(z[i]);
		}
	}
	sort(ALL(prefixes));

	vi cnt(n + 1); // cnt of substrings for z-prefixes
	for(int i = 0; i < n; i++) {
		cnt[z[i]]++;
	}

	// larger prefixes contains smaller prefixes also
	// if cnt[5] = 4, then prefixes of length 1, 2, 3, 4 also occur 4 times
	vi suffix_sum(n + 2, 0);
	for(int i = n; i >= 0 ; i--) {
		suffix_sum[i] = suffix_sum[i+1] + cnt[i];
	}

	cout << SZ(prefixes) << endl;
	for (int i = 0; i < SZ(prefixes); ++i) {
		cout << prefixes[i] << " " << suffix_sum[prefixes[i]] << endl;
	}
	return 0;
}
