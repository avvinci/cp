// avvinci - march 17 
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long int , long long int> P;
#define mod 1000000007 
#define pb push_back
#define mk make_pair
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 4000004
const long long infl = 1e18+5;

struct tri
{
	int a;
	int b;
	int c;
	
};
ll m,n,q,x,y,k,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
string s;
std::vector< tri > tree(N);

void build( int node , int start ,int end ){

	if(start == end){
		if(s[start]== '('){
			tree[node].a =1;
			tree[node].b = 0;
			tree[node].c  = 0 ;
		}
		else{
			tree[node].a =0;
			tree[node].b = 0;
			tree[node].c  = 1 ;
		}
		return;
	}

	int mid = (start + end ) /2;
	build(2*node , start , mid);
	build(2*node+1, mid+1, end);
	int mn = min(tree[2*node].a , tree[2*node+1].c);
	tree[node].a = tree[2*node].a + tree[2*node+1].a - mn;
	tree[node].c = tree[2*node].c + tree[2*node+1].c - mn;
	tree[node].b = tree[2*node].b + tree[2*node+1].b + mn;
 
}

tri query(int node, int start, int end , int l ,int r){
	tri t;
	t.a = 0 ;
	t.b = 0;
	t.c =0;
	if(l> end || r< start)
		return t ;
	
	if(start >=l && end <= r){
		return tree[node];
	}

	int mid = (start + end ) /2;

	tri p1 = query(2*node,start,mid,l,r);
	tri p2 = query(2*node+1,mid+1,end,l,r);
	int mn = min(p1.a , p2.c);
	t.a  = p1.a + p2.a - mn;
	t.c = p1.c + p2.c - mn;
	t.b = p1.b + p2.b + mn;
	// ws(start);
	// ws(end);
	// ws(tree[node]);
	// cout<<"\n";
	return t ;
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>s;
cin>>m;
n = (ll)s.siz;
// ws(n);
build(1,0,n-1);

fr(i,0,m){
	cin>>x>>y;
	x--;y--;
	tri p1 = query(1,0,n-1,x,y);
	ans = 2*p1.b;
	cout<<ans<<"\n";
} 

return 0 ;
}
