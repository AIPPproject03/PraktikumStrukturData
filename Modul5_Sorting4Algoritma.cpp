#include <iostream>
#include <conio.h>
using namespace std;

void Bubble(int arr[], int n, bool Asc_or_Dsc) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            bool swap = false;
            if(Asc_or_Dsc) {
                if(arr[i] > arr[j]) {
                    swap = true;
                }
            } else {
                if(arr[i] < arr[j]) {
                    swap = true;
                }
            }
            if(swap) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Selection(int arr[], int n, bool Asc_or_Dsc) {
    int i, j, temp, idx;
    for (i = 0; i < n - 1; i++) {
        idx = i;
        for (j = i + 1; j < n; j++) {
            if (Asc_or_Dsc) {
                if (arr[j] < arr[idx]) {
                    idx = j;
                }
            } else {
                if (arr[j] > arr[idx]) {
                    idx = j;
                }
            }
        }
        temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
    }
}

void Insertion(int arr[], int n, bool Asc_or_Dsc) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        if (Asc_or_Dsc) {
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else {
            while (j >= 0 && arr[j] < temp) {
                arr[j + 1] = arr[j];
                j--;
            }
        }

        arr[j + 1] = temp;
    }
}

void Shell(int arr[], int n, bool ascending) {
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i += 1) {
            temp = arr[i];
            if (ascending) {
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            } else {
                for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            }
            arr[j] = temp;
        }
    }
}

int main(){
	int num[] = {15,8,0,-2,19,42,31,81,-72,1,2};
	int size = sizeof(num)/sizeof(num[0]);
	//cout <<" num : "<< sizeof(num) << endl;
	int menu,choose;
	char ulang;
	do{
		ulang = 'y';
		system("cls");
		cout <<" |_____________________________|"<< endl;
		cout <<" |+|+|+|+|+|+|+|+|+|+|+|+|+|+|+|"<< endl;
		cout <<" |--------[MENU SORTING]-------|"<< endl;
		cout <<" |=============================|"<< endl;
		cout <<"[1] Bubble Sort                |"<< endl;
		cout <<"[2] Selection Sort             |"<< endl;
		cout <<"[3] Insertion Sort             |"<< endl;
		cout <<"[4] Shell Sort                 |"<< endl;
		cout <<"[5] Exit                       |"<< endl;
		cout <<" |=============================|"<< endl;
		cout <<" | Choose : ";
		cin >> menu;
		switch (menu){
			case 1:
                while (ulang != 'n' && ulang != 'N') {
                    system("cls");
                    cout << " Sebelum Disorting : " << endl;
                    cout << " {15,8,0,-2,19,42,31,81,-72,1,2}" << endl << endl;
                    cout << " Mau Ascending(1) Atau Descending(2) ? ";
                    cin >> choose;
                    cout << endl;
                    if (choose == 1) {
                        Bubble(num, size, true);
                        cout << " Inilah Hasil Dari Bubble Sort Ascending : " << endl;
                        cout << " {";
                        for (int i = 0; i < size; i++) {
                            cout << " " << num[i];
                        }
                        cout << " }" << endl;
                    }
                    else if (choose == 2) {
                        Bubble(num, size, false);
                        cout << " Inilah Hasil Dari Bubble Sort Descending : " << endl;
                        cout << " {";
                        for (int i = 0; i < size; i++) {
                            cout << " " << num[i];
                        }
                        cout << " }" << endl;
                    }
                    else {
                        cout << " Invalid" << endl;
                    }
                    cout << " Coba Lagi (y/n) ? ";
                    cin >> ulang;
                }
			break;
        	case 2:
                while(ulang != 'n' && ulang != 'N'){
                    system("cls");
                    cout <<" Sebelum Disorting : "<< endl;
                    cout <<" {15,8,0,-2,19,42,31,81,-72,1,2}"<< endl;
                    cout << endl;
                    cout <<" Mau Ascending(1) Atau Descending(2) ? ";
                    cin >> choose;
                    cout << endl;
                    if(choose == 1){
                        Selection(num, size, true);
                        cout <<" Inilah Hasil Dari Selection Sort Ascending : "<< endl;
                        cout <<" {";
                        for (int i = 0; i < size ; i++){
                            cout <<" "<< num[i];
                        }
						cout <<" }"<< endl;
                    }
                    else if(choose == 2) {
                        Selection(num, size, false);
                            cout <<" Inilah Hasil Dari Selection Sort Descending : "<< endl;
                            cout <<" {";
                            for (int i = 0; i < size ; i++){
                               cout <<" "<< num[i];
                            }
			                cout <<" }"<< endl;
                            }else{
                            cout <<" Invalid"<< endl;
                            }
                            cout <<" Coba Lagi (y/n) ? ";
                            cin >> ulang;
                        }
                    break;
case 3:
    while(ulang != 'n' && ulang != 'N') {
        system("cls");
        cout << "Sebelum Disorting : " << endl;
        cout << "{15, 8, 0, -2, 19, 42, 31, 81, -72, 1, 2}" << endl;
        cout << endl;
        cout << "Mau Ascending(1) Atau Descending(2) ? ";
        cin >> choose;
        cout << endl;

        if(choose == 1) {
            Insertion(num, size, true);
            cout << "Inilah Hasil Dari Insertion Sort Ascending : " << endl;
            cout << "{";
            for(int i = 0; i < size ; i++) {
                cout << " " << num[i];
            }
            cout << " }" << endl;
        } else if(choose == 2) {
            Insertion(num, size, false);
            cout << "Inilah Hasil Dari Insertion Sort Descending : " << endl;
            cout << "{";
            for(int i = 0; i < size ; i++) {
                cout << " " << num[i];
            }
            cout << " }" << endl;
        } else {
            cout << "Invalid" << endl;
        }

        cout << "Coba Lagi (y/n) ? ";
        cin >> ulang;
    }
    break;

case 4:
    while(ulang != 'n' && ulang != 'N') {
        system("cls");
        cout << "Sebelum Disorting : " << endl;
        cout << "{15, 8, 0, -2, 19, 42, 31, 81, -72, 1, 2}" << endl;
        cout << endl;
        cout << "Mau Ascending(1) Atau Descending(2) ? ";
        cin >> choose;
        cout << endl;

        if(choose == 1) {
            Shell(num, size, true);
            cout << "Inilah Hasil Dari Shell Sort Ascending : " << endl;
            cout << "{";
            for(int i = 0; i < size ; i++) {
                cout << " " << num[i];
            }
            cout << " }" << endl;
        } else if(choose == 2) {
            Shell(num, size, false);
            cout << "Inilah Hasil Dari Shell Sort Descending : " << endl;
            cout << "{";
            for(int i = 0; i < size ; i++) {
                cout << " " << num[i];
            }
            cout << " }" << endl;
        } else {
            cout << "Invalid" << endl;
        }

        cout << "Coba Lagi (y/n) ? ";
        cin >> ulang;
    }
    break;

case 5:
    system("cls");
    cout << "Arigatou :)" << endl;
    break;

default:
    cout << "Invalid Instruction" << endl;
}

getch();
} while(menu != 5);
}
