#include <bits/stdc++.h>

using namespace std;



bool conComp(int i, vector<bool> &visited, unordered_map<int, vector<int>> &graph, vector<int> &id, int &zero, int &one) {
    visited[i] = true;
    for (int j : graph[i]) {
        if (j == 0) {
            id[i] = j;
            zero++;
        }
        else if (j == 1) {
            id[i] = j;
            one++;
        }
        if (id[i] == 0 && id[j] == 1 || id[i] == 1 && id[j] == 0) {
            return true;
        }
        if (!visited[j]) {
            cout << j << " ";
            conComp(j, visited, graph, id, zero, one);
        }
    }
    return false;
}


int helper(vector<bool> &visited, unordered_map<int, vector<int>> &graph, vector<int> &id) {
    int wynik = 0;
    int zero = 0;
    int one = 0;
    for (auto i : graph) {
        if (!visited[i.first]) {
            if (conComp(i.first, visited, graph, id, zero, one)) {
                return 0;
            };
            cout << endl;
            wynik++;
        }
    }
    if (zero > 0) {
        wynik--;
    }
    if (one > 0) {
        wynik--;
    }
    return wynik;
}


int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    int x; // liczba równań
    int k; // liczba zmiennych
    cin >> x;
    cin >> k;

    // assign length to letter by alphabet order
    // unordered_map<char, int> varLen;
    // int len;
    // for (int i = 0; i < k; i++) {
    //     cin >> len;
    //     varLen[alphabet[i]] = len;
    // }

    unordered_map<char, vector<int>> convert;

    int len;
    int counter = 2;
    for (int i = 0; i < k; i++) {
        cin >> len;
        for (int j = 0; j < len; j++) {
            convert[alphabet[i]].push_back(counter);
            counter++;
        }
    }

    for (int i = 0; i < x; i++) {
        int l;
        cin >> l;

        string L;
        cin >> L;

        vector<int> copl;

        for (int j = 0; j < l; j++) {
            if (isalpha(L[j])) {
                for (int m : convert[L[j]]) { // indeks w zmiennej
                    copl.push_back(m);
                }
            }
            else {
                copl.push_back(L[j]-'0');
            }
        }

        int r;
        cin >> r;

        string R;
        cin >> R;

        vector<int> copr;

        for (int j = 0; j < r; j++) {
            if (isalpha(R[j])) {
                for (int m : convert[R[j]]) { // indeks w zmiennej
                    copr.push_back(m);
                }
            } 
            else {
                copr.push_back(R[j]-'0');
            }
        }
        if (copl.size() != copr.size()) {
            continue;
        }
        else {
            unordered_map<int, vector<int>> graph; // graf
            vector<bool> visited; visited.resize(counter+1);
            vector<int> id; id.resize(counter+1);

            for (int i = 0; i < id.size(); i++) {
                id[i] = i;
            }

            for (int j = 0; j < copl.size(); j++) {
                graph[copl[j]].push_back(copr[j]);
                graph[copr[j]].push_back(copl[j]);
            }
            int wynik = helper(visited, graph, id);
            wynik = (int) pow(2, wynik);
            cout << endl;
        }
    }
}