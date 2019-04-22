// avvinci
// march 17 
#include"prettyprint.hpp"
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
//#define infl LLONG_MAX
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 51
const long long infl = 1e18+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =-1 ,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind = -1,ci;
char a[N][N] ;
map < P, ll > mp;
void dfs( int x ,int y , int st ){
	if(st == 0 ){
		if(a[x][y] != 'B' || a[x][y] != 'P' || a[x][y] != 'G' )
			return;
	}
	if(x< 0 || y< 0 || x >= n || y >= n) return;
	if(a[x][y] == '.') return;
	
	sz++;
	if(a[x][y] == 'G' && k == 0   ){
		k = 3 ;
	}
	else if( a[x][y] == 'G' && k != 0 ){
		k = 5;
	}
	else if(k == 0 && (a[x][y] == 'B'))
		k =1;
	else if(k == 0 && (a[x][y] == 'P'))
		k =2;
	else if( (k == 1 || k == 3) && (a[x][y] == 'P' ))
		k =5;
	else if( (k == 2  || k == 3 )&& (a[x][y] == 'B' ))
		k =5;

	
	if(mp.find( mk (x,y)) != mp.end()) return ;
	mp[ mk(x,y)] = 1;
	dfs(x-1,y,st);
	dfs(x+1,y,st);
	dfs(x,y-1,st);
	dfs(x,y+1,st);

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
while(t--){
	mp.clear();
	cin>>n;
	fr(i,0,n){
		fr(j,0,n){
			cin>>a[i][j];
			// if(a[i][j] == '?')
			// 	f = 1;
		}
	}

// if(f == 0 ){
// 	cout<<"0\n";
// 	continue;
// }

f =0 ;
ans = 1LL;
ll re ; 
fr(i,0,n){
	fr(j,0,n){

		P p = mk(i,j);
		if(a[i][j] == '.') continue;
		if(mp.find(p) != mp.end()) continue;
		sz = 0 ;
		k=0;
		if(a[i][j] != '?' ) {
			ws(p);
			// if(a[i][j] == 'G')
			// 	k =3;
			// else if(a[i][j] == 'P')
			// 	k =2 ;
			// else
			// 	k = 1;
			dfs(p.fs,p.sc,0);
			if(k == 5) {
				f = 1;	
				
			}
			continue;
			
			
		}
		if(mp.find(p) == mp.end()){

			dfs(p.fs,p.sc,1);
			if(k == 3 || k ==1 || k == 2) {
				continue;
			}
			else if(k == 5){
					f =1;
			}
			else if(sz == 1){
				ans *= 3LL;
				ans %= mod;
			}
			else if(sz >= 1 ){
				ans *= 2LL;
				ans %= mod;
			}
			// ws(ans);

		}
	}
}
 if(f ){
 	cout<<"0\n";
 }
 else
 	cout<<ans<<"\n";


 // fr(i,0,cmp){
 // 	if(cnt[cmp] == 1) {
 // 		ans *= 
 // 	}
 // }


}
return 0 ;
}
