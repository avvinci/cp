/*
 *  Author: Tara Prasad
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
#define CONTAINS(cont, val) (cont.find(val) != cont.end())
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

const int MAX_NUMBER_OF_NODES = 6 * 1E5 + 10;
const int ROOT = 0;
const int NIL = -1;
const int CHARSET = 3;

vvi next_trie_node(MAX_NUMBER_OF_NODES, vi(CHARSET, NIL));
vb ends_word(MAX_NUMBER_OF_NODES, false);
string node_symbol(MAX_NUMBER_OF_NODES, '*');
int next_node = ROOT;

int new_node(char c) {
	next_node++;
	node_symbol[next_node] = c;
	return next_node;
}

void insert(string &s) {
	int node = ROOT;
	for(int i = 0; i < SZ(s); i++){
		int p = s[i] - 'a';
		if(next_trie_node[node][p] == NIL) 
			next_trie_node[node][p] = new_node(s[i]);
		node = next_trie_node[node][p];
	}
	ends_word[node] = true;
}

bool dfs(int node, string &input, int index, int mismatch) {
	// what_is(mt(node_symbol[node], index, mismatch));
	if(mismatch > 1) return false;
	if(index == SZ(input)) {
		if(ends_word[node] && mismatch == 1) return true;
		return false;
	}
	for(int c = 0; c < CHARSET; c++) {
		int child = next_trie_node[node][c];
		if(child == NIL) continue;

		int childs_mismatch = mismatch;
		if(c != (input[index] - 'a')) 
			childs_mismatch++;
		
		bool status = dfs(child, input, index + 1, childs_mismatch);
		if(status == true) return true;
	}
	return false;
}

void answer(bool ans) {
	if(ans) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}

int main() {
	IO_SPEED_UP;
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	set<int> sizes;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
		sizes.insert(SZ(s));
	}
	// print_trie(ROOT, "");
	while(m--) {
		string query;
		cin >> query;
		if(!CONTAINS(sizes, SZ(query))) answer(false);
		else answer(dfs(ROOT, query, 0, 0));
	}
	return 0;
}