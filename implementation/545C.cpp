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
	int n;
	cin >> n;
	pair <LL,LL> tree[100005];

	for(int i=0;i<n;i++)
	{
		cin >> tree[i].first >> tree[i].second ;
	}
	tree[n].first = 1e10;
	tree[n].second = 0;
	int idx = tree[0].first - tree[0].second;
	int ans = 1;
	for(int i=1;i<n;i++)
	{
		if(tree[i].first - tree[i].second > idx && tree[i].first - tree[i].second > tree[i-1].first )
		{
			idx = tree[i].first - tree[i].second;
			ans++;
		}
		else if(tree[i].first + tree[i].second < tree[i+1].first)
		{
			idx = tree[i].first + tree[i].second;
			ans++;
		}
		//cout << idx << endl;
	}
	cout << ans << endl;
}
