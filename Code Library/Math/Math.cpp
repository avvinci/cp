#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const ll MOD = 1E9 + 7;

// from dreamoon
template<int MOD>
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(int _x) {
        x = _x % MOD;
        if (x < 0) x += MOD;
    }
    ModInt(long long _x) {
        x = _x % MOD;
        if (x < 0) x += MOD;
    }
    ModInt& operator+=(ModInt rhs) {
        x += rhs.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        x -= rhs.x;
        if (x < 0) x += MOD;
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (long long)x * rhs.x % MOD;
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        return *this *= rhs.inv();
    }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    ModInt inv() const {
        // should work for non-prime MOD if gcd(x, MOD) = 1
        int a = x, b = MOD, u = 1, v = 0;
        while (b != 0) {
            int t = a / b;
            a -= t * b;
            u -= t * v;
            swap(a, b);
            swap(u, v);
        }
        return u;
    }
    ModInt pow(long long e) {
        ModInt r = 1, p = *this;
        while (e) {
            if (e & 1) r *= p;
            p *= p;
            e >>= 1;
        }
        return r;
    }
    bool operator==(ModInt rhs) { return x == rhs.x; }
    bool operator!=(ModInt rhs) { return x != rhs.x; }
    bool operator<(ModInt rhs) { return x < rhs.x; }
    bool operator<=(ModInt rhs) { return x <= rhs.x; }
    bool operator>(ModInt rhs) { return x > rhs.x; }
    bool operator>=(ModInt rhs) { return x >= rhs.x; }
    friend ostream& operator<<(ostream &os, ModInt i) { return os << i.x; }
};

vi dec2base10(ll n, ll base) {
    vi digits;
    if(n == 0) 
        digits.pb(0);
    while(n) {
        digits.pb(n % base);
        n /= base;
    }
    reverse(ALL(digits));
    return digits;
}

ll modpow(ll x, ll e, ll m) {
    vi exp = dec2base10(e, 2);
    ll res = 1;
    for(int i = SZ(exp) - 1; i >= 0; i--) {
        if(exp[i] == 1) {
            res *= x;
            res %= m;
        }
        x = (x * x) % m;
    }
    return res;
}

// Tested on InterviewBit: https://www.interviewbit.com/problems/modular-expression/
int ModPow(int A, int B, int C) {
    if(B == 0) {
        return 1 % C;
    }
    if(B % 2 == 0) {
        long long ret = ModPow(A, B/2, C);
        return (ret * ret + C) % C;
    } else {
        B--;
        long long ret = ModPow(A, B/2, C);
        return ((ret * ret + C) % C * A + C) % C;
    }
}

template <typename T>
T modpow(T x, T exp, T mod) {
    x %= mod;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * x) % mod;
        x = (x * x) % mod;
        exp >>= 1;
    }
    return result;
}

ll prime_mod_inverse(ll x) {
    return modpow(x, M - 2, M); // from Euler's 
}

// mod with a prime number
int ncr_prime_mod(int n, int r) {
    int deno = (prime_mod_inverse(fact[n - r]) * prime_mod_inverse(fact[r])) % M;
    return (fact[n] * deno) % M;
}

vb primes(1E7 + 10, true);
void sieve(int n) {
    primes[0] = false;
    primes[1] = false;
    for (int p = 2; p*p <= n; p++) {
        if (primes[p] == true) {
            for (int i = p * 2; i <= n; i += p)
                primes[i] = false;
        }
    }
}

ll gcd(ll a, ll b) {
    while(a % b) {
        ll c = a % b;
        a = b, b = c;
    }
    return b;
}

// lcm(a, b, c) = lcm(a, lcm(b, c))
ll lcmv(vector<ll> a) {
    ll l = a[0];
    for(int i = 1; i < (int)a.size(); i++) {
        l = lcm(l, a[i]);
    }
    return l;
}

ll lcm(ll a, ll b) {
    return (a * b)/ __gcd(a, b);
}
// O(sqrt(n))
vi divisors(int n) {
    vi v;
    int high = sqrt(n) + 1;
    for(int i = 1; i <= high ; i++) {
        if(n % i == 0) {
            int a = i, b = n/i;
            if(a == b) v.pb(a);
            else {
                v.pb(a);
                v.pb(b);
            }
        }
    }
    return v;
}

inline vi prime_factors(int n) {
    vi primes;
    if(n % 2 == 0)
        primes.pb(2);
    while (n%2 == 0) {
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2) {
    	if(n % i == 0)
    		primes.pb(i);
    	while (n%i == 0) {
            n = n/i;
        }
    }
    if (n > 2)
        primes.pb(n);
    return primes;
}

vi fact(1234567, 0);
ll fact_mod(ll n) {
    if (fact[n] != 0)
        return fact[n];
    if (n == 0) {
        fact[n] = 1;
        return 1;
    }
    fact[n] = ((n % M) * (fact_mod(n - 1) % M)) % M;
    return fact[n];
}

int str2dec(string s) {
    int ret = 0;
    REV(s);
    int n = s.size();
    int ten = 1;
    for(int i = 0; i < n; i++) {
        int k = s[i] - '0';
        ret += k * ten;
        ten *= 10;
    }
    return ret;
}

int str2base(string s, int base) {
    int ret = 0;
    REV(s);
    int n = s.size();
    int fac = 1;
    for(int i = 0; i < n; i++) {
        int k = s[i] - '0';
        ret += k * fac;
        ten *= base;
    }
    return ret;
}

int main() {
	
	return 0;
}
