
   Author Tara Prasad
   Problem 453B
 
#include bitsstdc++.h
#define DEBUG
#ifdef DEBUG
  #include printcpp11.h 
#endif
using namespace std;

#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define REV_ALL(x) x.rbegin(), x.rend()
#define SZ(x) (int)x.size()
#define CONTAINS(cont, val) (cont.find(val) != cont.end())
#define endl 'n'
#define what_is(x) cout  #x   =   x  endl
#define IO_SPEED_UP iossync_with_stdio(false);cin.tie(NULL)
#define FOR(i, st, ed, inc) for(ll i = st; i  ed; i += inc)
#define leftmost_set(x) __builtin_clzll(x)

typedef long long ll;typedef pairll, ll ii;
typedef vectorll vi;typedef vectorbool vb;
typedef vectorii vii;typedef vectorvi vvi;

const ll PINF = 1E9;
const ll NINF = -1E9;
const ll M = 1E9 + 7;
const double EPS = 1E-9;
const int N = 100;
 
int dp[101][1  20]; 

vi a, factor(60); 
int n;

int rec(int cur, int mask) {
  if(cur  n) return 0;
  int &ret = dp[cur][mask];
  if(ret != -1) return ret;

  ret = PINF;
   the b[cur] has 59 choices
  for(int i = 1; i  60; i++) {
    if((factor[i] & mask) == 0) {  if none of the factors are used
      int v = rec(cur + 1, mask  factor[i]) + abs(a[cur] - i);  cost if i is assigned to cur
      if(v  ret) {
        ret = v;
        choice[cur][mask] = i;
      }
    }
  }
  return ret;
}

int main() {
  IO_SPEED_UP;
#ifdef DEBUG
  freopen(input.txt, r, stdin);
  freopen(output.txt, w, stdout);
#endif
  for(int i = 1; i  60; i++) {  any number can be assigned
    factor[i] = 0;  factor[i] is a mask indicating all the indices of prime factors of i 
     if primes[k] is a factor of i, then the kth bit is on in factor[i]
    for(int j = 0; j  16; j++)
      if(i % primes[j] == 0)
        factor[i] = (1  j);
  }
  cin  n; a.resize(n + 1);
  for(int i = 1; i = n; i++) {
    cin  a[i];
  }
  memset(dp, -1, sizeof(dp));
  int min_cost = rec(1, 0);  not asked in question

   choice[1][0] should be set to some index by now 
  int mask = 0;
  for(int i = 1; i = n; i++) {
    cout  choice[i][mask]   ; 
    mask = factor[choice[i][mask]];  mark the primes used
  }
  return 0;
}
