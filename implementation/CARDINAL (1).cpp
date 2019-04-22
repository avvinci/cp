#include <iostream>
#include <cassert>
#include <set>

using namespace std;

typedef long long ll;
#define FOR(i,n) for(int i=0;i<(n);i++)

ll A[128];
ll S[1024], C[1024];

void adjust(int idx, int su, int ca) {
	if (S[idx] < su) {
		S[idx] = su;
		C[idx] = ca;
	} else if (S[idx] == su && C[idx] < ca) {
		C[idx] = ca;
	}
}

int main() {
	int N;
	int te = 0;
	while(cin >> N) {
		assert(N >= 1 && N <= 100);
		set<int> T;
		FOR(i,N) {
			cin >> A[i];
			assert(A[i] >= 1 && A[i] <= 1000000000);
			assert(T.find(A[i]) == T.end());
			T.insert(A[i]);
		}
		FOR(i,1024) {
			S[i] = 0;
			C[i] = 0;
		}
		FOR(i,N) {
			int nm = 0, _t = A[i];
			while(_t) {
				nm |= (1<<(_t%10));
				_t /= 10;
			}
			adjust(nm,A[i],1);
			int rm = (1<<10) - 1 - nm;
			for (int bm = rm; bm; bm = (rm & (bm - 1))) {
				adjust(bm+nm,S[bm]+A[i],C[bm]+1);
			}
		}
		int mas = 0, mac = 0;
		FOR(i,1024) {
			if (S[i] > mas) {
				mas = S[i];
				mac = C[i];
			} else if (S[i] == mas && C[i] > mac) {
				mac = C[i];
			}
		}
		cout << mac << endl;
		te++;
	}
	assert(te <= 100);
	return 0;
}
