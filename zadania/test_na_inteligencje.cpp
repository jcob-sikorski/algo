/*************************************************************************
 *                                                                       *
 *                    XVII Olimpiada Informatyczna                       *
 *                                                                       *
 *   Zadanie:           Test na inteligencję (TES)                       *
 *   Plik:              tess2.cpp                                        *
 *   Autor:             Bartosz Górski                                   *
 *   Opis:              Rozwiązanie powolne.                             *
 *                      Rozwiązanie wykorzystuje STLa.                   *
 *   Złożoność czasowa: O(m + l * log m + |A|)                           *
 *   Kodowanie znaków:  UTF-8                                            *
 *                                                                       *
 *************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define MAX_M 1000000 // maksymalna długość ciągu a_i
#define MAX_A 1000000 // maksymalny wyraz ciągu


int main() 
{
    int m, n, mi, a, b, p;
    vector<int> ind[MAX_A];
    bool ok;

    cin >> m;

	for(int i = 0; i < m; ++i) {
        cin >> a;
		ind[a - 1].push_back(i);
	}

	// scanf("%d", &n);
    cin >> n;
	for(int i = 0; i < n; ++i) {
        cin >> mi;
		p = -1;
		ok = true;
		for(int j = 0; j < mi; ++j) {
            cin >> b; --b;
			if(!ok || ind[b].empty()) {
				ok = false;
				continue;
			}
			int l = 0, c, r = ind[b].size();
			while(l < r) {
				c = (l + r) / 2;
				if(ind[b][c] <= p)
					l = c + 1;
				else
					r = c;
			}
			if(l == (int)ind[b].size())
				ok = false;
			else
				p = ind[b][l];
		}
		printf("%s\n", (ok ? "TAK" : "NIE"));
	}

	return 0;
}
