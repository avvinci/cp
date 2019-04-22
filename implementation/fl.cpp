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
#define infl LLONG_MAX
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 1234567
// const long long infl = 1e19+5;
ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =0 ,f,val,sz,cnt,ans,t=1,i,j;
char ch;
int a[155][155];
ll  b[105][105];
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n>>m;
fr(i,0,n){
	fr(j,0,m){
		cin>>ch;
		if(ch == 'W')
			a[i][j] =1;
		else
			a[i][j] = -1;
		
	}
}
for(i = n-1; i>=0 ;i --){
	for(j=m-1;j>=0;j--){
		if(a[i][j] != b[i][j]){
			cnt++;
			val = a[i][j] - b[i][j];
			fr(x,0,i+1){
				fr(y,0,j+1){
					b[x][y] +=val;
					
				}
			}
		}
	}
}
cout<<cnt;

return 0;



}
