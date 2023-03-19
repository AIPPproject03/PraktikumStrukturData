#include<iostream>
#include<conio.h>
#define size 5
using namespace std;


struct node{
int bil;
struct node *next;
};

struct stack{
int jumlah;
struct node *top;
};

int cekPenuh(stack *stack){
if(stack->jumlah==size)
return 1;
else
return 0;
}

int cekKosong(stack *stack){
if(stack->jumlah==0)
return 1;
else
return 0;
}

void Push(stack *stack){
node *baru;
if (cekPenuh(stack)){
cout <<"stack full"<< endl;
getch();
}
else
{
baru=new(node);
cout<<"\nmasukkan nilai yang ingin dipush ke stack: ";
cin>>baru->bil;
baru->next=stack->top;
stack->top=baru;
stack->jumlah++;
}
}

void cetak(stack *stack){
node *bacaPtr;
bacaPtr=stack->top;
if(cekKosong(stack))
{
cout<<"  stack kosong";
getch();
}
else
{
cout<<"  TOP\n";
cout<<"---------\n";
while(bacaPtr!=NULL){
cout<<bacaPtr->bil<<endl;
cout<<"---------"<<endl;
bacaPtr=bacaPtr->next;
}
getch();
}
}
void Pop(stack *stack){
// int dataTop;
node *hapusPtr;
hapusPtr=stack->top;
if (cekKosong(stack)){
cout<<"Stack Kosong";getch();
}
else
{
// dataTop=stack->top->bil;
stack->top=stack->top->next;
stack->jumlah--;
delete hapusPtr;
cout<<"\nproses pop berhasil\n";
getch();
}
}

void Top(stack *stack){
int dataTop;
if(cekKosong(stack)){
cout<<"\ntop = NULL\n";
getch();
}
else
{
dataTop=stack->top->bil;
cout<<"\ntop = "<<dataTop<<endl;
getch();
}
}

void hapus(stack *stack){
node *bantuHapus;
while(stack->top!=NULL){
bantuHapus=stack->top;
stack->top=stack->top->next;
delete bantuHapus;
}
stack->jumlah=0;
}

int main(){
stack stack;
stack.jumlah=0;
stack.top=NULL;
int pilih;
do{
system("cls");
cetak(&stack);
cout << endl;
cout <<" |=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|"<< endl;
cout <<" |         (MENU STACK)        |"<< endl;
cout <<"[1]. Kosongkan Stack           |"<< endl;
cout <<"[2]. Push                      |"<< endl;
cout <<"[3]. Pop                       |"<< endl;
cout <<"[4]. Lihat Top Stack           |"<< endl;
cout <<"[5]. Keluar                    |"<< endl;
cout <<" |-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|"<< endl;
cout <<" | Pilihan : ";
cin >> pilih;
   switch(pilih){
   	 case 1 :
   	 hapus(&stack);
   	 break;
   	 case 2 :
   	 Push(&stack);
   	 break;
   	 case 3 :
   	 Pop(&stack);
   	 break;
   	 case 4 :
   	 Top(&stack);
   	 break;
   	 case 5 :
   	 break;
   	 default : 
   	 cout <<" Invalid"<< endl;
   }getch();
   }while(pilih != 5);
}
