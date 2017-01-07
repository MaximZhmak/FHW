#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class ASTBinaryNode
{
	T m_right;
	T m_left;
public:
	const T& GetRight() const
	{
		return m_right;
	}
	const T& GetLeft() const
	{
		return m_left;
	}
	ASTBinaryNode(const T&left, const T&right) :m_right(right), m_left(left) {}

	virtual T evaluate()const = 0;
	virtual  ~ASTBinaryNode() {};
};

template <class T>
class ASTBinaryNodePlus :public ASTBinaryNode<T>
{
public:
	ASTBinaryNodePlus(const T&left, const T&right) :ASTBinaryNode(left, right) {}
	T evaluate()const override
	{
		return GetLeft() + GetRight();
	}
};

template <class T>
class ASTBinaryNodeMinus :public ASTBinaryNode<T>
{
public:
	ASTBinaryNodeMinus(const T&left, const T&right) :ASTBinaryNode(left, right) {}
	T evaluate()const override
	{
		return GetLeft() - GetRight();
	}
};

template <class T>
class ASTBinaryNodeDivide :public ASTBinaryNode<T>
{
public:
	ASTBinaryNodeDivide(const T&left, const T&right) :ASTBinaryNode(left, right) {}
	T evaluate()const override
	{
		return GetLeft() / GetRight();
	}
};

template <class T>
class ASTBinaryNodeMultiply :public ASTBinaryNode<T>
{
public:
	ASTBinaryNodeMultiply(const T&left, const T&right) :ASTBinaryNode(left, right) {}
	T evaluate()const override
	{
		return GetLeft() * GetRight();
	}
};

int main()
{
	ASTBinaryNode<int>* operations[]
	{
		new ASTBinaryNodePlus<int>(2, 2),
		new ASTBinaryNodeMinus<int>(2, 2),
		new ASTBinaryNodeMultiply<int>(2, 2),
		new ASTBinaryNodeDivide<int>(2, 2)
	};

	assert(operations[0]->evaluate() == 4);
	assert(operations[1]->evaluate() == 0);
	assert(operations[2]->evaluate() == 4);
	assert(operations[3]->evaluate() == 1);

	cout << "PASSED" << endl;
}