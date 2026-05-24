Sistema de Gerenciamento de Biblioteca
Este é um sistema de linha de comando acadêmico desenvolvido em Linguagem C para o gerenciamento básico de um acervo de livros. O projeto armazena os dados em memória através de estruturas (struct) utilizando alocação estática e permite a leitura de dados salvos em um arquivo de texto.

🚀 Funcionalidades
Carregamento Automático: Ao iniciar, o programa lê o arquivo livros.txt e popula a memória com os dados salvos (código, título, ano e quantidade).

Adicionar Novo Livro: Permite cadastrar novos livros diretamente pelo terminal.

Buscar Livro por Código: Realiza uma busca sequencial no vetor estático para encontrar e exibir as informações de um item.

Imprimir Acervo: Exibe uma listagem formatada de todos os livros atualmente carregados na memória.

Ordenar por Ano: Reorganiza o vetor utilizando o algoritmo Bubble Sort para listar os livros em ordem cronológica.

⚠️ Limitações Conhecidas
Uso de Memória Engessado: O sistema utiliza um vetor com limite máximo hardcoded de 100 livros, não possuindo alocação dinâmica.

Baixo Desempenho de Ordenação e Busca: Utiliza Bubble Sort e busca linear. Inadequado para volumes reais de dados.

Entrada de Strings: A leitura de títulos com scanf("%s") funciona corretamente, mas não permite espaços no titulo.

🛠️ Estrutura do Código
O código foi dividido nas seguintes funções:

carregar_livros: Manipulação de arquivos (FILE, fopen, fscanf) para obtenção de dados.

adicionar_livros: Entrada de dados com tratamento de buffer (getchar).

imprimir_livros: Exibição formatada dos dados na tela.

ordenar_e_imprimir: Algoritmo de ordenação Bubble Sort operando sobre o array de structs.

buscar_livros: Algoritmo de busca sequencial.

main: Menu interativo baseado em laço while e controle de fluxo com if/else.

📦 Como Executar
Pré-requisitos
Certifique-se de ter um compilador C instalado no seu sistema (como o gcc).

Passo 1: Preparar o Arquivo de Dados
Crie um arquivo chamado livros.txt no mesmo diretório do código-fonte. O formato dos dados deve seguir o padrão separado por espaços, com uma quebra de linha no final de cada registro. Exemplo:
```text
101 Algoritmos 2020 5  
102 BancoDeDados 2018 3  
103 Redes 2022 7  
104 Compiladores 2015 2  
105 EstruturasDeDados 2021 6
```

### Passo 2: Compilar
Abra o terminal na pasta do projeto e execute o seguinte comando:

```bash
gcc -o biblioteca projeto.c
```

### Passo 3: Executar o programa
```bash
./biblioteca
```
📝 Estrutura de Dados
```
struct Livros {
    int codigo;
    char titulo[50];
    int ano;
    int quantidade;
};
```
