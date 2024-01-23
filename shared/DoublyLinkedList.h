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

		// ����: prev/next�� �ƴ϶� left/right
	};

	DoublyLinkedList()
	{
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // ��� ������(delete) �մϴ�.
	{
		// TODO:
	}

	bool IsEmpty()
	{
		return first_ == nullptr ? true : false ; // TODO: nullptr �̾�? �׷��� �� �ƴϾ�? �׷��� ����
	}

	int Size()
	{
		int size = 0;

		// TODO: ���?
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
		// TODO:���� ���� ���� 
		
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
		// TODO: ���� first_�� ���̸�? �߰� ����� ����? ������ while�� Ÿ�� ���� ������
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

		// �� �ڿ��� �ϳ� ���� ��带 ã�ƾ� �մϴ�.

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