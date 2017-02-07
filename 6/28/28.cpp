#include "list.h"
#include "forward_list.h"
#include <functional>
#include <string>
#include <cassert>


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

	my::forward_list<string> forwList;
	my::list<string> list;


	list.push_back(name1);
	list.push_back(name2);

	list.reverse();

	assert(list.pop_back() == name1);
	assert(list.pop_back() == name2);
	assert(list.empty());
	
	forwList.push_front(name1);
	forwList.push_front(name2);

	forwList.reverse();

	assert(forwList.pop_front() == name1);
	assert(forwList.pop_front() == name2);


	cout << "PASSED" << endl;
}

