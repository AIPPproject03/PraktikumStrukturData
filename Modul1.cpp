#include <iostream>
#include <conio.h>
#define max 6
using namespace std;

/* 

			MADE BY AIPP_PROJECT03
			THIS PROGRAM IS COPYRIGHT
			PLEASE USE THIS FOR EDUCATIONAL
			" HAVE A GOOD LIFE AND SALAM CODING!!!"


**/


//------------------------------PAGE OF STRUCT---------------------------------//
struct DataMhs{
	int mhs = 0;
	string nim[max];
	string nama[max];
	string email[max];
}data;

//-----------------------------PAGE FIX FIBONACCI-----------------------------//
int* fibo(int n){
int* arr = new int[n];
    arr[0] = 1;
    arr[1] = 1;

for (int i = 2; i < n; i++){
    arr[i] = arr[i - 1] + arr[i - 2];
}
    return arr;
}

//------------------------------SOAL 1---------------------------------//
void input(){
	int x = 0;
	int i;
    cout <<" Berapa Banyak Data Yang Ingin Kamu Input : ";
	cin >> i;
	cin.ignore();
	do{
	cout <<" Data Ke-"<< x+1 << endl;
	cout <<" Masukan Nama  : ";
	getline(cin,data.nama[data.mhs]);
	cout <<" Masukan NIM   : ";
	getline(cin,data.nim[data.mhs]);
	cout <<" Masukan Email : ";
	getline(cin,data.email[data.mhs]);
	data.mhs++;
	x++;
}while (x < i);
}
 void display(){
 	int n;
 	for (n = 0; n <= data.mhs-1 ; n++){
 		cout << endl;
 		cout <<" "<< n+1 <<")============================"<< endl;
 		cout <<" Nama  : "<< data.nama[n] << endl;
 		cout <<" NIM   : "<< data.nim[n] << endl;
 		cout <<" Email : "<< data.email[n] << endl;
 		cout <<"==============================="<< endl;
	 }
 }

//------------------------------SOAL 2---------------------------------//
void fibo(){
    int num, *ptr;
    cout << "jumlah bilangan fibonacci : ";
    cin >> num;
    ptr = fibo(num);
    for (int i = 0; i < num; i++){
        cout <<" "<<ptr[i];
    }
}

int main(){
	int menu;
	do{
	system("cls");
	cout <<"========================================================"<< endl;	
	cout <<"|                  Program Modul 1                     |"<< endl;
	cout <<"|                  Array Of Struct                     |"<< endl;
	cout <<"+======================================================+"<< endl;
	cout <<"| 1) Program Masukan NIM, Nama Dan Email Mahasiswa     |"<< endl;
	cout <<"| 2) Program Perbaiki Code Fibonacci                   |"<< endl;
	cout <<"| 3) EXIT                                              |"<< endl;
	cout <<"|<><><><><><><><><><><><><><><><><><><><><><><><><><><>|"<< endl;
	cout <<" PILIH : ";
	cin >> menu;
	switch (menu){
		case 1 :
			int op1;
			do{
			system("cls");
			cout <<"=========================="<< endl;
			cout <<"| 1) Input Data          |"<< endl;
			cout <<"| 2) Display Data        |"<< endl;
			cout <<"| 3) Exit                |"<< endl;
			cout <<"|========================|"<< endl;
			cout <<" PILIH : ";
			cin >> op1;
			switch (op1){
				case 1:
				system("cls");
				input();
				break;
				case 2:
				system("cls");
				display();
				break;
				case 3:
				break;
				default:
				system("cls");
				cout <<" Invalid Command"<< endl;
			}getch();
		}while(op1 != 3);
		break;
		case 2 :
		system("cls");
		fibo();
		break;
		case 3 :
		break;
		default:
		system("cls");
		cout <<" Invalid Command"<< endl;
	}getch();		
	}while (menu != 3);	
}
