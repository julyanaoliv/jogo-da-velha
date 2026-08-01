// jogo da velha

#include <stdio.h>

void PrintTabuleiro(char tabuleiro[3][3]);
int VerificarVitoria(char matriz[3][3]);

int main(){
	// jogador 1 = impar 
	// jogador 2 = par

	char tabuleiro[3][3];
	int rodada = 0;
	for(int i = 0; i< 3; i++){  // inicia tabuleiro
		for( int j = 0; j<3; j++){
			tabuleiro[i][j] = ' ';
		}
	}

	 while (VerificarVitoria(tabuleiro) != 1 && rodada <9){
		PrintTabuleiro(tabuleiro);
		char caractere;
		if(rodada %2 == 0) {caractere = 'O';} else {caractere = 'X';}
		int linha, coluna;
		printf("Escolha a jogada: linha (1-3) coluna (1-3)\n");
		scanf("%d %d", &linha, &coluna);

		if(linha<1 || linha>3 || coluna < 1 || coluna >3){
			printf("Jogada invalida!\n");
			continue;
		}
		if (tabuleiro[linha-1][coluna-1] != ' '){
			printf("Casa preenchida.\n");
			continue;
		} else {
			tabuleiro[linha-1][coluna-1] = caractere;
		}
		rodada++;
		if (VerificarVitoria(tabuleiro)) {
		    printf("Jogador %c venceu!\n", caractere);
		    PrintTabuleiro(tabuleiro);
		}
	}
	if(!VerificarVitoria(tabuleiro)) {
		printf("Empate!\n");
		PrintTabuleiro(tabuleiro);
	}

	return 0;
}


void PrintTabuleiro(char tabuleiro[3][3]){
	for(int i = 0; i< 3; i++){
		for( int j = 0; j<3; j++){
			printf(" %c ", tabuleiro[i][j]);
			if (j!= 2) printf("|");
		}
		printf("\n");
		if (i!=2) printf("-----------\n");
	}
}

int VerificarVitoria(char matriz[3][3]){
	//checar linhas
	for(int i = 0; i<3; i++){
		if(matriz[i][0] != ' ' && matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]){
			//alguem ganhou na linha
			return 1;
		}
		if( matriz[0][i] != ' ' && matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]){
			//alguem ganhou na coluna
			return 1;
		}
	}
	if( matriz[0][0] != ' ' && matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]){
		//alguem ganhou na matriz principal
		return 1;
	}
	if( matriz[0][2] != ' ' && matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]){
		//alguem ganhou na matriz secundaria
		return 1;
	}
	return 0; // ninguem ganhou
}