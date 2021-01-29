#include<bits/stdc++.h>

using namespace std;

void pom(stack<int> &sta, stack<int> &cop, int &wynik) {
    bool cleared = true;

    int x1, y1, x2, y2;

    if (sta.size() >= 4) {
        x1 = sta.top(); cop.push(sta.top()); sta.pop();
        y1 = sta.top(); cop.push(sta.top()); sta.pop();
        x2 = sta.top(); cop.push(sta.top()); sta.pop();
        y2 = sta.top(); cop.push(sta.top()); sta.pop();

        cleared = false;
    }

    // 5 2 3 1 4 1 4 3 5 2

    // sta  
    // cop  2 5


    while (!sta.empty()) {
        if (cop.top() != sta.top()) {
            if (cleared && sta.size() >= 2) {
                int wait = cop.top(); cop.pop();

                x1 = cop.top(); y1 = wait; cop.push(wait);

                x2 = sta.top(); cop.push(sta.top()); sta.pop();
                y2 = sta.top(); cop.push(sta.top());

                cleared = false;
            }
            else {
                x1 = y1; y1 = x2; x2 = y2;
                y2 = sta.top(); cop.push(sta.top());
            }

            if (!cleared) { // jeśli możemy już sprawdzić czy zachodzi inwersja
                if (x1 == x2 && y1 == y2) {
                    wynik++;
                    cleared = true;

                    for (int i = 0; i < 4; i++) {
                        cop.pop();
                    }
                }
            }
        }
        else {
            cop.pop();
        }
        sta.pop();
    }
}


int main() {
    vector<int> arr = {5, 2, 3, 1, 4, 1, 4, 3, 5, 2};

    stack<int> sta;

    for (int i = 0; i < arr.size(); i++) {
        sta.push(arr[i]);
    }

    stack<int> cop;

    int wynik = 0;

    pom(sta, cop, wynik);

    cout << wynik << endl;
}