// avvinci
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007 
#define MOD 1000000007
#define all(container) container.begin(),container.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define pb push_back
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define mk make_pair
#define present(container,x) ((container).find(x) != (container).end())
#define inf 3234567891
//#define infl LLONG_MAX
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 123456
const long long infl = 1e12+5;

ll m,n,pp,q,x,y ,cn,k,tmp1,tmp,mx =0 ,mn,f,val,sz,sm,cnt,aans,t=1,i,j,ind,ci;

ll a,b,c;
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>a>>b>>c;
if(a == b && b== c)
    f=3;
else if(b-a  == c- b)
    f=1;
else if( b== sqrt(a*c) && b!=0 )
    f =2;
if(f == 0){
    cout<<"None";
}
else if(f == 1){
     cout<<"AP";
}
else if(f==2){
     cout<<"GP";
}
else
 cout<<"Both";
return 0 ;



}