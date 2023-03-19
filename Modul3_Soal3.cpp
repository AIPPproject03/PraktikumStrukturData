#include <iostream>
#include <conio.h>
using namespace std;

// deklarasi struktur node
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// fungsi untuk menambahkan data dari depan
void insertFront(Node** headRef, int newData) {
    // alokasi node baru
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = (*headRef);
    newNode->prev = NULL;
    if ((*headRef) != NULL) {
        (*headRef)->prev = newNode;
    }
    (*headRef) = newNode;
}

// fungsi untuk menambahkan data dari belakang
void insertBack(Node** headRef, int newData) {
    // alokasi node baru
    Node* newNode = new Node;
    Node* lastNode = (*headRef);
    newNode->data = newData;
    newNode->next = NULL;
    if ((*headRef) == NULL) {
        newNode->prev = NULL;
        (*headRef) = newNode;
        return;
    }
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

// fungsi untuk menghapus data dari tengah
void deleteMiddle(Node** headRef, int key) {
    if (*headRef == NULL) {
    	cout <<" Data Kosong"<< endl;
        return;
    }
    Node* current = (*headRef);
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL) {
    	cout <<" Elemen Tidak Ditemukan"<< endl;
        return;
        
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    else {
        *headRef = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    delete current;
}

// fungsi untuk menampilkan isi linked list
void displayList(Node* node) {
    while (node != NULL) {
        cout <<" "<< node->data;
        node = node->next;
    }
    cout << endl;
}

// fungsi main untuk menu
int main() {
    Node* head = NULL;
    int choice, newData, key;
    do {
    	system("cls");
    	displayList(head);
    	cout <<"=-=-=-=-=-=[DOUBLE LINKED LIST]-=-=-=-=-=-="<< endl;
        cout << "1. Tambahkan data dari depan" << endl;
        cout << "2. Tambahkan data dari belakang" << endl;
        cout << "3. Hapus data dari tengah" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan Anda (1-4): ";
        cin >> choice;
        switch (choice) {
            case 1:
            	system("cls");
                cout << "Masukkan data yang ingin ditambahkan: ";
                cin >> newData;
                insertFront(&head, newData);
                break;
            case 2:
            	system("cls");
                cout << "Masukkan data yang ingin ditambahkan: ";
                cin >> newData;
                insertBack(&head, newData);
                break;
            case 3:
            	system("cls");
            	displayList(head);
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> key;
                deleteMiddle(&head, key);
                break;
            case 4:
            	system("cls");
                cout << "Terima kasih!" << endl;
                break;
            default:
            	cout <<" Invalid"<< endl;
            }getch();
        }while(choice != 4);
    }
