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
        cout << akar->data <<" --> ";
        preOrder(akar->kiri);
        preOrder(akar->kanan);
    }
}

void inOrder(node *akar) {
    if (akar != NULL) {
        inOrder(akar->kiri);
        cout << akar->data <<" --> ";
        inOrder(akar->kanan);
    }
}

void postOrder(node *akar) {
    if (akar != NULL) {
        postOrder(akar->kiri);
        postOrder(akar->kanan);
        cout << akar->data <<" --> ";
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

int findMin(node *akar) {
    if (akar == NULL) {
        return -1; // jika pohon kosong
    }
    int nilaiMin = akar->data;
    if (akar->kiri != NULL) { // cek anak kiri
        int nilaiMinKiri = findMin(akar->kiri);
        if (nilaiMinKiri < nilaiMin) {
            nilaiMin = nilaiMinKiri;
        }
    }
    if (akar->kanan != NULL) { // cek anak kanan
        int nilaiMinKanan = findMin(akar->kanan);
        if (nilaiMinKanan < nilaiMin) {
            nilaiMin = nilaiMinKanan;
        }
    }
    return nilaiMin; // mengembalikan nilai data node terkecil
}


void binarytree(){
	cout <<"\n         3     "<< endl;
    cout <<"       /   \\     "<< endl;
    cout <<"      8     6  "<< endl;
    cout <<"       \\   /   "<< endl;
    cout <<"        9 1     "<< endl;
    cout <<"         \\     "<< endl;
    cout <<"          5    "<< endl;
    cout << endl;
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
    
    do {
    system("cls");
    cout <<" PROGRAM BY AIPP_PROJECT03"<< endl;
    cout <<" BE FUN AND STAY CODE :) \n\n"<< endl;
    cout <<" Berikut Tampilan Binary Tree : "<< endl;
    binarytree();
	cout <<"_____________________________"<< endl;
	cout <<"|       <[MAIN MENU]>       |"<< endl;
	cout <<"|===========================|"<< endl;
    cout <<"|[1] Pre-order Traversal    |"<< endl;
    cout <<"|[2] In-order Traversal     |"<< endl;
    cout <<"|[3] Post-order Traversal   |"<< endl;
    cout <<"|[4] Jumlah Node            |"<< endl;
    cout <<"|[5] Jumlah Elemen          |"<< endl;
    cout <<"|[6] Nilai Minimum          |"<< endl;
    cout <<"|[7] Keluar                 |"<< endl;
    cout <<"|===========================|"<< endl;
    cout <<"|Pilihan Anda: ";
        cin >> pilih;
    switch (pilih) {
    case 1:
    	system("cls");
    	binarytree();
        cout << " Hasil Pre-order Traversal : ";
        preOrder(akar);
        cout<<"NULL";
        cout << endl;
    break;
    case 2:
    	system("cls");
    	binarytree();
        cout << " Hasil In-order Traversal : ";
        inOrder(akar);
        cout<<"NULL";
        cout << endl;
    break;
    case 3:
    	system("cls");
    	binarytree();
        cout << " Hasil Post-order Traversal : ";
        postOrder(akar);
        cout<<"NULL";
        cout << endl;
    break;
    case 4:
    system("cls");
    binarytree();
    cout << " Jumlah Node : " << countNodes(akar) << endl;
    break;
    case 5:
    system("cls");
    binarytree();
    cout << " Jumlah Elemen : " << countElemen(akar) << endl;
    break;
    case 6:
    system("cls");
    binarytree();
    cout << " Nilai Minimum : " << findMin(akar) << endl;
    break;
    case 7:
    system("cls");
    cout << " Byeeee :)" << endl;
    cout << endl;
    cout << " A.Irwin Putra Pangesti A.K.A AIPP_PROJECT03" << endl;
    cout << " Tetap Semangat Dan Salam Koding!" << endl;
    cout << " Awokawokwkwkw" << endl;
    return 0;
    default:
    cout << " Pilihan tidak valid. Silakan coba lagi." << endl;
    }
        cout << " Apakah Anda ingin melanjutkan (y/n) ? ";
        cin >> ulang;
    }while (ulang == 'y' || ulang == 'Y');
        system("cls");
        cout << " Terima kasih telah menggunakan program ini :)" << endl;
        cout << endl;
        cout << " A.Irwin Putra Pangesti A.K.A AIPP_PROJECT03" << endl;
        cout << " Tetap Semangat Dan Salam Koding!" << endl;
        cout << " Awokawokwkwkw" << endl;
} 

