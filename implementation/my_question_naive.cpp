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
vector < ll > my_z(string s ){
    ll l = 0, r = 0 ,i = 0;
    ll n = s.size() ;
    vector< ll > z(n,0) ;  
    z[0] =  n ;
    fr(i,1,n){
        if(i <=  r )
            z[i] = min(r - i + 1 , z[i-l]  ) ; 
        while(i + z[i] < n && s[i + z[i] ] == s[ z[i] ] ) 
            ++z[i] ; 
        if( i + z[i] -1 > r ){
            l = i ; r = i + z[i] - 1;
        } 
    }
    return z ; 
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>t; 
while(t--){
    string s , p; 
    cin>>s>>k;
    n = s.size() ; 
    p = s ; 
    fr(i,0,k-1) p+=s ; 
    m = p.size() ; 
    vector< ll > z = my_z(p) ;
    cout<<accumulate(all(z) , 0 )<<"\n" ; 
    int f = 1  ; 
    // fr(i , 1, n ){
    //     if(z[i] >= n ) f = 1 ; 
    // }
    // if(f) cout<<s<<endl;

    fr(i, 0 , m){
        if(i%n ==0 && f == 1 )
            cout<<" "<<z[i]<<" "; 
        else if( f == 1)
            cout<<z[i] <<" " ;
    }
    // if(f)
    // cout<<endl ; 
}




return 0 ;
}