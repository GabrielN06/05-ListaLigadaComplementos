#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls");
		cout << "Menu Lista Ordenada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;

		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;

	cout << "Lista inicializada \n";
}


void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL){
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL){
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	NO* novo = (NO*)malloc(sizeof(NO));
	NO* atual = primeiro;
	NO* anterior = NULL;

	if (novo == NULL){
		return;
	}

	cout << "Digite um elemento que gostaria de inserir na lista: \n";
	cin >> novo->valor;
	novo->prox = NULL;

	while (atual != NULL && atual->valor < novo->valor){
		anterior = atual;
		atual = atual->prox;
	}

	if (atual != NULL && atual->valor == novo->valor){
		cout << "numero existe \n";
		free(novo);
		return;
	}

	if (anterior == NULL){
		novo->prox = primeiro;
		primeiro = novo;
	}else{
		novo->prox = atual;
		anterior->prox = novo;
	}

	if (novo->prox == NULL){
		ultimo = novo;
	}

}

void excluirElemento()
{
	int excluir;
	NO* atual = primeiro;
	NO* anterior = NULL;

	cout << "Por favor, digite o elemento que voce gostaria de excluir: \n";
	cin >> excluir;


	while (atual != NULL){


		if (atual->valor == excluir){

			if (anterior == NULL){
				primeiro = atual->prox;
			}else{
				anterior->prox = atual->prox;
			}

			if (atual->prox == NULL) {
				ultimo = anterior;
			}

			free(atual);
			cout << "elemento excluido com sucesso!\n";
			return;
		}

		if (atual->valor > excluir){
			cout << "elemento nao encontrado na lista\n";
			return;
		}

		anterior = atual;
		atual = atual->prox;
	}
	cout << "elemento nao encontrado na lista\n"; 
}

void buscarElemento()
{
	NO* aux = primeiro;
	int digitado;

	cout << "Digite o elemento que voce gostaria de buscar: ";
	cin >> digitado;

	while (aux != NULL){

		if (aux->valor == digitado){
			cout << "elemento encontrado na lista!\n";
			return;
		}

		if (aux->valor > digitado){
			cout << "elemento nao encontrado na lista!\n";
			break;
		}
		aux = aux->prox;
	}
	cout << "elemento nao encontrado na lista!\n";
}



