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
#define N 323456
#define minf -12345678998

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
// void print_vector(vi &v) {
// 	for (int i = 0; i < (int)v.size(); ++i)	{
// 		cout << v[i]<< " ";
// 	}
// 	cout << endl;
// }

ll m,i,j,n,tmp,p,q,cnt,cl,ans,sm,k,a[N],b[N],sans,eans,ansl,cs,ce;
 //vector< vector < P > >  g(N);
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

// struct cmp
// {
//     bool operator()(P a, P b)
//     {
//         if (a.fs == b.fs)  
//             return a.sc > b.sc;
//         else
//             return a.fs < b.fs;
//     }
// };

int main(){
INP
if (fopen("inp.txt", "r")) 
    freopen("inp.txt", "r", stdin);
   
    
}
return 0;
}