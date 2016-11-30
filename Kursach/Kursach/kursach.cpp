#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <fstream>
#include <io.h>
#include <string>
#include "Authorization.h"

using namespace std;

/*���������� ��������� ������� ������ �� ���������� ������
 *�������� � ���������� ������ ����������� �������� ����� ��������� ���: �.�.� ����������;
 *���; �����; ���������� ����, ���������� �� �������; ������ �� ���� ����.
 *
 *�������������� �������: ��� ������ � ���� � ������� ������ �����������
 * � ��������� ������ �� ���������� ������ ��� ������� �� ���. ������� ����� �����
 * ������ �� ��������� ������ �� ������������ �����. �,� �������� � ����������.
 * 
 * ����� ��� ���� ��������� �������: ����������� ����������� �� ����� � �������(��� �����������!),
 * ���������� �������������� � ���������� ������������, ��� ������� ��� ���� ������, ��� ������� ��� ���� ����������.
 */
FILE *fl;
typedef struct
{
	char marka[50];
	unsigned char date[10];
	unsigned char check;
	//char tr = 
} TStudent;
TStudent stud[300]; // ������ ��������
char name[20]; // ��� �����
int nst = 0; // ����� ��������� ��������
int Menu(); // �������� ����

void Newf(); // �������� ������ �����
void Spisok(); // ������������ �����
void Opf(); // �������� �����
void Resc(); // ����� ���������� �� �����
void Resf(); // ����� ���������� � ����

void beginMenu();
string login;
string password;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	beginMenu();
	do
	{
		if (Authorization()){
			cout << "\nOK!\n";
			system("pause");
			system("cls");
			//Menu();
			break;
		}
		cout << "\nError! Return please!\n";
		system("pause");
		system("cls");
		beginMenu();
		
		
	} while (true);
	while (true)
	{
		switch (Menu())
		{
			//case 1: Nnf(); break;
		case 1: Newf(); break;
		case 2: Spisok(); break;
		case 3: Opf(); break;
		case 4: Resc(); break;
		case 5: Resf(); break;
		case 6: return 0;
		default: puts("Viberite pravilno!");
		}
		system("pause");
		system("cls"); // ������� ������
	}
}

void beginMenu()
{
	printf("%-15s%-8s%-7i", "������ �.�.", "������", 680961);
	cout << "\n\n��������� ������� ������ �� ���������� ������" << endl;
	cout << "-------------------------------------------------\n" << endl;
}

int Menu() // ����
{
	cout << "����:\n" << endl;
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "1.", "�������� ������ �����", '|','\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "2.", "���������� ��", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "3.", "�������� �� ���������� ������", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "4.", "������� ���������", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "5.", "�������� � ����", '|', '\n');
	printf("%-3c%-7s%-35s%-1c%-1c", '|', "6.", "�����", '|', '\n');
	cout << "��� �����: " << endl;
	int i;
	cin >> i; // ���� ���������� ������ ����
	return i;
}

void Spisok() // ���� ������ � �����
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		exit(1);
	}
	cout << "Vvedite chislo TV" << endl;
	cin >> nst;
	for (int i = 0; i<nst; i++)
	{
		cout << "Vvedite Marku: ";
		cin >> stud[i].marka;
		cout << "Vvedite date: ";
		cin >> stud[i].date;
		cout << "Vvedite vipolnen ili net: ";
		cin >> stud[i].check;
		fwrite(&stud[i], sizeof(TStudent), 1, fl);
	}
	fclose(fl);
}

void Newf() // �������� ������ �����
{
	cout << "������� ��� �����" << endl;
	cin >> name;
	if ((fl = fopen(name, "wb")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		exit(1);
	}
	cout << "OK" << endl;
	fclose(fl);
}

void Opf() // �������� ��������� �����
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		exit(1);
	}
	nst = 0;
	TStudent std;
	while (true)
	{
		int nwrt = fread(&std, sizeof(TStudent), 1, fl);
		if (nwrt != 1) break;
		stud[nst] = std;
		printf("%-3c%-30s%-20p%-35hhu%-1c%-1c", '|', stud[nst].marka, stud[nst].date, stud[nst].check, '|', '\n');
		cout << stud[nst].marka << " " << stud[nst].date<< " " << stud[nst].check << endl;
		nst++;
	}
	fclose(fl);
}
void Resc() // ����� ���������� �� �����
{
	for (int i = 0; i < nst; i++)
		if (stud[i].check == '0')
			cout << stud[i].marka << endl;
}
void Resf() // ����� ���������� � ��������� ����
{
	char namet[30];
	FILE *ft;
	cout << "������� ��� �����, ����������" << endl;
	cin >> namet;
	if ((ft = fopen(namet, "w")) == NULL)
	{
		cout << "������ ��� ��������" << endl;
		exit(1);
	}
	char s[80];
	for (int i = 0; i < nst; i++)
		if (stud[i].check == '0')
		{
			strcpy(s, stud[i].marka);
			strcat(s, "\n"); // ���������� ����������� �����
			fputs(s, ft);
		}
	fclose(ft);
}