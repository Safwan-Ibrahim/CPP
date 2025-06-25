#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 9;
bool gone[nn];

void prec() {
    vector<int>primes;
    for (int i = 2; i * i < nn; i++) {
        if (!gone[i]) {
            for (int j = i * i; j < nn; j += i) {
                gone[j] = true;
            }
        }
    }

    for (int i = 2; i < nn; i++) {
        if (!gone[i]) {
            primes.push_back(i);
        }
    }
}
 
int32_t main() {   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int>primes;
    for (int i = 2; i * i < nn; i++) {
        if (!gone[i]) {
            for (int j = i * i; j < nn; j += i) {
                gone[j] = true;
            }
        }
    }

    for (int i = 2; i < nn; i++) {
        if (!gone[i]) {
            primes.push_back(i);
        }
    }

    cout << primes.size() << endl;
    return 0;
} 