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
#define N 1000004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N] ;

struct mat{
    ll m[2][2] ; 
    mat(){
        memset(m,0,sizeof(m)) ; 
    }
    mat(int v){
        memset(m,0,sizeof(m)) ; 
        m[0][0] = v ;
        m[1][1] = v ;
    }
} ;

inline mat operator + (mat a ,mat b){
    mat c ; 
    for(int i = 0 ;i < 2 ;i++ ) 
        for(int j = 0 ; j  < 2 ;j++)
            c.m[i][j]  = ( a.m[i][j] + b.m[i][j] )%mod ;
    return c ; 
} 

inline mat operator * (mat a ,mat b ){
    mat c ; 
    for(int i = 0 ;i <2 ; i++)
        for(int j =0 ; j < 2 ;j++)
            for(int k = 0 ;k < 2 ;k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j])%mod ;
    return c ; 
}
inline mat modpow(mat a , ll b ){
    mat c(1) ; 
    while(b > 0 ){
        if(b&1)
            c =  c * a ; 
        a = a * a ; 
        b /= 2;
    }
    return c ; 
}
inline mat fib(ll b ){
    mat c ; 
    c.m[0][0] = 1;
    c.m[0][1] = 1 ; 
    c.m[1][0] = 1; 
    return modpow(c,b) ; 
}
mat lz[N] , tr[N] ; 

void build(int v ,int l, int r ){
    lz[v] = mat(1) ; 
    if(l + 1 == r){
        tr[v] = fib(a[l]) ; 
        return ; 
    }
    int mid = (l+r)/2 ;
    build(v+v,l,mid) ; 
    build(v+v+1,mid,r) ; 
    tr[v] = tr[v+v] + tr[v+v+1] ; 
}

void push(int v){
    lz[v+v] = lz[v+v]*lz[v] ; 
    lz[v+v+1] = lz[v+v+1]*lz[v] ; 
    tr[v+v] = tr[v+v] * lz[v] ; 
    tr[v+v+1] = tr[v+v+1]  * lz[v] ; 
    lz[v] = mat(1) ; 
    return; 
}

void upd(int v ,int l ,int r ,int lq ,int rq , mat val){
    if(l >= lq && r <= rq ){
        lz[v] = lz[v] *  val ; 
        tr[v] = tr[v] * val ; 
        return ; 
    }
    if(l >= rq || r <= lq ) return ; 
    push(v) ; 
    int mid =  (l  + r )/2 ; 
    upd(v+v, l ,mid ,lq,rq,val ) ;
    upd(v+v+1,mid,r,lq,rq,val) ;
    tr[v] = tr[v+v] + tr[v+v+1] ; 

}

mat sum(int v ,int l ,int r ,int lq, int rq){
    if(l >= lq && r <= rq ){
        return tr[v] ;
    }
    if( l >= rq || r <= lq ) {
        return mat() ; 
    }
    push(v) ; 
    int mid = (l+r)/2 ; 
    return sum(v+v,l,mid,lq,rq) + sum(v+v+1,mid,r,lq,rq ) ; 
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}


cin>>n>>q;
fr(i,0,n) cin>>a[i] ; 
build(1,0,n) ; 
ll l , r ; 
while(q--){
    cin>>t>>l>>r; 
    if(t == 1 ){
        cin>>val ;
        upd(1,0,n,l-1,r,fib(val)) ;  
    }
    else{
        mat res = sum(1,0,n,l-1,r) ; 
        cout<<res.m[0][1]<<"\n";
    }
}



return 0 ;
}