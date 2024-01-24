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

	DoublyLinkedList(const DoublyLinkedList& list)
	{
		Node* current = list.first_;
		while (current)
		{
			this->PushBack(current->item);
			current = current->right;
		}
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // ��� ������(delete) �մϴ�.
	{
		while (first_)
		{
			PopFront();
		}
		// TODO:
	}

	bool IsEmpty()
	{
		return first_ == nullptr;//first_ == nullptr ? true : false ; // TODO: nullptr �̾�? �׷��� �� �ƴϾ�? �׷��� ����
	}

	int Size()
	{
		int size = 0;

		// TODO: ���?
		Node* current = first_;
		while (current)
		{
			current = current->right;
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
			// TODO: ������� ��� ����
			while (1)
			{
				cout << current->item << " ";
				/*if (current->right)
					current = current->right;
				else
					break;*/
				if (!current->right)
					break;
				current = current->right;
			}
			cout << endl;

			cout << "Backward: ";
			// TODO: �������� ��� ����
			while (1)
			{
				cout << current->item << " ";
				/*if (current->left)
					current = current->left;
				else
					break;*/

				if (!current->left)
					break;
				current = current->left;
			}
			cout << endl;
		}
	}

	Node* Find(T item)
	{
		Node* current = first_;

		while (current)
		{
			if (current->item == item)
				return current;
			current = current->right;
		}
		
		return current; // TODO:
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
			Node* temp = new Node;
			temp->item = item;
			temp->right = node->right;
			node->right = temp;

			if (temp->right)
				temp->right->left = temp;
			temp->left = node;
		}
	}

	void PushFront(T item)
	{
		// TODO:���� ���� ���� 
		
		Node* current = new Node;
		current->item = item;

		
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