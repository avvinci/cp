// avvinci
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007
 // 
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
#define ws(x) cout << #x << " = " << x << endl
// ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
// ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define N 100002
#define oo 100000

ll b,t,cnt,cnt1, m,n,tmp,q,cn,i,j,k,ans,pos,a[N],dp[N][100];


// bool compare(P a, P b)
// {
//     return a.fs>b.fs;
// }
//vector < vector< ll> > g(N);

ll rec( ll ind , ll val){
    if(ind ==n)
        return 0;
    else if(dp[ind][val]!=0)
        return dp[ind][val];
    else if(val!=0 && gcd(a[ind] , val)==1){
              dp[ind][val] = (rec(ind+1, val) );
    }
   else if(val == 0){
             dp[ind][val] = max( rec(ind+1, a[ind]) + 1, rec(ind+1,0));
    }
    else{
        dp[ind][val] = max( rec(ind + 1 ,gcd(a[ind] , val)) + 1, rec(ind+1, val));
    }
    return      dp[ind][val];
}

int main(){
INP
if (fopen("inp.txt", "r")) 
    freopen("inp.txt", "r", stdin);
 cin>>n;
 fr(i,0,n)  cin>>a[i];
 sort(a,a+n);
 dp[0][0] = max(rec(1,0), rec(1,a[0])+1);
cout<<dp[0][0];
return 0;
}

