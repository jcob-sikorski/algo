#include <bits/stdc++.h>


using namespace std;



void conComp(int i, vector<bool> &visited, unordered_map<int, vector<int>> &g) {
    for (int j : g[i]) {
        if (!visited[j]) {
            visited[j] = true;
            conComp(j, visited, g);
        }
    }
}


int helper(vector<bool> &visited, unordered_map<int, vector<int>> &g) {
    int wynik = 0;
    for (auto i : g) {
        if (!visited[i.first]) {
            conComp(i.first, visited, g);
            wynik++;
        }
    }
    return wynik;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    int x; // liczba równań
    int k; // liczba zmiennych
    cin >> x;
    cin >> k;

    // unordered_map<char, int> alphaOrder; // indeks każdej z liter alfabetu
    // for (int i = 0; i < k; i++) {
    //     alphaOrder[alphabet[i]] = i;
    // }

    // string alphabet 
    unordered_map<char, int> varLen;
    int len;
    for (int i = 0; i < k; i++) {
        cin >> len;
        varLen[alphabet[i]] = len;
    }

    // int counter = 0;
    // unordered_map<string, int> bijection; // przypisujemy wartość każdemu typowi komórki
    // for (int i = 0; i < varLen.size(); i++) {
    //     for (int j = 0; j < varLen[i]; j++) {
    //         bijection[alphabet[i] + to_string(j)] = counter;
    //         counter++;
    //     }
    // }

    unordered_map<int, vector<int>> g; // graf
    unordered_map<string, bool> visited;

    for (int i = 0; i < x; i++) {
        int l;
        cin >> l;
        string L;
        cin >> L;

        int r;
        cin >> r;
        string R;
        cin >> R;

        int lLen = 0; // rzeczywista długość lewej strony równania
        for (int j = 0; j < L.size(); j++) {
            if (isalpha(L[j])) {
                for (int m = 0; m < varLen[L[j]]; m++) { // indeks w zmiennej
                    
                    lLen++;
                }
            } 
            else {
                lLen++;
            }
        }

        helper(visited, g);
    }
    int wynik = 1;
    wynik <<= uf.components(); // wynikiem jest 2 do liczby grup

    cout << wynik << endl;
    cout << endl;
}