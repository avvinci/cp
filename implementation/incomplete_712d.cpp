// avvinci
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
#define wis(x) cout << #x << " = " << x << endl
// ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
// ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define N 312345
#define oo 100000

int a,b,t,cnt, m,n,tmp,q,cn,i,j,k,ans,pos,dp[110][201000],v,p[110][201000];


// bool compare(P a, P b)
// {
//     return a.fs>b.fs;
// }

int main(){
INP
if (fopen("inp.txt", "r")) 
    freopen("inp.txt", "r", stdin);

cin>>a>>b>>k>>t;
dp[0][oo+0] =1;
fr(i,0,(2*k*t+1))
    p[0][oo+i] = 1;

fr(i,1,t+1){
    fr(j,-(2*k*t),(2*k*t+1)){
        
        dp[i][oo+j] += p[i-1][oo+j+2*k]-p[i-1][oo+j-2*k];
         wis(i);         wis(oo+j);
        wis(dp[i][oo+j] );
        p[i][oo+j] =p[i][oo+j-1]+dp[i][oo+j];
    }
}

int diff = b-a;
fr(i,diff,(k*t+1)){
    ans += dp[t][oo+i];
    
}
cout<<ans;
return 0;
}

