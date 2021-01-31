#include <bits/stdc++.h>

using namespace std;


constexpr string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main() {
    int x; // liczba równań
    int k; // liczba zmiennych
    cin >> x;
    cin >> k;

    // string alphabet 
    vector<int> varLen;
    int len;
    for (int i = 0; i < k; i++) {
        cin >> len;
        varLen.push_back(l);
    }

    int counter = 0;
    unordered_map<string, int> bijection; // assign strigns(whatever) to random numbers
    for (int i = 0; i < varLen.size(); i++) {
        for (int j = 0; j < varLen[i]; j++) {
            bijection[alphabet[i] + to_string(j)] = counter;
            counter++;
        }
    }

    unordered_map<int, vector<int>> g;

    int l;
    cin >> l;
    string L;
    cin >> L;

    int r;
    cin >> r;
    string R;
    cin >> R;

    for (int i = 0; i < L.size(); i++) {
        if (isalpha(L[i])) {
            
        }
    }

    // https://www.youtube.com/watch?v=0jNmHPfA_yE&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=21
    // czas: 2:11
    // skończyłem na "trzeci wiersz opisu zawiera (...)"
}