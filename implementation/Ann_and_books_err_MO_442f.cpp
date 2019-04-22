// avvinci - sem_7 
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
#define sz(x)  (ll)x.size()
#define N 100004
#define BLOCK 400 

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,mx = -1,mn = infl ;
ll pr[N] , a[N] ,b[N] ,ans[N];
vector < pair <P , ll >  > v ; 
map < ll ,ll > mp ; 
bool cmp( pair< P ,ll > a , pair<P , ll >  b ) {
    if(a.fs.fs/BLOCK != b.fs.fs/BLOCK ) return a.fs.fs/BLOCK < b.fs.fs/BLOCK ; 
    return a.fs.sc < b.fs.sc  ;
}

void fun(int x ,int st ){
    ll prev = 0 ; 
    if(x > 0  ) prev = pr[x-1] ; 
    if(pr[x] - prev == k ) cnt += st ; 
}

void addl(int x){
    cnt += mp[pr[x] + k ] ; 
    mp[pr[x]]++;
    // fun(x,1) ; 
 }
void addr(int x ){
    cnt += mp[pr[x]- k ] ; 
    mp[pr[x]]++ ; 
    // fun(x,1) ; 
    // ws(cnt);

}
void reml(int x){
    cnt -= mp[pr[x] + k] ; 
    mp[pr[x]]-- ; 
    // fun(x,-1) ; 
}
void remr(int x){ 
    cnt -=mp[ pr[x] - k ] ;
    mp[pr[x]]-- ;     
    // fun(x,-1)  ;  
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>k ;
fr(i,0,n){
    cin>>b[i] ; 
} 
fr(i,0,n){
    cin>>a[i] ; 
    if(b[i] == 2 ) a[i] = -1*a[i] ; 
}

pr[0] = a[0] ; 
fr(i,1,n) 
    pr[i] = a[i] + pr[i-1] ; 

cin>>q;
    
fr(i,0,q){
    cin>>x>>y;
    x--; y-- ; 
    v.pb({ {x,y}, i}) ; 
}

// sort(all(v), cmp )  ; 
ll cl = 0 ,cr = 0  ; 

fr(i,0,q){
    ind = v[i].sc ; 
    x = v[i].fs.fs; 
    y = v[i].fs.sc ; 
    // cout<<x<<" " <<y<<"\n";

    while(cl < x ) {
        reml(cl) ; 
        cl++ ; 
    }
    // ws(cnt);
    while(cl > x ){
        addl(cl-1) ;
        cl-- ; 
    }
    // ws(cnt);

    while(cr <= y ){
        addr(cr) ;
        cr++ ;  
    }
    // ws(cnt);
    
    while(cr > y+1 ) {
        remr(cr-1) ; 
        cr--;
    }
    // cout<<cnt<<"\n";

    ans[ind] = cnt ; 
}

fr(i,0,q) {
    cout<<ans[i]<<"\n" ; 
}
return 0 ;
}