#include<bits/stdc++.h>
using namespace std;

double func(double x) {
	return 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6;
}

int main() {
	int t; cin >> t;

	while(t--) {
		double Y;
		cin >> Y;
		if (Y < (func(0)) || Y > (func(100))) {
			cout << "No solution!\n";
			continue;
		}

		double l = 0, r = 100;
    int iterations = 60;
		while (iterations--) {
			double mid = (l + r) / 2;
			if (func(mid) >= Y) {
				r = mid;
			} else {
				l = mid;
      }
		}
		cout << fixed << setprecision(4) << l << "\n";
	}

	return 0;
}