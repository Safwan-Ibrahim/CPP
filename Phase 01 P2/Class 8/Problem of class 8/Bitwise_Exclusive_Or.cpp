#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void toogle_bit(int &x, int k) {
    x = x ^ (1 << k);
}

bool is_set(int x, int k) {
    return (x >> k) & 1;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b; cin >> a >> b;

    for (int i = 0; i <= 7; i++) {
        if (is_set(b,i)) {
            toogle_bit(a,i);
        }
    }

    cout << a << endl;

    return 0;
} 