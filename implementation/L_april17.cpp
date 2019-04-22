// avvinci - April 17 
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
#define all(container) container.begin(),container.end()
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 1000004
const long long infl = 1e18+5;


ll m,n,p,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a[N] ,l[N],r[N], k[N] ;
std::vector<vector <ll> > v1(N) , v2(N);
std::map<P, int> mp;
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
while(t--){
	cin>>n>>m;
	fr(i,0,N){
		v1[i].clear();
		v2[i].clear();
	}

	fr(i,0,n){
		cin>>a[i];
	}
	fr(i,0,m){
	
		cin>>l[i]>>r[i]>>k[i];
		v1[l[i]].pb(k[i]);
		v2[r[i]].pb(k[i]);
	}

	fr(i,0,n){
		if( i>0 && a[i] == a[i-1])
			cnt++;
		else
			cnt = 1;

		fr(j,0,v1[i+1].siz){
			val  = read(n-v1[i+1][j]);
			mp1[ { i+1,v1[i+1][j] } ] = val;
		}

		update(n-cnt,1);
		
		fr(j,0,v2[i+1].siz){
			val = read(n - v2[i+1][j]) ;
			mp2[ { i+1,v2[i+1][j] } ] = val;

		}
	}
	fr(i,0,m){
		cout<<mp2[{ r[i],k[i] }] - mp1[ {l[i],k[i] } ]<<"\n";
	}

	
}



return 0 ;
}