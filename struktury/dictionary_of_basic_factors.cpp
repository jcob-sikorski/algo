// 1 dzielimy słowo na literki
// podczas dzielenia przypisujemy literkom identyfikatory

// potem tworzymy dwu-literkowe podsłowa i tworzymy parę identyfikatorów dwóch podsłów które "sklejamy"
// sortujemy i przypisujemy identyfikatory
// potem tworzymy 4-8-16... literkowe podsłowa dopóki długość kolejnej wielkości podsłowa jest <= długości całego ciągu


// ---------------------------------------------------------------------------------------------------------------------------------
// ZADANIE


// czyli musimy znaleźć najdłuższe wspólne podsłowo
// i potem wyszukać z tego podsłowa ostatnie leksykograficznie podsłowo

// jeśli ostatnie leksykograficznie podsłowo jest mniejsze niż "bitek" to rezygnujemy

// 2 4  11   3
// b i   t e k

//  *                    *  *        * *   *
// 14  1 10 9 7 8 4 1 8 13 12 9 5 9 12 8 4 6 
//  z  a  p o m n i a n  y  w o j o  w n i k



// 14  1 10 9 7 8 4 1 8 13 12 9 5 9 12 8 4 6

// przydzielamy do id słów wskaźniki
// szukamy największego id i potem kolejnego największego itd. itd.

#include <bits/stdc++.h>

using namespace std;


class DBF {
private:
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    unordered_map<char, int> alpha_order;
    string s;
public:
    // tablica indeksów
    vector<int> dbf;

    // tablica par
    vector<pair<int, int>> p;

    // tablica podsłów
    vector<string> ss;

    // indeks na danym poziomie po posortowaniu
    unordered_map<string, int> order;

    // indeks w dbf
    unordered_map<string, int> indeks;


void construct_dbf(int base) {
    int end = base + s.size();
    
    // przydzielamy każdej literce indeks alfabetyczny
    for (int i = base; i < end; i++) {
        dbf[i] = alpha_order[s[i-base]];
        p[i].first = dbf[i]; p[i].second = dbf[i];
        ss[i] = s[i-base];
        order[ss[i]] = dbf[i];
    }

    // przechodzimy do wyższej pozycji
    base >>= 1; end >>= 1;

    // długość podsłowa
    int l = 1;

    vector<pair<int, int>> sorted;

    // podczas gdy 2*l <= s.len
    while ((l << 1) <= s.size()) {
        for (int i = base; i <= end; i++) {
            p[i] = make_pair(order[ss[2*i]], order[ss[2*i + l]]);
        }
        sorted = sort(p.begin()+base, p.begin()+end);

    for (int i = base; i < end; i++) {
        dbf[i] = sorted[i-base];

        base >>= 1; end >>= 1; l <<= 1;
    }
}

    void init() {
        // init alphabetical order
        for (int i = 0; i < alphabet.size(); i++) {
            alpha_order[alphabet[i]] = i;
        }
        

        // reserve enough space for dbf
        int base = 1;
        while (base < s.size()) {
            base <<= 1;
        }
        dbf.resize(base*2);
        p.resize(base*2);
        ss.resize(base*2;


        construct_dbf(base);
    }
}