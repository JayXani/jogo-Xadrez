#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
/*Nomes:
    Danilo de Araújo Leite Gomes
    Bruno Jean Lima

*/

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

    char peca;
    int mover = 0;
    int deslocaVertical = std::abs(linDestino - linOrigem);
    int deslocaHorizon = std::abs(colDestino - colOrigem);

    if((linOrigem >= 0 && linOrigem < 8) && (colOrigem >= 0 && colOrigem < 8)){  
        if((linDestino >= 0 && linDestino < 8) && (colDestino >= 0 && colDestino < 8)){

            peca = xadrez[linOrigem][colOrigem];
            
            if((peca == 'T' || peca == 't') && (deslocaVertical == 0 || deslocaHorizon == 0)) mover = 1;     //verificação de movimento da TORRE
            if((peca == 'B' || peca == 'b') && (deslocaVertical == deslocaHorizon)) mover = 1;              //verificação de movimentos do BISPO

            //verificaçãa de movimento do CAVALO (Condição que está abaixo)
            if(((peca == 'C' || peca == 'c') && (deslocaVertical == 1 && deslocaHorizon == 2)) || (deslocaVertical == 2 && deslocaHorizon == 1)) mover = 1; 

            //verificação de movimentos da RAINHA 
            if((peca == 'Q' || peca == 'q') && ((deslocaVertical == deslocaHorizon)) || ((deslocaVertical == 0) || (deslocaHorizon == 0))) mover = 1;
            
            //verificação de movimentos do REI (King)
            if((peca == 'K' || peca == 'k') && (deslocaVertical >= 0 && deslocaVertical <= 1) && (deslocaHorizon >= 0 && deslocaHorizon <= 1)) mover = 1;

            //verificação de movimentos do PEÃO PRETO
            if((peca == 'P') && (linDestino - linOrigem == 1) && (deslocaHorizon == 0)) mover = 1;

            //verificaçõa de movimentos do PEÃO BRANCO
            if((peca == 'p') && (linOrigem - linDestino == 1) && (deslocaHorizon == 0)) mover = 1;

        
            if(mover){
                system("CLS");
                xadrez[linDestino][colDestino] = xadrez[linOrigem][colOrigem];
                xadrez[linOrigem][colOrigem] = ' ';
                 
                return 1;     // 1 == Peça movida com sucesso
            }else{
                return 9;   // 9 == peça nõa pode ser movida 
            }
        }
       
    }else{
        
        return 0;
    }
}

int main(){
    int linhaOrigem, linhaDestino, colunaOrigem, colunaDestino, resultado = 0;
    while(1){
        printarMatriz();

        cout<<"Informe a linha e coluna de origem: "; 
        scanf("%d %d", &linhaOrigem, &colunaOrigem);        //usei scanf porquê o "cin" está dando bug

        cout<<"Informe a linha e coluna de destino: ";
        scanf("%d %d", &linhaDestino, &colunaDestino);

        resultado = moverPecas(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
        if(resultado != 1){
            switch ( resultado )
            {
                case 9 : 
                    cout<< "ERRO ! \nPeca nao pode ser movida";
                    getch();

                    break;
                case 0:
                    cout<< "ERRO : Valores invalidos\nClique na tecla \"Enter\" para colocar novos valores !";
                    getch();

                    break;
                
                case 1:

                    break;
            }
            getch();
        }
    }
    getch();
    return 0;
}