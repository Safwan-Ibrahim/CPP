#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int GCD(int a, int b) {
    if (b > a) swap(a, b);
    if (b == 0 || a == 0) {
        return max(a, b);
    }
    return GCD(a % b, b);
    //return GCD(a - (a - 1) / b * b, b); 
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i <= 1355; i++) {
        for (int j = i; j <= 1595; j++) {
            assert(__gcd(i, j) == GCD(i, j));
        }
    }
    
    
    return 0;
} 