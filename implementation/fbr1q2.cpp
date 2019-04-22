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
#define N 123

ll b,cnt, m,n,tmp,q,cn,i,j,k,ans ,pos,val,tmp1,f =1,c,t,a[N],s[N],d[N],cst[N],g[N][N],dist[N][N],k1,dp[N][3];

ll rec(int ind , int ld){

   if(dp[ind][ld]!=0)
       return dp[ind][ld];

    if(ld== 1){
        if(ind == k) 
        {
            dp[ind][ld] = dist[s[ind]][d[ind]];
            return dp[ind][ld];
        }
       dp[ind][ld]  = min(rec(ind+1,1)+ dist[s[ind]][d[ind]] + dist[d[ind]][s[ind+1]]    , 
                            rec(ind+1, 2) + dp[s[ind]][s[ind+1]]  );
    }
    else{
        if(ind == k ){
            dp[ind][ld] =  dist[s[ind]][d[ind-1]] + dp[d[ind-1]][d[ind]];
            return dp[ind][ld];
        }
        dp[ind][ld] = rec(ind+1, 1) + dist[s[ind]][d[ind-1]] + dp[d[ind-1]][d[ind]]+ dp[d[ind]][s[ind+1]];
    }
    
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>t;
for(c=1;c<=t;c++){

    cin>>n>>m>>k;
    fr(i,0,N){
        fr(j,0,N){
            g[i][j] = inf ;
            dist[i][j] = inf;
        }
    }
    fr(i,0,N)   dist[i][i] = 0;
        
    fr(i,0,m){
    cin>>tmp>>tmp1>>val;
        if(g[tmp][tmp1] > val){
            g[tmp][tmp1] = val;
            g[tmp1][tmp] = val;
        }
    }

    for (i = 0; i <= n; i++)
        for (j = 0; j <=n; j++)
            dist[i][j] = g[i][j];

    for (k1 = 0; k1 <=n; k1++)
    {
        for (i = 0; i <=n ; i++)
        {
            for (j = 0; j <=n; j++)
            {
                if (dist[i][k1] + dist[k1][j] < dist[i][j])
                    dist[i][j] = dist[i][k1] + dist[k1][j];
            }
        }
    }

    
    fr(i,1,k+1){
        cin>>s[i]>>d[i];
    }  
    ans =  rec(1,1);
    ws(s[1]);
    ws(dist[1][s[1]]);

    cout<<"Case #"<<c<<": ";
    cout<<ans + dist[1][s[0]] <<"\n";

}

return 0;
}