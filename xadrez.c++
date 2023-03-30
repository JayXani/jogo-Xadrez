#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

/*Inicializando o tabuleiro, Q = queen, K = king
Letras em maiúsculas representam peças Pretas, em minúculas peças brancas */

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

//função que printa o tabuleiro na tela
void printarMatriz(){
    system("CLS"); 
    for(int i = 0; i < 8; i++){
        for(int pintaLinha = 0; pintaLinha < 3; pintaLinha++){ //Somente para deixar um espaço para a peça no tabuleiro e centralizar a peça
            for(int j = 0; j < 8; j++){
                char peca = xadrez[i][j];
                char letra = ((i + j) % 2 == 0) ? '\xB2' : ' ';
                letra = (pintaLinha == 1 && peca != ' ') ? peca : letra;

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

//função que move as peças no tabuleiro

int moverPecas(int linOrigem, int colOrigem, int linDestino, int colDestino){

    if((linOrigem >= 0 && linOrigem < 8) && (colOrigem >= 0 && colOrigem < 8)){  
        if((linDestino >= 0 && linDestino < 8) && (colDestino >= 0 && colDestino < 8)){
            xadrez[linDestino][colDestino] = xadrez[linOrigem][colOrigem];
            xadrez[linOrigem][colDestino] = ' ';
        }
        return 1;
    }else{
        return 0;
    }

}

int main(){
    int linhaOrigem, linhaDestino, colunaOrigem, colunaDestino;
    while(1){
        printarMatriz();

        cout<<"Informe a linha e coluna de origem: "; 
        scanf("%d %d", &linhaOrigem, &colunaOrigem);        //usei scanf porquê o "cin" está dando bug

        cout<<"Informe a linha e coluna de destino: ";
        scanf("%d %d", &linhaDestino, &colunaDestino);

        if(moverPecas(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino) != 1){

            cout<< "ERRO: Valores INVALIDOS ! \nClique na tecla \"Enter\" para colocar novos valores !";
            getch();
        }
    }
    getch();
    return 0;
}