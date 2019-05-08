#include <iostream>
using namespace std;

//variaveis GLOBAIS
int tamanho_vetor, tamanho_vetor_preechido = 0;
int *lista = new int[tamanho_vetor];

//declara metodos
int buscaElemento(int x);
void insereElemento(int x);
void removeElemento(int x);

//funcao principal
int main(){
	bool encerra_programa = false;
	int opcao, x, indice;
	
	cout << "Escolha um tamanho para a lista: ";
	cin >> tamanho_vetor;
	lista[tamanho_vetor];

	while (encerra_programa == false){
		cout << "\n***** MENU LISTA *****\n";
		cout << "[01] insere elemento na lista.." << endl;
		cout << "[02] remove elemento na lista.." << endl;
		cout << "[03] busca elemento na lista..." << endl;
		cout << "[04] encerrar programa........." << endl;

		cout << "Opção: ";
		cin >> opcao;

		switch(opcao){
			case 1:
				cout << "\nDigite um valor para inserir: ";
				cin >> x;
				insereElemento(x);
				break;
			case 2:
				cout << "\nDigite um valor para remover: ";
				cin >> x;
				removeElemento(x);
				break;
			case 3:
				cout << "\nDigite um valor para buscar: ";
				cin >> x;
				indice = buscaElemento(x);
				if(indice != -1){
					cout << "\nO elemento " << lista[indice] << " foi encontrado na posição: " << indice << endl; 
				}
				else{
					cout << "\nElemento " << x << " não encontrado\n";
				}
				break;
			case 4:
				encerra_programa = true;
				cout << "\nEncerrando programa, lista final..\n";
				break;
		}

		for (int i = 0; i < tamanho_vetor_preechido; ++i){
			cout << lista[i] << " ";
		}
		cout << endl;
	}
	delete[] lista;
	return 0;
}

//metodos
int buscaElemento(int x){
	int esquerda, direita, meio, c;
	esquerda = 0;
	direita = tamanho_vetor;

	while(esquerda < direita and c <= (tamanho_vetor/2)){
		meio = (esquerda + direita) / 2;
		if (lista[meio] == x){
			return meio;
		}
		else if (lista[meio] < x){
			esquerda = meio;
			c++;
		}
		else{
			direita = meio;
			c++;
		}
	}
	return -1;
}

void insereElemento(int x){
	if (tamanho_vetor_preechido < tamanho_vetor){
		if (buscaElemento(x) == -1){
			lista[tamanho_vetor_preechido] = x;
			tamanho_vetor_preechido++;
		}
		else{
			cout << "\nElemento já existente." << endl;
		}
	}
	else{
		cout << "\n<> Overflow <> não a espaço para o numero: " << x << endl;
	}
}

void removeElemento(int x){
	int indice;
	if(tamanho_vetor_preechido != 0){
		indice = buscaElemento(x);
		if(x == lista[indice]){
			for (int i = indice; i < tamanho_vetor_preechido; ++i){
				lista[i] = lista[i+1];
			}
			tamanho_vetor_preechido--;
		}
		else{
			cout << "\nElemento " << x <<" não existente na lista." << endl;
		}
	}
	else{
		cout << "\nUnderflow\n." << endl;
	}
}
