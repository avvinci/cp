/*
 *  Author: Tara Prasad
 */
#include <bits/stdc++.h>
#define DEBUG
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

vvi next_trie_node(MAX_NUMBER_OF_NODES, vi(CHARSET, NIL));
vb ends_word(MAX_NUMBER_OF_NODES, false);
string node_symbol(MAX_NUMBER_OF_NODES, '*');
int node_count = ROOT;

int new_node(char c) {
	node_count++;
	node_symbol[node_count] = c;
	return node_count;
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

void print_trie(int node, string s) {
	what_is(mt(node, s));
	if(ends_word[node]) {
		cout << s << "\n";
	} 
	for(int c = 0; c < CHARSET; c++) {
		int child = next_trie_node[node][c];
		if(child != NIL)
			print_trie(child, s + char(c + 'a'));
	}
}

bool search(string s) {
	int node = 0;
	for(int i = 0; i < SZ(s); ++i) {
		int p = s[i] - 'a';
		if(trie[node][p] == 0) return false;
		node = trie[node][p];
	}
	return true;
}

int main() {
	IO_SPEED_UP;
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	insert("man");
	insert("mango");
	insert("pango");
	insert("pangoes");
	insert("mangoes");
	insert("many");
	insert("hand");
	insert("handy");
	what_is(search("man"));
	what_is(search("mango"));
	what_is(search("many"));
	what_is(search("manchester"));
	what_is(search("hand"));
	what_is(search("hammer"));
	return 0;
}
