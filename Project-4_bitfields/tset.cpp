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

// доступ к битам----------------------------

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return MaxPower;
}

void TSet::InsElem(const int n) // включение элемента множества
{
	BitField.SetBit(n);
}

void TSet::DelElem(const int n) // исключение элемента множества
{
	BitField.ClrBit(n);
}

int TSet::IsMember(const int n) const // элемент множества
{
	if (BitField.GetBit(n) == 1)
		return 1;
	else
		return 0;
}


// теоретико-множественные операции----------------------
int TSet::operator==(const TSet& s) const // сравнение
{
	if ((MaxPower == s.MaxPower) && (BitField == s.BitField))
		return 1;
	else
		return 0;
}

TSet& TSet::operator=(const TSet& s) // присваивание
{
	BitField = s.BitField;
	MaxPower = s.MaxPower;
	return *this;
}

TSet TSet::operator+(const int n) // объединение с элементом
{
	TSet tmp(*this);
	tmp.BitField.SetBit(n);
	return tmp;
}

TSet TSet::operator-(const int n) // разность с элементом
{
	TSet tmp(*this);
	tmp.BitField.ClrBit(n);
	return (tmp);
}

TSet TSet::operator+(const TSet& s) // объединение
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


TSet TSet::operator*(const TSet& s) // пересечение
{
	TBitField tmp(MaxPower);
	tmp = BitField & s.BitField;
	TSet _s(tmp);
	return _s;
}

TSet TSet::operator~(void) // дополнение
{
	TSet tmp(MaxPower);
	tmp.BitField = ~BitField;
	return tmp;
}


//  ввод вывод
istream& operator>>(istream& istr, TSet& s) // ввод
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

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
	for (int i = 0; i < s.MaxPower; i++)
		if (s.BitField.GetBit(i))
			ostr << i << " ";
	return ostr;
}
