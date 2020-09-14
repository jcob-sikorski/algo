#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// Driver function to sort the vector elements 
// by second element of pairs 
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second); 
}

vector<pair<int, int>> make_v(int n) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(-1, -1));
    }
    return v;
}

int main() {
    int n = 6;
    //vector<int> klocki {5, 2, 3, 1, 4, 1, 4, 3, 5, 2};
    vector<int> klocki {4, 3, 2, 4, 1, 2, 3, 5, 6, 5, 6, 1};

    // tworzymy tablicę dystansów
    // potem sortujemy ją rosnąco
    // uzyskujemy dostęp do elementów między którymi jest najmniejszy dystans
    // zamieniamy dopóki nie skasujemy pierwszego elementu z tablicy dystansów
    // możemy też zauważyć, że przy każdej inwersji tak naprawdę nie zamieniamy kolejności elementów w tablicy jedynie wtedy 
    // gdy kasujemy dwa elementy - musimy jeszcze sprawdzić czy po usunięciu - tablica dystansów nie zmieni kolejności
    // jeśli nie to przeprowadzamy ten sam proces dopóki stos elementów zostanie opróżniony

    // twierdzenie: na początku usuwamy elementy najbliższe sobie, bo to one stanowią przeszkodę (zwiększają liczbę inwersji)
    // dla innych elementów

    vector<pair<int, int>> dist = make_v(klocki.size());
    
    // tworzymy tablicę dystansów
    for (int i = 0; i < klocki.size(); i++) {
        if (dist.at(i).first == -1) {
            dist.at(i).first = i;
        } else {
            dist.at(i).second = i;
        }
    }
    // sortujemy tablicę dystansów rosnąco
    sort(dist.begin(), dist.end(), sortbysec);

    int counter = 0;
    for (int i = 0; i < dist.size(); i++) {
        // i*2 tylko wtedy gdy pomiędzy dwoma innymi elementami znajdują się 2 elementy usuwane
        // i tylko wtedy gdy jeden element usuwany znajduje się pomiędzy dwoma innymi elementami
        counter += dist.at(i).second - dist.at(i).first - i*2;

        for (int j = i; j < dist.size(); j++) {
            cout << klocki.at(dist.at(i).first) << "  " << dist.at(j).second - dist.at(j).first - i*2 << endl;
        }
    }
    cout << counter << endl;
    cout << endl;
}
















int main() {
    int n = 5;
    //vector<int> klocki {5, 2, 3, 1, 4, 1, 4, 3, 5, 2};
    vector<int> klocki {4, 3, 2, 4, 1, 2, 3, 5, 6, 5, 6, 1};
    //vector<int> klocki {1, 2, 5, 3, 4, 3, 5, 2, 1, 4};

    stack<int> st;
    for (int i = 0; i < n; i++) {
        st.push(klocki.at(i));
    }
    stack<int> nd;
    for (int i = 2*n-1; n < i; i--) {
        nd.push(klocki.at(i));
    }

    int i = 0;
    int j = 2*n-1;

    int counter = 0;

    // representation: st element == top element in stack       nd element == element below top element
    pair<int, int> st_pair = make_pair(-1, klocki.at(i)); pair<int, int> nd_pair = make_pair(-1, klocki.at(j));
    i++; j--;
    while ( i < j ) {
        st_pair.first = klocki.at(i); nd_pair.first = klocki.at(j);

        cout << st_pair.first << "  " << nd_pair.first << endl;
        cout << st_pair.second << "  " << nd_pair.second << endl; 

        if (st_pair.first == nd_pair.second && st_pair.second == nd_pair.first) {
            cout << "counter++" << endl;
            counter++;
        }
        st_pair.second = st_pair.first; nd_pair.second = nd_pair.first;
        i++; j--;
        cout << endl;
    }
    // jesli na tym algorytm nie zakonczy swego dzialania, to dla kazdej mozliwej pary sasiadow w pierwszym stosie
    // iterujemy kazda pare dla drugiego stosu, jesli to nie da efektu, to...
    cout << counter << endl;
}