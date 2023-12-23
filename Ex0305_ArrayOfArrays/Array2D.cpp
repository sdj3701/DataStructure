#include "Array2D.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Array2D::Array2D(int num_rows, int num_cols)
{
	//TODO:

	num_rows_ = num_rows;
	num_cols_ = num_cols;
	
	arrays_ = new float* [num_rows_];  // �࿡ ���� ������ �迭 ���� �Ҵ�

	for (int i = 0; i < num_rows_; i++) {
		arrays_[i] = new float[num_cols_];  // �� �࿡ ���� ������ ���� �Ҵ�
	}

	for (int i = 0; i < num_rows_ ; i++)
	{
		for (int j = 0; j < num_cols_; j++)
		{
			arrays_[i][j] = 0;
		}
	}
}

// ���� ������ (b�� ����)
Array2D::Array2D(const Array2D& b)
{
	//TODO:

	num_rows_ = b.num_rows_;
	num_cols_ = b.num_cols_;

	arrays_ = new float* [num_rows_];  // �࿡ ���� ������ �迭 ���� �Ҵ�

	for (int i = 0; i < num_rows_; i++) {
		arrays_[i] = new float[num_cols_];  // �� �࿡ ���� ������ ���� �Ҵ�
	}


	for (int i = 0; i < num_rows_; i++)
	{
		for (int j = 0; j < num_cols_; j++)
		{
			arrays_[i][j] = b.arrays_[i][j];
		}
	}
	

}

Array2D::~Array2D()
{
	//TODO:

	for (int i = 0; i < num_rows_; i++)
	{
		delete[] arrays_[i];
	}
	delete[] arrays_;

}

void Array2D::SetValue(int row, int col, float value)
{
	// TODO:
	arrays_[row][col] = value;
}

float Array2D::GetValue(int row, int col) const // �� ���� const�� �Լ� �ȿ��� ��� ������ ���� �ٲ��� �ʰڴٴ� �ǹ�
{
	return arrays_[row][col]; // TODO:
}

Array2D Array2D::Transpose()
{
	Array2D temp(num_cols_, num_rows_); // num_cols_, num_rows_ ���� ����

	for (int r = 0; r < num_rows_; r++)
		for (int c = 0; c < num_cols_; c++)
			temp.SetValue(c, r, GetValue(r, c));

	return temp;
}

Array2D Array2D::Add(const Array2D& b)
{
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Array2D temp(num_rows_, num_cols_);

	for (int r = 0; r < num_rows_; r++)
		for (int c = 0; c < num_cols_; c++)
			temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));

	return temp;
}

void Array2D::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";

		cout << endl;
	}
}