#include <iostream>
#include <conio.h>
using namespace std;

/*==========================================================================|
|																		    |
|    PROJECT RESPONSI STRUKTUR DATA                                         |
|    BY    :  AIPPproject03                                                 |
|    NAME  :  A.Irwin Putra Pangesti                                        |
|    NIM   : 223020503162                                                   |
|                                                                           |
|    )> Program Pengelolaan Data Jenis-Jenis Game                           |
|    )> FIFO & LIFO                                                         |
|    )> Linked List  : Double                                               |
|    )> Sorting      : Bubble And Selection (Asc & Desc)                    |
|    )> Searching    : Sequential Search                                    |
|    )> Main Menu    : Switch Case by Int                                   |
|                                                                           |
|===========================================================================|*/

//================= (BAGIAN STRUCT PENYIMPANAN DATA GAME) ====================//
struct Game{
	string name;
	string genre;
	int year;
	float rating;
};
struct Node{
	Game data;
	Node* prev;
	Node* next;
};
Node* head = NULL;
Node* tail = NULL;

//================= (PROCEDURE/FUNCTION UNTUK INSTRUKSI JALANNYA PROGRAM) ====================//
void addGame(){ //-------------------( MENAMBAH GAME )---------------------//
	Game newGame; // Inisialisasi Data Game Menjadi New Game Karena Ingin Menambahkan Game Baru 
	cout << " Game Name          : ";
	cin.ignore();
	getline(cin, newGame.name);
	cout << " Genre              : ";
	getline(cin, newGame.genre);
	cout << " Release Year       : ";
	cin >> newGame.year;
	cout << " Rating (out of 10) : ";
	cin >> newGame.rating;

	Node* newNode = new Node;
	newNode->data = newGame;
	newNode->next = NULL;

	if (head == NULL){
		head = newNode;
		tail = newNode;
		newNode->prev = NULL;
	} else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	cout << " New Game Added Successful! " << endl;
}
void delGame(){ //-------------------( MENGHAPUS GAME )---------------------//
	if (head == NULL){
		cout << " The Game List Is Empty!" << endl;
		return;
	}

	string gameName;
	cout << " Enter The Name Of The Game You Want To Delete : ";
	cin.ignore();
	getline(cin, gameName);

	Node* current = head;
	while (current != NULL){
		if (current->data.name == gameName){
			if (current == head && current == tail){
				head = NULL;
				tail = NULL;
			} else if (current == head){
				head = head->next;
				head->prev = NULL;
			} else if (current == tail){
				tail = tail->prev;
				tail->next = NULL;
			} else {
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			delete current;
			cout << " Game Deleted!" << endl;
			return;
		}
		current = current->next;
	}
	cout << " Game Not Found!" << endl;
}
void editGame(){ //-------------------( MENGEDIT GAME )---------------------//
	if (head == NULL){
		cout << " The List Is Empty!" << endl;
		return;
	}

	string gameName;
	cout << " Enter The Name Of The Game You Want To Edit : ";
	cin.ignore();
	getline(cin, gameName);

	Node* current = head;
	while (current != NULL){
		if (current->data.name == gameName){
			cout << " New Game Name          : ";
			getline(cin, current->data.name);
			cout << " New Genre              : ";
			getline(cin, current->data.genre);
			cout << " New Release Year       : ";
			cin >> current->data.year;
			cout << " New Rating (out of 10) : ";
			cin >> current->data.rating;
			cout << " Game Has Been Edited!" << endl;
			return;
		}
		current = current->next;
	}
	cout << " Game Not Found!" << endl;
}
void showGame(){ //-------------------( MELIHAT SEMUA GAME YANG ADA )----------------------//
    if (head == NULL){
        cout << " The Game List Is Empty!" << endl;
        return;
    } else {
        Node* current = head;
        cout << "+===========================================================+"<< endl;
        cout << "| No. |       Name      |    Genre   |    Year    |  Rating |"<< endl;
        cout << "+===========================================================+"<< endl;

        int counter = 1;
        while(current != NULL){
            printf("| %-3d | %-15s | %-10s |    %-7d |  %-5.2f  |\n", counter, current->data.name.c_str(), current->data.genre.c_str(), current->data.year, current->data.rating);
            current = current->next;
            counter++;
        }
        cout << "+===========================================================+\n";
    }
}


//================= (BAGIAN SORTING BUBBLE DAN SELECTION) ====================//

// Procedure untuk sorting data menggunakan algoritma Bubble Sort
void bubbleSortName(bool Asc_Dsc){
    if (head == NULL){
        cout << " The Game List Is Empty!" << endl;
        return;
    }

    Node *temp1, *temp2;
    Game tempData;
    temp1 = head;

    while (temp1 != NULL){
        temp2 = temp1->next;
        while (temp2 != NULL){
            if (Asc_Dsc){
                if (temp1->data.name > temp2->data.name){ // Kondisi True Untuk Ascending
                    tempData = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = tempData;
                }
            } else {
                if (temp1->data.name < temp2->data.name){ // Kondisi False Untuk Descending
                    tempData = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = tempData;
                }
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}
void bubbleSortYear(bool Asc_Dsc){
    if (head == NULL){
        cout << " The Game List Is Empty!" << endl;
        return;
    }

    Node *temp1, *temp2;
    Game tempData;
    temp1 = head;

    while (temp1 != NULL){
        temp2 = temp1->next;
        while (temp2 != NULL){
            if (Asc_Dsc){
                if (temp1->data.year > temp2->data.year){ // Kondisi True Untuk Ascending
                    tempData = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = tempData;
                }
            } else {
                if (temp1->data.year < temp2->data.year){ // Kondisi False Untuk Descending
                    tempData = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = tempData;
                }
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}
void bubbleSortRating(bool Asc_Dsc){
    if (head == NULL){
        cout << " The Game List Is Empty!" << endl;
        return;
    }

    Node *temp1, *temp2;
    Game tempData;
    temp1 = head;

    while (temp1 != NULL){
        temp2 = temp1->next;
        while (temp2 != NULL){
            if (Asc_Dsc){
                if (temp1->data.rating > temp2->data.rating){ // Kondisi True Untuk Ascending
                    tempData = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = tempData;
                }
            } else {
                if (temp1->data.rating < temp2->data.rating){ // Kondisi False Untuk Descending
                    tempData = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = tempData;
                }
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}
// Procedure untuk sorting data menggunakan algoritma Selection Search
void selectionSortName(bool Asc_Dsc){
    if (head == NULL){
        cout << " The Game List Is Empty!" << endl;
        return;
    }

    Node *temp1, *temp2, *minNode;
    Game tempData;

    temp1 = head;
    while (temp1 != NULL){
        minNode = temp1;
        temp2 = temp1->next;
        while (temp2 != NULL){
            if ((Asc_Dsc && temp2->data.name < minNode->data.name) || (!Asc_Dsc && temp2->data.name > minNode->data.name)){
                minNode = temp2;
            }
            temp2 = temp2->next;
        }
        if (minNode != temp1){
            tempData = temp1->data;
            temp1->data = minNode->data;
            minNode->data = tempData;
        }
        temp1 = temp1->next;
    }
}
void selectionSortYear(bool Asc_Dsc){
    if (head == NULL){
        cout << " The Game List Is Empty!" << endl;
        return;
    }

    Node *temp1, *temp2, *minNode;
    Game tempData;

    temp1 = head;
    while (temp1 != NULL){
        minNode = temp1;
        temp2 = temp1->next;
        while (temp2 != NULL){
            if ((Asc_Dsc && temp2->data.year < minNode->data.year) || (!Asc_Dsc && temp2->data.year > minNode->data.year)){
                minNode = temp2;
            }
            temp2 = temp2->next;
        }
        if (minNode != temp1){
            tempData = temp1->data;
            temp1->data = minNode->data;
            minNode->data = tempData;
        }
        temp1 = temp1->next;
    }
}
void selectionSortRating(bool Asc_Dsc){
    if (head == NULL){
        cout << " The Game List Is Empty!" << endl;
        return;
    }

    Node *temp1, *temp2, *minNode;
    Game tempData;

    temp1 = head;
    while (temp1 != NULL){
        minNode = temp1;
        temp2 = temp1->next;
        while (temp2 != NULL){
            if ((Asc_Dsc && temp2->data.rating < minNode->data.rating) || (!Asc_Dsc && temp2->data.rating > minNode->data.rating)){
                minNode = temp2;
            }
            temp2 = temp2->next;
        }
        if (minNode != temp1){
            tempData = temp1->data;
            temp1->data = minNode->data;
            minNode->data = tempData;
        }
        temp1 = temp1->next;
    }
}


//================= (BAGIAN FIFO DAN LIFO) ====================//
void dequeue(){
    if (head == NULL){
        cout << " The Game List Is Empty!" << endl;
        return;
    }
    Node* current = head; // FIFO Itu Menunjuk Pada Elemen Pertama Pada Node, Jadi Menggunakan Head
    head = head->next;
    if (head == NULL){
        tail = NULL;
    } else {
        head->prev = NULL;
    }
    cout << " Game : (" << current->data.name << ") Has Been Deleted!" << endl;
    delete current;
}
void pop(){
    if (head == NULL){
        cout << " The Game List Is Empty!" << endl;
        return;
    }
    Node* current = tail; // LIFO Itu Menunjuk Pada Elemen Terakhir Pada Node, Jadi Menggunakan Tail
    tail = current->prev;
    if (tail == NULL){
        head = NULL;
    } else {
        tail->next = NULL;
    }
    cout << " Game : (" << current->data.name << ") Has Been Deleted!" << endl;
    delete current;
}

//================= (BAGIAN SEARCHING DATA DENGAN SEQUENTIAL SEARCH) ====================//
void searchName() {
    if (head == NULL) {
        cout << " The Game List Is Empty!" << endl;
        return;
    }
    string searchName;
    bool found = false;
    
    cin.ignore();
    cout << " Enter The Name Of The Game You Are Looking For : ";
    getline(cin,searchName);

    Node* current = head;
    while (current != NULL) {
        if (current->data.name == searchName) {
        	cout <<"|=============================================|"<< endl;
            cout <<"|Name   : "<< current->data.name << endl;
            cout <<"|Genre  : "<< current->data.genre << endl;
            cout <<"|Year   : "<< current->data.year << endl;
            cout <<"|Rating : "<< current->data.rating << endl;
            cout <<"|=============================================|"<< endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << " No Games Found With The Given Name." << endl;
    }
}
void searchGenre() {
    if (head == NULL) {
        cout << " The Game List Is Empty!" << endl;
        return;
    }
    string searchGenre;
    bool found = false;
    
    cin.ignore();
    cout << " Enter The Genre Of The Game You Are Looking For : ";
    getline(cin,searchGenre);

    Node* current = head;
    while (current != NULL) {
        if (current->data.genre == searchGenre) {
            cout <<"|=============================================|"<< endl;
            cout <<"|Name   : "<< current->data.name << endl;
            cout <<"|Genre  : "<< current->data.genre << endl;
            cout <<"|Year   : "<< current->data.year << endl;
            cout <<"|Rating : "<< current->data.rating << endl;
            cout <<"|=============================================|"<< endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << " No Games Found With The Given Genre." << endl;
    }
}
void searchYear() {
    if (head == NULL) {
        cout << " The Game List Is Empty!" << endl;
        return;
    }
    int searchYear;
    bool found = false;

    cout << " Enter The Year Of The Game You Are Looking For : ";
    cin >> searchYear;

    Node* current = head;
    while (current != NULL) {
        if (current->data.year == searchYear) {
            cout <<"|=============================================|"<< endl;
            cout <<"|Name   : "<< current->data.name << endl;
            cout <<"|Genre  : "<< current->data.genre << endl;
            cout <<"|Year   : "<< current->data.year << endl;
            cout <<"|Rating : "<< current->data.rating << endl;
            cout <<"|=============================================|"<< endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << " No Games Found With The Given Year." << endl;
    }
}
void searchRating() {
    if (head == NULL) {
        cout << " The Game List Is Empty!" << endl;
        return;
    }
    float searchRating;
    bool found = false;

    cout << " Enter The Rating Of The Game You Are Looking For : ";
    cin >> searchRating;

    Node* current = head;
    while (current != NULL) {
        if (current->data.rating == searchRating) {
            cout <<"|=============================================|"<< endl;
            cout <<"|Name   : "<< current->data.name << endl;
            cout <<"|Genre  : "<< current->data.genre << endl;
            cout <<"|Year   : "<< current->data.year << endl;
            cout <<"|Rating : "<< current->data.rating << endl;
            cout <<"|=============================================|"<< endl;
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << " No Games Found With The Given Rating." << endl;
    }
}

//================= (BAGIAN MAIN PROGRAM) ====================//
int main(){
	int menu;
	do{
		menu = 0;
		system("cls");
		cout <<"_____________________________"<< endl;
		cout <<"|[A][I][P][P][I][R][W][I][N]|"<< endl;
		cout <<"|:):):):):):)---(:(:(:(:(:(:|"<< endl;
		cout <<"|===========================|"<< endl;
		cout <<"|   WELLCOME TO AIPP.GAME   |"<< endl;
		cout <<"|>>>>>>>>>>>>><<<<<<<<<<<<<<|"<< endl;
		cout <<"|[1] ADD GAME               |"<< endl;
		cout <<"|[2] DELETE GAME            |"<< endl;
		cout <<"|[3] EDIT GAME              |"<< endl;
		cout <<"|[4] SHOW GAME              |"<< endl;
		cout <<"|[5] EXIT                   |"<< endl;
		cout <<"|<><><><><><[A.G]><><><><><>|"<< endl;
		cout <<"| Choose : ";
		cin >> menu;
		cout << endl;
		switch (menu){
			case 1:{
			system("cls");
			addGame();
			break;}
			case 2:{
				int menu2;
			do{
				showGame();
				menu2 = 0;
				system("cls");
				showGame();
				cout <<"________________________________"<< endl;
				cout <<"|{-}{-}{-}{-}{-}{-}{-}{-}{-}{-}|"<< endl;
				cout <<"|==(CHOOSE THE DELETE SYSTEM)==|"<< endl;
				cout <<"|{-}{-}{-}{-}{-}{-}{-}{-}{-}{-}|"<< endl;
				cout <<"|[1] DELETE BY NAME            |"<< endl;
				cout <<"|[2] FIFO (DEQUEUE)            |"<< endl;
				cout <<"|[3] LIFO (POP)                |"<< endl;
				cout <<"|[4] EXIT                      |"<< endl;
				cout <<"|==============================|"<< endl;
				cout <<"| Choose : ";
				cin >> menu2;
				cout << endl;
				switch(menu2){
					case 1:{
						delGame();
						break;
					}
					case 2:{
						dequeue();
						break;
					}
					case 3:{
						pop();
						break;
					}
					case 4:{
						break;
					}
					default:
					cout <<" Invalid Command"<< endl;
				}getch();
			}while(menu2 != 4);
			break;}
			case 3:{
			system("cls");
			editGame();
			break;}
			case 4:{
			int menu4;
			do{
				menu4 = 0;
				system("cls");
				cout <<"________________________________"<< endl;
				cout <<"|{*}{*}{*}{*}{*}{*}{*}{*}{*}{*}|"<< endl;
				cout <<"|==(WHAT DO YOU WANT TO SHOW)==|"<< endl;
				cout <<"|{*}{*}{*}{*}{*}{*}{*}{*}{*}{*}|"<< endl;
				cout <<"|[1] SHOW ALL                  |"<< endl;
				cout <<"|[2] SHOW BY SEARCH            |"<< endl;
				cout <<"|[3] SHOW BY NAME SORT         |"<< endl;
				cout <<"|[4] EXIT                      |"<< endl;
				cout <<"|==============================|"<< endl;
				cout <<"| Choose : ";
				cin >> menu4;
				cout << endl;
				switch(menu4){
					case 1:{
						system("cls");
						showGame();
						break;
					}
					case 2:{
						int menu_src;
					    do{
					    	menu_src = 0;
				            system("cls");
				            cout <<"________________________________"<< endl;
				            cout <<"|_______|_S_E_A_R_C_H_|________|"<< endl;
			            	cout <<"|==(SEARCH THE GAME BY WHAT?)==|"<< endl;
				            cout <<"|[1] BY NAME                   |"<< endl;
				            cout <<"|[2] BY GENRE                  |"<< endl;
				            cout <<"|[3] BY YEAR                   |"<< endl;
				            cout <<"|[4] BY RATING                 |"<< endl;
				            cout <<"|[5] EXIT                      |"<< endl;
				            cout <<"|==============================|"<< endl;
				            cout <<"| Choose : ";
				            cin >> menu_src;
				            switch (menu_src){
				            	case 1:{
				            		searchName();
									break;
								}
								case 2:{
									searchGenre();
									break;
								}
								case 3:{
									searchYear();
									break;
								}
								case 4:{
									searchRating();
									break;
								}
								case 5:{
									break;
								}
								default:
								cout <<" Invalid Command"<< endl;
							}getch();
					    }while(menu_src != 5);
						break;
					}
					case 3:{
						int menu_sort;
						int choose,BorS;
						char ulang;
						do{
							system("cls");
							showGame();
							BorS = 0;
							choose = 0;
							ulang = 'y';
					    	menu_sort = 0;
					    	cout <<"________________________________"<< endl;
						    cout <<"|_______|_S_O_R_T_I_N_G_|______|"<< endl;
			                cout <<"|===(SORT THE GAME BY WHAT?)===|"<< endl;
				            cout <<"|[1] BY NAME                   |"<< endl;
				            cout <<"|[2] BY YEAR                   |"<< endl;
				            cout <<"|[3] BY RATING                 |"<< endl;
				            cout <<"|[4] EXIT                      |"<< endl;
				            cout <<"|==============================|"<< endl;
				            cout <<"| Choose : ";
				            cin >> menu_sort;
				            cout << endl;
				            switch(menu_sort){
				            	case 1:{
				            		while (ulang != 'n' && ulang != 'N') {
				            		cout <<" Bubble(1) Atau Selection(2) : ";
				            		cin >> BorS;
				            		cout << endl;
				            		switch(BorS){
				            			case 1:{
				            		    cout <<" Mau Ascending(1) Atau Descending(2) ? ";
                                        cin >> choose;
                                        cout << endl;
                                            if (choose == 1) {
                                    	    bubbleSortName(true);
                                            }
                                            else if (choose == 2) {
                                    	    bubbleSortName(false);
                                            } else {
                                            cout << " Invalid" << endl;
                                            }
                                            cout << " Coba Lagi (y/n) ? ";
                                            cin >> ulang;
                                            break;
                                        }
                                        case 2:{
                                        cout <<" Mau Ascending(1) Atau Descending(2) ? ";
                                        cin >> choose;
                                        cout << endl;
                                            if (choose == 1) {
                                    	    selectionSortName(true);
                                            }
                                            else if (choose == 2) {
                                    	    selectionSortName(false);
                                            } else {
                                            cout << " Invalid" << endl;
                                            }
                                            cout << " Coba Lagi (y/n) ? ";
                                            cin >> ulang;
											break;
										}
                                }getch();
								}
								break;
							    }
								case 2:{
									while (ulang != 'n' && ulang != 'N') {
				            		cout <<" Bubble(1) Atau Selection(2) : ";
				            		cin >> BorS;
				            		cout << endl;
				            		switch(BorS){
				            			case 1:{
				            		    cout <<" Mau Ascending(1) Atau Descending(2) ? ";
                                        cin >> choose;
                                        cout << endl;
                                            if (choose == 1) {
                                    	    bubbleSortYear(true);
                                            }
                                            else if (choose == 2) {
                                    	    bubbleSortYear(false);
                                            } else {
                                            cout << " Invalid" << endl;
                                            }
                                            cout << " Coba Lagi (y/n) ? ";
                                            cin >> ulang;
                                            break;
                                        }
                                        case 2:{
                                        cout <<" Mau Ascending(1) Atau Descending(2) ? ";
                                        cin >> choose;
                                        cout << endl;
                                            if (choose == 1) {
                                    	    selectionSortYear(true);
                                            }
                                            else if (choose == 2) {
                                    	    selectionSortYear(false);
                                            } else {
                                            cout << " Invalid" << endl;
                                            }
                                            cout << " Coba Lagi (y/n) ? ";
                                            cin >> ulang;
											break;
										}
                                }getch();
								}
								break;
								}
								case 3:{
									while (ulang != 'n' && ulang != 'N') {
				            		cout <<" Bubble(1) Atau Selection(2) : ";
				            		cin >> BorS;
				            		cout << endl;
				            		switch(BorS){
				            			case 1:{
				            		    cout <<" Mau Ascending(1) Atau Descending(2) ? ";
                                        cin >> choose;
                                        cout << endl;
                                            if (choose == 1) {
                                    	    bubbleSortRating(true);
                                            }
                                            else if (choose == 2) {
                                    	    bubbleSortRating(false);
                                            } else {
                                            cout << " Invalid" << endl;
                                            }
                                            cout << " Coba Lagi (y/n) ? ";
                                            cin >> ulang;
                                            break;
                                        }
                                        case 2:{
                                        cout <<" Mau Ascending(1) Atau Descending(2) ? ";
                                        cin >> choose;
                                        cout << endl;
                                            if (choose == 1) {
                                    	    selectionSortRating(true);
                                            }
                                            else if (choose == 2) {
                                    	    selectionSortRating(false);
                                            } else {
                                            cout << " Invalid" << endl;
                                            }
                                            cout << " Coba Lagi (y/n) ? ";
                                            cin >> ulang;
											break;
										}
                                }getch();
								}
								break;
								}
								case 4:{
									break;
								}
								default:
									cout <<" Invalid Command"<< endl;
						    }getch();
					    }while(menu_sort != 4);
					    break;
					}
					case 4:{
						break;
					}
					default:
					cout <<" Invalid Command"<< endl;
				}getch();
			}while(menu4 != 4);
			break;}
			case 5:{
				cout <<" ARIGATOU :)"<< endl;
			break;}
			default:
			cout <<" Invalid Command"<< endl;
		}getch();
	}while(menu != 5);	
	system("cls");
	cout <<"|-----------------------------------------------------------------------------------------------------------|"<< endl;
	cout <<"|                                     Program By A.Irwin Putra Pangesti                                     |"<< endl;
	cout <<"|-----------------------------------------------------------------------------------------------------------|"<< endl;
	cout << endl;
	getch();
	system("cls");
	cout <<"|-----------------------------------------------------------------------------------------------------------|"<< endl;
	cout <<"|                                     Response Of Data Structure                                            |"<< endl;
	cout <<"|-----------------------------------------------------------------------------------------------------------|"<< endl;
	cout << endl;
	getch();
	system("cls");
	cout <<"|-----------------------------------------------------------------------------------------------------------|"<< endl;
	cout <<"|                                     My Workspace : AIPPproject03 (Github)                                 |"<< endl;
	cout <<"|                                          Instagram : @aippirwin                                           |"<< endl;
	cout <<"|-----------------------------------------------------------------------------------------------------------|"<< endl;
	cout << endl;
	getch();
	system("cls");
	cout <<"|-----------------------------------------------------------------------------------------------------------|"<< endl;
	cout <<"|                                     *KEEP THE SPIRIT AND ALWAYS PRAY*                                     |"<< endl;
	cout <<"|                                      *MAY GOD ALWAYS WITH US, AMEEN*                                      |"<< endl;
	cout <<"|-----------------------------------------------------------------------------------------------------------|"<< endl;
	cout << endl;
	getch();
	system("cls");
	cout <<"|-----------------------------------------------------------------------------------------------------------|"<< endl;
	cout <<"|                                          EAT, SLEEP AND CODE                                              |"<< endl;
	cout <<"|-----------------------------------------------------------------------------------------------------------|"<< endl;
	cout << endl;
	getch();
}
