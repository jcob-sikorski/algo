#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void memo(int l, int r, int k, unordered_map<int, pair<int, int>> &range, vector<int> &liczby) {
    range[k] = make_pair(l, r);

    if (k >= 3) {
        if (liczby[l] == 2) {
            memo(l+1, r, k-2, range, liczby);
        }
        else if (liczby[r] == 2) {
            memo(l, r-1, k-2, range, liczby);
        }
        else {
            memo(l+1, r-1, k-2, range, liczby);
        }
    }
    cout << k << "  " << range[k].first << " " <<  range[k].second << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> liczby;

    string y;
    cin >> y;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int x = y[i] == 'T' ? 2 : 1;
        liczby.push_back(x);
        sum += x;
    }

    vector<int> zap;

    int k;

    for (int i = 0; i < m; i++) {
        cin >> k;
        zap.push_back(k);
    }
    unordered_map<int, pair<int, int>> range;

    // memo dla liczb parzystych, znajdz tez dla liczb nieparzystych
    // badz zrozum wzor w ksiazce
    memo(0, liczby.size()-1, sum, range, liczby);

    for (int i = 0; i < m; i++) {
        if ( !(range.find(zap.at(i)) == range.end()) ) {
            cout << range[zap.at(i)].first << " " << range[zap.at(i)].second << endl;
        }
        else {
            cout << "NIE" << endl;
        }
    }
}