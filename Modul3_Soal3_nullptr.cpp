#include <iostream>
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
    newNode->prev = nullptr;
    if ((*headRef) != nullptr) {
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
    newNode->next = nullptr;
    if ((*headRef) == nullptr) {
        newNode->prev = nullptr;
        (*headRef) = newNode;
        return;
    }
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

// fungsi untuk menghapus data dari tengah
void deleteMiddle(Node** headRef, int key) {
    if (*headRef == nullptr) {
        return;
    }
    Node* current = (*headRef);
    while (current != nullptr && current->data != key) {
        current = current->next;
    }
    if (current == nullptr) {
        return;
    }
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    else {
        *headRef = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    delete current;
}

// fungsi untuk menampilkan isi linked list
void displayList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// fungsi main untuk menu
int main() {
    Node* head = nullptr;
    int choice, newData, key;
    do {
        cout << "1. Tambahkan data dari depan" << endl;
        cout << "2. Tambahkan data dari belakang" << endl;
        cout << "3. Hapus data dari tengah" << endl;
        cout << "4. Tampilkan data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan Anda (1-5): ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Masukkan data yang ingin ditambahkan: ";
                cin >> newData;
                insertFront(&head, newData);
                break;
            case 2:
                cout << "Masukkan data yang ingin ditambahkan: ";
                cin >> newData;
                insertBack(&head, newData);
                break;
            case 3:
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> key;
                deleteMiddle(&head, key);
                break;
            case 4:
                cout << "Data dalam linked list: ";
                displayList(head);
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
            	cout <<" Invalid"<< endl;
            }
        }while(choice != 5);
    }
