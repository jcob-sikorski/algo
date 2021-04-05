#include<bits/stdc++.h>

using namespace std;


int after(int &x, vector<int> &arr) 
{
    int l = 0, mid, r = arr.size();

    while(l < r) 
    {
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<vector<int>>> pos; pos.resize(n, vector<vector<int>>(26));
    vector<int> rec;         rec.resize(n, -1);

    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;

        for (int j = 0; j < s.size(); j++)
        {
            // index of letter in alphabet
            int position = s[j] - 'a';
            pos[i][position].push_back(j);
        }
    }

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    s = "";
    for (int i = 25; i >= 0; i--)
    {
        // czegoś nie wyłapuje
        while (true)
        {
            bool all = true;
            for (int j = 0; j < n; j++)
            {
                int x = after(rec[j], pos[j][i]);

                if (x == -1)
                {
                    all = false;
                    goto killThisLetter;
                }
                else
                    rec[j] = x;
            }

            if(all)
                s += alphabet[i];
        }
        killThisLetter:;
    }

    if (s >= "bitek") {
        cout << s << endl;
    }
    else {
        cout << "bitek" << endl;
    }

    return 0;
}