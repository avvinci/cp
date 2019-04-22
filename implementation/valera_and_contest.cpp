// avvinci
// #include"prettyprint.hpp"
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
#define siz size()
#define N 123456
const long long infl = 1e18+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =0 ,f,val,sz,cnt,ans,t=1,i,j;

ll l,r,sa,sk,sn;
vector <int > ans1 ,ans2;
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n>>k>>l>>r>>sa>>sk;
sn = sa -sk;
ll minx,cminx,csn,rminx;
minx = l;
fr(i,l,r+1){
	if(k*i >= sk){
		rminx = i;
		break;
	}
}


fr(i,1,n-k+1){
	// ws(i);
	fr(j,l,rminx+1){
		csn = sn -j;
		cn = n-i;
			// ws(rminx*(cn-k));
			// ws(l*(cn-k));
		if( l*(cn-k)<= csn && rminx*(cn-k) >= csn ){
		
			cout<<j<<" \n";
			ans1.pb(j);
			ans +=j;
			sn  =csn;
			break;

		}




	}
}
cout<<ans1.siz<<"    "<<ans<<" "<<sn<<"\n";
rminx--;
ans = 0;
minx  = max(rminx,minx);
fr(i,n-k+1,n+1){
	fr(j,minx,r+1){

		csn  =sk - j;
		cminx = max(minx,j);
		cn = n- i ;
		if( cminx * cn <= csn  && r*(cn) >= csn ){
			cout<<j<<" \n";
			ans2.pb(j);
			ans += j;
			sk = csn;
			minx = cminx;
			break;
		}


	}
}
cout<<ans2.siz<<"    "<<ans<<"\n";
ans = 0;

return 0;



}
