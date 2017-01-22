#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>



using namespace std;

typedef pair<string, int> PAIR;


void TrimNotAlpha(string&str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]))
		{
			str.erase(i, 1);
			i--;
		}
	}
}

bool IsSmallWord(const string& word)
{
	const vector<string> smallWords = {
		"i",
		"or",
		"and",
		"that",
		"the",
		"of",
		"not",
		"to",
		"is",
		"a",
		"in",
		"with",
		"at",
		"an",
		"as",
		"for",
		"but"
	};

	auto it = find(smallWords.begin(), smallWords.end(), word);
	if (it != smallWords.end())
		return true;
	else
		return false;
}


struct Compare
{
	bool operator()(const PAIR pair1, const PAIR pair2) const
	{
		return pair1.second > pair2.second;
	}
};

int main()
{
	map<string, int> map;

	ifstream file("E://war and peace.txt");
	if (!file.is_open())
	{
		cout << "FILE IS NOT OPEN!" << endl;
		return 1;
	}

	string word;

	while (file >> word)
	{
		::transform(word.begin(), word.end(), word.begin(), tolower);
		TrimNotAlpha(word);

		if (!IsSmallWord(word))
		{
			auto it = map.find(word);
			if (it != map.end())
			{
				it->second++;
			}
			else
				map[word] = 1;
		}
	}

	vector<PAIR> myVector;

	copy(map.begin(), map.end(), back_inserter(myVector));
	sort(myVector.begin(), myVector.end(), Compare());

	cout << "--------------------------------------------------------------" << endl;
	for (size_t i = 0; i < 10; i++)
		cout << myVector[i].second << " " << myVector[i].first << endl;
}


