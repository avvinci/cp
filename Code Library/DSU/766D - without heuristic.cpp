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

// union by rank heuristics not needed
class DSU {
private:
	vi root, set_size, opposite;
	int num_sets;
public:
	DSU(int N) {
		set_size.assign(N, 1);
		num_sets = N;
		root.assign(N, 0);
		opposite.assign(N, -1);
		for (int i = 0; i < N; i++)
			root[i] = i;
	}
	int find_set(int i) {
		return (root[i] == i) ? i : (root[i] = find_set(root[i]));
	}
	int find_opposite_set(int i) {
		int root = find_set(i);
		if(opposite[root] == -1)
			return -1;
		return opposite[root] = find_set(opposite[root]);
	}
	bool union_set(int i, int j) {
		int x = find_set(i);
		int y = find_set(j);
		int opposite1 = find_opposite_set(i);
		int opposite2 = find_opposite_set(j);
		if(x == opposite2 || y == opposite1)
			return false;

		root[y] = x; // unite them
		if(opposite1 == -1 and opposite2 == -1)
			return true;

		if(opposite1 != -1 and opposite2 != -1) {
			root[opposite2] = opposite1; // unite the opposites
			opposite[x] = opposite1;
		} else if(opposite1 == -1) {
			opposite[x] = opposite2;
		} else if(opposite2 == -1) {
			opposite[x] = opposite1;
		}
		return true;
	}
	bool make_opposite(int i, int j) {
		int x = find_set(i);
		int y = find_set(j);
		int opposite1 = find_opposite_set(i);
		int opposite2 = find_opposite_set(j);
		// i and j are in the same set or their opposite are in the same set
		if(x == y || (opposite1 == opposite2 and opposite1 != -1))
			return false;

		opposite[x] = y;
		opposite[y] = x;

		if(opposite2 != -1) {
			root[opposite2] = x;
		}
		if(opposite1 != -1) {
			root[opposite1] = y;
		}
		return true;
	}
};

int main() {
	IO_SPEED_UP; // Turn Off for Interactive Problems
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	int n, m, q; cin >> n >> m >> q;

	map<string, int> word_map;
	for (int i = 0; i < n; ++i) {
		string word; cin >> word;
		word_map[word] = i;
	}

	DSU dsu(n);

	for (int i = 0; i < m; ++i) {
		int type; string x, y;
		cin >> type >> x >> y;
		int idx1 = word_map[x];
		int idx2 = word_map[y];
		if (type == 1) {
			if(dsu.union_set(idx1, idx2))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		} else {
			if(dsu.make_opposite(idx1, idx2))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	while(q--) {
		string a, b;
		cin >> a >> b;
		int idx1 = word_map[a];
		int idx2 = word_map[b];
		if (dsu.find_set(idx1) == dsu.find_set(idx2)) {
			cout << 1 << endl;
		} else if (dsu.find_set(idx1) == dsu.find_opposite_set(idx2)) {
			cout << 2 << endl;
		} else {
			cout << 3 << endl;
		}
	}
	return 0;
}
