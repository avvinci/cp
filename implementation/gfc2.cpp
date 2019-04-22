// avvinci
//#include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007 
#define MOD 1000000007
#define all(container) container.begin(),container.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define pb push_back
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define mk make_pair
#define present(container,x) ((container).find(x) != (container).end())
#define inf 3234567891
//#define infl LLONG_MAX
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define sz size()
#define N 1034567
const long long infl = 1e18+5;

ll m,n,q,cn,k,w,pos,tmp1,sz,mx =0,tmp,mx1 = -1,sm,mn = infl ,x,i,j,f,cnt=1,u,ans,t= 1;
// vector< vector< int > > g(N),ans(2);
 ll a[N],p[N],b[N];

ll tr[N][27];
bool en[N]; 
string s;
void ins(){
	
ll v= 0 ;
	for(  ll it= 0 ; it< s.size() ; it++){

		if( !tr[v][s[it]-'a'] ){
			tr[v][s[it]-'a']  = t++;

		}
				
		
		v= tr[v][s[it]-'a'] ;
		if(tr[v][26] ==0 )
			tr[v][26] =cnt;
	}
	en[v] = true; 
	cnt++;
	
}

int solv(ll ind, ll tind ){

	if(ind == s.size()){
		return tr[tind][26];
	}

	ll  v = s[ind] -'a';


	int re =0;
	if(tr[tind][v] != 0 )
		re  =  solv(ind+1,tr[tind][v] );
	else
		return tr[tind][26];
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n;
fr(i,0,n){
	cin>>s;
	ans = solv( 0, 0);
//	ws(ans);
	ins();
	if(ans == 0 )
		cout<<"-1\n";
	else
		cout<<ans<<"\n";

}


return 0;
}