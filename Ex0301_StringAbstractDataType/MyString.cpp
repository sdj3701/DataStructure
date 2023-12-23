#include "MyString.h"

using namespace std;

// 비어 있는 MyString() 생성
MyString::MyString()
{
	str_ = nullptr;
	size_ = 0;
}

// 맨 뒤에 널 캐릭터'\0'가 들어 있는 문자열로부터 초기화
MyString::MyString(const char* init)
{
	// 크기(size_) 결정
	while (true)
	{
		if (init[size_] != '\0')
			size_++;
		else
			break;
	}
	// 메모리 할당
	str_ = new char[size_];

	// 데이터 복사
	for (int i = 0;i < size_;i++)
	{
		str_[i] = init[i];
	}
	
}

// MyString의 다른 instance로부터 초기화
MyString::MyString(const MyString& str)
{
	// 기본 복사 생성자는 포인터 주소만 복사하기 때문에 
	// 소멸시 오류 발생
	// 여기서는 새로 메모리를 할당 받아서 복사

	size_ = str.size_;
	str_ = new char[size_];
	for (int i = 0; i < size_;i++)
	{
		str_[i] = str.str_[i];
	}

}

MyString::~MyString()
{
	if(str_ != nullptr) delete[] str_;
	// 메모리 해제
}

bool MyString::IsEmpty()
{
	return Length() == 0;
}

bool MyString::IsEqual(const MyString& str) // 편의상 참조& 사용
{
	// 힌트: str.str_, str.size_ 가능
	int count = 0;
	for (int i = 0;i < size_;i++)
	{
		if (str.str_[i] == str_[i])
			count++;
	}

	return count == str.size_ ? true : false;
}

int MyString::Length()
{
	return size_;
}

void MyString::Resize(int new_size)
{
	// 메모리 재할당과 원래 갖고 있던 내용 복사
	size_ += new_size;

	if (new_size != size_)
	{
		char* new_str = new char[new_size];

		memcpy(new_str, str_, size_);

		delete[] str_;
		str_ = new_str;
		size_ = new_size;
	}

}

// 인덱스 start위치의 글자부터 num개의 글자로 새로운 문자열 만들기
MyString MyString::Substr(int start, int num)
{
	// 복사할 인덱스: start, start + 1, ... , start + num - 1
	// assert(start + num - 1 < this->size_); // 문제를 단순하게 만들기 위해 가정

	MyString temp;

	// TODO:
	temp.Resize(num);

	for (int i = 0; i < num; i++)
		temp.str_[i] = this->str_[start + i];

	return temp;
}

MyString MyString::Concat(MyString app_str)
{
	MyString temp;
	temp.Resize(this->size_ + app_str.size_);

	memcpy(temp.str_, this->str_, this->size_);
	memcpy(&temp.str_[this->size_], app_str.str_, app_str.size_);
	// TODO: 

	return temp;
}

MyString MyString::Insert(MyString t, int start)
{
	assert(start >= 0);
	assert(start <= this->size_);

	MyString temp;
	
	temp.size_ = size_ + t.size_;
	temp.str_ = new char[temp.size_];

	bool check = false;

	for (int i = 0;i < temp.size_;i++)
	{
		if (i == start)
		{
			for (int j = 0;j < t.size_;j++)
				temp.str_[i + j] = t.str_[j];
			i += t.size_- 1;
			check = true;
		}
		else
		{
			if (i - (t.size_ +1)< 0 && check == true)
			{
				temp.str_[i] = str_[i - t.size_];
			}
			else
			{
				temp.str_[i] = str_[i];
			}
		}
	}

	//temp.Resize(size_ + t.size_);

	// TODO:t가 입력할 글자 start는 자리
	/*for (int i = 0; i < start; i++)
		temp.str_[i] = str_[i];

	for (int i = start; i < start + t.size_; i++)
		temp.str_[i] = t.str_[i - start];

	for (int i = start + t.size_; i < size_ + t.size_; i++)
		temp.str_[i] = str_[i - t.size_];*/

	return temp;
}

int MyString::Find(MyString pat)
{
	//TODO: 같은 글자가 있으면 몇번째 자리인지 알려줘야함
	for (int i = 0; i < size_;i++)
	{
		int count = 0;
		for (int j = 0;j < pat.size_;j++)
		{
			if (str_[i + j] == pat.str_[j])
			{
				count++;
			}
		}
		if (count == pat.size_)
			return i;
	}

	return -1;
}

void MyString::Print()
{
	for (int i = 0; i < size_; i++)
		cout << str_[i];
	cout << endl;
}

