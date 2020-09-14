#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> expression;
    vector<string> wynik;
    stack<string> nawias;

    for (int i = 1; i < n; i++) {
        string a;
        cin >> a;
        expression.push_back(a);
    }

    if (expression[0] == "+") {
        wynik.push_back("-(--");
        nawias.push("(");
    }
    else {
        wynik.push_back("-");
    }
    
    for (int i = 1; i < n-1; i++) {
        if (expression[i-1] == "-" && expression[i] == "+") {
            if (nawias.empty() && i+1 < n) {
                wynik.push_back("(");
                nawias.push("(");
            }
        }
        else if (expression[i-1] == "+" && expression[i] == "-") {
            if (!nawias.empty()) {
                wynik.push_back(")");
                nawias.pop();
            }
        }
        wynik.push_back("-");
    }
    if (!nawias.empty()) {
        wynik.push_back(")");
    }

    for (string a: wynik) {
        cout << a;
    }
    cout << endl;
}