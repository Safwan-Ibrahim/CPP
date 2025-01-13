#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void prime_factor(int n) {
    for (int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) {
        cout << n;
    }
    cout << endl;
}

int32_t main() {   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x; cin >> x;
    prime_factor(x);
    
    return 0;
} 