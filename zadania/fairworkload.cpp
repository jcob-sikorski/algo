#include <bits/stdc++.h>

using namespace std;

int getMostWork(vector<int> folders, int workers) {
    int lo = *max_element(folders.begin(), folders.end());
    int hi = accumulate(folders.begin(), folders.end(), 0);

    while (lo < hi) {
        int mid = lo + (hi - lo)/2;

        int current_sum = 0;
        int required = 1;
        for (int i = 0; i < folders.size(); i++) {
            if (current_sum + folders[i] <= mid) {
                current_sum += folders[i];
            }
            else {
                current_sum = folders[i];
                required++;
            }
        }
        if (required <= workers) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }

    }
    return lo;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    vector<int> v = {1,1,100};
    int w = 3;

    getMostWork(v, w);

    return 0;
}