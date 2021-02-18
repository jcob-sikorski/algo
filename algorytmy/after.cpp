#include<bits/stdc++.h>

using namespace std;


// szukamy indeksu najbliższej wartości >= x
int aftereq(int &x, vector<int> &arr) {
	int l = 0, mid, r = arr.size();

	while(l < r) {
		mid = (l + r) / 2;
		if(arr[mid] <= x)
			l = c + 1;
		else
			r = c;
	}
	if(l == (int)ind[b].size())
		return -1;
	else
		return arr[l];
}


int main() {
    vector<int> arr = {0, 4, 6, 9, 11, 13, 19, 21, 44, 86};

    int wynik = aftereq(43, arr);
    return 0;
}