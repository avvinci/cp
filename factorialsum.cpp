#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<int> sz(100000), ds(100000);

int root(int x){
	while(ds[x]!=x)
		x=ds[x];
	return x;
}
void uniond(int a, int b){
	int roota=root(a);
	int rootb=root(b);
	if(roota==rootb)
		return;
	if(sz[roota]>=sz[rootb]){
		ds[rootb]=roota;
		sz[roota]+=sz[rootb];
	}
	else{
		ds[roota]=rootb;
		sz[rootb]+=sz[roota];
	}

}

int main(){
	if(fopen("input.txt","r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	int m, n;
	cin>>n>>m;
	
	for (int i = 0; i < n; ++i)
	{
		ds[i]=i;
		sz[i]=1;
	}

	while(m--){
		int a, b;
		cin>>a>>b;
		uniond(a,b);
	}
	long long int prod=1;
	for (int i = 0; i < n; ++i)
	{
		if(ds[i]==i)
			prod=(prod*sz[i])%mod;
		//cout<<sz[i]<<" ";
	}
	cout<<prod<<endl;
	return 0;
}