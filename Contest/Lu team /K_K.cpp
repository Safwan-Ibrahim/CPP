// Created on: 2025-04-11 17:07
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    vector<vector<string>>A(8);

    bool j9 = false, t9 = false;
    for (int i = 1; i <= 10; i++) {
        string S;
        getline(cin, S);
        if (i == 1 || i == 10) {
            continue;
        }
        stringstream ssin(S);
        char a, b; 
        ssin >> a >> b;
        string c = string() + a + b;
        if (c == "ti") {
            for (int j = 1; j <= 5; j++) {
                char dum; ssin >> dum;
            }
            string Tmp; 
            while (ssin >> Tmp) {
                if (Tmp.back() == ',') {
                    Tmp.pop_back();
                }
                if (Tmp.back() == '}') {
                    Tmp.pop_back();
                }
                A[1].push_back(Tmp);
            }
        }
        else if (c == "jo") {
            for (int j = 1; j <= 7; j++) {
                char dum; ssin >> dum;
            }
            string Tmp; 
            while(ssin >> Tmp) {
                if (Tmp.back() == ',') {
                    Tmp.pop_back();
                }
                if (Tmp.back() == '}') {
                    Tmp.pop_back();
                }
                A[2].push_back(Tmp);
            }
            
        }
        else if (c == "vo") {
            for (int j = 1; j <= 6; j++) {
                char dum; ssin >> dum;
            }
            string Tmp; 
            ssin >> Tmp;
            if (Tmp.back() == ',') {
                Tmp.pop_back();
            }
            if (Tmp.back() == '}') {
                Tmp.pop_back();
            }
            A[4].push_back(Tmp);
        }
        else if (c == "nu") {
            for (int j = 1; j <= 6; j++) {
                char dum; ssin >> dum;
            }
            string Tmp; 
            ssin >> Tmp;
            if (Tmp.back() == ',') {
                Tmp.pop_back();
            }
            if (Tmp.back() == '}') {
                Tmp.pop_back();
            }
            A[5].push_back(Tmp);
        }
        else if (c == "pa") {
            for (int j = 1; j <= 5; j++) {
                char dum; ssin >> dum;
            }
            string Tmp; 
            ssin >> Tmp;
            if (Tmp.back() == ',') {
                Tmp.pop_back();
            }
            if (Tmp.back() == '}') {
                Tmp.pop_back();
            }
            A[6].push_back(Tmp);
        }
        else if (c == "ye") {
            for (int j = 1; j <= 4; j++) {
                char dum; ssin >> dum;
            }
            string Tmp; 
            ssin >> Tmp;
            if (Tmp.back() == ',') {
                Tmp.pop_back();
            }
            if (Tmp.back() == '}') {
                Tmp.pop_back();
            }
            A[3].push_back(Tmp);
        }
        else if (c == "pu") {
            continue;
        }
        else if (c == "au") {
            for (int j = 1; j <= 6; j++) {
                char dum; ssin >> dum;
            }
            string Tmp; 
            while(ssin >> Tmp) {
                string Tmp2; 
                ssin >> Tmp2;
                string Ans = string() + Tmp[0] + Tmp[1] + ". " + Tmp2[0];
                A[0].push_back(Ans);
            }
        }
    }

    for (int i = 0; i < 7; i++) {
        if (i == 0) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j];
                if (j != A[i].size() - 1) {
                    cout << ", ";
                }
                else {
                    cout << ". ";
                }
            }
        }
        else if (i == 1) {
            for (int j = 0; j < A[i].size(); j++) {
                if (j != A[i].size() - 1) {
                    cout << A[i][j];
                    cout << " ";
                }
                else {
                    cout << A[i][j] << ". ";
                }
            }
        }
        else if (i == 2) {
            for (int j = 0; j < A[i].size(); j++) {
                if (j != A[i].size() - 1) {
                    cout << A[i][j];
                    cout << " ";
                }
                else {
                    cout << A[i][j] << ". ";
                }
            }
        }
        else if (i == 3) {
            cout << A[i][0] << ";";
        }
        else if (i == 4) {
            cout << A[i][0];
        }
        else if(i == 5) {
            cout << "(" << A[i][0] << "):";
        }
        else {
            cout << A[i][0] << ".";
        }
    }
    cout << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n; cin >> n;
        cin.ignore();
        for (int j = 1; j <= n; j++) {
            Try();
        }
    }
    return 0;
} 