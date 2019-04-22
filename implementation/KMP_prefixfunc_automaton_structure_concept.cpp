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
#define N 104

const long long infl = 1e18+5;
const int K = 3 , B = 26; 


ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
string s[K] ;
int dp[N][N][N] , l[K]; 
int prefix[N] , automat[N][B+1] ; 

struct node{
    int i,j ,k; 
    node(){
        i=j=k=-1;
    }
    node(int  i , int j , int k) : i(i) , j(j) , k(k){}
    bool operator==(const node &a){
        return (a.i ==i && a.j == j && a.k ==k  ) ; 
    }
};
node p[N][N][N] ; 

void prep(string &s){
  
    int i,j,n = s.size() ; 
    fr(i,1,n){
        int j = prefix[i-1]  ;
        while(j > 0 && s[i] != s[j])
            j = prefix[j-1] ; 

        if(s[i] == s[j]) j++;
        prefix[i] = j ;  
    }
    fr(i,0,n){
        fr(j,0,B){
            if(i > 0 && (j != (s[i]-'A') ) )
                automat[i][j] = automat[prefix[i-1]][j];
            else
                automat[i][j] = i + (j == (s[i]-'A')) ; 
        }
    }

}



int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

fr(i,0,3){
    cin>>s[i] ; 
    l[i] = s[i].size() ; 
}
prep(s[2]) ; 
dp[0][0][0] = 0 ;
node back  = node(-1,-1,-1) ; 
ans = 0 ;
node Ans; 
 
fr(i,0,l[0]){
    fr(j,0,l[1]){
        fr(k,0,l[2]){
            int nxt = automat[k][s[0][i]-'A'] ; 
            if((s[0][i] == s[1][j] )&&  (nxt < l[2] ) ){
                        if(dp[i+1][j+1][nxt]<dp[i][j][k]+1){
                        dp[i+1][j+1][nxt] = dp[i][j][k]+1;
                        p[i+1][j+1][nxt] = node(i,j,k);
                    }
            }
           if(dp[i][j][k]>dp[i+1][j][k]){
                   dp[i+1][j][k] = dp[i][j][k];
                   p[i+1][j][k] = p[i][j][k];
                }
                if(dp[i][j][k]>dp[i][j+1][k]){
                   dp[i][j+1][k] = dp[i][j][k];
                   p[i][j+1][k] = p[i][j][k];
                }

        }
    }
}

fr(i,0,l[0]+1) {
    fr(j,0,l[1]+1){
        fr(k,0,l[2]+1){
            if(ans < dp[i][j][k]) {
                ans = dp[i][j][k];
                Ans = p[i][j][k];
            }
        }
    }
}
// ws(ans);
string res = "" ; 
while(true){
    if(Ans == back ) break; 
    res += s[0][Ans.i] ; 
    Ans = p[Ans.i][Ans.j][Ans.k] ;
}
reverse(all(res)) ; 
if(res == "") cout<<"0";
else cout<<res; 


return 0 ;

}