// avvinci -  winters 18    
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long > P;

#define mod 1000000007 
#define pb emplace_back
#define fs first
#define sc second
#define ll long long 
#define fr(it,st,en) for(it=st;it<en;it++)
#define all(container) container.begin(),container.end()
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl;
#define N 1000004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t,i,j;
ll ind,cnt,sz,sm,ans,mx,mn;
ll a[N] ;


int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>x>>y>>k;
ll prev = 1, val = 1, f = 0 ; 
while(true){
	if(val >= x) {
		f = 1 ; 
		cout<<val <<" " ; 
	}
	prev = val;   
	val = prev * k ;
	if(val/k != prev || val > y ) break ;
}
if(f==0) cout<<"-1" ; 


return 0 ;
}