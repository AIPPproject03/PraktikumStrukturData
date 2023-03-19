#include <iostream>
#include <conio.h>
using namespace std;

struct node {
    int data;
    node *kiri;
    node *kanan;
};

node *akar = NULL;

void addNode(node **akar, int isi){
    if((*akar) == NULL){
        node *baru = new node;
        baru->data = isi;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*akar) = baru;
    }
} 

void preOrder(node *akar) {
    if (akar != NULL) {
        cout <<" "<< akar->data <<"  + ";
        preOrder(akar->kiri);
        preOrder(akar->kanan);
    }
}

void inOrder(node *akar) {
    if (akar != NULL) {
        inOrder(akar->kiri);
        cout <<" "<< akar->data <<"  + ";
        inOrder(akar->kanan);
    }
}

void postOrder(node *akar) {
    if (akar != NULL) {
        postOrder(akar->kiri);
        postOrder(akar->kanan);
        cout <<" "<< akar->data <<"  + ";
    }
}

int countNodes(node *akar) {
    if (akar == NULL) {
        return 0;
    } else {
        int jumlahKiri = countNodes(akar->kiri);
        int jumlahKanan = countNodes(akar->kanan);
        return jumlahKiri + jumlahKanan + 1;
    }
}

int countElemen(node *akar){
    if(akar == NULL){
        return 0;
    } else {
        int hitungkiri = countElemen(akar->kiri);
        int hitungkanan = countElemen(akar->kanan);
        return hitungkiri + hitungkanan + akar->data;
    }    
}


int main() {
	int angka;
	int pilih;
	char ulang;
    // BAGIAN AKAR //
    addNode(&akar, angka = 3);
    // LEVEL 1 //
    addNode(&akar->kanan, angka = 6);
    addNode(&akar->kiri, angka = 8);
    // LEVEL 2 //
    addNode(&akar->kanan->kiri, angka = 1);
    addNode(&akar->kiri->kanan, angka = 9);
    // LEVEL 3 //
    addNode(&akar->kiri->kanan->kanan, angka = 5);
    cout <<" PROGRAM BY AIPP_PROJECT03"<< endl;
    cout <<" BE FUN AND STAY CODE :) \n\n"<< endl;
    cout <<" Berikut Tampilan Binary Tree : "<< endl;
    cout <<"\n         3     "<< endl;
    cout <<"       /   \\     "<< endl;
    cout <<"      8     6  "<< endl;
    cout <<"       \\   /   "<< endl;
    cout <<"        9 1     "<< endl;
    cout <<"         \\     "<< endl;
    cout <<"          5    "<< endl;
    cout << endl;
    cout <<" Jumlah Node Pada Pohon : "<< countNodes(akar) << endl;
    do{
    cout <<"\n Ingin Melihat Hasil Perhitungan Secara ? "<< endl;
    cout <<" [1] preOrder"<< endl;
    cout <<" [2] inOrder"<< endl;
    cout <<" [3] postOrder"<< endl;
    cout <<" Choose : ";
    cin >> pilih;
    switch (pilih){
    	case 1:
    	preOrder(akar);
    	cout<<"NULL = ";
    	cout << countElemen(akar) << endl;
    	break;
    	case 2:
    	inOrder(akar);
    	cout<<"NULL = ";
    	cout << countElemen(akar) << endl;
    	break;
    	case 3:
    	postOrder(akar);
    	cout<<"NULL = ";
    	cout << countElemen(akar) << endl;
    	break;
    	default:
    	cout <<" Invalid"<< endl;
	}getch();
	cout <<" Mau melihat lagi (y/n) ? ";
	cin >> ulang;
}while(ulang != 'n' && ulang != 'N');
}

