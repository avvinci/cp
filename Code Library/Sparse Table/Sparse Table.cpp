#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)x.size()
#define what_is(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef vector<ll> vi; typedef vector<vi> vvi;
class RMQ { // Range Minimum Query
private:
	int n;
	vi A; // copy of the input array
	vvi SpT; // SpT[i][j] stores the index of the minimum element starting 
	// at index i and ending at index i + 2^j - 1
public:
	RMQ(vi& a) {
		n = a.size();
		A.resize(n);
		int max_log2 = floor(log((double)n)/log(2.0)) + 1;
		SpT.assign(n, vi(max_log2));
		for (int i = 0; i < n; i++) {
			A[i] = a[i];
			SpT[i][0] = i; // RMQ of sub array starting at index i and length 2^0
		}
		for (int j = 1; (1 << j) <= n; j++) {// for each j s.t. 2^j <= n, O(log n)
			for (int i = 0; i + (1 << j) - 1 < n; i++) {// for each valid i, O(n)
				// RMQ: from two overlapping ranges whose union covers the interval [i, i + 2^j - 1]
				if (A[SpT[i][j - 1]] < A[SpT[i + (1 << (j - 1))][j - 1]]) 
					SpT[i][j] = SpT[i][j - 1]; // start at index i of length 2 ^ (j - 1)
				else // start at index i + 2 ^ (j - 1) of length 2 ^ (j - 1)
					SpT[i][j] = SpT[i + (1 << (j - 1))][j-1];
			}
		}
	}

	int query(int i, int j) {
		int k = (int)floor(log((double)j - i + 1) / log(2.0)); // 2^k <= (j-i+1)
		// RMQ: from two overlapping ranges R1, R2 whose union covers the interval [i, j]
		// R1 = the first 2^k elements, R2 = the last 2^k elements
		if (A[SpT[i][k]] <= A[SpT[j - (1 << k) + 1][k]]) 
			return SpT[i][k];
		else 
			return SpT[j - (1 << k) + 1][k];
	} 
};

int main() {
	vi a = {1, 5, 4, 3, 3, 2, 8, 9, 2};	
	RMQ rmq(a);
	what_is(a[rmq.query(0, 0)]);
	what_is(a[rmq.query(0, 5)]);
	what_is(a[rmq.query(1, 3)]);
	what_is(a[rmq.query(2, 8)]);
	what_is(a[rmq.query(0, 8)]);
	return 0;
}
