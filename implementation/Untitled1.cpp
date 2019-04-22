#include<bits/stdc++.h>
using namespace std;

typedef vector <long long int > ve;
typedef vector<ve> vve;
typedef pair<long long int , long long int> P;
#define mod 1000000007
#define M 10007
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
#define KM 100000
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define N 12345678
// struct sort_pred {
//     bool operator()(const std::pair<V,int> &left, const std::pair<V,int> &right) {
//         return left.second < right.second;
//     }
// };
ll m,mx=-1,i,j,n,d,cnt=0,t,q,tmp,flag= 0,k,pos,bpos=123456789,x,y;
// bool compare(P a, P b)
// {
//   return (abs(a.first) >  abs(b.first) );
// }
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
unsigned ll  ans[N];
// std::priority_queue<P, std::vector< P >, decltype(&compare)> pq(&compare);
int main(){
INP
cout<<"here i start..";
return 0;
}
