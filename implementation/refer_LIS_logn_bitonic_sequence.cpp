// avvinci -  sem 8    
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

int n,m,k,q,x,y,f,val,t,i,j;
int ind,sz,sm,ans,mx,mn;
int a[N] ,l[N],r[N] ;

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>m;
fr(i,0,n){
    cin>>x>>y;
    a[x]++ ; 
    a[y+1]-- ; 
}
fr(i,1,m+1 ) a[i] += a[i-1] ; 
multiset<int>s ; 
fr(i,1,m+1){
	auto it =  s.upper_bound(a[i]) ; //for non-decreasing, lower_bound for strictly increasing
	if(it != s.end()) s.erase(it) ; 
	s.insert(a[i]) ; 
	l[i] = s.size() ;
}
s.clear() ; 
for( i = m ; i>= 1 ;i-- ){
	auto it = s.upper_bound(a[i]) ; 
	if(it != s.end()) s.erase(it) ; 
	s.insert(a[i]) ; 
	r[i] = s.size() ; 
}
ans = max(l[m] ,r[1]) ; 
fr(i,2,m){
	ans = max(ans , r[i] + l[i-1]) ; 
	ans = max(ans , l[i] + r[i+1]) ; 
}
cout<<ans; 
return 0 ;
}