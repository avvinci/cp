// avvinci
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007  
#define all(container) container.begin(),container.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define sz(a) int((a).size())
#define pb push_back
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define mk make_pair
#define present(container,x) ((container).find(x) != (container).end())
#define inf 123456789123456
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define NL cout<<"\n";  
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define N 312


ll b,cnt, m,n,tmp,q,cn,i,j,k,ans ,pos,tmp1,f =1,c,t,s[N][N],cst[N][N],dp[N][N];


int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>t;
for(c=1;c<=t;c++){
    cin>>n>>m;
    vector< vector < ll > >a(n);
    fr(i,0,n){
        fr(j,0,m){
            cin>>tmp;
            a[i].pb(tmp);
        }
    }
    fr(i,0,n+1){
        fr(j,0,n+1){
            dp[i][j] =inf;
            cst[i][j] =inf;
            s[i][j]=0;
        }
        cst[i][0] = 0;
    }

    fr(i,0,n){
        sort(all(a[i]));
        //ws(a[i][0]);
    }
    fr(i,1,n+1){
        fr(j,1,m+1){
            if(j==1)
                s[i][j] = a[i-1][j-1];
            else
                s[i][j] = a[i-1][j-1]+s[i][j-1];
            cst[i][j] = s[i][j]+(j)*(j);
          //  ws(cst[i][j]);
        }
    }
    fr(j,1,n+1) dp[1][j] = cst[1][j];
dp[1][0] = inf;
    fr(i,2,n+1){
        fr(j,i,n+1){                  
            fr(k,i-1,j+1){
                dp[i][j] = min(dp[i][j], dp[i-1][k] + cst[i][j-k]);
                // ws(i);
                // ws(j);
                // ws(k);
                // ws(dp[i][j]);
                // ws(dp[i-1][k]);
                // ws(cst[i][j-k]);
            }

        }
    }
cout<<"Case #"<<c<<": ";
cout<<dp[n][n]<<"\n";

}

return 0;
}