#include <iostream>
#include "tbitfield.h"
using namespace std;

//private:
TBitField::TBitField(int len) : BitLen(len)
{
	MemLen = (len + 31) >> 5;
	//MemLen = BitLen / (sizeof(TELEM) * 8) + 1;
	pMem = new TELEM[MemLen];
	if (pMem != NULL)
		for (int i = 0; i < MemLen; i++) {
			pMem[i] = 0;
		}
}

TBitField::TBitField(const TBitField& bf)
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	if (pMem != NULL)
		for (int i = 0; i < MemLen; i++) {
			pMem[i] = bf.pMem[i];
		}
}

TBitField::~TBitField()
{
	delete[] pMem;
}

// методы реализации
int TBitField::GetMemIndex(const int n) const // индекс ћем дл€ бита n // номер €чейки котора€ int
{
	try {
		if ((n < 0) || (n > BitLen))
			throw exception("некоректно ввели");
		else
			return n >> 5;

	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

TELEM TBitField::GetMemMask(const int n) const // битова€ маска дл€ бита n
{
	try {
		if ((n < 0) || (n > BitLen))
			throw exception("некоректно ввели");
		else
		{
			return 1 << (n & 31);
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

// доступ к битам
void TBitField::SetBit(const int n) // установить бит
{
	try {
		if ((n < 0) || (n > BitLen))
			throw exception("некоректно ввели");
		else
		{
			int m = GetMemIndex(n);
			TELEM mask = GetMemMask(n);
			pMem[m] = (pMem[m] | mask);
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

void TBitField::ClrBit(const int n) // очистить бит
{

	try {
		if ((n < 0) || (n > BitLen))
			throw exception("некоректно ввели");
		else
		{
			int m = GetMemIndex(n);
			TELEM mask = GetMemMask(n);
			pMem[m] = (pMem[m] & ~mask);
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return (BitLen);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	try {
		if ((n < 0) || (n > BitLen))
			throw exception("некоректно ввели ");
		else
		{
			int m = GetMemIndex(n); // ищем €чейку
			TELEM mask = GetMemMask(n); // маска на эту €чейку
			int result = (mask & pMem[m]);
			if (result == 0)
				return(0);
			else
				return(1);
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

//операции 
int TBitField::operator==(const TBitField& bf) const // сравнение
{
	if (BitLen != bf.BitLen)
		return 0;
	else
	{
		for (int i = 0; i < BitLen; i++)
			if (GetBit(i) != bf.GetBit(i))
				return 0;
		return 1;
	}
}

TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++)
		pMem[i] = bf.pMem[i];
	return *this;
}

TBitField TBitField::operator|(const TBitField& bf) // операци€ "или"
{
	if (BitLen == bf.BitLen)
	{
		TBitField tmp(BitLen);
		for (int i = 0; i < BitLen; i++)
		{
			int tmpval = (GetBit(i) || bf.GetBit(i));
			if (tmpval == 0)
				tmp.ClrBit(i);
			else
				tmp.SetBit(i);
		}
		return tmp;
	}
	else
	{
		if (BitLen > bf.BitLen)
		{
			TBitField tmp(BitLen);
			for (int i = 0; i < bf.BitLen; i++)
			{
				int tmpval = (GetBit(i) || bf.GetBit(i));
				if (tmpval == 0)
					tmp.ClrBit(i);
				else
					tmp.SetBit(i);
			}
			for (int i = bf.BitLen; i < BitLen; i++)
				if (GetBit(i) == 1)
					tmp.SetBit(i);
				else
					tmp.ClrBit(i);
			return tmp;
		}
		else
		{
			TBitField tmp(bf.BitLen);
			for (int i = 0; i < BitLen; i++)
			{
				int tmpval = (GetBit(i) || bf.GetBit(i));
				if (tmpval == 0)
					tmp.ClrBit(i);
				else
					tmp.SetBit(i);
			}
			for (int i = BitLen; i < bf.BitLen; i++)
				if (bf.GetBit(i) == 1)
					tmp.SetBit(i);
				else
					tmp.ClrBit(i);
			return tmp;
		}
	}
}

TBitField TBitField::operator&(const TBitField& bf) // операци€ "и"
{
	if (BitLen == bf.BitLen)
	{
		TBitField tmp(BitLen);
		for (int i = 0; i < BitLen; i++)
		{
			int tmpval = (GetBit(i) && bf.GetBit(i));
			if (tmpval == 0)
				tmp.ClrBit(i);
			else
				tmp.SetBit(i);
		}
		return tmp;
	}
	else
	{
		if (BitLen > bf.BitLen)
		{
			TBitField tmp(BitLen);
			for (int i = 0; i < bf.BitLen; i++)
			{
				int tmpval = (GetBit(i) && bf.GetBit(i));
				if (tmpval == 0)
					tmp.ClrBit(i);
				else
					tmp.SetBit(i);
			}
			for (int i = bf.BitLen; i < BitLen; i++)
				tmp.ClrBit(i);
			return tmp;
		}
		else
		{
			TBitField tmp(bf.BitLen);
			for (int i = 0; i < BitLen; i++)
			{
				int tmpval = (GetBit(i) && bf.GetBit(i));
				if (tmpval == 0)
					tmp.ClrBit(i);
				else
					tmp.SetBit(i);
			}
			for (int i = BitLen; i < bf.BitLen; i++)
				tmp.ClrBit(i);
			return tmp;
		}
	}
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField tmp(BitLen);
	for (int i = 0; i < MemLen; i++)
		tmp.pMem[i] = ~pMem[i];
	return tmp;
}

//ввод и ввывод
istream& operator>>(istream& istr, TBitField& bf) // ввод
{
	int i = 0, h;
	while ((i >= 0) && (i < bf.BitLen))
	{
		istr >> i;
		if (i > bf.GetLength())
			continue;
		bf.SetBit(i);
	}
	return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
	for (int i = 0; i < bf.BitLen; i++)
		ostr << bf.GetBit(i);
	return ostr;
}
