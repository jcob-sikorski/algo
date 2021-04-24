#include<bits/stdc++.h>

using namespace std;

struct s
{
    int counter, pos;
};

unordered_set<char> zbior =  

{
    'a', 'b', 'c','d', 'e', 'f', 'g', 'h', 
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'q', 'r', 's', 't', 'u', 'v', 'w', 
    'x', 'y', 'z', 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
    'L', 'M', 'N', 'O', 'P', 'Q', 'R','S', 'T', 'U', 'V', 'W', 'X', 'Y', 
    'Z'
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    string word;
    unordered_map<string, s> m;

    // powinno przyjmować bez tego
    // CTRL-Z and then ENTER to stop

    int pos = 0;
    while (cin >> word) {
        bool alpha = true;
        for (char i : word) {
            if (zbior.find(i) == zbior.end()) {
                alpha = false;
                break;
            }
        }
        if (alpha) {
            if (m.find(word) == m.end()) {
                m[word].pos = pos;
            }
            m[word].counter++;
            pos++;
        }
    }
    cin.clear();

    word = "";
    int counter = INT32_MIN;
    pos = INT32_MAX;
    for (auto& it: m) {
        if ((it.second.counter == counter && it.second.pos < pos) || it.second.counter > counter) {
            word = it.first;
            counter = it.second.counter;
            pos = it.second.pos;
        }
    }

    // musimy wypisywać słowa! ciągi słów zawierających liczby ignorujemy!
    cout << word << " " << counter;

    return 0;
}