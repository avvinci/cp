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
#define N 1004
const long long infl = 1e18+5;

ll m,n,p,q,x,y,k,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1 ,l;
char a[N][N] ;
	string s;
int vis[N][N];
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>t;
while(t--){
	cin>>l>>n;
	cin>>s;

	map < P , int > mp;
	std::vector<P> v;
	set<P> st ,st1;
	queue<  pair< int ,int > > q,q2;
	fr(i,0,n+2){
		q.push( mk(0,i) );
		q.push( mk(n+1,i) );

	}
	fr(i,1,n+1){
		q.push(mk(i,0) );
		q.push(mk(i,n+1));
	}


	fr(i,1,n+1){
		fr(j,1,n+1){
			cin>>a[i][j];
			vis[i][j] = -1;
			st.insert(mk(i,j));
			if(a[i][j] == '#'){
				vis[i][j] = 0;
				q.push( mk(i,j)  );
			}

			
		}
	}
	while(!q.empty()){
		st1.insert(q.front());
		q.pop();
	}
	for(auto it:st1){
		P p1,p2,p3,p4;
		p1.fs = it.fs - 1; p1.sc = it.sc;
		p2.fs = it.fs + 1; p2.sc = it.sc ;
		p3.fs  = it.fs ; p3.sc = it.sc - 1;
		p4.fs = it.fs ; p4.sc = it.sc +1;
		if(st1.find(p1) != st1.end() && st1.find(p2) != st1.end() && st1.find(p3) != st1.end() && st1.find(p4) != st1.end()){
			// ws(it);
			continue;

		}
		q.push(it);
	}


	x = 0 ; y = 0 ;
	fr(i,0,l){
		if(s[i] == 'L')
			y--;
		else if(s[i] == 'R')
			y++;
		else if(s[i] == 'D')
			x++;	
		else
			x--;
	// st.insert(mk{x,y});
		// ws(v.siz);
		if(mp.find(mk(x,y)) == mp.end()){
			v.pb(mk(x,y));
			mp[mk(x,y)] = i;
		}
		
	}

	int nx,ny;
	for(auto it :v){
		nx = it.fs;
		ny = it.sc;
		// ws(mk(nx,ny));
		while(!q.empty()){
			x  = q.front().fs;
			y = q.front().sc;

			q2.push(q.front());
			
			x -= nx;
			y -= ny;
			if(st.empty())
				break;

			if(st.find(mk(x,y)) != st.end()){
				// ws(q.front());
				// ws(mk(x,y));
				st.erase(mk(x,y));
				vis[x][y] = mp[it];
			}
			q.pop();

		}
		// cout<<endl;
		if(st.empty())
			break;
		while(!q2.empty()){
			q.push(q2.front());
			q2.pop();
		}
	}

	ans = 0 ;
	fr(i,1,n+1){
		fr(j,1,n+1){
			if(a[i][j] == '#') {
				// cout<<"# "; 
				continue;
			}
			else if(vis[i][j] == -1) {
				ans ^= l;
				// cout<<l<<" ";
			}
			else{
				ans ^= vis[i][j];
				// cout<<vis[i][j]<<" ";
			}

			
		}
		// cout<<endl;
	}
	cout<<ans<<"\n";

}




return 0 ;
}