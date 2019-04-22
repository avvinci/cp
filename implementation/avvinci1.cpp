//by avvinci
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
#define N 1234
#define minf -12345678998
# define M_PI           3.14159265358979323846  /* pi */


double m,n,tmp,q,cn,h;
int t;
double ans[111112];

string s[111112];

double cl(ll f ,ll no  , ll k ){
	
	double dp[no+1][k+1];
	CLR(dp);
	ll u,i,j;
	for(i=1;i<=f && i<=k ;i++)	dp[1][i] = 1;
	
	fr(i,2,no+1){
		fr(j,1,k+1){
		
			for(u=1;u<=f && u<= j ;u++ ){
				dp[i][j] += dp[i-1][j-u];
			}
		}
	}
	
	return dp[no][k];
}

int main(){

if (fopen("inp.txt", "r")) 
    freopen("inp.txt", "r", stdin);
freopen ("myfile.txt","w",stdout);
cin>>t;
  int i,j;
fr(j,1,t+1){
    cin>>h>>n;
  
	fr(i,0,n)	cin>>s[i];
	int x, y, z =0 ;
	fr(i,0,n){
		z=0;
		if(s[i].find('-') != std::string::npos ){
			string st1 =s[i].substr(0,s[i].find('-'));
			string st2  = s[i].substr(s[i].find('-')+1);
			z= stoi(st2);
			z *= -1;
			s[i] = st1;
			
		}
		if(s[i].find('+') != std::string::npos ){
			string st1 =s[i].substr(0,s[i].find('+'));
			string st2  = s[i].substr(s[i].find('+')+1);
			z= stoi(st2);
			s[i] = st1;
			
		}
		if(s[i].find('d') != std::string::npos ){
			x =stoi(s[i].substr(0,s[i].find('d')));
			y = stoi(s[i].substr(s[i].find('d')+1));					
		}
	//	what_is(s[i]);what_is(x);what_is(y);what_is(z);
	
	//	h= h - z;
		double minv = x;
		double maxv = y*x;
		//what_is(h-z);what_is(h);what_is(minv);what_is(maxv);
		if((h-z )<= minv){
			ans[i] = 1;
			continue;
		}
		else if((h-z) > maxv ){
			ans[i] = 0;
			continue;
		}
		double w=0,k;
		fr(k,(h-z),maxv+1){			
			w  += cl(y ,x,k);
		//	what_is(w);
		//	what_is(k);									
		}
	
		ans[i] = (w * 1.0 ) / pow(y,x);
		//	what_is(w);what_is(ans[i]);what_is(pow(y,x));
	}
	
	double 	fans = 0;
	fr(i,0,n) fans = max(fans,ans[i]);
    cout<<"Case #"<<j<<": ";
    std::cout << std::fixed;
     std::cout << std::setprecision(6) << fans << '\n';
   

}

return 0;
}
