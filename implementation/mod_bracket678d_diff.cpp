#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long power(long long N, long long expo)
{
    long long ans = 1;
    
    N = N%MOD;
    
    while(expo)
    {
        if(expo%2)
            ans = ans*N%MOD;
        
        N = N*N%MOD;
        expo/= 2;
    }
    
    return ans;
}

int main()
{
    if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
    long long A, B, N, X;
    cin >> A >> B >> N >> X;
    
    long long x = power(A, N);
    long long y = power(A-1, MOD-2);
    
    if(A==1)
    {
        long long ans = x*X%MOD + B*(N%MOD)%MOD;
        
        cout << (ans%MOD) << endl;
        return 0;
    }
    
    long long ans = x*X%MOD + B*((x-1+MOD)%MOD)%MOD*y%MOD;
    
    cout << ans%MOD << endl;
    
	return 0;
}