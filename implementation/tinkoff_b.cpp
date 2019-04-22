#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) (int)x.size()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef vector<pii> vpii;

template<typename T>
T getint() {
    T x=0,p=1;
    char ch;
    do{ch=getchar();}while(ch <= ' ');
    if(ch=='-')p=-1,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*p;
}

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

template<typename T1,typename T2>bool umin(T1 &x,const T2&y){if(x>y)return x=y,true;return false;}
template<typename T1,typename T2>bool umax(T1 &x,const T2&y){if(x<y)return x=y,true;return false;}

const int maxn=(int)1e6+10;
const int inf=(int)1e9+5;
const int mod=(int)1e9+7;
const ll llinf=(ll)1e18+5;
const ld pi=acos(-1.0);

struct state {
    int x,y,d,k;
};

int d[1010][1010][4][3];
char s[1010][1010];
    queue<state> q;

void add(int x,int y,int di,int k){
    // if(d[x][y][di][k]!=-1)return;
    d[x][y][di][k]=0;
    q.push({x,y,di,k});
}

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int main() {

    freopen("inp.txt","r",stdin);
    freopen("myfile.txt","w",stdout);

    ios_base::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;
    int a,b,c,dd;
    rep(i,0,n)rep(j,0,m){
        cin>>s[i][j];
        if(s[i][j]=='S')a=i,b=j;
        if(s[i][j]=='T')c=i,dd=j;
    }
    memset(d,-1,sizeof d);
    rep(j,0,4){
        add(a,b,j,0);
    }
    while(!q.empty()){
        cout<< (q.size())<<"\n";
        int a=q.front().x;
        int b=q.front().y;
        int dir=q.front().d;
        int k=q.front().k;
        q.pop();
        rep(j,0,4){
            int nx=a+dx[j];
            int ny=b+dy[j];
            int nd=j;
            int nk=k+(j!=dir);
            if(nk==3||nx<0||ny<0||nx>=n||ny>=m)continue;
            if(s[nx][ny]=='*')continue;
            add(nx,ny,nd,nk);
        }
    }

    bool ok=false;
    rep(j,0,4)rep(k,0,3)ok|=d[c][dd][j][k]!=-1;
    cout<<(ok?"YES":"NO")<<endl;

    return 0;
}