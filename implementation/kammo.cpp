// avvinci - sem_7 
#include"prettyprint.hpp"
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
#define sz(x)  (ll)x.size()
#define N 1000004
#define M 4


const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t,i,j;
ll ind = -1,cnt,sz,sm,mx = -1,mn = infl ;
set< int > s[N] ; 
vector< P > v_out ;
int main(){
INP
if (fopen("graph_data1.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("graph_data1.txt", "r", stdin);
}
cin>>t;
// ws(t);
while(t--){
	vector< vector < char > >vv ;
	vector<char> v;
	map< P , int > mp ;
	vector<int > v_inp;
	vector< vector < int > > vv_inp ;
	cin>>n>>m;
	fr(i,0,n){
		j = 0 ; 
		while(j < m ){
			int p =0 ;
			fr(k,0,M){
				j++;
				if(j > m ) break ;
				cin>>x; 
				v_inp.pb(x) ; 
				p = p*2 + x ; 
			}
			char ch = 'a' + p; 
			v.pb(ch);
			// j += M ; 
		}
		vv_inp.pb(v_inp);
		v_inp.clear();
		vv.pb(v); 
		v.clear();
	}
	// ws(vv);
	pair<int, int > p = mk(0,0) ; 
	int bb = sizeof(p)*m ;
	int ans1 = sizeof(vv) + bb * vv.capacity() ; 
	int bi = sizeof(vv_inp[0].size()  )+ sizeof(int) * vv_inp[0].capacity() ;
	int ans2 = sizeof(vv_inp) +  bi * vv_inp.capacity() ; 
	// cout<<ans2 <<" "<<ans1<<"\n";
	v_out.pb(mk(bb,ans2));

	// ws();
} 
sort(all(v_out));
fr(i,0,v_out.size()){
	cout<<v_out[i].fs<<" "<<v_out[i].sc<<"\n";
}

// fr(i,0,vv.size()){o
// 	j =0;
// 	while(j < vv[i].size()){
// 		int p =	vv[i][j] -'a' ;
// 		int g  =  j ; 
// 		fr(k,0,M){
// 			if(p&(1<<k)){
// 				if(mp.find(mk(g,k)) == mp.end()){
// 					mp[{g,k}] = t++;
// 				}
// 				// ws(mk(g,k));
// 				int val = mp[{g,k}];
// 				s[val].insert(i) ; 
// 			}
// 		}
// 		j++; 

// 	}

// }
// // ws(s[0]);
// vector< vector< int >  > ans(n, vector< int > (n,0));

// fr(i,0,t){
// 	vector<int> v;
// 	for(auto it: s[i]){
// 		v.pb(it);
// 	}
// 	// ws(v);
// 	// ws(t);/
// 	fr(j,0,v.size()){
// 		fr(k,j+1,v.size()){
// 			ans[v[j]][v[k]] = 1;
// 			ans[v[k]][v[j]] = 1;
// 		}
// 	}
// 	v.clear();

// }

// fr(i,0,ans.size()){
// 	fr(j,0,ans[i].size()){
// 		cout<<ans[i][j]<<" ";
// 	}
// 	cout<<"\n"; 
// }





return 0 ;
}