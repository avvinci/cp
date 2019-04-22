// avvinci -  Winters (12/17)  
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
#define N 3000004
#define M 1000004

// const long long infl = 1e18+5;

int n,m,k,q,x,y,f,val,t=1,i,j;
int ind = -1,cnt,sz,sm,ans,mx = -1 ;
int  a[M] , b[M]  ;
int p[N]  ,rmp[N];
vector<pair< int , int> > ansv ; 
vector<int> v ;

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>k ;
fr(i,0,n)  {
    cin>>a[i]>>b[i] ; 
    a[i] *= 2LL ;
    b[i] *= 2LL ; 
    v.pb(a[i]) ; 
    v.pb(b[i]) ; 
    v.pb(b[i]+1) ; 
}
sort(all(v)) ; 
auto it  = unique (all(v));
v.resize(it - v.begin()) ; 

 
fr(i,0,n){
    x= lower_bound(all(v),a[i]) - v.begin() ; 
    val= lower_bound(all(v),b[i]) - v.begin() ; 
    y = lower_bound(all(v),b[i]+1) - v.begin() ; 
    rmp[x] = a[i] ; 
    rmp[val] = b[i] ; 
    p[x]++;
    p[y]--;
}

fr(i,1,N) p[i] += p[i-1] ; 

fr(i,0,N){
    if(p[i] >= k){
        ans++ ;
        j = i ;  
        while(j < N && p[j] >= k ) j++;
        j--;
        ansv.pb({i,j}) ; 
        i = j; 
    }
}

cout<<ans<<"\n" ; 
fr(i,0,ans){
    cout<<rmp[ansv[i].fs]/2 << " " <<rmp[ansv[i].sc]/2<<"\n" ; 
}



return 0 ;
}