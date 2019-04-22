#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007
#define all(container) container.begin(),container.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define sz(a) int((a).size())
#define pb push_back
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define mk make_pair
#define present(container,x) ((container).find(x) != (container).end())
#define inf 123456789123456
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define NL cout<<"\n";  
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define what_is(x) cout << #x << " = " << x << endl
// ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
// ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define N 234567

// bool compare(P a, P b){ return ((a.first) >  (b.first) ); }
//ll ord[123456],a[123456],f[123456],p[123456],s[123456];
// // ll find (ll u ){
// //     if(p[u]!=u)
// //         return(find(p[u]));
// //     return u;
// // }
// void  merge (ll u, ll v){
//     ll y = find(u);
//     ll yy = find(v);
//     p[yy] = y;
//     s[y] = s[yy] + s[y];
// }
//std::priority_queue<P, std::vector< P >, decltype(&compare)> pq(&compare);

ll m,mx=-1,i,j,n,tmp,t,ans,k,cnt = 0 ,di[N],val[N];
// ll deg[N],vis[N],v[N],u[N];
// vector< set < ll> >  g(210);
// struct sort_pred {
//     bool operator()(const  ll &left, const ll &right) {
    	
//         if(deg[left]%2 != deg[right]%2){
//         	if(deg[left]%2==1)
//             return false;
//             else 
//             return true;
// 		}
//         return ((deg[left]%2 == deg[right]%2 ) && (deg[left] > deg[right]));
//     }  };


vector<ll> v;
int main(){
INP
freopen("inp.txt","r",stdin);
cin>>n;
ll sm =0;
fr(i,0,n){
    cin>>val[i]>>di[i];
    sm  += val[i];
}
ll low = -123456789, high = 123456789 , mid ,ans =-999888777666 ,f; 
while(low<= high){
    mid = low + (high - low) /2 ;
    ll  cur  = mid;
    f= 0;
    fr(i,0,n){
        if(di[i] == 1 && cur < 1900)
        {
            f = 2 ;
            break;
        }
        if(di[i] == 2 && cur >= 1900)
        {
            f= 1 ;
            break;
        }
        cur += val[i];
    }
    if(f==1){
        high = mid - 1;
        
    }
    else {
            if(f!=2)
                ans = mid;
         low   = mid + 1;
         
    }
    
}
if(ans == 123456789){
    cout<< "Infinity";
    return 0 ;
}
if(ans != -999888777666){
    cout<< ans+sm;
    return 0 ;
}
cout<<"Impossible";


return 0;
}
