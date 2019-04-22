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
 
ll m,n,p,q,x,y,k,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a,b ;
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
 
cin>>a>>b;
fr(j,a,b+1){
	priority_queue<int> pq;
	int exp= 0 ; 
	val = j ;
	sm = 1;
	sz = 0 ; 
	if(j == 1) continue;
	for(i=2;i*i<=val;i++){
		exp = 0 ;
		while(val%i == 0 ){
			val /= i ;
			exp++;
		}
		sm *= (exp+1);
		pq.push(exp+1);
 
	}
	if(val >= 2 ){
		sm *= 2;
		pq.push(2);
	}
	sz += sm-1;
	// ws(pq.siz);
	while(!pq.empty()){
		x = pq.top();
		// ws(x);
		pq.pop();
		if(x == 1) break;
		sm = (sm/x) *(x-1);
		sz += sm; 
		pq.push(x-1);
	}
 
	// if(sz == 3)
	// 	sz--;
	 ans += sz ;
	 // ws(sz);
 
 
}
 
cout<<ans;
 
return 0 ;
} 