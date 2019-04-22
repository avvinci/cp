// avvinci -  Winters (1/18)  
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
#define N 2000004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N] ;
vector< ll > v ;
void gen_prime(){
    for(int i = 2 ; i< N ; i++ ){
        if(a[i]) continue ; 
        for(j = i + i ; j <N ; j+= i ) 
            a[j] = 1 ; 

        v.pb(i) ;  
    }
}
int check(int n ){
    
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t ; 
gen_prime() ; 
// ws(v.size()) ; 
// fr(i,100,v.size()) { 
//     if(v[i] - v[i-1] > 100 ) ans++ ;  
// }
// cout<<ans<<"\n" ; 
// fr(i,100,v.size()) { 
//     if(v[i] - v[i-1] > 100 ) cout<<v[i-1]+1<<"\n" ;  
// }
a[1] = 1 ; 
a[0] = 1 ; 
while(t--){
    cin>>x ; 
    fr(i,x,2e6 + 1) if(check(i)  ) {
        cout<< i <<"\n" ; 
        break ;
    }
}

return 0 ;
}