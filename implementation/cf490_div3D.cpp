// avvinci -  summers 18    
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
ll ind,sz,sm,ans,mx,mn;
ll a[N] ,cnt[N];


int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
vector<P> v ;
cin>>n>>m;
fr(i,0,n){
	cin>>a[i];
	v.pb(x%m,i);
	cnt[x%m]++;
}
k = n/m ; 
multiset<int> s; 
fr(i,0,k){
	if(cnt[i] < k){
		fr(j,0,k-cnt[i]) s.insert(i) ; 
	} 
}
sort(all(v)) ; 
fr(i,0,v.size()){
	if(cnt[v[i].fs] > k ){
		val = *s.begin() ; 
		ind = v[i].sc ; 
		if(a[ind]%m > val) a[ind] -= (a[ind]%m) -val ;
		else a[ind] += val - a[ind] ; 
		s.erase(val);
		ans++;
		cnt[v[i].fs]--;
	}
}

cout<<ans<<"\n" ; 
fr(i,0,n) cout<<a[i]<<" " ; 

return 0 ;
}