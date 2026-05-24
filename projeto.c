#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max_livros 100

struct Livros{
    int codigo;
    char titulo[50];
    int ano;
    int quantidade;
};
int carregar_livros(struct Livros livros[]){
    FILE *arquivo = fopen("livros.txt","r");
    if(arquivo == NULL){ 
        printf("erro ao abrir aquivo 'livros.txt'.\n");
        return 0;
    }
    int i = 0; //cria inicio do vetor
    while(fscanf(arquivo, "%d %s %d %d",
        &livros[i].codigo,
        livros[i].titulo,
        &livros[i].ano,
        &livros[i].quantidade) == 4){ // ==4 garante que o codigo continua se as 4 informações foram preenchidas
        i++;
    }
    fclose(arquivo);
    return i; //retorna quantidade de livros carregados
}
void adicionar_livros(struct Livros livros[], int *total){ // total deve ser um ponteiro para que seja possivel
    if(*total >= max_livros){                              // modificar o valor da variavel que esta no int main
        printf("memoria do sistema esta cheia, nao eh possivel adicionar mais livros.\n");
        return; //return; encerra a função e volta pro chamador
    }
    printf("\n---CADASTRAR NOVO LIVRO---\n");
    printf("digite codigo do livro: ");
    scanf("%d", &livros[*total].codigo);
    printf("digite titulo: ");
    scanf("%s", livros[*total].titulo); 
    printf("digite ano de publicacao: ");  
    scanf("%d", &livros[*total].ano);
    printf("digite quantidade de livros: ");
    scanf("%d", &livros[*total].quantidade);
        
    (*total)++;
    printf("\nLIVRO CADASTRADO COM SUCESSO!\n");
    printf("total: %d\n", *total);
}
void imprimir_livros(struct Livros livros[], int total){
    if(total == 0){
        printf("nao existe nenhum livro cadastrado\n");
        return; 
    }
    for(int i = 0; i < total; i++){
        printf("Codigo: %d\n", livros[i].codigo);
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Ano: %d\n", livros[i].ano);
        printf("Quantidade: %d\n", livros[i].quantidade);
        printf("\n----------------------------------\n");
    }   
}
void ordenar_e_imprimir(struct Livros livros[], int total){
    if(total == 0){
        printf("nao possui livro cadastrado.\n");
        return;
    }
    struct Livros temp; // temp eh um variavel temporaria
    for(int i = 0; i < total - 1; i++){ // bubblesort para ordenar livros por ano
        for(int j = 0; j < total - i - 1; j++){ // -i evita comparacao
            if(livros[j].ano > livros[j + 1].ano){ 
            temp = livros[j];
            livros[j] = livros[j + 1];
            livros[j + 1] = temp;
            }
        }
    }
    printf("\n--- LIVROS ORDENADOS POR ANO ---\n");
    imprimir_livros(livros, total);
}
void buscar_livros(struct Livros livros[], int total){
    if(total == 0){
        printf("nao possui livros cadastrados para realizar busca.\n");
        return;
    }
    int codigo_pesquisa;
    int encontrado = 0;
    printf("\n--- BUSCAR LIVRO POR CODIGO ---\n");
    printf("digite codigo do livro desejado: ");
    scanf("%d", &codigo_pesquisa);
    for(int i = 0; i < total; i++){
        if(livros[i].codigo == codigo_pesquisa){
            printf("\nLIVRO ENCONTRADO!\n");
            printf("Codigo: %d\n", livros[i].codigo);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Ano de lancamento: %d\n", livros[i].ano);
            printf("Quantidade: %d\n", livros[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if(encontrado == 0){
        printf("\nAVISO: codigo %d eh invalido.\n", codigo_pesquisa);
    }
}
int main(){
    struct Livros biblioteca[max_livros];

    int total_livros = carregar_livros(biblioteca);
    int opcao = 0;

    while(opcao != 5){
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Adicionar livro\n");
        printf("2. Buscar livro por codigo\n");
        printf("3. Imprimir livros\n");
        printf("4. Ordenar por ano e imprimir\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n----------------------------------\n");

        if (opcao == 1) {
            adicionar_livros(biblioteca, &total_livros);
        } else if (opcao == 2) {
            buscar_livros(biblioteca, total_livros);
        } else if (opcao == 3) {
            imprimir_livros(biblioteca, total_livros);
        } else if (opcao == 4) {
            ordenar_e_imprimir(biblioteca, total_livros);
        } else if (opcao == 5) {
            printf("Encerrando o sistema.\n");
        } else {
            printf("OPCAO INVALIDA, TENTE NOVAMENTE!\n");
        }
    }

    return 0;
}