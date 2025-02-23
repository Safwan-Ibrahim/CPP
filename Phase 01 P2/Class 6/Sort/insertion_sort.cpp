// Created on: 2025-02-13 17:42
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// insertion sort : eveytime next value k thik jaygay insert koro

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
	int n;
	cin >> n;
	int A[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	for (int i = 2; i <= n; i++) {
		int key = A[i];
		int j = i - 1;
		while (j >= 1 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}

	for (int i = 1; i <= n; i++) {
		cout << A[i] << ' ';
	}
    
    return 0;
} 