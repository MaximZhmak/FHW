#include <iostream>
#include <thread>
#include <future>
#include <condition_variable>
#include <cstddef>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <thread>
#include <algorithm>
#include <chrono>
#include <ostream>
#include <sstream>
#include <array>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T, size_t N>
class RingBuffer
{
	array<T, N> m_data;

	std::mutex mtx;
	std::condition_variable cond;

	typedef unsigned long long tSize;

	unsigned long long m_start = 0;
	unsigned long long m_end = 0;

	bool UnsafeEmpty() const
	{
		return (m_start == m_end);
	}

	bool UnsafeFull() const
	{
		return (N == (m_start - m_end));
	}

public:

	size_t size() const
	{
		return N;
	}

	size_t count() const
	{
		return m_start - m_end;
	}

	bool empty() const
	{
		lock_guard<mutex> lock(mtx);
		return UnsafeEmpty();
	}

	bool full() const
	{
		lock_guard<mutex> lock(mtx);
		return UnsafeFull();
	}

	void push_back(const T& elem)
	{
		unique_lock<mutex> lock(mtx);
		while (UnsafeFull())
		{
			cond.wait(lock);
		}

		tSize start = m_start%N;
		m_data[start] = elem;
		++m_start;
		cout << "push value: " << elem << endl;
		
		cond.notify_one();
	//	cond.wait(lock);
	}

	T& front()
	{
		unique_lock<mutex> lock(mtx);
		while (UnsafeEmpty())
		{

			cond.wait(lock);
		}
		cout << "\tread value: " << m_data[m_end%N] << endl;
		return m_data[m_end%N];
	}

	void pop_front()
	{
		unique_lock<mutex> lock(mtx);
		if (!UnsafeEmpty())
		{

			++m_end;
			cond.notify_one();
		}
	}

};


int main(int argc, char *argv[])
{
	const size_t N = 20;
	RingBuffer<int, N> ringBuffer;
	thread push{ [&]()
	{
		int counter = N*10;
		while (counter)
		{
			ringBuffer.push_back(--counter);

		}
		cout << "push completed" << endl;
	} };

	thread pop{ [&]()
	{
		int value;
		do
		{
			value = ringBuffer.front();
			ringBuffer.pop_front();

			std::chrono::milliseconds timeout(10);
			std::this_thread::sleep_for(timeout);
		} while (value);
		cout << "\tpop completed" << endl;
	} };

	pop.join();
	push.join();


	cout << "Completed!" << endl;
	return 0;
	}