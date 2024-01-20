#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		// TODO: ���� ����Ʈ ����
		Node* current = list.first_;
		while (current)
		{
			this->PushBack(current->item);
			current = current->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // ��� ������(delete) �մϴ�.
	{
		// TODO: ��� ����
		Node* current_ = first_;

		while (current_)
		{
			Node* temp_ = current_;
			current_ = current_->next;
			delete temp_;
		}
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		// TODO: size�� �ϳ��ϳ� ��� ��ȯ
		Node* current_ = first_;
		while (current_)
		{
			size++;
			current_ = current_->next;
		}

		return size;
	}

	T Front()
	{
		assert(first_);

		return first_->item; // TODO: ����
	}

	T Back()
	{
		assert(first_);

		Node* current = first_;
		while (current->next)
		{
			current = current->next;
		}
		return current->item;

	}

	Node* Find(T item)
	{
		// TODO: item�� ������ ��� ������ ��ȯ

		Node* current_ = first_;
		while (current_)
		{
			if (current_->item == item)
			{
				return current_;
			}

			current_ = current_->next;
		}
		return nullptr;
	}

	void InsertBack(Node* node, T item)
	{
		Node* current_ = new Node;
		current_->item = item;
		current_->next = node->next;
		node->next = current_;
			
	}

	void Remove(Node* n)
	{
		assert(first_);

		// �ϳ� ���� ��带 ã�ƾ� �մϴ�.
		Node* prev = first_;
		while (prev->next)
		{
			if (prev->next == n)
				break;
			prev = prev->next;
		}
		prev->next = n->next;
		delete n;

	}

	void PushFront(T item)
	{
		// first_�� nullptr�� ���� �ƴ� ��� ������ �����غ��� (�ᱹ�� �� ��츦 �ϳ��� ��ĥ �� ����)

		// ���ο� ��� �����
		// TODO:
		Node* temp = new Node;
		temp->item = item;
		// ���� ���� ����
		// TODO:
		temp->next = first_;
		first_ = temp;
	}

	void PushBack(T item)
	{
		if (first_)
		{
			Node* temp = new Node;
			// TODO: ���� �־�?
			while (first_)
			{
				first_ = first_->next;
				if (first_ == nullptr)
				{
					temp->item = item;
					temp->next = first_;
					first_ = temp;
					break;
				}
			}
			/*
			Node* current  = first_;
			while(current->next)
				current = current->next;
			Node* new_node = new Node;
			new_node->item = item;
			new_node->next = nullptr;

			current->next = new_node;

			*/
		}
		else
		{
			// TODO: ���� ����?
			PushFront(item);
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

		Node* temp = first_;
		first_ = first_->next;

		delete temp;

		// TODO: �޸� ����
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		if (first_->next == nullptr)
		{
			delete first_;
			first_ = nullptr;
			return;
		}

		// �� �ڿ��� �ϳ� ���� ��带 ã�ƾ� �մϴ�.

		assert(first_);

		Node* second_last = first_;
		while (second_last->next->next)
			second_last = second_last->next;

		Node* temp = second_last->next;
		second_last->next = second_last->next->next;

		delete temp;

		// TODO: �޸� ����
	}

	void Reverse()
	{
		// TODO: 
		Node* current = first_;
		Node* prev = nullptr;
		prev = first_->next;

		while (current)
		{
			Node* temp = prev;
			prev = current;
			current = current->next;
			prev->next = temp;

		}
		first_ = prev;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					//cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// �ּҸ� ª�� ������ ��� (�� �κ��� ��κ� �����ϱ⶧���� �޺κи� ���)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node* first_ = nullptr;

	bool print_debug_ = false;
};