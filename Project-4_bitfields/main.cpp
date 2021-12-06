#include<iostream>
#include"tbitfield.h"
#include "tset.h"
using namespace std;

int main() {
	setlocale(NULL, "rus");
	int n, h, res, search;
	cout << "\n������� ������ ��� �: ";
	cin >> n;

	TBitField A(n), C(n);
	cin >> A;
	cout << A << endl;

	TSet SA(A), SC(C);
	cout << "A: " << SA;

	cout << "\n--------------";
	cout << "\n������� ������ ��� B: ";
	cin >> n;

	TBitField B(n);
	cin >> B;
	cout << B << endl;

	TSet SB(B);
	cout << "B: " << SB;


	cout << "\n\n_____������� ����______________";
	int forth1;
	do {
		cout << "\n������������\n";
		C = A;
		cout << "C:\t" << C;
		cout << "\n���������� ��� h = ";
		cin >> h;
		C.SetBit(h);
		cout << "\t" << C;
		//-------------------
		cout << "\n������� ��� h = ";
		cin >> h;
		C.ClrBit(h);
		cout << "\t" << C;
		//--------------------
		cout << "\n�������� ����� C (� - �� �����):";
		cout << C.GetLength();
		//--------------------
		cout << "\n #����������-������� ����� ����� /������ �������� ����� - 1 :";
		cin >> forth1;
		cout << "-----------------------";
	} while (forth1 == 1);

	cout << "\n_____���������________________";
	int forth2;
	do {
		cout << "\n������������\n";
		SC = SA;
		cout << "C:\t" << SC;
		cout << "\n�������� ������� � ��������o C: ";
		cin >> h;
		SC.InsElem(h);
		cout << "\t" << SC;
		cout << "\n������� ������� �� ��������� C: ";
		cin >> h;
		SC.DelElem(h);
		cout << "\t" << SC;
		cout << "\n��������� ������� �������� � ��������� C: ";
		cin >> search;
		cout << SA.IsMember(search);
		cout << "\n #����������-������� ����� ����� /������ �������� ����� - 1 :";
		cin >> forth2;
		cout << "-----------------------";
	} while (forth2 == 1);

	cout << "\n_____��������________________\n";
	cout << "A:\t" << A << endl;
	cout << "B:\t" << B << endl;
	cout << "_______________";
	cout << "\n���������\n";
	res = A == B;
	cout << res;
	cout << "\n_______________";
	cout << "\n������������\n";
	C = A;
	cout << C;
	cout << "\n_______________";
	cout << "\n�������� \"���\" \n";
	C = A | B;
	cout << C;
	cout << "\n_______________";
	cout << "\n�������� \" � \"\n";
	C = A & B;
	cout << C;
	cout << "\n_______________";
	cout << "\n��������� A\n";
	C = ~A;
	cout << "~A:\t" << C << endl;
	SC = ~SA;
	cout << "~A:\t" << SC << endl;
	cout << "_______________\n";
	cout << "A:\t" << SA << endl;
	cout << "B:\t" << SB << endl;
	cout << "\n___________________";
	cout << "\n�����������\n";
	SC = SA + SB;
	cout << "\t" << SC;
	cout << "\n___________________";
	cout << "\n�����������\n";
	SC = SA * SB;
	cout << "\t" << SC;

	cout << "\n_______________";
	int forth3;
	do {
		cout << "\n��������� �������� � ���������\n";
		int a1;
		cout << "C = A + ";
		cin >> a1;
		SC = SA + a1;
		cout << "C:\t" << SC;
		cout << "\n�������� �������� �� ���������\n";
		int a2;
		cout << "C = A - ";
		cin >> a2;
		SC = SA - a2;
		cout << "C:\t" << SC;
		cout << "\n #����������-������� ����� ����� /������ �������� ����� - 1 :";
		cin >> forth3;
		cout << "-----------------------";
	} while (forth3 == 1);
}
