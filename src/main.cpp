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

//Variaveis de escopo global
char peca;
int podeMover = 0;
int deslocaVertical;
int deslocaHorizon;
int linOrigem, colOrigem, linDestino, colDestino;

/*Inicializando o tabuleiro, Q = queen, K = king
Letras em maiúsculas representam peças Pretas, em minúculas peças brancas */
char xadrez[10][10] = {
	{'-', '1', '2', '3', '4', '5', '6', '7', '8' },
	{'1', 't', 'c', 'b', 'k', 'q', 'b', 'c', 't' },
	{'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
	{'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
	{'8', 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T' }
	
};

//Declaração das funções no escopo
int movimentoTorre();
int movimentoBispo();
int movimentoCavalo();
int movimentoQueen();
int movimentoKing();
int movimentoPeao();

//função que printa o tabuleiro na tela
void printarMatriz(){
    char letra;
    for(int i = 0; i < 9; i++){
        for(int pintaLinha = 0; pintaLinha < 3; pintaLinha++){ //Somente para deixar um espaço para a peça no tabuleiro e centraliza-la
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

//função que move TODAS as peças no tabuleiro
int moverPecas(){
    peca = xadrez[linOrigem][colOrigem];
    deslocaVertical = std::abs(linDestino - linOrigem);
    deslocaHorizon = std::abs(colDestino - colOrigem);
	
	switch(peca) {
		case 'T':
			case 't':
				movimentoTorre();
				break;
		
		case 'B':
			case 'b':
                movimentoBispo();
			break;

		case 'C':
			case 'c':
				movimentoCavalo();
				break;

		case 'Q':
			case 'q':
				movimentoQueen();
				break;
		case 'K':
			case 'k':
				movimentoKing();
				break;
		
		case 'P':
			movimentoPeao();
			break;	
		case 'p':
			movimentoPeao();
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

//Função que analisa se os movimentos da TORRE são permitidos 
int movimentoTorre(){

    podeMover = (deslocaVertical == 0 || deslocaHorizon == 0);
    return podeMover;
     
}

//função que analisa se os movimentos do BISPO são permitidos
int movimentoBispo(){
    podeMover = (deslocaVertical == deslocaHorizon);
    return podeMover;
}

//função que analisa se os movimentos do BISPO são permitidos
int movimentoCavalo(){
    podeMover = ((deslocaVertical == 1 && deslocaHorizon == 2) || (deslocaVertical == 2 && deslocaHorizon == 1));
    return podeMover;
}

//função que analisa se os movimentos da RAINHA são permitidos
int movimentoQueen(){
    podeMover = (deslocaVertical == deslocaHorizon) || ((deslocaVertical == 0) || (deslocaHorizon == 0));
    return podeMover;
}

//função que analisa se os movimentos do REI são permitidos
int movimentoKing(){
    podeMover = (deslocaHorizon >= 1 || deslocaVertical <= 1);
    return podeMover;
}

//função que analisa se os movimentos do PEÃO são permitidos
int movimentoPeao(){

    if(peca == 'P'){
        podeMover = ((linOrigem - linDestino == 1) && (deslocaHorizon == 0));
        return podeMover;
    }else{
        if(peca == 'p'){
            podeMover = ((linDestino - linOrigem == 1) && (deslocaHorizon == 0));
            return podeMover;
        }
    }
}


int main (){
    int resultado = 0;
    while(1){

        printarMatriz();

        cout<<"Informe a linha e coluna de origem: "; 
        scanf("%d %d", &linOrigem, &colOrigem);        //usei scanf porquê o "cin" está dando bug

        cout<<"Informe a linha e coluna de destino: ";
        scanf("%d %d", &linDestino, &colDestino);

        resultado = moverPecas();
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