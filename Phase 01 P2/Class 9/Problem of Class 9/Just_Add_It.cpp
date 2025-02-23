#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 10000007;

int power(int x, int n, int m = M) {
    int ans = 1 % m;
    while(n) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        x = 1LL * x * x % m;
        n >>= 1;
    }
    return ans;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; 
    while(cin >> n) {
        cin >> k;
        if (k + n == 0) {
            break;
        }
        int a = power(n, k), b = power(n, n), c = 2 * power(n - 1, k), d = 2 * power(n - 1, n - 1);
        //cout << (((power(n, k) + power(n, n)) % M + 2 * power(n - 1, k)) % M + 2 * power(n - 1, n - 1)) % M << endl; 
        cout << ((((a + b) % M ) + c ) % M + d) % M << endl;
    }
    
    return 0;
} 