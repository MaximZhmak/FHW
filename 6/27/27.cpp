#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <unordered_map>

#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))

using namespace std;

typedef pair<string, int> PAIR;

bool NotAlpha(const char&c)
{
	return (c < 0 || !isalpha(c));
}


void TrimNotAlpha(string&str)
{
	//function deletes punctuation marks and numbers from words
	str.erase(remove_if(str.begin(), str.end(), NotAlpha), str.end());
}

bool IsSmallWord(const string& word)
{
	static const string smallWords[] = {
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
		"but",
		"his",
		"he",
		"are",
		"has",
		"who",
		"by",
		"about",
		"which"	
	};

	static const unordered_set<string> small_set(smallWords, smallWords + ARRAY_LENGTH(smallWords));

	auto it = find(small_set.begin(), small_set.end(), word);
	if (it != small_set.end())
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
	int count = 0;

	unordered_map<string, int> map;

	ifstream file("D://war and peace.txt");
	if (!file.is_open())
	{
		cout << "FILE IS NOT OPEN!" << endl;
		return 1;
	}

	string word;

	while (file >> word)
	{
		count++;
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

	vector<PAIR> myVector(map.size());

	copy(map.begin(), map.end(), back_inserter(myVector));
	sort(myVector.begin(), myVector.end(), Compare());

	cout << "--------------------------------------------------------------" << endl;
	for (size_t i = 0; i < 10; i++)
		cout << myVector[i].second << " " << myVector[i].first << endl;


	cout << "total: " << count << endl;
}

