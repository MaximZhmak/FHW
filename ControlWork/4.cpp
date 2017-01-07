#include <iostream>
#include <cassert>
#include <string>

using namespace std;

template <class T>
class BinaryTree
{
private:
	T m_key;
	BinaryTree<T>* m_right;
	BinaryTree<T>* m_left;
public:
	BinaryTree(const T&value) :m_key(value)
	{
		m_right = nullptr;
		m_left = nullptr;
	}
	void AddLeft(BinaryTree<T>* left)
	{
		m_left = left;
	}
	void AddRight(BinaryTree<T>* right)
	{
		m_right = right;
	}
	string Serialize()
	{
		string str = m_key;
		if (m_right || m_left)
		{
			str += "(";
			if (m_left)
			{
				str += m_left->Serialize();
			}
			else
				str += " ";
			str += ", ";
			if (m_right)
			{
				str += m_right->Serialize();
			}
			else
				str += " ";
			str += ")";
		}
		return str;
	}
	template<typename U>
	friend ostream& operator<< (ostream os, const BinaryTree<U>& bt);
};

template <class U>
ostream& operator<< (ostream os, const BinaryTree<U>& bt) 
{
	os << obj.Serialize();
	return os;
}

int main()
{
	BinaryTree<string> root("+");
	BinaryTree<string> left("1");
	BinaryTree<string> right("2");

	root.AddLeft(&left);
	root.AddRight(&right);

	cout << root.Serialize() << endl << endl;
	//------------------------------------------
	BinaryTree<char*> A("0");
	BinaryTree<char*> B("1");
	BinaryTree<char*> C("2");

	BinaryTree<char*>D("3");
	BinaryTree<char*>E("4");
	BinaryTree<char*>F("5");
	BinaryTree<char*>G("6");

	B.AddLeft(&D);
	B.AddRight(&E);
	C.AddLeft(&F);
	//C.AddRight(&G);

	A.AddLeft(&B);
	A.AddRight(&C);

	cout << A.Serialize() << endl;	
}