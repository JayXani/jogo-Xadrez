#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
/*Nomes:
    Danilo de Araújo Leite Gomes        RA: 1840482212023
    Bruno Jean Lima                     RA: 1840482212011

    OBS{
        O código foi desenvolvido no Visual Studio Code, por tanto, a pasta que contém o .exe
        é a que possui o nome "output"

        para rodar em outros compiladores, basta utilizar o .cpp que ele cria o .exe na maquina

    }
        
*/


/*Inicializando o tabuleiro, Q = queen, K = king
Letras em maiúsculas representam peças Pretas, em minúculas peças brancas */

char xadrez[10][10] = {
	{'-', '1', '2', '3', '4', '5', '6', '7', '8' },    //TABULEIRO,  USEI UMA MATRIZ  10 X 10/
	{'1', 't', 'c', 'b', 'k', 'q', 'b', 'c', 't' },
	{'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
	{'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
	{'8', 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T' }
	
};


//funÃ§Ã£o que printa o tabuleiro na tela
void printarMatriz(){
    char letra;
    for(int i = 0; i < 9; i++){
        for(int pintaLinha = 0; pintaLinha < 3; pintaLinha++){ //Somente para deixar um espaÃ§o para a peÃ§a no tabuleiro e centralizar a peÃ§a
            for(int j = 0; j < 9; j++){
            	
                char peca = xadrez[i][j];
                if((letra = ((i  + j) % 2 == 0)) && ((i != 0 && i != 9) && (j != 0 && j != 9))){  //Somente deixar as coordenadas não pintadas e já faz a verificação para a pintura da "letra"
                    letra = '\xB2';
                }else{
                    letra = ' ';
                }
                letra = (pintaLinha == 1 && peca != ' ') ? peca : letra;

                if(((i!=0 && i !=9) && (j!=0 && j !=9)) && (i + j) % 2 == 0){
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

//função que move as peças no tabuleiro
int moverPecas(int linOrigem, int colOrigem, int linDestino, int colDestino){
    char peca = xadrez[linOrigem][colOrigem];
    int podeMover = 0;
    int deslocaVertical = std::abs(linDestino - linOrigem);
    int deslocaHorizon = std::abs(colDestino - colOrigem);
	
	switch(peca) {
		//Se for uma torre, só poderá se mover se estiver na seguinte restrições
		case 'T':
			case 't':
				podeMover = (deslocaVertical == 0 || deslocaHorizon == 0);
				break;
		//Se for um bispo, só poderá se mover se estiver na seguinte restrições
		case 'B':
			case 'b':
			podeMover = (deslocaVertical == deslocaHorizon);
			break;
		//Se for um cavalo, só poderá se mover se estiver na seguinte restrições
		case 'C':
			case 'c':
				podeMover = ((deslocaVertical == 1 && deslocaHorizon == 2) || (deslocaVertical == 2 && deslocaHorizon == 1));
				break;
		//Se for uma rainha, só poderá se mover se estiver na seguinte restrições
		case 'Q':
			case 'q':
				podeMover = (deslocaVertical == deslocaHorizon) || ((deslocaVertical == 0) || (deslocaHorizon == 0));
				break;
		case 'K':
			case 'k':
				podeMover = (deslocaHorizon >= 1 || deslocaVertical <= 1);
				break;
		//Se for um peão, só poderá se mover se estiver na seguinte restrições
		case 'P':
			podeMover = (linDestino - linOrigem == 1) && (deslocaHorizon == 1);
			break;	
		case 'p':
			podeMover = (linDestino - linOrigem == 1) && (deslocaHorizon == 0);
			break;
	}
	//Se a peça ela respeitar as restrições baseadas em seu tipo, ela poderá se mover (return 1)
	if(podeMover) {
		system("CLS");
		xadrez[linDestino][colDestino] = xadrez[linOrigem][colOrigem];
    	xadrez[linOrigem][colOrigem] = ' ';
		return 1;
	} else {
		//Se não, não poderá mover a peça (return 9)
		return 9;
	}
}

int main (){
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
    system("CLS");

    return 0;
}