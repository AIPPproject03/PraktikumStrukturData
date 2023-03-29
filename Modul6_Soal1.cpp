#include <iostream>
#include <string>
#include <conio.h>
#define min 10
using namespace std;
/*      

			WELLCOME CODE LOVERS :V
			REMEMBER TO BE ALWAYS BRAVE AND CONFIDENCE !!!
			ALWAYS TRY NEW THINGS AND NEVER GIVE UP !!!
			AIPPproject03


**/
struct data{
	int tampung = 0;
	int ID[min];
}pembeli;

void costumer(){
	cout <<"|=======================================================|"<< endl;
	cout <<"| MASUKAN 10 DATA PEMBELI !                             |"<< endl;
	cout <<"| Ket : * Contoh Input Pukul Pembelian 18:45 --> 1845 * |"<< endl;
		for(int i = 0; i < min; i++){
	cout <<"|["<< i+1 <<"] Pembeli Pada Pukul : ";
	cin >> pembeli.ID[pembeli.tampung];
	pembeli.tampung++;
	}
}

int sequentialSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int l, int r, int x) { // BINARY SEARCH HANYA BISA MENCARI DENGAN VALID JIKA URUTAN ELEMEN PADA ARRAY RAPI SECARA ASCENDING //
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return -1;
}

void Bubble(int arr[], int n) { // DIGUNAKAN UNTUK MENGURUTKAN DATA SECARA ASCENDING UNTUK ELEMEN DIDALAM ARRAY AGAR BINARY SEARCH LEBIH OPTIMAL //
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
                if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int x;
    int choice;
    do{
        system("cls");
        cout <<" The ID List : "<< endl;
        if (pembeli.tampung == 0){
        	cout <<" Empty"<< endl;
		}else{
        for (int i = 0; i < pembeli.tampung ; i++){
    	cout <<" ["<< i+1 <<"] "<< pembeli.ID[i] << endl;
    	}
    }
    	cout <<"[================================]"<< endl;
        cout <<"[ Program Pencarian ID Pelanggan ]"<< endl;
        cout <<"[================================]"<< endl;
        cout <<"[  1. Add Pembeli                ]"<< endl;
        cout <<"[  2. Sequential Search          ]"<< endl;
        cout <<"[  3. Binary Search              ]"<< endl;
        cout <<"[  4. Keluar                     ]"<< endl;
        cout <<"[ Pilihan Anda : ";
        cin >> choice;

        switch (choice) {
        	case 1:{
        		system("cls");
        		costumer();
        		Bubble(pembeli.ID, pembeli.tampung);
				break;
			}
            case 2:{
                cout << "Masukkan ID pembeli yang ingin dicari : ";
                cin >> x;
                int seq_result = sequentialSearch(pembeli.ID, pembeli.tampung, x);
                if (seq_result == -1) {
                    cout << "Data Tidak Ditemukan!" << endl;
                }
                else {
                    cout << "Data Ditemukan pada indeks ke-" << seq_result+1 << endl;
                }
                break;
}
            case 3:{
                cout << " Masukkan ID pembeli yang ingin dicari : ";
                cin >> x;
                int bin_result = binarySearch(pembeli.ID, 0, pembeli.tampung - 1, x);
                if (bin_result == -1) {
                    cout << " Data Tidak Ditemukan!" << endl;
                }
                else {
                    cout << " Data Ditemukan pada indeks ke-" << bin_result+1 << endl;
                }
                break;
            }
            case 4:
            	break;
            default:
                cout << " Invalid Instruction." << endl;
                break;
        }getch();
    } while (choice != 4);
}
