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
		return first_ == nullptr ? true : false ; // TODO: nullptr 이야? 그러면 참 아니야? 그러면 거짓
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
			current->left = nullptr;
			current->right = nullptr;
		}
		else
		{
			current->item = item;
			Node* temp = new Node;
			Node* prev = new Node;
			prev = first_;
			prev = prev->right;
			temp = first_;
			first_ = current;
			current->left = nullptr;
			current->right = prev;
			prev->left = current;
		}
	}

	void PushBack(T item)
	{
		// TODO: 만약 first_가 널이면? 추가 해줘야 겠지? 있으면 while문 타고 가면 되지만
		Node* current = new Node;
		if (first_ == nullptr)
		{
			current->item = item;
			first_ = current;
			current->left = nullptr;
			current->right = nullptr;
		}
		else
		{
			while (first_->right)
			{
				first_ = first_->right;
			}
			Node* temp = new Node;
			Node* back = new Node;
			temp = first_;
			current->item = item;
			first_ = current->left;
			current->left = first_;
			current->right = nullptr;
			temp->right = current;
		}

		

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