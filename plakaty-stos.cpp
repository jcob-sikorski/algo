// for each range set min_h

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    //int max_h = 0;
    int counter = 1;

    vector<int> bud;
    //vector<int> range;

    int d, w;
    int min_h = INT32_MAX;
    //int max_h = 0;

    for (int i = 0; i < n; i++) {
        cin >> d >> w;
        bud.push_back(w);
        min_h = min_h > w ? w : min_h;
        //max_h = max_h < w ? w : max_h;
        //range.push_back(max_h);
    }

    int curr = bud[0];
    for (int i = 1; i < n; i++) {
        //if (bud[i] <= range[i] && bud[i] != curr && bud[i] > min_h) {
        if (bud[i] != curr && bud[i] > min_h) {
            counter++;
            curr = bud[i];
        }
    }

    cout << counter << endl;
}