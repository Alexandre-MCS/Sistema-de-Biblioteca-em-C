<<<<<<< HEAD
# Sistema de Gerenciamento de Biblioteca

Este é um sistema de linha de comando acadêmico desenvolvido em **Linguagem C** para o gerenciamento básico de um acervo de livros. O projeto armazena os dados em memória através de estruturas (`struct`) utilizando alocação estática e permite a leitura de dados salvos em um arquivo de texto.

## 🚀 Funcionalidades

1. **Carregamento Automático:** Ao iniciar, o programa lê o arquivo `livros.txt` e popula a memória com os dados salvos (Código, título, ano e quantidade).
2. **Adicionar Novo Livro:** Permite cadastrar novos livros diretamente pelo terminal.
3. **Buscar Livro por Código:** Realiza uma busca sequencial no vetor estático para encontrar e exibir as informações de um item.
4. **Imprimir Acervo:** Exibe uma listagem formatada de todos os livros atualmente carregados na memória.
5. **Ordenar por Ano:** Reorganiza o vetor utilizando o algoritmo **Bubble Sort** para listar os livros em ordem cronológica.

## ⚠️ Limitações Conhecidas (Aviso Técnico)

* **Uso de Memória Engessado:** O sistema utiliza um vetor com limite máximo *hardcoded* de 100 livros, não possuindo alocação dinâmica.
* **Baixo Desempenho de Ordenação e Busca:** Utiliza Bubble Sort (complexidade $O(n^2)$) e busca linear (complexidade $O(n)$). Inadequado para volumes reais de dados.
* **Potencial Falha no Parser:** A documentação original cita o uso de `%[^\n]` para leitura de strings em um arquivo com delimitadores `;`. Isso pode causar bugs na importação dos campos numéricos adjacentes.

## 🛠️ Estrutura do Código

O código foi dividido nas seguintes funções:

* `carregar_livro`: Manipulação de arquivos (`FILE`, `fopen`, `fscanf`) para obtenção de dados.
* `adicionar_livro`: Entrada de dados com tratamento de buffer (`getchar`).
* `imprimir_livro`: Exibição formatada dos dados na tela.
* `ordenar_e_imprimir`: Algoritmo de ordenação Bubble Sort operando sobre o array de structs.
* `buscar_livro`: Algoritmo de busca sequencial.
* `main`: Menu interativo baseado na estrutura de repetição `do-while` e controle de fluxo com `switch-case`.

## 📦 Como Executar

### Pré-requisitos
Certifique-se de ter um compilador C instalado no seu sistema (como o `gcc`).

### Passo 1: Preparar o Arquivo de Dados
Crie um arquivo chamado `livros.txt` no mesmo diretório do código-fonte. O formato dos dados deve seguir o padrão separado por ponto e vírgula `;`, com uma quebra de linha no final de cada registro. Exemplo:
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
gcc -o biblioteca main.c
```

### Passo 3: Executar o programa
```bash
./biblioteca
```

### 📝 Formato da Estrutura de Dados

```c
typedef struct {
    int codigo;
    char titulo[30];
    int ano;
    int quantidade;
} Livro;
```
