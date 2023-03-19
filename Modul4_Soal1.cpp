#include <iostream>
#include <conio.h>
using namespace std;
/*  
PREORDER TRAVERSAL
Dalam preOrder traversal, root node dikunjungi terlebih dahulu, kemudian dilanjutkan dengan pengunjungan
simpul anak kiri dan kemudian simpul anak kanan. Notasi "/ " mewakili simpul anak kiri dan anak kanan 
secara berurutan.
Contoh:

          A
         / \
        B   C
       / \   \
      D   E   F
      
PreOrder traversal: A -> B -> D -> E -> C -> F
Notasi:            / \ / \ / \ / \ / \ / \
                    A B D E C F
                    
INORDER TRAVERSAL
Dalam inOrder traversal, simpul anak kiri dikunjungi terlebih dahulu, kemudian root node, dan diikuti dengan
pengunjungan simpul anak kanan. Notasi "/ " mewakili simpul anak kiri dan anak kanan secara berurutan. 
Contoh:

          A
         / \
        B   C
       / \   \
      D   E   F
      
InOrder traversal: D -> B -> E -> A -> C -> F
Notasi:            / \ / \ / \ / \ / \ / \
                    D B E A C F
                    
POSTORDER TRAVERSAL
Dalam postOrder traversal, simpul anak kiri dan anak kanan dikunjungi terlebih dahulu, kemudian diikuti dengan
pengunjungan root node. Notasi "/ " mewakili simpul anak kiri dan anak kanan secara berurutan.
Contoh:

          A
         / \
        B   C
       / \   \
      D   E   F
      
PostOrder traversal: D -> E -> B -> F -> C -> A
Notasi:               / \ / \ / \ / \ / \ / \
                       D E B F C A
                       
Dalam semua contoh di atas, node A adalah root node. Notasi "/ " mewakili simpul anak kiri dan anak kanan secara berurutan.
**/
struct node {
    char data;
    node *kiri;
    node *kanan;
};

node *akar = NULL;

void addNode(node **akar, char isi){
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

int main() {
    char abjad;
    cout <<" PROGRAM BY AIPP_PROJECT03"<< endl;
    cout <<" BE FUN AND STAY CODE :)"<< endl;
    cout << endl;
    cout <<"\n\n Posisi Awal Tree : "<< endl;
    cout <<"\n         A     "<< endl;
    cout <<"       /   \\    "<< endl;
    cout <<"      C     B  "<< endl;
    cout <<"       \\   /     "<< endl;
    cout <<"        E D   "<< endl;
    cout <<"         \\     "<< endl;
    cout <<"          F    \n"<< endl;
    
    // BAGIAN AKAR //
    addNode(&akar, abjad = 'A');
    // LEVEL 1 //
    addNode(&akar->kanan, abjad = 'B');
    addNode(&akar->kiri, abjad = 'C');
    // LEVEL 2 //
    addNode(&akar->kanan->kiri, abjad = 'D');
    addNode(&akar->kiri->kanan, abjad = 'E');
    // LEVEL 3 //
    addNode(&akar->kiri->kanan->kanan, abjad = 'F');
    
    cout <<" Tampilan PreOrder  : "; preOrder(akar);cout<<"NULL"<<endl;
    cout <<"\n Tampilan InOrder   : "; inOrder(akar);cout<<"NULL"<<endl;
    cout <<"\n Tampilan PostOrder : "; postOrder(akar);cout<<"NULL"<<endl;
    cout << endl;
    getch();
}

