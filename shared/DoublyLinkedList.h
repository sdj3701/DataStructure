#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template<typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node* left = nullptr;
		Node* right = nullptr;

		// 참고: prev/next가 아니라 left/right
	};

	DoublyLinkedList()
	{
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO:
	}

	bool IsEmpty()
	{
		return true; // TODO:
	}

	int Size()
	{
		int size = 0;

		// TODO: 몇개니?
		while (first_)
		{
			first_ = first_->right;
			size++;
		}

		return size;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
			// TODO:
			cout << current->left;
			cout << endl;

			cout << "Backward: ";
			// TODO:
			cout << current->right;
			cout << endl;
		}
	}

	Node* Find(T item)
	{
		return nullptr; // TODO:
	}

	void InsertBack(Node* node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
			// TODO:
		}
	}

	void PushFront(T item)
	{
		// TODO:이제 양쪽 연결 
		
		Node* current = new Node;
		if (first_ == nullptr)
		{
			current->item = item;
			first_ = current;
			current->left = first_;
			current->right = nullptr;
		}
		else
		{
			//한 발짝 앞으로
			current = first_->right;

			//잠깐 가지고 있을 temp 생성
			Node* temp = new Node;
			temp->left = current->left;
			temp->item = item;
			temp->right = first_->right;

			//이제 연결해야지 끊고 연결
			first_->right = temp->left;
			current->left = temp->right;
		}
	}

	void PushBack(T item)
	{
		// TODO:이제 뒤에서 넣기
		while (first_)
		{
			first_ = first_->right;
		}
		Node* current = new Node;
		current->item = item;
		first_ = current->left;
		current->left = first_;
		current->right = nullptr;

	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		// TODO:
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

		assert(first_);

		// TODO:
	}

	void Reverse()
	{
		// TODO:
	}

	T Front()
	{
		assert(first_);

		return T(); // TODO:
	}

	T Back()
	{
		assert(first_);

		return T(); // TODO:
	}

protected:
	Node* first_ = nullptr;
};