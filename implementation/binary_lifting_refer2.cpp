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
#define B 21

const long long infl = 1e15+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N],p ;
ll  par[N][B] , par_sum[N][B]; 
// vector< ll > g[N];

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
ll last = 0 ,Q,r,w,pind;
cnt = 1 ;  
a[0] = infl ; 
fr(i,0,B) par_sum[1][i] = infl ;
cin>>Q;
while(Q--){
    cin>>t;
    cin>>p>>q ; 
    r = p ^ last ; 
    if(t == 1) {
        w = q ^ last ;
        // cout<< r <<" " <<w<<" \n" ; 
        cnt++; 
        a[cnt] = w; 
        if(a[r] >= a[cnt] ) {
            par[cnt][0] = r ; 
        }
        else{
            
            int lt = B-1 , ind = r ; 
            while(lt >= 0 ){
                if(a[par[ind][lt]] < w )
                    ind = par[ind][lt] ;
                lt-- ; 
            }
            par[cnt][0] = par[ind][0] ; 
            // ws(ind);

        }
        // cout<<cnt <<" " <<par[cnt][0]<<" --\n";

        if(par[cnt][0] == 0 ) {
            par_sum[cnt][0] = infl; 
        }
        else
            par_sum[cnt][0] = a[par[cnt][0]] ; 
        fr(i,1,B){
            pind = par[cnt][i-1]; 
            par[cnt][i] = par[pind][i-1]; 
            if(par[cnt][i] == 0 )
                par_sum[cnt][i] = infl;
            else
                par_sum[cnt][i] = par_sum[cnt][i-1] + par_sum[pind][i-1] ; 
        }

    }
    else{
        x = q ^ last ; 
        // ws(a[r]);
        // ws(x);
        // cout<< r <<" " <<x<<" ..\n" ; 

        if(a[r] > x){
            last = 0 ;  
            cout<<"0\n" ; 
            continue ; 
        }
        x -= a[r] ; 
        int lt = B-1 ,ind = r ,ans = 1 ; 
        while(lt >= 0 ){
            if(par_sum[ind][lt] <= x ){
                x -= par_sum[ind][lt]  ; 
                ans += (1LL<<lt);  
                ind = par[ind][lt] ;
                // ws(ind);

            }
            lt-- ;
        }
        cout<<ans<<"\n"; 
        last = ans ; 
    }
}
// cout<<par[5][0] ; 

return 0 ;
}