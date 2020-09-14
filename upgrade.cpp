#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    // pierwszy pominąć
    int counter = 1;

    unordered_map<int, bool> exists;
    vector<int> arr;
    int d, w;
    cin >> d >> w;
    arr.push_back(w);
    exists[w] = true;

    for (int i = 1; i < n; i++) {
        cin >> d >> w;
        arr.push_back(w);

        // if not exists
        if (exists.find(w) == exists.end()) {
            counter++;
            exists[w] = true;
        }
        else {
            int curr = INT32_MAX;
            int j = arr.size()-2;
            while (curr != w && curr > w && (0 < j && j < arr.size())) {
                curr = arr[j];
                j--;
            }
            if (curr != w) {
                counter++;
            }
        }
    }

    cout << counter << endl;
}