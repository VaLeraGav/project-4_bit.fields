#pragma once
#include <iostream>
#include <fstream> 
using namespace std;
typedef unsigned int TELEM;

class TBitField
{
private:
	int BitLen;			// ����� �������� ���� - ����. �-�� �����
	TELEM* pMem;		// ������ ��� ������������� �������� ����
	int MemLen;			// �-�� ��-��� ��� ��� ������������� ���.����

	// ������ ����������
	int GetMemIndex(const int n) const;			// ������ � p��� ��� ���� n
	TELEM GetMemMask(const int n) const;		// ������� ����� ��� ���� n

public:
	TBitField(int len);
	TBitField(const TBitField& bf);
	~TBitField();

	// ������ � �����
	void SetBit(const int n);			// ���������� ���
	void ClrBit(const int n);			// �������� ���
	int GetLength(void) const;			// �������� ����� (�-�� �����)
	int GetBit(const int n) const;		// �������� �������� ����


	// ������� ��������
	int operator==(const TBitField& bf) const;		// ���������
	TBitField& operator=(const TBitField& bf);		// ������������
	TBitField operator|(const TBitField& bf);		// �������� "���"
	TBitField operator&(const TBitField& bf);		// �������� "�"
	TBitField operator~(void);						// ���������


	friend istream& operator>>(istream& istr, TBitField& bf);
	friend ostream& operator<<(ostream& ostr, const TBitField& bf);
};

