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
ll a[N] , L , R ;
struct  node {
    ll lt , rt ,le ,re  ;
    ll val ; 
};

node tr[2 * N + 10 ] ; 

node fun( node x ,node  y , ll mid  ){

    node v ; 
    if(x.lt  == mid ) 
        v.lt = y.lt ;
    else
        v.lt = x.lt  ; 
    
    if(x.le == mid )
        v.le = y.le ; 
    else
        v.le = x.le ;

    if(y.rt == mid -1 ) 
        v.rt = x.rt ;
    else 
        v.rt = y.rt ;

    if(y.re == mid -1 )
        v.re = x.re ;
    else
        v.re = y.re ; 

    ll d1 = 0 ,d2 ; 
    ll e1 = max(x.re , x.rt ) ; 
    ll e2 = min(y.lt , y.le ) ; 

    d1 = (mid-1 - x.rt ) * (y.lt - mid ) ; 

    d2 = (mid-1 - e1 ) * (e2 - mid )  ; 
    // cout<<d1<<" "<<d2<<" *\n";
    v.val = x.val + y.val + d1 - d2 ; 
    return v ; 
}

void build(ll v , ll l ,ll r ){
    if( l + 1 == r ){
        tr[v] = {r,l-1,r,l-1,0} ;
        return ;  
    }
    ll mid  = (l+r)/2 ; 
    build(v+v , l , mid);
    build(v+v+1,mid,r) ; 
    tr[v] = fun( tr[v+v] ,tr[v+v+1] ,mid) ; 
}

void upd(ll v , ll l , ll r , ll ind , ll val ){
    if( l+1 == r  ){
        // ws(l);

        if(val < L ){
            tr[v] = {r,l-1,r,l-1,0} ;
        }
        else if(val > R ){
            tr[v] = {ind ,ind , r,l-1 ,0 } ; 
        }
        else
            tr[v] = {r,l-1,ind,ind,1} ; 
        // cout<<l+1 <<" " <<r << " " << tr[v].val <<" ..\n";   

        return ; 
    }
    ll mid  = (l + r) / 2 ; 
    if(ind < mid ) 
        upd(v+v,l,mid,ind,val) ; 
    else
        upd(v+v+1,mid,r,ind,val) ; 
    tr[v] = fun(tr[v+v],tr[v+v+1],mid) ; 
    // cout<<l+1 <<" " <<r << " " << tr[v].val <<" ..\n";
}


node get(ll v ,ll l ,ll r, ll lq ,ll rq ){

    if( l >= lq && r <= rq ){
        // cout<<l+1 <<" " <<r <<  " ("<<v<<") " << tr[v].val <<" ||\n";
        return tr[v] ;
    }
    if( l >= rq || r <= lq ){
        return {l,r-1,l,r-1,0};
    }

    ll mid = (l + r) /2 ; 
    node n1 = get(v+v,l,mid,lq,rq) ; 
    node n2 = get(v+v+1,mid,r,lq,rq) ;
    node n = fun(n1,n2,mid) ; 
    // cout<<l +1<<" " <<r << " " << n.val <<" ||\n";

    return n ; 
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n>>q>>L>>R ; 
build(1,0,n) ; 
while(q--){
    cin>>t ; 
    if(t == 1){
        cin>>ind>>val ; ind-- ; 
        // cout<<"\n";
        upd(1,0,n,ind,val) ;  
    }
    else{
        cin>>x>>y;
        node re = get(1,0,n,x-1,y) ; 
        cout<<re.val<<"\n" ; 
    }
}


return 0 ;
}