#include <stdio.h>
#include <string.h>

int jogadas(int campo[4][4]){
    int posicao_x,posicao_y;//define uma variavel para a coordenada x e y, indicando a posição das jogadas
    while (1){//laço de repetição para serem feitas as jogadas
    printf("Posicao X: "); scanf("%d", &posicao_x);//printa na tela para indicar a ação que o usuário irá fazer e lê a informação escrita na poisção x
    printf("Posicao Y: "); scanf("%d", &posicao_y);//printa na tela para indicar a ação que o usuário irá fazer e lê a informação escrita na poisção y concluindo a coordenada da jogada
    if (posicao_x>=0 && posicao_x<4 && posicao_y>=0 && posicao_y<4){//laço de comparação para contabilizar os pontos
       if(campo[posicao_x][posicao_y]!=0){// se a coordenada indicada para a jogada for diferente de zero seguimos para o proximo passo
        int pontuacao = campo[posicao_x][posicao_y];// atribui o valor que esta na coordenada a quantidade de pontos
        printf("PONTUOU! Pontos: %d\n", pontuacao);//printa na tela a quantidade de pontos feitas na jogada
        campo[posicao_x][posicao_y] = 0; // atribui valor 0 para retornar ao laço de repetição
        return pontuacao;// retorna a pontuação feita, voltando ao laço de repetição
    } else{// caso o requesito não se encaixe na comparação acima ele prosseguirá para a linha abaixo
      printf ("Nenhum barco nesta posicao. Pontuacao: 0.\n");// caso o jogador coloque uma coordenada que não possui barco na posição indicada
      return 0;//finaliza esse laço
    }
    } else{// caso o requesito não se encaixe nas comparações acima ele prosseguirá para a linha abaixo
        printf("Jogada invalida. Digite valores entre 0 e 3.\n");// quando o usuário digitar uma coordenada inexistente no campo
    }
    }
}
    
void posicionarbarco(int campo[4][4], int n){
   int posicao_x,posicao_y;
    while(1){
    printf("\nPosicao X: "); scanf("%d", &posicao_x);
    printf("Posicao Y: "); scanf("%d", &posicao_y);
    if (posicao_x >= 0 && posicao_x < 4 && posicao_y >= 0 && posicao_y < 4 && campo[posicao_x][posicao_y] == 0) {
            campo[posicao_x][posicao_y] = n+1;
            n++;
            break;
        }else {
            printf("\nPosicao invalida ou ja ocupada! Digite valores entre 0 e 3 para linha e coluna.\n");
        }
    }
}

int main(){
  int campo1 [4][4], campo2 [4][4]; // Declara duas matrizes 4x4, para os campos dos dois jogadores.
  char jogador1[61], jogador2[61]; // Declara arrays de caracteres para armazenar os nomes dos jogadores.
  int pontos1 = 0,pontos2 = 0; // Atribui as variáveis para marcação de pontos dos jogadores, começando com 0 pontos para ambos.
  printf("\n\t\t\tBATALHA NAVAL\t\t\t\n"); //Printa na tela o título do jogo.
  printf("\n\n\t---------------------------------------------\n\n");
  printf("Jogador 1, digite seu nome: "); //Permite com que o jogador 1 digite seu nome.
  scanf("%s", jogador1); //Armazena o nome do jogador 1 na variável em questão, sendo do tipo "char".
  printf("Jogador 2, digite seu nome: "); //Permite com que o jogador 2 digite seu nome.
  scanf("%s", jogador2); //Armazena o nome do jogador 2 na variável em questão, sendo do tipo "char".
  for(int i = 0;i<4;i++){ //Criação de uma estrutura de repetição para preencher as posições do campo do usuário com "0", inibindo que o programa preencha as posições não usadas com valores indefinidos. Esse laço é referente as linhas da matriz.
    for(int j =0;j<4;j++){ //Laço referente à leitura das colunas da matriz.
        campo1[i][j] = 0; //Preenche todos as posições da matriz "campo1" com o valor "0".
        campo2[i][j] = 0; //Preenche todos as posições da matriz "campo2" com o valor "0".
    }
  }
  
  for (int i=0; i<4; i++){ //Estrutura de repetição que permite o jogador fazer o posicionamento de seus barcos e ainda permite visualizar qual barco está posicionando.
  printf("\n%s posicione seu %do barco\n", jogador1, i+1);
  posicionarbarco(campo1, i); //Utilização de uma função usada para posicionar os barcos. Os parâmetros utilizados serão: a matriz "campo1" do 1º usuário e a variável de repetição que será incrementada a cada rodagem da estrutura e utilizada com valores indo de 0 até 3 dentro da função.
  }
  for (int i=0; i<4; i++){
  printf("\n%s posicione seu %do barco\n", jogador2, i+1);
  posicionarbarco(campo2, i);
  }
 for (int i=0; i<4; i++){
  printf("\n%s, faca sua %d jogada\n", jogador1, i+1);
  pontos1 += jogadas(campo2);
  }
  
  for (int i=0; i<4; i++){
  printf("\n%s, faca sua %d jogada\n", jogador2, i+1);
  pontos2 += jogadas(campo1);
  }

  printf("\t\nPontuacao final:\t\n");
  printf("%s: %d pontos\n",jogador1,pontos1);
  printf("%s: %d pontos\n",jogador2,pontos2);

  if(pontos1 > pontos2){ //condicional para verificar se o jogador1 ganhou.
    printf("\n%s EH O VENCEDOR!\n", jogador1);//Se sim, irá printar que ele é o vencedor.
  }else if(pontos2 > pontos1){//condicional para verificar se o jogador2 ganhou.
    printf("\n%s EH O VENCEDOR!\n", jogador2);//Se sim, irá printar que ele é o vencedor.
  }else{//Caso nenhuma das duas condições sejam atendidas, irá resultar em um empate.
    printf("\nEMPATE!\n");//Printa que o jogo empatou.
  }
}
