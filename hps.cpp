#include<bits/stdc++.h>

using namespace std;

string cnt(string &seq, const char* lett) {
    string occur = "";
    for (auto i : seq) {
        if (i == *lett) {
            occur += lett;
        }
        else {
            occur += " ";
        }
    }
    return occur;
}

int main() {
    string seq = "hpshpshsphpspshphsshsspshphphsshpshsphspshpshpshpshsphsphspspssssssppppphphphhhhhphphphpshsphshphspshpssphpshhpshphsphsphshshspshphshspshphspspshpshphpshpshpshpshsphsphsphspshpshpshpshpshpshpshpshpshpshpshpshsphsphsphsphsphspshpshpshsphsphs";

    string h = cnt(seq, "h");
    string p = cnt(seq, "p");
    string s = cnt(seq, "s");

    cout << h << endl;
    cout << p << endl;
    cout << s << endl;

    return 0;
}