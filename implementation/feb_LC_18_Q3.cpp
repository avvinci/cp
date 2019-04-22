// avvinci -  sem 8    
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
#define N 1000004
#define B 27 

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,mx = -1,mn = infl ;
int  a[N] ,ans[N];
int  char_cnt[B] ; 

void fun(int i , int &lt , int &rt , int sz){
    int j ; 
    fr(j,0,sz){
        ans[v[i][j]] = lt ; 
        ans[v[i+1][j]] = rt ; 
        j++ ; 
        lt++ ; 
        rt-- ; 
    }
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

string s; 
cin>>t;

while(t--){
    vector< vector< int > > v(B) ; 
    memset(char_cnt,0,sizeof(char_cnt)) ;
    cnt = 0 ; 
    cin>>s;
    n =  (int )s.size() ; 
    fr(i,0,n) {
        char_cnt[s[i] -'a']++;
        v[s[i]-'a'].pb(i) ; 
    }
    fr(i,0,B) {
        if(char_cnt[i]&1) cnt++ ; 
    }
    if(cnt > 1){
        cout<<"-1" ; 
        continue; 
    }
    int lt = 0 ,  rt  = n-1 ;
    fr(i,0,B){
        sz = v[i].size() ; 
        if(sz&1) {ind = i ; continue ;} 
        fun(i,lt,rt,sz)  ; 
    }

    sz = v[ind].size() ; 
    fun(ind,lt,rt,sz) ; 

    fr(i,0,n) {
        cout<<ans[i]<<" " ; 
    }
    cout<<"\n" ; 

}



return 0 ;
}