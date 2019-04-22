// avvinci -  sem 8    
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
#define N 104

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
int  phi[N];
int b[N] , dv[N]; 
ll sh ; 
vector< int > v ; 

void my_primes(){
    for(int i  =2 ; i< N ; i++){
        if(b[i]) continue ; 
        for(int j = i+i; j< N ; j += i ){
            b[j]= 1;
        }
        v.pb(i); 
    }
}

// map< ll ,ll >dv ; 

void get_dv(ll a ,ll b ){
    for(auto i : v ){
        ll st = i * (a/i) ;
        if(st < a ) st += i ;  
        for(int j = st ; j <= b ; j += i )
            dv[j-sh] = i ; 
    }
}

void gen_phi(){
    int i , j ;
    fr(i,1,N) phi[i] = i ; 
    fr(i,2,N){
        if(b[i]) continue ; 
        for(j = i ; j <N ;j += i){
            phi[j] -=   phi[j]/i ; 
        }
    }
}

ll get_phi(ll x) {
    // return dv[x-sh];
    if(x < N ) return phi[x] ; 
    if(dv[x-sh] == 0 ) return (x-1); 
    // return -1;
    if(dv[x-sh] < 2 || x % dv[x-sh] != 0 ) {
        ws(x);
        return -1; 
    }
    return (get_phi(x/dv[x-sh]) * dv[x-sh] ) ; 
}


int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>x>>y ; 
my_primes() ; 
sh = x ; 
get_dv(x,y) ; 
gen_phi() ; 
fr(i,x,y+1){
    cout<<get_phi(i)<<"\n" ; 
}



return 0 ;
}