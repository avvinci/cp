// avvinci - sem_7 
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
#define sz(x)  (ll)x.size()
#define N 1000004

const long long infl = 1e7+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans ;
ll a[N],bx,by,bz,mx,my,mz,vx,vy,vz,ux,uy,uz ;
double fn ( double t  ){
    double v1  =  bx + vx * t  - ( mx + ux * t )  ; 
    double v2 =  by + vy * t - (my + uy * t); 
    double v3  = bz + vz * t - (mz + uz *t ) ; 
    return sqrt(v1 * v1 + v2 * v2 + v3 * v3 ) ; 
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
cin>>bx>>by>>bz ; 
cin>>vx>>vy>>vz ; 
cin>>mx>>my>>mz; 
cin>>ux>>uy>>uz ; 
double ans = infl ; 

double l =  0 , r = t ,v1,v2;
 
for(int i=0; i<200; i++) {
  double l1 = (l*2+r)/3.0;
  double l2 = (l+2*r)/3.0;
  v1 = fn(l1) ; v2 = fn(l2) ; 
  if(v1 > v2) l = l1; else r = l2;
  ans = min(ans ,min(v1 ,v2) ) ; 
  }
// double re = sqrt(ans) ; 
cout<<fixed<<setprecision(7)<<ans; 




return 0 ;
}