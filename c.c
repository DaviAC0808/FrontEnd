#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define TAMANHO_PILHA 100 // Tamanho m�ximo das pilhas

// Definindo a estrutura da pilha
typedef struct pilha
{
    int topo;                 // �ndice do topo da pilha
    int itens[TAMANHO_PILHA]; // Vetor que armazena os itens da pilha
} Pilha;

// Fun��o para criar uma nova pilha vazia
Pilha criarPilha()
{
    Pilha p;
    p.topo = -1;
    return p;
}

// Fun��o para verificar se a pilha est� vazia
bool pilhaVazia(Pilha p)
{
    return p.topo == -1;
}

// Função para verificar se a pilha est� cheia
bool pilhaCheia(Pilha p)
{
    return p.topo == TAMANHO_PILHA - 1;
}

// Fun��o para inserir um valor na pilha
void inserirValor(Pilha *p, int valor)
{
    if (pilhaCheia(*p))
    {
        printf("Erro: pilha cheia.\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = valor;
}

// Função para remover um valor da pilha
void removerValor(Pilha *p)
{
    if (pilhaVazia(*p))
    {
        printf("Erro: pilha vazia.\n");
        return;
    }
    p->topo--;
}

// Fun��o para mostrar o conte�do de uma pilha
void mostrarPilha(Pilha p)
{
    printf("[ ");
    for (int i = p.topo; i >= 0; i--)
    {
        printf("%d ", p.itens[i]);
    }
    printf("]\n");
}

// Fun��o para mostrar a quantidade de valores em cada pilha
void mostrarQuantidade(Pilha p1, Pilha p2, Pilha p3)
{
    printf("\nQuantidade de valores na pilha 1: %d\n", p1.topo + 1);
    printf("\nQuantidade de valores na pilha 2: %d\n", p2.topo + 1);
    printf("\nQuantidade de valores na pilha 3: %d\n", p3.topo + 1);
}

// Fun��o para limpar todas as pilhas
void limparPilhas(Pilha *p1, Pilha *p2, Pilha *p3)
{
    *p1 = criarPilha();
    *p2 = criarPilha();
    *p3 = criarPilha();
}

// Fun��o principal
int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    
    int opcao;
    Pilha pilha1 = criarPilha();
    Pilha pilha2 = criarPilha();
    Pilha pilha3 = criarPilha();

    while (true)
    {
        // Mostra o menu de op��es
        
        printf("\n===== M E N U =====\n");
        printf("\nEscolha uma op��o:\n");
        printf("1 - Inserir valor na pilha 1\n");
        printf("2 - Inserir valor na pilha 2\n");
        printf("3 - Inserir valor na pilha 3\n");
        printf("========================\n");
        printf("4 - Remover valor da pilha 1\n");
        printf("5 - Remover valor da pilha 2\n");
        printf("6 - Remover valor da pilha 3\n");
        printf("========================\n");
        printf("7 - Mostrar conte�do das pilhas\n");
        printf("8 - Mostrar quantidade de valores em cada pilha\n");
        printf("9 - Limpar todas as pilhas\n");
        printf("========================\n");
        printf("0 - Sair\n");

        // L� a op��o escolhida pelo usu�rio
        scanf("%d", &opcao);

        // Executa a opera��o escolhida pelo usu�rio
        switch (opcao)
        {
        case 1:
            printf("\nDigite o valor a ser inserido na pilha 1: ");
            int valor1;
            scanf("%d", &valor1);
            inserirValor(&pilha1, valor1);
            break;
        case 2:
            printf("\nDigite o valor a ser inserido na pilha 2: ");
            int valor2;
            scanf("%d", &valor2);
            inserirValor(&pilha2, valor2);
            break;
        case 3:
            printf("\nDigite o valor a ser inserido na pilha 3: ");
            int valor3;
            scanf("%d", &valor3);
            inserirValor(&pilha3, valor3);
            break;
        case 4:
            removerValor(&pilha1);
            break;
        case 5:
            removerValor(&pilha2);
            break;
        case 6:
            removerValor(&pilha3);
            break;
        case 7:
            printf("\nConte�do da pilha 1: ");
            mostrarPilha(pilha1);
            printf("\nConte�do da pilha 2: ");
            mostrarPilha(pilha2);
            printf("\nConte�do da pilha 3: ");
            mostrarPilha(pilha3);
            break;
        case 8:
            mostrarQuantidade(pilha1, pilha2, pilha3);
            break;
        case 9:
            limparPilhas(&pilha1, &pilha2, &pilha3);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Op��o inv�lida.\n");
            break;
        }
    }

    return 0;
}