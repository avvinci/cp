/*
 *  Author: Tara Prasad	
 */
#include <bits/stdc++.h>
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

// cycle detection + toposort for directed graphs
vb visited;
vi toposort;
set<int> rec_stack;
void dfs(vvi &g, int u) {
	visited[u] = true;
	rec_stack.insert(u);
	for(int i = 0; i < SZ(g[u]); i++) {
		int v = g[u][i];
		if(visited[v] && CONTAINS(rec_stack, v)) {
			// cycle
		} else if(!visited[v]){
			dfs(g, v);
		}
	}
	rec_stack.erase(u);
	toposort.pb(u);
}

/*For undirected graphs. For counting the number of cycles. Divide the result by 2.*/
vb visited;
vi parent;
int cycles_cnt = 0;
void dfs(vvi &g, int u) {
	visited[u] = true;
	for(int i = 0; i < SZ(g[u]); i++) {
		int v = g[u][i];
		if(visited[v]) {
			if(parent[u] != v){
				cycles_cnt++;
			}
		} else {
			parent[v] = u;
			dfs(g, v);
		}
	}
}

void dfs(vvi &g, int u, vb &visited) {
	for(int i = 0; i < SZ(g[u]); i++) {
		int v = g[u][i];
		if(!visited[v]) {
			visited[v] = true;
			dfs(g, v, visited);
		}
	}
}
// 0 indexing
int num_cc(vvi &g) {
	int n = SZ(g);
	int cnt = 0;
	vb visited(n, false);
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			visited[i] = true;
			dfs(g, i, visited);
			cnt++;
		}
	}
	return cnt;
}

int main() {
	return 0;
}
