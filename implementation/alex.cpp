#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "b";

const int NMAX = 100100;
int n, a[NMAX], ans[NMAX], prev[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);

	forn(i, NMAX)
		prev[i] = -1;
	int answer = 0;
	forn(i, n)
	{
		ans[i] = 1;
		for (int d = 2; d * d <= a[i]; ++d)
			if (a[i] % d == 0)
			{
				if (prev[d] >= 0) ans[i] = max(ans[i], ans[prev[d]] + 1);
				if (prev[a[i] / d] >= 0) ans[i] = max(ans[i], ans[prev[a[i] / d]] + 1);
				prev[d] = prev[a[i] / d] = i;
			}
		if (prev[a[i]] >= 0) ans[i] = max(ans[i], ans[prev[a[i]]] + 1);
		prev[a[i]] = i;
		answer = max(answer, ans[i]);
	}
	cout << answer << endl;

	return 0;
}