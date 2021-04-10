#include<bits/stdc++.h>

using namespace std;


class UnionFind
{

private:
    // stores where object belongs
    vector<int> bijection;

    // stores key for every object
    unordered_map<char, int> mapper;

public:
    void map_obj(char &obj)
    {
        mapper[obj] = bijection.size();
        bijection.push_back(mapper[obj]);
    }
    int obj_key(char &obj)
    {
        if (mapper.find(obj) == mapper.end()) {
            return -1;
        }
        else {
            return mapper[obj];
        }
    }
    int whr_belongs(char &obj)
    {
        int key = obj_key(obj);

        if (key != -1) {
            return bijection[key];
        }
        else {
            return -1;
        }
    }
    void union_obj(char a, char b)
    {
        int a_group = whr_belongs(a);

        if (a_group == -1) {
            map_obj(a);
        }

        int b_group = whr_belongs(b);

        if (b_group == -1) {
            map_obj(b);
        }

        if (a_group > b_group) {
            bijection[obj_key(b)] = a_group;
        }
        else {
            bijection[obj_key(a)] = b_group;
        }
    }

    UnionFind(vector<char> &a)
    {
        for (char i : a) {
            int group = whr_belongs(i);

            if (group == -1) {
                map_obj(i);
            }
        }
    }
};


int main()
{
    vector<char> a = {'E', 'F', 'I', 'D', 'C', 'A', 'J', 'L', 'G', 'K', 'B', 'H'};
    UnionFind uf = UnionFind(a);

    uf.union_obj('C', 'K');
    uf.union_obj('F', 'E');
    uf.union_obj('A', 'J');
    uf.union_obj('A', 'B');
    uf.union_obj('C', 'D');
    uf.union_obj('D', 'I');
    uf.union_obj('L', 'F');
    uf.union_obj('C', 'A');
    uf.union_obj('A', 'B');
    uf.union_obj('H', 'G');
    uf.union_obj('H', 'F');
    uf.union_obj('H', 'B');

    return 0;
}