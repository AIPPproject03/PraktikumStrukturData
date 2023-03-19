#include <iostream>
#include <conio.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};
    Node* head = NULL;

void insertFront(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

void insertBack(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* lastNode = head;
        while (lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

void deleteFront(){
        if (head == NULL) {
            cout << " The List Is Empty" << endl;
            return;
        }
        cout <<" Successful"<< endl;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
void deleteBack(){
        if (head == NULL) {
            cout << " The List Is Empty" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* prevNode = head;
        Node* lastNode = head->next;
        while (lastNode->next != NULL) {
            prevNode = lastNode;
            lastNode = lastNode->next;
        }
        cout <<" Successful"<< endl;
        prevNode->next = NULL;
        delete lastNode;
    }

void display(){
        Node* currentNode = head;
        if (head == NULL) {
            cout << " The List Is Empty" << endl;
            return;
        }
        while (currentNode != NULL) {
            cout << currentNode->data <<" ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

int main(){
    int choice, data;
    // loop menu
    do {
    	system("cls");
    	cout <<" [= = = = = = = = = = = = =]"<< endl;
        cout <<" |    WITH SINGLE LINKED   |" << endl;
        cout <<" [ = = = = = = = = = = = = ]"<< endl;
        cout << "[1] Input Front" << endl;
        cout << "[2] Input Back" << endl;
        cout << "[3] Delete Front" << endl;
        cout << "[4] Delete Back" << endl;
        cout << "[5] Display" << endl;
        cout << "[6] Exit" << endl;
        cout << " Choose : ";
        cin >> choice;
        switch (choice) {
        case 1:
        	system("cls");
            cout << " Input Data : ";
            cin >> data;
            insertFront(data);
            break;
        case 2:
        	system("cls");
            cout << " Input Data : ";
            cin >> data;
            insertBack(data);
            break;
        case 3:
        	system("cls");
            deleteFront();
            break;
        case 4:
        	system("cls");
            deleteBack();
            break;
        case 5:
        	system("cls");
            display();
            break;
        case 6:
            break;
        default:
            cout << " Pilihan tidak valid" << endl;
    }getch();
} while (choice != 6);
}

