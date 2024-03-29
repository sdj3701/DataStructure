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
		// TODO: 연결 리스트 복사
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

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO: 모두 삭제
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

		// TODO: size를 하나하나 세어서 반환
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

		return first_->item; // TODO: 수정
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
		// TODO: item이 동일한 노드 포인터 반환

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

		// 하나 앞의 노드를 찾아야 합니다.
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
		// first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)

		// 새로운 노드 만들기
		// TODO:
		Node* current = new Node;
		current->item = itme;

		current->next = first_;
		first_ = current;
		
		// 연결 관계 정리
		// TODO:
	}

	void PushBack(T item)
	{
		if (first_)
		{
			Node* temp = new Node;
			// TODO: 값이 있어?
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
			// TODO: 값이 없어?
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

		// TODO: 메모리 삭제
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

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

		assert(first_);

		Node* second_last = first_;
		while (second_last->next->next)
			second_last = second_last->next;

		Node* temp = second_last->next;
		second_last->next = second_last->next->next;

		delete temp;

		// TODO: 메모리 삭제
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

					// 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
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