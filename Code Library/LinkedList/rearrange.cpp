#include <bits/stdc++.h>
using namespace std;
const int epsilon = 1E-12;
const int INF = 1000000000;
//#define DEBUG

int main() {
  std::ios::sync_with_stdio(false);
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while(t--) {
      int n; cin >> n;
      list<char> l;
      set<int> s;
      for(int i = 0; i < n; i++) {
          char data; cin >> data;
          if(s.find(data) == s.end()) {
              l.push_back(data);
              s.insert(data);
          } else {
              l.remove(data);
              s.erase(data);
          }
          what_is(l);
          what_is(s);
          if(l.size() == 0) cout << "-1 ";
          else cout << *l.begin() << " ";
      }
      cout << endl;
  }
  return 0;
}
