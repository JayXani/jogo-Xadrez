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

void printarMatriz(){
    system("CLS"); //Esse comando limpa a tela
    for(int i = 0; i < 8; i++){
        for(int pintaLinha = 0; pintaLinha < 3; pintaLinha++){ //Somente para deixar um espaço para a peça no tabuleiro
            for(int j = 0; j < 8; j++){
                char peca = xadrez[i][j];
                char letra = ((i + j) % 2 == 0) ? '\xB2' : ' ';
                letra = (pintaLinha == 1) ? peca : letra;

                if((i + j) % 2 == 0){
                    cout<<"\xB2\xB2"<<letra<<"\xB2\xB2"; //Printa os quadrados do xadrez PINTADOS
                }else{
                    cout<<"  "<<letra<<"  ";
                }
            }
            cout<<"\n";
        }
    }
}

int main(){
    printarMatriz();
    getch();

    return 0;
}