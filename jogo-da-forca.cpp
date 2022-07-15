#include<iostream>
#include<string>
#include<time.h>

using namespace std;

void limpa_tela(){
  system("clear");
}

string palavra_aleatoria(){
  string palavras[3] = {"abacaxi", "manga", "goiaba"};

  int indice_aleatorio = rand() % 3;

  return palavras[indice_aleatorio];
}

string palavra_mascarada(string palavra){
  int i;
  string palavra_escondida;

  for(i = 0; i<palavra.size(); i++){
    palavra_escondida += "_";
  }

  return palavra_escondida;
}

void status(string palavra, int tentativas, string palavra_escondida, string letras_arriscadas, string mensagem){
  cout << mensagem << endl;
  cout << "Palavra: " << palavra_escondida << endl;
  cout << "Tamanho da palavra: " << palavra.size() << endl;
  cout << "Tentativas restantes: " << 10 - tentativas << endl;
  cout << "Letras ja arriscadas: ";
  
  int i;

  for(i = 0; i<letras_arriscadas.size(); i++){
    cout << letras_arriscadas[i] << " ";
  }

  cout << endl;
}

int jogar(int qnt_jogadores){
  string palavra;

  if(qnt_jogadores == 1){
    palavra = palavra_aleatoria();
  }else{
    cout << "Escolha uma palavra" << endl;
    cin >> palavra;

    limpa_tela();
  }

  int tentativas = 0;
  char letra; //Letra a ser analisada.
  int i; //Contador pra repetição.

  string palavra_escondida;
  palavra_escondida = palavra_mascarada(palavra);

  string resultado = "Voce ganhou!";
  string letras_arriscadas;
  string mensagem = "Escolha uma letra";

  bool letra_repetida = false;
  bool acerto = false;

  int opcao; //Opcao ao final do jogo.

  while(palavra != palavra_escondida && tentativas < 10){

    status(palavra, tentativas, palavra_escondida, letras_arriscadas, mensagem);
    
    cout << endl << "Digite uma letra" << endl;
    cin >> letra;

    for(i = 0; i < tentativas; i++){
      if(letras_arriscadas[i] == letra){
        letra_repetida = true;

        mensagem = "Essa letra ja foi digitada";
      }
    }

    if(letra_repetida == false){

      letras_arriscadas += tolower(letra); //tolower transforma uma letra maiuscula em minuscula.

      for(i = 0; i<palavra.size(); i++){
        if(palavra[i] == tolower(letra)){
          palavra_escondida[i] = palavra[i];
          mensagem = "Voce acertou uma letra";

          acerto = true;
        }
      }
      if(acerto == false){
        mensagem = "Voce errou";
        tentativas++;
      }
    }

    limpa_tela();

    acerto = false;
    letra_repetida = false;
  }

  if(tentativas == 10){
    resultado = "Voce perdeu!";
  }
  
  cout << resultado << endl;
  cout << "Deseja reiniciar ?" << endl;
  cout << "1 - Sim" << endl;
  cout << "2 - Não" << endl;
  cin >> opcao;
  limpa_tela();
  return opcao;
}

void menu_inicial(){
  int opcao = 0;

  while(opcao < 1 || opcao > 4){
    cout << "Bem vindo ao jogo" << endl;
    cout << "1 - Jogar Solo" << endl;
    cout << "2 - Jogar em Dupla" << endl;
    cout << "3 - Sobre" << endl;
    cout << "4 - Sair" << endl;
    cout << endl << "Escolha uma opcao e tecle ENTER" << endl;
    cin >> opcao;

    limpa_tela();

    switch(opcao){
      case 1:
        cout << "Jogo inicado" << endl << endl;
        if(jogar(1) == 1){
          menu_inicial();
        }
      break;

      case 2:
        cout << "Jogo inicado" << endl << endl;
        if(jogar(2) == 1){
          menu_inicial();
        }
      break;

      case 3:
        cout << "Informacoes do jogo:" << endl;
        cout << "Jogo desenvolvido por Caio em 2020" << endl; 
        cout << "1 - Voltar" << endl;
        cout << "2 - Sair" << endl;
        cin >> opcao;
        limpa_tela();
        if(opcao == 1){
          menu_inicial();
        }
      break;

      case 4:
        cout << "Ate mais" << endl;
      break;
    }
  }
}

int main(){

  //Gera números aleatórios.
  srand((unsigned)time(NULL));

  menu_inicial();


}
