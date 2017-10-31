#include <bits/stdc++.h>
using namespace std;

bool next_permutation(vector<int> &s) {
    int n = s.size();
    bool ok = false;
    for(int i = n - 1; i > 0; i--) {
        if(s[i - 1] < s[i]) {
            ok = true;
        }
    }
    if(!ok) {
        reverse(s.begin(), s.end());
        return false;
    }

    for(int i = n - 1; i > 0; i--) {
        if(s[i - 1] < s[i]) {
            int to_swap = i - 1, j;
            reverse(s.begin() + to_swap + 1, s.end());
            auto it = upper_bound(s.begin() + to_swap + 1, s.end(), s[to_swap]);
            int min_greater = it - s.begin();
            swap(s[to_swap], s[min_greater]);
            break;
        }
    }
    return true;
}

bool next_permutation(string &s) {
    int n = s.size();
    bool ok = false;
    for(int i = n - 1; i > 0; i--) {
        if(s[i - 1] < s[i]) {
            ok = true;
        }
    }
    if(!ok) return false;

    for(int i = n - 1; i > 0; i--) {
        if(s[i - 1] < s[i]) {
            int to_swap = i - 1, j;
            for(j = i; j < n; j++) {
                if(s[j] <= s[to_swap]) {
                    break;
                }
            }
            int min_greater = j - 1;
            swap(s[to_swap], s[min_greater]);
            sort(s.begin() + to_swap + 1, s.end());
            break;
        }
    }
    return true;
}

bool next_permutation_optimized(string &s) {
    int n = s.size();
    bool ok = false;
    for(int i = n - 1; i > 0; i--) {
        if(s[i - 1] < s[i]) {
            ok = true;
        }
    }
    if(!ok) return false;

    for(int i = n - 1; i > 0; i--) {
        if(s[i - 1] < s[i]) {
            int to_swap = i - 1, j;
            reverse(s.begin() + to_swap + 1, s.end());
            auto it = lower_bound(s.begin() + to_swap + 1, s.end(), s[to_swap]);
            int min_greater = it - s.begin();
            swap(s[to_swap], s[min_greater]);
            break;
        }
    }
    return true;
}

int main() {
    string s = "134652";
    next_permutation_optimized(s);
    cout << s << endl;
    return 0;
}