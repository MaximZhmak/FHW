#include "list.h"
#include "forward_list.h"
#include <functional>
#include <string>
#include <cassert>
#include <list>


using namespace std;

struct Student
{
	char* name;
	Student*prev;
	Student*next;
};


int main()
{
	string name1 = "Ivanov";
	string name2 = "Petrov";



	my::list<string> list;


	{
		my::list<string> list;

		list.push_back(name1);
		list.pop_back();
		list.push_back(name2);
		list.push_back(name1);
		list.push_back(name2);

		list.reverse();
	}

	{
		my::list<int> my_list;

		for (int i = 0; i < 1000; i++)
			my_list.push_back(i);

		my_list.reverse();

		for (int i = 0; i < 1000; i++)
			assert(my_list.pop_back() == i);

	}

	{
		my::forward_list<string> forwList;

		forwList.push_front(name1);
		forwList.pop_front();
		forwList.push_front(name2);
		forwList.push_front(name1);

		forwList.reverse();

		assert(forwList.pop_front() == name2);
		assert(forwList.pop_front() == name1);
	}

	cout << "PASSED" << endl;
}

