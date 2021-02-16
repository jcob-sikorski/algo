#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int limit, n;

    cin >> limit;
    cin >> n;
    
    deque<int> v;
    int w;
    for (int i = 0; i < n; i++) {
        cin >> w;
        v.push_back(w);
    }

    sort(v.begin(), v.end());

    int wynik = 0;

    while(!v.empty()) {
        int front = v.front();
        int back = v.back();
        if (v.size() >= 2 && v.front() + v.back() <= limit) {
            v.pop_back(); v.pop_front();
        }
        else {
            v.pop_back();
        }
        wynik++;
    }
    cout << wynik << endl;
}