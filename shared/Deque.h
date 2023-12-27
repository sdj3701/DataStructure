#pragma once

#include "Queue.h"

#include <cassert>
#include <iostream>
#include <iomanip>

// Double Ended Queue (덱, dequeue와 구분)
template<typename T>
class Deque : public Queue<T>
{
	//원형 큐만들기 R 이 맨 앞을 의미 하고 F 가 맨 마지막을 의미함 
	//F 가 맨 처음을 가리키면 다음위치는 맨 마지막을 가리킨다.
	typedef Queue<T> Base;

public:
	Deque(int capacity)
		: Queue<T>(capacity)
	{
	}

	T& Front()
	{
		return Base::Front();
	}

	T& Back()
	{
		return Base::Rear();
	}

	void PushFront(const T& item)
	{
		if (Base::IsFull())
			Base::Resize();

		// TODO: R과 F의 위치는 처음에는 같다 하지만 F가 맨 앞에 있으면 다음 위치는 맨 마지막으로 가리킴
		
	}

	void PushBack(const T& item)
	{
		Base::Enqueue(item);
	}

	void PopFront()
	{
		Base::Dequeue();
	}

	void PopBack()
	{
		assert(!Base::IsEmpty());

		// TODO: 맨뒤에서 제거
		
	}

private:
	// Queue와 동일
};
