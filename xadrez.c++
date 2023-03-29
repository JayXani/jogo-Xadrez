#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//Inicializando o tabuleiro, Q = queen, K = king
//Letras em maiúsculas representam peças Pretas, em minúculas peças brancas

char xadrez[8][8] = {
    {'T' , 'C' , 'B' , 'Q' , 'K' , 'B' , 'C' , 'T' },
    {'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
    {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
    {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
    {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
    {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
    {'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
    {'t' , 'c' , 'b' , 'q' , 'k' , 'b' , 'c' , 't' }
};

int printarMatriz(){
    system("CLS"); //Esse comando limpa a tela
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout<<"\xB2"; //Printa os quadrados do xadrez
        }
        cout<< "\n";
    }
}


int main(){
    printarMatriz();
    getch();
    return 0;
}