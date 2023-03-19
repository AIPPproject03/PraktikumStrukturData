#include <iostream>
#include <conio.h>
using namespace std;

struct Node{
	string nim;
	string nama;
	Node* next;
};

Node *head, *second, *fix;

void inputNamaNimHead(){
	head = new Node();
	cin.ignore();
	cout <<" Masukan Nama : ";
	getline(cin,head->nama);
	cout <<" Masukan NIM  : ";
	getline(cin,head->nim);
	head->next = NULL;
}

void inputNamaNimSecond(){
	second = new Node();
	cin.ignore();
	cout <<" Masukan Nama : ";
	getline(cin,second->nama);
	cout <<" Masukan NIM  : ";
	getline(cin,second->nim);
	second->next = NULL;
}

void display(){
	head->next = second;
	Node* fix = head;
	while(fix != NULL){
		cout <<" NAMA : "<< fix->nama << endl;
		cout <<" NIM  : "<< fix->nim << endl;
		cout << endl;
		fix = fix->next;
	}
}

int main(){
	int menu;
	do{
		system("cls");
		cout <<"[=====================]"<< endl;
		cout <<"|   With Non Circular |"<< endl;
		cout <<"[=====================]"<< endl;
		cout <<" [1] Input Data "<< endl;
		cout <<" [2] Tampilkan "<< endl;
		cout <<" [3] Exit "<< endl;
		cout <<" Choose : ";
		cin >> menu;
		switch(menu){
			case 1:
			system("cls");
			inputNamaNimHead();
			inputNamaNimSecond();
			break;
			case 2:
			system("cls");
			display();
			break;
			case 3:
			break;
			default:
			cout <<" Invalid Command"<< endl;
		}getch();
	}while(menu != 3);
}
