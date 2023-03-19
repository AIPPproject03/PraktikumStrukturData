#include <iostream>
#include <conio.h>
#define max 4
using namespace std;

struct ListMusik{
	int awal = 0;
	string judul[max];
	string penyanyi[max];
}list;

/*  PENGKONDISIAN TERTENTU UNTUK MENENTUKAN EMPTY ATAU FULL **/
bool isFull(){
	if (list.awal >= max){
		return true;
	}
	else{
		return false;
	}
}
bool isEmpty(){
	if (list.awal == 0){
		return true;
	}
	else{
		return false;
	}
}

/* BAGIAN FUNCTION/PROCEDURE **/
void input(){
	if(!isFull()){
		cout <<" Judul Lagu    : ";
		cin.ignore();
		getline(cin,list.judul[list.awal]);
		cout <<" Nama Penyanyi : ";
		getline(cin,list.penyanyi[list.awal]);
		list.awal++;
	}
	else{
		cout <<" The List Is Full"<< endl;
	}
}

void dequeue(){
	if(!isEmpty()){
		cout <<" Kamu Telah Mengambil Lagu Berjudul ("<< list.judul[0] <<") Dengan Nama Penyanyi ("<< list.penyanyi[0] <<") !"<< endl;
		for(int i = 0; i < list.awal; i++){
			list.judul[i] = list.judul[i+1];
			list.penyanyi[i] = list.penyanyi[i+1];
		}
		list.awal--;
	}
	else{
		cout <<" The List Is Empty"<< endl;
	}
}

void pop(){
	if(!isEmpty()){
			cout <<" Kamu Telah Mengambil Lagu Berjudul ("<< list.judul[list.awal-1] <<") Dengan Nama Penyanyi ("<< list.penyanyi[list.awal-1] <<") !"<< endl;
			list.awal--;
	}
	else{
		cout <<" The List Is Empty"<< endl;
	}
}

void display(){
	if(!isEmpty()){
		for (int i = 0; i < list.awal; i++){
			cout <<"List["<< i+1 <<"]_______________________________"<< endl;
			cout <<"    | Judul Lagu : "<< list.judul[i] << endl;
			cout <<"    | Penyanyi   : "<< list.penyanyi[i] << endl;
			cout <<"    |_________________________________"<< endl;
		}
	}
	else{
		cout <<" The List Is Empty"<< endl;
	}
}

void clear(){
		cout <<" All The List Has Been Cleared"<< endl;
		list.awal = 0;
}

int main(){
	int menu;
	do{
		system("cls");
		display();
		cout <<"|==================================|"<< endl;
		cout <<"|      -((MENU LIST MUSIK))-       |"<< endl;
		cout <<"|==================================|"<< endl;
		cout <<"| 1) Input Musik                   |"<< endl;
		cout <<"| 2) Ambil Musik Paling Pertama    |"<< endl;
		cout <<"| 3) Ambil Musik Paling Akhir      |"<< endl;
		cout <<"| 4) Clear                         |"<< endl;
		cout <<"| 5) Exit                          |"<< endl;
		cout <<"[][][][][][][][][][][][][][][][][][]"<< endl;
		cout <<"| Pilih : ";
		cin >> menu;
		switch(menu){
			case 1:
			system("cls");
			input();
			break;
			case 2:
			system("cls");
			dequeue();
			break;
			case 3:
			system("cls");
			pop();
			break;
			case 4:
			system("cls");
			clear();
			break;
			case 5:
			break;
			default:
			cout <<" Invalid Instruction"<< endl;
		}getch();
	}while(menu != 5);
}
