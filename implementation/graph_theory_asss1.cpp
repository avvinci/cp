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
// set< int > s[N] ; 
// vector< P > v_out ;


int main(){

INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

int ssz; 
cin>>ssz;
while(ssz--){

	// map< P , int > mp ;
	cin>>n>>m;
	int  vv_inp[n][m] ;
	int new_col = (m+M-1 ) / M ;  
	char vv[n][new_col] ;
	
	//--> Construction of Compressed Matrix -- > 

	fr(i,0,n){
		j = 0 ; 
		int my_cnt = 0 ;
		while(j < m ){
			int p =0 ;
			fr(k,0,M){
				j++;
				if(j > m ) break ;
				cin>>x; 
				vv_inp[i][j] = x ;
				p = p*2 + x ; 
			}
			char ch = 'a' + p; 
			vv[i][my_cnt++] = ch ; 
		}
	}




	// std::vector<int> ex_v;
	// ex_v.pb(1) ; 
	// cout << "sizeof: " << sizeof(ex_v) << endl;
	// cout << "size: " << ex_v.size() << endl;
	// cout << "capacity: " << ex_v.capacity() << endl;
	// cout << "max_size: " << ex_v.max_size() << endl;	//  Size calculation -- > 

/*	int bb = sizeof(vv[0].size() ) + sizeof(char) * vv[0].capacity() ;
	int ans1 = sizeof(vv) + bb * vv.capacity() ; 
	int bi = sizeof(vv_inp[0].size()  )+ sizeof(int) * vv_inp[0].capacity() ;
	int ans2 = sizeof(vv_inp) +  bi * vv_inp.capacity() ; 
	cout<<ans2 <<" "<<ans1<<"\n";
	v_out.pb(mk(ans1,ans2));

		ws();
	} 
	sort(all(v_out));
	fr(i,0,v_out.size()){
		cout<<v_out[i].fs<<" "<<v_out[i].sc<<"\n";
	}
	// cout<<sizeof(vv)<<" "<<sizeof(vv_inp)<<"\n"; 

*/




	// print compressed matrix --> 
	cout<<"   Compressed Matrix \n";

	fr(i,0,n){
		fr(j,0,new_col){
			cout<<vv[i][j]<<" " ; 
		}
		cout<<"\n"; 
	}


	// --> Conversion to adjacency matrix-->
	vector< vector< int >  > ans(n, vector< int > (n,0));
	int temp_arr[m + 4] ; 
	memset(temp_arr,-1,sizeof(temp_arr));

	fr(i,0,n){
		j =0;
		while(j < new_col){
			int p =	vv[i][j] -'a' ;
			int g  =  j ; 
			fr(k,0,M){
				if(p&(1<<k)){
					// if(mp.find(mk(g,k)) == mp.end()){
					// 	mp[{g,k}] = t++;
					// }
					// ws(mk(g,k));
					int temp_val = temp_arr[g*4 + k ] ; 
					if(temp_val  == -1 ){
						temp_arr[g*4 + k] =  i ; 
					}
					else{
						ans[i][temp_val] = 1;
						ans[temp_val][i] = 1; 
					}
					// int val = mp[{g,k}];
					// s[val].insert(i) ; 
				}
			}
			j++; 

		}

	}




	// fr(i,0,t){
	// 	vector<int> v;
	// 	for(auto it: s[i]){
	// 		v.pb(it);
	// 	}
	// 	fr(j,0,v.size()){
	// 		fr(k,j+1,v.size()){
	// 			ans[v[j]][v[k]] = 1;
	// 			ans[v[k]][v[j]] = 1;
	// 		}
	// 	}
	// 	v.clear();

	// }




	// print adjacency matrix
	cout<<"\n    Adjacency Matrix \n\n";
	fr(i,0,ans.size()){
		fr(j,0,ans[i].size()){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n"; 
	}
	cout<<"-------------------------------\n\n";

}



return 0 ;
}