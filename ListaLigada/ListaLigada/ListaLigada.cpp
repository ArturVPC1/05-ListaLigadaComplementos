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
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
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
	// se a lista ja possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
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
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	if (posicaoElemento(novo->valor) != NULL) {
		cout << "Ja existe esse valor\n";
		return;
	}
	novo->prox = NULL;
	ultimo = novo;
	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		// procura o final da lista
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
		ultimo = novo;
	}
}

void buscarElemento()
{
	int valorBusca;
	cout << "Digite um valor para ser buscado: ";
	cin >> valorBusca;

	NO* result = posicaoElemento(valorBusca);

	if (result != NULL) {
		cout << "O valor foi encontrado na lista\n";
		return;
	}
	cout << "O valor nao foi encontrado na lista\n";
}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}

void excluirElemento()
{
	int valorDeletar;
	cout << "Digite o valor a ser deletado: \n";
	cin >> valorDeletar;
	NO* knotToDelete = posicaoElemento(valorDeletar);
	if (knotToDelete == NULL || primeiro == NULL) {
		cout << "O valor nao foi encontrado para ser deletado ou a lista está vazia\n";
		return;
	}
	if (knotToDelete->prox != NULL) {
		NO* knotToSearch = primeiro;
		NO* previousKnot = NULL;
		while (knotToSearch->valor != valorDeletar && knotToSearch->prox != NULL) {
			previousKnot = knotToSearch;
			knotToSearch = knotToSearch->prox;
		}
		if (previousKnot == NULL) { //caso onde precisamos deletar o primeiro elemento
			primeiro = primeiro->prox;
			return;
			if (primeiro == ultimo) { //caso onde precisamos deletar o único elemento da lista
				primeiro = NULL;
				return;
			}
		}
		if (knotToSearch->prox == NULL) {//caso onde precisamos deletar o útlimo elemento
			previousKnot->prox = NULL;
			free(knotToSearch);
			return;
		}
		previousKnot->prox = knotToSearch->prox;
		free(knotToSearch);
		cout << "Lista atual\n";
		exibirElementos();
	}
}