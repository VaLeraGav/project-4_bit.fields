#include<iostream>
#include"tbitfield.h"
#include "tset.h"
using namespace std;

int main() {
	setlocale(NULL, "rus");
	int n, h, res, search;
	cout << "\nВведите размер для А: ";
	cin >> n;

	TBitField A(n), C(n);
	cin >> A;
	cout << A << endl;

	TSet SA(A), SC(C);
	cout << "A: " << SA;

	cout << "\n--------------";
	cout << "\nВведите размер для B: ";
	cin >> n;

	TBitField B(n);
	cin >> B;
	cout << B << endl;

	TSet SB(B);
	cout << "B: " << SB;


	cout << "\n\n_____битовые поля______________";
	int forth1;
	do {
		cout << "\nприсваивание\n";
		C = A;
		cout << "C:\t" << C;
		cout << "\nустановить бит h = ";
		cin >> h;
		C.SetBit(h);
		cout << "\t" << C;
		//-------------------
		cout << "\nудалить бит h = ";
		cin >> h;
		C.ClrBit(h);
		cout << "\t" << C;
		//--------------------
		cout << "\nполучить длину C (к - во битов):";
		cout << C.GetLength();
		//--------------------
		cout << "\n #Продолжить-нажмите любую цифру /начать операцию снова - 1 :";
		cin >> forth1;
		cout << "-----------------------";
	} while (forth1 == 1);

	cout << "\n_____множество________________";
	int forth2;
	do {
		cout << "\nприсваивание\n";
		SC = SA;
		cout << "C:\t" << SC;
		cout << "\nвключить элемент в множествo C: ";
		cin >> h;
		SC.InsElem(h);
		cout << "\t" << SC;
		cout << "\nудалить элемент из множества C: ";
		cin >> h;
		SC.DelElem(h);
		cout << "\t" << SC;
		cout << "\nпроверить наличие элемента в множестве C: ";
		cin >> search;
		cout << SA.IsMember(search);
		cout << "\n #Продолжить-нажмите любую цифру /начать операцию снова - 1 :";
		cin >> forth2;
		cout << "-----------------------";
	} while (forth2 == 1);

	cout << "\n_____операции________________\n";
	cout << "A:\t" << A << endl;
	cout << "B:\t" << B << endl;
	cout << "_______________";
	cout << "\nсравнение\n";
	res = A == B;
	cout << res;
	cout << "\n_______________";
	cout << "\nприсваивание\n";
	C = A;
	cout << C;
	cout << "\n_______________";
	cout << "\nоперация \"или\" \n";
	C = A | B;
	cout << C;
	cout << "\n_______________";
	cout << "\nоперация \" и \"\n";
	C = A & B;
	cout << C;
	cout << "\n_______________";
	cout << "\nотрицание A\n";
	C = ~A;
	cout << "~A:\t" << C << endl;
	SC = ~SA;
	cout << "~A:\t" << SC << endl;
	cout << "_______________\n";
	cout << "A:\t" << SA << endl;
	cout << "B:\t" << SB << endl;
	cout << "\n___________________";
	cout << "\nобъединение\n";
	SC = SA + SB;
	cout << "\t" << SC;
	cout << "\n___________________";
	cout << "\nпересечение\n";
	SC = SA * SB;
	cout << "\t" << SC;

	cout << "\n_______________";
	int forth3;
	do {
		cout << "\nвключение элемента в множество\n";
		int a1;
		cout << "C = A + ";
		cin >> a1;
		SC = SA + a1;
		cout << "C:\t" << SC;
		cout << "\nудаление элемента из множества\n";
		int a2;
		cout << "C = A - ";
		cin >> a2;
		SC = SA - a2;
		cout << "C:\t" << SC;
		cout << "\n #Продолжить-нажмите любую цифру /начать операцию снова - 1 :";
		cin >> forth3;
		cout << "-----------------------";
	} while (forth3 == 1);
}
