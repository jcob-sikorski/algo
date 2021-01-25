#include <bits/stdc++.h>

using namespace std;


struct node {
    int val;
};


// zapytanie o przedział x-y
void query(int x, int y, 
        const int &base, 
        set<int> &places, 
        const unordered_map<int, vector<int>> &lookup, 
        const vector<node> &tree) 
        {

    int ref = INT32_MAX; // wartość minimum której szukamy

    x += base-1; // prawy wskaźnik
    y += base+1; // lewy wskaźnik

    while (y-x > 1) { // dopóki prawy i lewy wskaźnik nie mają tego samego ojca

        // oba wskaźniki co chwilę zmieniają pozycje naprzeciw poddrzewa
        // dlatego stawiamy im warunki

        if (!(x&1)) { // jeśli prawy wskaźnik jest parzysty
            if (ref > tree[x+1].val) {
                ref = tree[x+1].val;
            }
        }

        if (y&1) { // jeśli lewyy wskaźnik jest nieparzysty
            if (ref > tree[y-1].val) {
                ref = tree[y-1].val;
            }
        }

        x >>= 1; y >>= 1; // dzielimy przez dwa (skaczemy do ojców)
    }

    if (ref != INT32_MAX) { // jeśli funkcja spełniła swoje zamierzone zadanie
        for (int to_delete: lookup[ref]) {
            places.erase(to_delete);
        }
    }
}

// konstruujemy drzewo w czasie O(n)
void construct(int base, 
            const vector<int> &arr, 
            unordered_map<int, vector<int>> &lookup, 
            vector<node> &tree) {
    int end = base + arr.size()-1; // prawy dolny kraniec poziomu liści w drzewie

    for (int i = base; i <= end; i++) { // przechodzimy z lewego krańca do prawego krańca liści
        // DEBUG
        node Node;
        Node.val = arr[i-base]; // przypisujemy wartość liściowi bazowemu z arr
        lookup[Node.val].push_back(i-base); // dodajemy miejsce wystąpienia tego rodzaju liścia

        tree[i] = Node;
    }

    base >>= 1; end >>= 1;

    while (base) { // dopóki węzeł posiada ojca
        for (int i = base; i <= end; i++) { // przechodzimy z lewego krańca do prawego krańca pozimu drzewa
                                            // ojciec posiada mniejszą wartość z dwóch synów
            if (tree[i*2].val > tree[i*2+1].val) {
                tree[i] = tree[i*2+1];
            }
            else if (tree[i*2].val < tree[i*2+1].val) {
                tree[i] = tree[i*2];
            }
            else {
                tree[i].val = tree[i*2].val;
            }
        }
        base >>= 1; end >>= 1; // skaczemy na wyższy poziom liści
    }
}

// funkcja pomocnicza
void pla(const int base, 
        set<int> &places, 
        const unordered_map<int, vector<int>> &lookup, 
        const vector<node> &tree, 
        int &wynik) 
        {

    while (!places.empty()) {
        int x = *places.begin(); // zaczynamy szukać zbioru indeksów na których wywołamy funkcję query
        int maxr = x;   // prawy kraniec zbioru indeksów

        for (int i : places) {
            if (i - maxr > 1) { // jeśli kolejny index nie należy już do zbioru
                query(x, maxr, base, places, lookup, tree);
                wynik++;    // każde wywołanie funckji query to jeden plakat
                break;  //zaczynamy od nowa bo zbiór indeksów do zrobienia został zmodyfikowany przez funkcję query
            }
            maxr = i;
        }
    }
}




void display(int base, const vector<int> &arr, const vector<node> &tree) {
    int end = base + arr.size();

    while (base) {

        for (int i = base; i <= end; i++) {
            cout << tree[i].val << " ";
        }
        base >>= 1; end >>= 1;

        cout << endl;
    }
}




int main() {
    vector<int> arr = {2, 2, 3, 4, 2, 4, 3, 2};

    int base = 1;

    while (base < arr.size()) {
        base <<= 1;
    }

    vector<node> tree;   tree.reserve(base*2); // alokujemy miejce na przyszłe elementy

    for (int i = 0; i < base*2; i++) {
        tree.push_back(node());
    }

    set<int> places;    // zbiór indeksów

    for (int i = 0; i < arr.size(); i++) { // dodajemy indexy do ich zbioru
        places.insert(i);
    }

    unordered_map<int, vector<int>> lookup; // służy do zapisania miejsc wystąpień każdego rodzaju liścia

    construct(base, arr, lookup, tree);

    int wynik = 0;

    pla(base, places, lookup, tree, wynik);

    cout << wynik << endl;
    cout << endl;
}