#include <bits/stdc++.h>

using namespace std;

// szukamy indeksu najbliższej wartości > x
int after(int &x, vector<int> &arr) {
	int l = 0, mid, r = arr.size();

	while(l < r) {
		mid = (l + r) / 2;
		if(arr[mid] <= x)
			l = mid + 1;
		else
			r = mid;
	}
	if(l == arr.size())
		return -1;
	else
		return arr[l];
}

string alphabet = "zyxwvutsrqponmlkjihgfedcba";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> arrs; arrs.reserve(n);

    unordered_map<int, vector<vector<int>>> occur; // musimy zresizować vector od liter (nie od pozycji liter!!!)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            occur[i].resize(26);
        }
    }

    string a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arrs.push_back(a);

        for (int j = 0; j < a.size(); j++) {
            occur[i][a[j]-'a'].push_back(j);
        }
    }


    vector<int> prev_index; prev_index.resize(n, -1);

    string bitek = "bitek";
    string ans;

    for (char c : alphabet) {
        while (true) {
            vector<int> holder; holder.reserve(n);

            for (int i = 0; i < arrs.size(); i++) {
                int j = after(prev_index[i], occur[i][c-'a']);
                if (j != -1) {
                    holder.push_back(j);
                }
                else {
                    goto leap;
                }
            }
            ans += c;
            for (int j = 0; j < holder.size(); j++) {
                prev_index[j] = holder[j];
            }
        }
        leap:;
    }

    if (ans < bitek) {
        cout << "bitek" << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}