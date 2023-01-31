#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <stdlib.h>

//������� ����� ��������� ����������.
//������������� ����������� ������ � ������������ ������ ����, ������
//����� �� ������ - ���� ��������(��������, �� ������ ��� �� ���� �������), ���������� ���� � ����������,
//�������� ���� �� ���, ���������� ���� �� ������ �����.
//�������� ���������, ��������������� ������ � ���� �������.
//��������� ������ ��������� ����, ����������� ����������� �������� ���� ������� ������.

using namespace std;

class book
{
public:
	book(string title = "Title", string autor = "Autor", int year = 0);
	string getAutor() { return autor; }
	string getTitle() { return title; }
	int getYear() { return year; }
	void setAutor(string autor) { this->autor = autor; }
	void setTitle(string title) { this->title = title; }
	void setYear(int year) { this->year = year; }
	void printBook() { cout << title << ' ' << autor << ' ' << year << endl; }
private:
	string title;	//�������� �����
	string autor;	//����� �����
	int year;	//��� �������
};
book::book(string title, string autor, int year) {
	this->title = title;
	this->autor = autor;
	this->year = year;
}

//���������� ��� ���������� �� ����
bool comYear(book a, book b) {
	return a.getYear() < b.getYear();
}
//���������� ��� ���������� �� ��������
bool comTitle(book a, book b) {
	return a.getTitle() < b.getTitle();
}
//���������� ��� ���������� �� ������
bool comAutor(book a, book b) {
	return a.getAutor() < b.getAutor();
}
class library
{
public:
	library(vector<book>a = {})  { data = a; } 
	library(const library& obj) { data = obj.data; }
	void printLibrary();
	void addBook(book a) { data.push_back(a); }
	void delBook(int i) { data.erase(data.begin()+i-1); }
	void modifyYear(int i, int year) { data[i-1].setYear(year); }
	void modifyTitle(int i, string title) { data[i-1].setTitle(title); }
	void modifyAutor(int i, string autor) { data[i-1].setAutor(autor); }
	void sortYear();
	void sortTitle();
	void sortAutor();
	void findYear(int year);
	void findTitle(string title);
	void findAutor(string autor);
	~library() { data.clear(); }
private:
	vector <book> data;
};
void library::sortYear() {
	sort(data.begin(), data.end(), comYear);
}
void library::sortTitle() {
	sort(data.begin(), data.end(), comTitle);
}
void library::sortAutor() {
	sort(data.begin(), data.end(), comAutor);
}
void library::printLibrary() {
	for (int i = 0; i < data.size(); i++) {
		cout << i + 1 << ' ';
		data[i].printBook();
		
	}
}
void library::findYear(int year) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i].getYear() == year) {
			cout << i + 1 << ' ';
			 data[i].printBook();
		}
	}
	cout << "����� �� �������" << endl;
}
void library::findTitle(string title) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i].getTitle() == title) {
			cout << i + 1 << ' ';
			data[i].printBook();
		}
	}
	cout << "����� �� �������" << endl;
}
void library::findAutor(string autor) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i].getAutor() == autor) {
			cout << i + 1 << ' ';
			data[i].printBook();
		}
	}
	cout << "����� �� �������" << endl;
}

class menu
{
public:
	menu() { printMenu(); }
	void printMenu();
private:
	int comand = 0;
	library LB;
};

void menu::printMenu() {
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�������� ����������" << endl;
	cout << "������� ����� �������, ������� �� ������ �������:" << endl;
	cout << "1-������� ��� ����������" << endl;
	cout << "2-�������� �����" << endl;
	cout << "3-������� ����� ��� �������" << endl;
	cout << "4-������������� ����������" << endl;
	cout << "5-����� �����" << endl;
	cout << "6-������� ����������" << endl;
	cin >> comand;
	switch (comand)
	{
	case 1: { LB.printLibrary(); system("pause"); break; }
	case 2: { 
		cout << "������� ����� � �������(������ \"������\" ������������ \"_\")\n��������\t�����\t��� �������" << endl;
		string title, autor;
		int year;
		cin >> title >> autor >> year;
		book BK(title, autor, year);
		LB.addBook(BK);
		break;
	}
	case 3: {int number; cin >> number; LB.delBook(number); break; }
	case 4: {
		cout << "����������� ��" << endl;
		cout << "1-��������" << endl;
		cout << "2-������" << endl;
		cout << "3-���� �������" << endl;
		cin >> comand;
		switch (comand)
		{
		case 1: {LB.sortTitle(); break; }
		case 2: {LB.sortAutor(); break; }
		case 3: {LB.sortYear(); break; }
		default:
			cout << "������� �� �������" << endl;
			break;
		}
		break;
	}
	case 5: {
		cout << "������ ��" << endl;
		cout << "1-��������" << endl;
		cout << "2-������" << endl;
		cout << "3-���� �������" << endl;
		cin >> comand;
		switch (comand)
		{
		case 1: {
			string title;
			cin >> title;
			LB.findTitle(title);
			system("pause");
			break;
		}
		case 2: {
			string autor;
			cin >> autor;
			LB.findAutor(autor);
			system("pause");
			break;
		}
		case 3: {
			int year;
			cin >> year;
			LB.findYear(year);
			system("pause");
			break;
		}
		default:
			cout << "������� �� �������" << endl;
			system("pause");
			break;
		}
		break;
	}
	case 6: {cout << "�� ��������" << endl; system("pause"); exit(0); break; }
	default:
		cout << "������� �� �������" << endl;
		break;
	}
};

int main() {
	menu MN;
	while (1) {
		MN.printMenu();
	}
	return 0;
}
