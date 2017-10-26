/* |-_-| */
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k ,m;
    cin >> n >> k >> m;

    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a, a+n);

    int b[m];
    memset(b, 0, sizeof(b));

    map<int, vector<int> > res; 
    for(int i = 0;i < n;i++) {
        int md = a[i]%m;
        b[md]++;
        if(res.find(md) == res.end()) {
         vector<int> t;
         t.push_back(a[i]);
         res.insert(make_pair(md, t));
        }    
        else {
         res[md].push_back(a[i]);
        }
    }

    bool can = false;
    for(map<int, vector<int> >::iterator it = res.begin();it != res.end();it++) {
        int md = it->first;
        vector<int> res = it->second;
        // cout << md << " " << b[md] << "\n";
        if(b[md] >= k){
            can = true;
            cout << "Yes\n";
            for(int i = 0;i < res.size() && k;i++, k--) {
                cout << res[i] << " ";
            }
            cout << "\n";
            break;
        }
    }
    if(!can) {
        cout << "No\n";
    }
    return 0;
}
