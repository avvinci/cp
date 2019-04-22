// avvinci
//#include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007  
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
#define N 312345
const long long infl = 1e18+5;

ll m,n,q,cn,i,j,k,w,pos,tmp1,cnt,f,sz,mx =-1,tmp,x,y,mx1 = -1,val,ans=1,t =1;
string s;
ll tr[N][3];
bool en[N]; 

void ins(){
	
ll v= 0 ;
	for(  ll it= 0 ; it< s.size() ; it++){

		if( !tr[v][s[it]-'a'] )
				tr[v][s[it]-'a']  = t++;
		v= tr[v][s[it]-'a'] ;
	}
	en[v] = true; 
	
}

int solv(ll ind, ll tind , int isone){

	if(ind == s.size()){
		if(!isone )
			return 0;
		return en[tind];
	}

	ll  v = s[ind] -'a';


	int re =0;
	if(tr[tind][v] != 0 )
		re  = solv(ind+1,tr[tind][v] , isone);
	if(!isone && !re){

		for(  ll it= 0 ; it< 3 ; it++){
			if(it == v || tr[tind][it]==0 ) continue;
			re  = solv(ind+1,tr[tind][it] , 1);
			if(re) return 1;
				
		}
	}
	return re;
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n>>m;
fr(i,0,n){
	cin>>s;
	ins();

}

fr(j,0,m){
	cin>>s;
	f = solv( 0 ,0 ,0 );
	if(f){
		cout<<"YES\n";

	}
	else
		cout<<"NO\n";

}
return 0;
}