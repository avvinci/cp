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

struct TrieNode {
	map<char, TrieNode*> children;
	bool is_word = false;
	TrieNode* insert(char c) {
		if (CONTAINS(children, c))
			return children[c];
		TrieNode* next = new TrieNode();
		children[c] = next;
		return next;
	}
};

struct Trie {
	int trie_size = 0;
	TrieNode root;
	void insert(string word) {
		if(word.length() == 0) return;

		TrieNode* temp = root.insert(word[0]);
		for (int i = 1; i < SZ(word); i++)
			temp = temp->insert(word[i]);

		temp->is_word = true;
		trie_size++;
	}

	bool search(string word) {
		if (word.length() == 0) return false;

		TrieNode* temp = root.children[word[0]];
		for (int i = 1; i < SZ(word); i++) {
			if (temp != NULL)
				temp = temp->children[word[0]];
			else return false;
		}

		if (temp != NULL && temp->is_word) return true;
		return false;
	}
};

int main() {
	IO_SPEED_UP;
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Trie t;
	t.insert("man");
	t.insert("mango");
	t.insert("mangoes");
	t.insert("many");
	t.insert("hand");
	t.insert("handy");
	what_is(t.search("man"));
	what_is(t.search("mango"));
	what_is(t.search("many"));
	what_is(t.search("manchester"));
	what_is(t.search("hand"));
	what_is(t.search("hammer"));
	what_is(t.trie_size);
	return 0;
}
