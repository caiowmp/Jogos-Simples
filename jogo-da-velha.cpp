#include<iostream>
#include<string>
#include<time.h>

using namespace std;

void menu_inicial(string nome1, string nome2);

void limpa_tela(){
  system("clear");
}

void exibe_tabuleiro(char tabuleiro[3][3]){
  int i, j;
  
  cout << endl << "Tabuleiro:" << endl << endl;
  for(i = 0; i<3; i++){
    for(j = 0; j<3; j++){
      cout << tabuleiro[i][j];
    }
    cout << endl;
  }
}

void cria_tabuleiro(char tabuleiro[3][3]){

  int i, j;

  for(i = 0; i<3; i++){
    for(j = 0; j<3; j++){
      tabuleiro[i][j] = '-';
    }
  }
}

void exibe_posicao(){

  cout << endl << "Mapa de posicoes:" << endl;
  cout << endl << "7 | 8 | 9" << endl;
  cout << "4 | 5 | 6" << endl;
  cout << "1 | 2 | 3" << endl;
}

void escolha(char tabuleiro[3][3], int posicao, int *rodada){
  int linha, coluna;
  
  switch(posicao){
    case 7:
      linha = 0;
      coluna = 0;
      if(tabuleiro[linha][coluna] == '-'){
        if(*rodada%2 == 1){
          tabuleiro[linha][coluna] = 'X';
        }else{
          tabuleiro[linha][coluna] = 'O';
        }
      }else{
        *rodada  = *rodada - 1;
      }     
    break;

    case 8:
      linha = 0;
      coluna = 1;
      if(tabuleiro[linha][coluna] == '-'){
        if(*rodada%2 == 1){
          tabuleiro[linha][coluna] = 'X';
        }else{
          tabuleiro[linha][coluna] = 'O';
        }
      }else{
        *rodada  = *rodada - 1;
      }
    break;

    case 9:
      linha = 0;
      coluna = 2;
      if(tabuleiro[linha][coluna] == '-'){
        if(*rodada%2 == 1){
          tabuleiro[linha][coluna] = 'X';
        }else{
          tabuleiro[linha][coluna] = 'O';
        }
      }else{
        *rodada  = *rodada - 1;
      }
    break;

    case 4:
      linha = 1;
      coluna = 0;
      if(tabuleiro[linha][coluna] == '-'){
        if(*rodada%2 == 1){
          tabuleiro[linha][coluna] = 'X';
        }else{
          tabuleiro[linha][coluna] = 'O';
        }
      }else{
        *rodada  = *rodada - 1;
      }
    break;

    case 5:
      linha = 1;
      coluna = 1;
      if(tabuleiro[linha][coluna] == '-'){
        if(*rodada%2 == 1){
          tabuleiro[linha][coluna] = 'X';
        }else{
          tabuleiro[linha][coluna] = 'O';
        }
      }else{
        *rodada  = *rodada - 1;
      }
    break;

    case 6:
      linha = 1;
      coluna = 2;
      if(tabuleiro[linha][coluna] == '-'){
        if(*rodada%2 == 1){
          tabuleiro[linha][coluna] = 'X';
        }else{
          tabuleiro[linha][coluna] = 'O';
        }
      }else{
        *rodada  = *rodada - 1;
      }
    break;

    case 1:
      linha = 2;
      coluna = 0;
      if(tabuleiro[linha][coluna] == '-'){
        if(*rodada%2 == 1){
          tabuleiro[linha][coluna] = 'X';
        }else{
          tabuleiro[linha][coluna] = 'O';
        }
      }else{
        *rodada  = *rodada - 1;
      }
    break;

    case 2:
      linha = 2;
      coluna = 1;
      if(tabuleiro[linha][coluna] == '-'){
        if(*rodada%2 == 1){
          tabuleiro[linha][coluna] = 'X';
        }else{
          tabuleiro[linha][coluna] = 'O';
        }
      }else{
        *rodada  = *rodada - 1;
      }
    break;

    case 3:
      linha = 2;
      coluna = 2;
      if(tabuleiro[linha][coluna] == '-'){
        if(*rodada%2 == 1){
          tabuleiro[linha][coluna] = 'X';
        }else{
          tabuleiro[linha][coluna] = 'O';
        }
      }else{
        *rodada  = *rodada - 1;
      }
    break;
    }
}

int ganhou(char tabuleiro[3][3]){
  int i, j;

  //Analisando Linhas.
  for(i = 0; i<3; i++){
    if(tabuleiro[i][0] == 'X' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
      return 1;
    }
    else if(tabuleiro[i][0] == 'O' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
      return 2;
    }
  }

  //Analisando Colunas.
  for(j = 0; j<3; j++){
    if(tabuleiro[0][j] == 'X' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]){
      return 1;
    }
    else if(tabuleiro[0][j] == 'O' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]){
      return 2;
    }
  }
    
  //Analisando Diagonal Principal.
  if(tabuleiro[0][0] == 'X' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
    return 1;
  }else if(tabuleiro[0][0] == 'O' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
    return 2;
  }

  //Analisando Diagonal Secundaria.
  if(tabuleiro[0][2] == 'X' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
    return 1;
  }else if(tabuleiro[0][2] == 'O' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
    return 2;
  }
    
  //Deu velha.
  else{
    return 0;
  }  
}

void jogo(string nome1, string nome2, int pontuacao1, int pontuacao2){
  char tabuleiro[3][3];
  int posicao;
  int rodada = 1;
  string nome_atual;
  int opcao;

  cria_tabuleiro(tabuleiro);

  while(rodada < 10){
    limpa_tela();

    exibe_tabuleiro(tabuleiro);
    exibe_posicao();

    //Atualisando nome do jogador a cada rodada.
    if(rodada%2 == 1){
      nome_atual = nome1;
    }else{
      nome_atual = nome2;
    }

    cout << nome_atual << ", escolha uma posicao e tecle Enter" << endl;
    cin >> posicao;

    if(posicao < 1 || posicao > 9){
      rodada--;
    }else{
      escolha(tabuleiro, posicao, &rodada);

      ganhou(tabuleiro);
    }

    if(ganhou(tabuleiro) == 1){
      limpa_tela();
      exibe_tabuleiro(tabuleiro);
      cout << "Fim de jogo!" << endl;
      cout << nome1 <<" ganhou" << endl;
      pontuacao1 += 10;
      break;
    }else if(ganhou(tabuleiro) == 2){
      limpa_tela();
      exibe_tabuleiro(tabuleiro);
      cout << "Fim de jogo!" << endl;
      cout << nome2 <<" ganhou" << endl;
      pontuacao2 += 10;
      break;
    }else{
      limpa_tela();
      exibe_tabuleiro(tabuleiro);
      cout << "Fim de jogo!" << endl;
      cout << "Deu velha" << endl;
    }

    rodada++;
  }

  cout << "Pontuacao:" << endl;
  cout << nome1 << ": " << pontuacao1 << " pontos" << endl;
  cout << nome2 << ": " << pontuacao2 << " pontos" << endl << endl;
  cout << "Jogar novamente ?" << endl << endl;
  cout << "1 - Sim" << endl;
  cout << "2 - Nao" << endl;
  cin >> opcao; 

  switch(opcao){
    case 1:
    jogo(nome1, nome2, pontuacao1, pontuacao2);
    break;

    case 2:
      limpa_tela();
      cout << "Ate mais!" << endl;
    break;
  }
}

void menu_inicial(string nome1, string nome2){
  int opcao = 0;

  while(opcao < 1 || opcao > 3){
    
    cout << "Bem vindo ao jogo!! " << endl << endl;
    cout << "1 - Jogar" << endl;
    cout << "2 - Sobre" << endl;
    cout << "3 - Sair" << endl;
    cout << endl << "Escolha uma opcao e tecle ENTER" << endl;
    cin >> opcao;

    limpa_tela();
  
    switch(opcao){
      case 1: 
        cout << "Digite o nome do Jogador 1: " << endl;
        cin >> nome1;
        cout << endl << "Digite o nome do jogador 2:" << endl;
        cin >> nome2; 
        jogo(nome1, nome2,0, 0);     
      break;

      case 2:
        cout << "Informacoes do jogo:" << endl;
        cout << " Jogo criado por Caio Miranda Pereira em 2020" << endl;
      break;

      case 3:
        cout << "Ate mais" << endl;
      break;
    }
  }
}

int main(){
  string nome1, nome2;

  menu_inicial(nome1, nome2);



}