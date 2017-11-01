#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

// 3 modes of fenwick tree:-
// point update - range query
// range update - point query
// range update - range query -> needs two fenwick tree
// Please note that it should be 1-based. It can't be done 0-based.
#define last_one(S) (S & (-S))
class fenwick_tree {
private:
  vi ft;
public:
  fenwick_tree() {}
  fenwick_tree(int n) { 
    ft.assign(n + 1, 0);
  }
  ll sum_first(int b) {
    ll sum = 0; 
    for (; b != 0; b -= last_one(b)) 
      sum += ft[b];
    return sum; 
  }
  ll sum_between(int a, int b) {
    return sum_first(b) - (a == 1 ? 0 : sum_first(a - 1)); 
  }
  void update(int k, int v) {
    for (; k < SZ(ft); k += last_one(k)) 
      ft[k] += v; 
  }
};

int main() {              // idx   0 1 2 3 4 5 6 7  8 9 10, no index 0!
  FenwickTree ft(10);     // ft = {-,0,0,0,0,0,0,0, 0,0,0}
  ft.adjust(2, 1);        // ft = {-,0,1,0,1,0,0,0, 1,0,0}, idx 2,4,8 => +1
  ft.adjust(4, 1);        // ft = {-,0,1,0,2,0,0,0, 2,0,0}, idx 4,8 => +1
  ft.adjust(5, 2);        // ft = {-,0,1,0,2,2,2,0, 4,0,0}, idx 5,6,8 => +2
  ft.adjust(6, 3);        // ft = {-,0,1,0,2,2,5,0, 7,0,0}, idx 6,8 => +3
  ft.adjust(7, 2);        // ft = {-,0,1,0,2,2,5,2, 9,0,0}, idx 7,8 => +2
  ft.adjust(8, 1);        // ft = {-,0,1,0,2,2,5,2,10,0,0}, idx 8 => +1
  ft.adjust(9, 1);        // ft = {-,0,1,0,2,2,5,2,10,1,1}, idx 9,10 => +1
  printf("%d\n", ft.rsq(1, 1));  // 0 => ft[1] = 0
  printf("%d\n", ft.rsq(1, 2));  // 1 => ft[2] = 1
  printf("%d\n", ft.rsq(1, 6));  // 7 => ft[6] + ft[4] = 5 + 2 = 7
  printf("%d\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
  printf("%d\n", ft.rsq(3, 6));  // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1

  ft.adjust(5, 2); // update demo
  printf("%d\n", ft.rsq(1, 10)); // now 13
} // return 0;

// 2D fenwick trees
const int N = 2505;
pair<ull, ull> s[N][N];

void add(int r1, int c1, pair<ull, ull> val) {
  for (int i = r1; i < N; i += i & (-i)) {
    for (int j = c1; j < N; j += j & (-j)) {
      s[i][j].F += val.F;
      s[i][j].S += val.S;
    }
  }
}

pair<ull, ull> query(int r1, int c1) {
  pair<ull, ull> res = mp(0, 0);
  for (int i = r1; i >= 0; i -= i & (-i)) {
    for (int j = c1; j >= 0; j -= j & (-j)) {
      res.F += s[i][j].F;
      res.S += s[i][j].S;
    }
  }
  return res;
}