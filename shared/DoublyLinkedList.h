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
		return true; // TODO:
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
			current->left = first_;
			current->right = nullptr;
		}
		else
		{
			//�� ��¦ ������
			current = first_->right;

			//��� ������ ���� temp ����
			Node* temp = new Node;
			temp->left = current->left;
			temp->item = item;
			temp->right = first_->right;

			//���� �����ؾ��� ���� ����
			first_->right = temp->left;
			current->left = temp->right;
		}
	}

	void PushBack(T item)
	{
		// TODO:���� �ڿ��� �ֱ�
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