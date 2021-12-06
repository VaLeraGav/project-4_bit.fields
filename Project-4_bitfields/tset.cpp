#include "tset.h"
#include "tbitfield.h"
#include <iostream>

TSet::TSet(int mp = 100) : BitField(mp), MaxPower(mp) {}

TSet::TSet(const TSet& s) : BitField(s.MaxPower)
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
}

TSet::TSet(const TBitField& bf) : BitField(bf.GetLength())
{
	BitField = bf;
	MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
	return BitField;
}

// ������ � �����----------------------------

int TSet::GetMaxPower(void) const // �������� ����. �-�� ��-���
{
	return MaxPower;
}

void TSet::InsElem(const int n) // ��������� �������� ���������
{
	BitField.SetBit(n);
}

void TSet::DelElem(const int n) // ���������� �������� ���������
{
	BitField.ClrBit(n);
}

int TSet::IsMember(const int n) const // ������� ���������
{
	if (BitField.GetBit(n) == 1)
		return 1;
	else
		return 0;
}


// ���������-������������� ��������----------------------
int TSet::operator==(const TSet& s) const // ���������
{
	if ((MaxPower == s.MaxPower) && (BitField == s.BitField))
		return 1;
	else
		return 0;
}

TSet& TSet::operator=(const TSet& s) // ������������
{
	BitField = s.BitField;
	MaxPower = s.MaxPower;
	return *this;
}

TSet TSet::operator+(const int n) // ����������� � ���������
{
	TSet tmp(*this);
	tmp.BitField.SetBit(n);
	return tmp;
}

TSet TSet::operator-(const int n) // �������� � ���������
{
	TSet tmp(*this);
	tmp.BitField.ClrBit(n);
	return (tmp);
}

TSet TSet::operator+(const TSet& s) // �����������
{
	if (MaxPower > s.MaxPower)
	{
		TBitField tmp(MaxPower);
		tmp = BitField | s.BitField;
		TSet _S(tmp);
		return _S;
	}
	else
	{
		TBitField tmp(s.MaxPower);
		tmp = BitField | s.BitField;
		TSet _S(tmp);
		return _S;
	}
}


TSet TSet::operator*(const TSet& s) // �����������
{
	TBitField tmp(MaxPower);
	tmp = BitField & s.BitField;
	TSet _s(tmp);
	return _s;
}

TSet TSet::operator~(void) // ����������
{
	TSet tmp(MaxPower);
	tmp.BitField = ~BitField;
	return tmp;
}


//  ���� �����
istream& operator>>(istream& istr, TSet& s) // ����
{
	int i = 0;
	while ((i >= 0) && (i < s.MaxPower))
	{
		istr >> i;
		if (i > s.GetMaxPower()) {
			continue;
		}
		s.InsElem(i);
	}
	return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // �����
{
	for (int i = 0; i < s.MaxPower; i++)
		if (s.BitField.GetBit(i))
			ostr << i << " ";
	return ostr;
}
