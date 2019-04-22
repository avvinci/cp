// avvinci
//#include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007 
#define MOD 1000000007
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
#define N 123456
const long long infl = 1e18+5;

ll m,n,q,cn,k,w,pos,tmp1,sz,mx =0,tmp,mx1 = -1,sm,b,c,d,mn = infl ,k1,p,x,i,j,f,cnt,u;
// vector< vector< int > > g(N),ans(2);
 ll a[N];

// double d1;
// string s,t;

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>tmp>>tmp1;
if(tmp == 0 && tmp1 == 0){
	cout<<"NO";
	return 0;
}

if(abs(tmp -tmp1) <= 1 )
	cout<<"YES";
else
	cout<<"NO";
return 0;
}