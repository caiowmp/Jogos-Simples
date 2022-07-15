#include<iostream>
#include<string>
#include<time.h>

using namespace std;

void menu_inicial();

void limpa_tela(){
  system("clear");
}

void preenche_tabuleiro(char tabuleiro[10][10], char mascara[10][10]){
  int linha, coluna;

  for(linha = 0; linha < 10; linha++){
    for(coluna = 0; coluna < 10; coluna++){
      tabuleiro[linha][coluna] = 'A';
      mascara[linha][coluna] = '*';
    }
  }
}

void exibe_tabuleiro(char tabuleiro[10][10], char mascara[10][10]){
  int linha, coluna, i;

  cout << "Tabuleiro :" << endl << endl;

  cout << "    ";
  for(i = 0; i<10; i++){
    cout << i+1 << " ";
  }
  cout << endl;
  cout << "    ";
  for(i = 0; i<10; i++){
    cout << "| ";
  }
  cout << endl;

  for(linha = 0; linha < 10; linha++){
    if(linha + 1 == 10){
      cout << linha + 1 << "- ";
    }else{
      cout << linha + 1 << " - ";
    }
    for(coluna = 0; coluna < 10; coluna++){
      cout << mascara[linha][coluna] << " ";
    }
    cout << endl;
  } 

  cout << endl;
  cout << "Legenda:" << endl;
  cout << "A - Agua" << endl << "p - Barco pequeno" << endl << "* - Lugar desconhecido" << endl << endl;
}

bool coordenadasJaEscolhidas(char mascara[10][10], int linha, int coluna){
  if(mascara[linha - 1][coluna - 1] == 'p' || mascara[linha - 1][coluna - 1] == 'A'){
    return true;
  }else{
    return false;
  }
}

void posiciona_barcos(char tabuleiro[10][10]){
  int i = 0;

  while( i < 20){
    int linha = rand() % 10;
    int coluna = rand() % 10;

    if(tabuleiro[linha][coluna] == 'A'){
      tabuleiro[linha][coluna] = 'p';
      i++;
    }else{
      i--;
    }
  }
}

void pontuacao(char tabuleiro[10][10], int linha, int coluna, int *pontos, string *mensagem, char mascara[10][10]){

  if(coordenadasJaEscolhidas(mascara,linha,coluna)){
    *mensagem = "Coordenadas já escolhidas";
  }else{
    switch(tabuleiro[linha - 1][coluna - 1]){
      case 'p':
        *mensagem = "Voce acertou um barco pequeno! (+10 pts)";
        *pontos = *pontos + 10;
      break;

      case 'A':
        *mensagem = "Voce acertou a Agua!";
      break;


    }
  }
  
  
}

void jogo(string nome_jogador){
  char tabuleiro[10][10], mascara[10][10];
  int linha, coluna;
  int status_jogo = 1; // 1 = Jogo rodando. 0 = Fim de jogo.
  int pontos = 0;//Pontuação do jogador.
  int tentativas = 0;
  int opcao;
  string mensagem = "Bem vindo ao jogo";

  preenche_tabuleiro(tabuleiro, mascara);

  posiciona_barcos(tabuleiro);

  while(tentativas < 16){
    limpa_tela();

    exibe_tabuleiro(tabuleiro, mascara);

    cout << mensagem << endl;
    cout << "Pontuacao: " << pontos << endl;

    if(tentativas < 10){
      cout << "Tentativas restantes: " << 10 - tentativas << endl << endl;

      cout << nome_jogador << ", digite uma linha e uma coluna" << endl;
      cin >> linha >> coluna;

      if((linha < 1 || coluna < 1) || (linha > 10 || coluna > 10)){
        mensagem = "Coordenadas invalidas";
        tentativas--;
      }

      if(coordenadasJaEscolhidas(mascara,linha,coluna)){
        tentativas--;
      }

      pontuacao(tabuleiro, linha, coluna, &pontos, &mensagem,mascara);

      mascara[linha - 1][coluna - 1] = tabuleiro[linha - 1][coluna - 1];
    }
    tentativas++;
  }

  cout << "Fim de jogo, o que deseja fazer ?" << endl;
  cout << "1 - Jogar novamente" << endl;
  cout << "2 - Ir para o menu" << endl;
  cout << "3 - Sair" << endl << endl;
  cout << "Escolha uma opcao e tecle Enter" << endl;
  cin >> opcao;

  switch(opcao){
    case 1:
      jogo(nome_jogador);
    break;

    case 2:
      limpa_tela();
      menu_inicial();
    break;

    case 3:
    break;
  }
}

void menu_inicial(){
  int opcao = 0;

  string nome_jogador;

  while(opcao < 1 || opcao > 3){
    cout << endl << "Bem vindo ao jogo de Batalha Naval!" << endl << endl ;
    cout << "1 - Jogar" << endl;
    cout << "2 - Sobre" << endl;
    cout << "3 - Sair" << endl;
    cout << endl << "Escolha uma opcao e tecle ENTER" << endl;
    cin >> opcao;

    limpa_tela();

    switch(opcao){
      case 1: 
        cout << "Jogo iniciado" << endl << endl;
        cout << "Qual seu nome ?" << endl;
        cin >> nome_jogador;
        jogo(nome_jogador);
      break;

      case 2:
        cout << "Informacoes do jogo:" << endl;
        cout << "Jogo desenvolvido por Caio em 2020" << endl; 
      break;

      case 3:
        cout << "Ate mais" << endl;
      break;
    }
  }


}

int main(){ 
  //Gera numeros aleatorios.
  srand((unsigned)time(NULL));  

  menu_inicial();

}