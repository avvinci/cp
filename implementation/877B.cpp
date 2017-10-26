/* Jatin Goel
	IIIT Allahabad*/
#include <bits/stdc++.h>
using namespace std;
#define  LL long long
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL)
int main()
{
	fast_io;
	if(fopen("input.txt", "r"))
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt","w",stdout);
	}
	string s;
	cin >> s;
	int a[10005]={0};
	int b[10005]={0};
	if(s[0] == 'a')
	{
		a[0] = 1;
	}
	else
	{
		b[0] = 1;
	}
	for(int i=1;i<s.size();i++)
	{
		if(s[i] == 'a')
		{
			a[i] = a[i-1]+1;
			b[i] = b[i-1];
		}
		if(s[i] == 'b')
		{
			a[i] = a[i-1];
			b[i] = b[i-1]+1;
		}
	}
	int ans=-1;
	int n=s.size();
	for(int i=0;i<s.size();i++)
	{
		for(int j=i;j<s.size();j++)
		{
			ans = max(ans,max(a[i],max(b[i],max(b[i]+a[n-1]-a[i],a[i]+b[j]-b[i]+a[n-1]-a[j]))));
		}
	}
	cout << ans << endl;

}
