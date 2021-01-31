#include <bits/stdc++.h>

using namespace std;

// 7341
//  150

// update na komórki x
void update(int x, int val, int base, int screenLength, string &str, vector<int> &tree) {
    // DEBUG
    int orig = str[x-1]-'0';
    int diff = val - orig;

    str[x-1] = val;

    x += 2*base - screenLength+1;


    if (tree[x] + diff >= 10) {
        tree[x] += diff; // update komórki w dw/dz i dodanie do komórki dw/dz różnicy między val a poprzednią liczbą
        tree[x] %= 10;

        while (tree[x-1] == 9) { // trzeba dodać przypadek kiedy koórka zmniejsza się z 9
                                 // wtedy usuwamy 1-ki do momentu kiedy kończy się domino
            x -= 1;
            x >>= 1;
            tree[x] = 1; cout << tree[x] << endl;
            x <<= 1; x++;
        }
    }
    else {
        tree[x] += diff;
    }
}



// zapytanie o sumę od pojedynczej komórki w górę
int query(int x, int base, int screenLength, const vector<int> &tree) {
    int res = 0;

    // x += 2*base - screenLength;
    x = 2*base - x + 1;

    while (tree[x] != 0) {
        res += tree[x];
        x >>= 1;
    }
    return res;
}



// konstruujemy drzewo w czasie O(n)
void construct(int base, string &dw, string &dz, vector<int> &tree) {
    int end = base*2; // rozmiar podstawy drzewa

    int dwInt = stoi(dw); // prawdziwa wartość podanej liczby
    int dzInt = stoi(dz); // prawdziwa wartość podanej liczby

    int dwRealSize = (int) log10((double) dwInt) + 1; // rozmiar liczby bez zer wstępnych
    int dzRealSize = (int) log10((double) dzInt) + 1; // rozmiar liczby bez zer wstępnych

    int smallerSize = min(dwRealSize, dzRealSize);
    int biggerSize = max(dwRealSize, dzRealSize);

    reverse(dw.begin(), dw.end()); // metoda dodawania zaczyna się od tyłu
    reverse(dz.begin(), dz.end()); // metoda dodawania zaczyna się od tyłu

    // w 7341
    // z 0150

    int carry = 0;
    for (int i = 0; i < smallerSize; i++) {

        int w = dw[i] - '0';
        int z = dz[i] - '0';
        tree[end-i] = w + z + carry;

        if (tree[end-i] >= 10) {
            tree[end-i] %= 10;

            carry = 1;
        }
        else {
            carry = 0;
        }
    }

    if (dwRealSize > dzRealSize) {
        for (int i = smallerSize; i < biggerSize; i++) {
            int w = dw[i] - '0';

            tree[end-i] = w + carry;

            // cout << tree[end-i] << endl;

            if (tree[end-i] >= 10) {
                tree[end-i] %= 10;

                carry = 1;
            }
            else {
                carry = 0;
            }
        }
    }
    else if (dwRealSize < dzRealSize) {
        for (int i = smallerSize; i < biggerSize; i++) {
            int z = dz[i] - '0';

            tree[end-i] = z + carry;

            // cout << tree[end-i] << endl;

            if (tree[end-i] >= 10) {
                tree[end-i] %= 10;

                carry = 1;
            }
            else {
                carry = 0;
            }
        }
    }
    if (carry) {
        tree[end-biggerSize] = carry;
    }
}


void display(int base, int size, const vector<int> &tree) {
    int end = base*2;

    while (base) {

        for (int i = base; i <= end; i++) {
            cout << tree[i] << " ";
        }
        base >>= 1; end >>= 1;

        cout << endl;
    }
}




int main() {
    string dw = "7341";      //{7, 3, 4, 1};
    string dz = "0150";      //{0, 1, 5, 0};

    // 7341
    // 0150

    int base = 1;

    int screenLength = 5;

    while (base < max(dw.size(), dz.size())+1) {
        base <<= 1;
    }

    vector<int> tree;   tree.resize(base*2, 0);

    construct(base, dw, dz, tree);

    display(base, max(dw.size(), dz.size()), tree);

    query(4, base, screenLength, tree);

    update(2, 9, base, screenLength, dz, tree);

    display(base, max(dw.size(), dz.size()), tree);

    query(2, base, screenLength, tree);

    cout << endl;
}