/*
 *  Author: sleepify
 *  Problem: 706D 
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

const int MAX_BITS = (int)ceil(log(1E9 + 10)/log(2.0));

struct trie_node {
	vector<struct trie_node*> children;
	int number_cnt = 0; // no. of numbers using this node
	trie_node() {
		children.assign(2, nullptr);
	}
};

struct trie {
	trie_node* root;
	trie() {
		root = new trie_node();
	}
	void insert(string s) {
		trie_node* node = root;
		for(int i = 0; i < MAX_BITS; i++){
			int index = s[i] - '0';
			if(node->children[index] == nullptr)
				node->children[index] = new trie_node();
			node = node->children[index];
			node->number_cnt++;
		}
	}

	void remove(string s) {
		trie_node* node = root;
		for (int i = 0; i < MAX_BITS; ++i) {
			int index = s[i] - '0';
			node = node->children[index];
			node->number_cnt--;
		}
	}

	// Greedy Strategy: Try to make as many 1 as possible during XOR
	string get_maximum_xor(string x) {
		string result(MAX_BITS, '0');
		trie_node* node = root;
		for (int i = 0; i < MAX_BITS; ++i) {
			int d = x[i] - '0';
			if(node->children[0] == nullptr || node->children[0]->number_cnt == 0) {
				result[i] = (d ^ 1) + '0';
				node = node->children[1];
			} else if(node->children[1] == nullptr || node->children[1]->number_cnt == 0) {
				result[i] = d + '0';
				node = node->children[0];
			} else {
				result[i] = '1';
				node = node->children[1 - d]; // to make the value 1
			}
		}
		return result;
	}
};

string to_binary(int n) {
	string s(MAX_BITS, '0');
	int i = 0;
	while(n) {
		s[i++] = (n & 1) + '0';
		n >>= 1;
	}
	reverse(ALL(s));
	return s;
}

int to_decimal(string x) {
	int n = 0;
	int exp = 1;
	for (int i = x.size() - 1; i >= 0; --i) {
		n += exp * (x[i] - '0');
		exp <<= 1;
	}
	return n;
}

int main() {
	IO_SPEED_UP; // Turn Off for Interactive Problems
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	int q; cin >> q;
	trie tree;
	tree.insert(to_binary(0));
	while(q--) {
		char type; cin >> type;
		int x; cin >> x;
		if(type == '+') {
			tree.insert(to_binary(x));
		} else if(type == '-') {
			tree.remove(to_binary(x));
		} else {
			cout << to_decimal(tree.get_maximum_xor(to_binary(x))) << endl;
		}
	}
	return 0;
}