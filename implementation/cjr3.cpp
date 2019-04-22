// avvinci - April 17 
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long int , long long int> P;
#define mod 1000000007 
#define pb push_back
#define mk make_pair
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define all(container) container.begin(),container.end()
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 1504
const long long infl = 1e6+5;

ll m,n,p,q,x,y,k,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a[N] ,dp[N][N][3][3];

int  rec(int ind ,int cnt1,  int st ,int ss){

	// if(cnt1 > 720  || ind - cnt1 > 720 )
	// 	return infl;

	if(a[ind] != 0 ){
		if(st != a[ind])
			return infl;
	}

	if(ind == 24*60 ){
		if(cnt1 != 720 ) return infl;
		if(st == ss)
			return 0 ;
		return 1;
	}

	if(dp[ind][cnt1][st][ss] != -1 )
		return dp[ind][cnt1][st][ss];

	int re;
	if(st == 1) {
		 re = min( rec(ind+1,cnt1+1,st,ss) , 1+ rec(ind+1,cnt1,2,ss));
	}
	else
		re = min(rec(ind+1,cnt1,st,ss) , 1 + rec(ind+1,cnt1+1,1,ss));


	 dp[ind][cnt1][st][ss] =re;

	return re;

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
sz = t;
while(t--){
	fr(i,0,N){
		fr(j,0,N)
			{

				dp[i][j][1][1] = -1;
				dp[i][j][1][2] = -1;
				dp[i][j][2][1] = -1;
				dp[i][j][2][2] = -1;
			}
		
	}
	cin>>n>>m;
	fr(i,0,n){
		cin>>x>>y;
		fr(j,x,y)
			a[j] = 1;

	}

	fr(i,0,m){
		cin>>x>>y;
		fr(j,x,y){
			a[j] =2;
		}
	}
	cout<<"Case #"<<sz-t<<": ";
	cout<<min(rec(0,1,1,1), rec(0,1,2,2));
	cout<<"\n";

}



return 0 ;
}