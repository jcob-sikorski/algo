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
    unordered_map<int, vector<int>> g;

    vector<bool> visited; visited.resize(12);

    g[0] = {1};
    g[1] = {0};


    g[2] = {3};
    g[3] = {2, 4};
    g[4] = {3};


    g[5] = {6, 7};
    g[6] = {5};
    g[7] = {5};


    g[8] = {9};
    g[9] = {8};


    g[10] = {11};
    g[11] = {10};

    int w = helper(visited, g);
    cout << w << endl;
}