// avvinci
//#include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007  
#define all(container) container.begin(),container.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define pb push_back
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define mk make_pair
#define present(container,x) ((container).find(x) != (container).end())
#define inf 3234567891
//#define infl LLONG_MAX
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define sz size()
#define N 112345
const long long infl = 1e18+5;

ll m,n,q,cn,i,j,k,w,pos,tmp1,cnt,sz,mx =-1,tmp,mx1 = -1,val,t,c,sm;
vector< vector< int > > g(N);
int mrk[N],siz[N];
double d1;
string s;

void dfs(int ver ,int par){
	int f = 0; 
	for(auto &it:g[ver]){
		if(it == par) continue;
		if(mrk[it] == 2)
			f = 1;
		dfs(it);
	}
	if(f == 0 && mrk[ver] == 0){
		mrk[ver]  = 1;
	}
	else if(mrk[ver] != 2){
		siz[ver] = g[ver].sz + 1;

	}

}
int main(){
cin>>n;
fr(i,0,n){
	cin>>tmp;
	tmp--;
	g[i].pb(tmp);
}
fr(i,0,n){
	if(g[i].empty()){
		mrk[i] = 2;
	}
}
dfs(0,-1);



return 0;
}