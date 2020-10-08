#include <iostream>
#include <unordered_map>
#include <utility>

typedef std::pair<char, int> pair;

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2> &pair) const
	{
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

int main()
{
	std::unordered_map<pair,int,pair_hash> unordered_map =
	{
		{{'a', 1000}, 2011},
		{{'b', 343}, 2014},
		{{'c', 223}, 2017},
		{{'e', 555}, 2011},
		{{'d', 555}, 2014},
		{{'f', 555}, 2017}
	};

	for (auto const &entry: unordered_map)
	{
		auto key_pair = entry.first;
		std::cout << "{" << key_pair.first << "," << key_pair.second << "}, "
				  << entry.second << '\n';
	}

	return 0;
}