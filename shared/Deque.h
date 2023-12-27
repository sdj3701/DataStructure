#pragma once

#include "Queue.h"

#include <cassert>
#include <iostream>
#include <iomanip>

// Double Ended Queue (��, dequeue�� ����)
template<typename T>
class Deque : public Queue<T>
{
	//���� ť����� R �� �� ���� �ǹ� �ϰ� F �� �� �������� �ǹ��� 
	//F �� �� ó���� ����Ű�� ������ġ�� �� �������� ����Ų��.
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

		// TODO: R�� F�� ��ġ�� ó������ ���� ������ F�� �� �տ� ������ ���� ��ġ�� �� ���������� ����Ŵ
		
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

		// TODO: �ǵڿ��� ����
		
	}

private:
	// Queue�� ����
};
