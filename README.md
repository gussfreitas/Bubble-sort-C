# Gerenciador de Jogadores (Lista Encadeada + Bubble Sort)

Projeto em C que cadastra jogadores em uma **lista encadeada** simples e permite **exibir** e **ordenar por matrícula** utilizando o algoritmo **Bubble Sort**. O programa é interativo via menu no terminal.

> Código-fonte principal: `Bubble correto.cpp` (estrutura `Jogador`, menu com cadastro/exibição e ordenação por matrícula). fileciteturn0file0  
> Conteúdo idêntico também disponibilizado em `Código caso precisar.docx`. fileciteturn0file1

---

## ✨ Funcionalidades

- **Cadastrar jogador** (nome, matrícula, time, número da camisa) em uma lista encadeada (inserção no início)
- **Exibir jogadores** cadastrados
- **Ordenar por matrícula** usando Bubble Sort (troca de dados entre nós)
- **Sair** do programa

---

## 🧱 Estrutura de Dados

Cada jogador é representado pela struct:

```c
typedef struct Jogador {
    char nome[50];
    int matricula;
    char time[50];
    int numeroCamisa;
    struct Jogador* next;
} Jogador;
```

A inserção é feita no **início da lista** e a ordenação utiliza Bubble Sort, percorrendo a lista e **trocando os campos** dos nós adjacentes quando fora de ordem (criterio: `matricula`). fileciteturn0file0

---

## 🧪 Menu (Interface de Linha de Comando)

```
=== MENU ===
1. Adicionar jogador
2. Exibir jogadores
3. Ordenar por matricula
4. Sair
```

Fluxo típico:
1) Cadastre alguns jogadores  
2) Exiba a lista (na ordem de cadastro)  
3) Ordene por matrícula  
4) Exiba novamente para ver o resultado

---

## ▶️ Como Compilar e Executar

> Requisitos: GCC/MinGW ou qualquer compilador C compatível.

### Windows (MinGW / MSYS2)
```bash
gcc "Bubble correto.cpp" -Wall -Wextra -O2 -o bubble.exe
.\bubble.exe
```

### Linux / WSL / macOS (Clang/GCC)
```bash
gcc "Bubble correto.cpp" -Wall -Wextra -O2 -o bubble
./bubble
```

> Um executável de exemplo (`Bubble correto.exe`) pode ser usado no Windows clicando duas vezes ou pelo terminal: `.\Bubble correto.exe`.

---

## 💡 Exemplo de Execução (ilustrativo)

```
=== MENU ===
1. Adicionar jogador
2. Exibir jogadores
3. Ordenar por matricula
4. Sair
Escolha uma opcao: 1
Digite o nome do jogador: Ana
Digite a matricula do jogador: 123
Digite o time do jogador: Tigres
Digite o numero da camisa do jogador: 10

=== MENU ===
1. Adicionar jogador
2. Exibir jogadores
3. Ordenar por matricula
4. Sair
Escolha uma opcao: 1
Digite o nome do jogador: Bruno
Digite a matricula do jogador: 45
Digite o time do jogador: Lobos
Digite o numero da camisa do jogador: 8

=== MENU ===
1. Adicionar jogador
2. Exibir jogadores
3. Ordenar por matricula
4. Sair
Escolha uma opcao: 2

Nome: Bruno
Matricula: 45
Time: Lobos
Numero da Camisa: 8

Nome: Ana
Matricula: 123
Time: Tigres
Numero da Camisa: 10

=== MENU ===
1. Adicionar jogador
2. Exibir jogadores
3. Ordenar por matricula
4. Sair
Escolha uma opcao: 3
Lista ordenada por matricula!

=== MENU ===
1. Adicionar jogador
2. Exibir jogadores
3. Ordenar por matricula
4. Sair
Escolha uma opcao: 2

Nome: Bruno
Matricula: 45
Time: Lobos
Numero da Camisa: 8

Nome: Ana
Matricula: 123
Time: Tigres
Numero da Camisa: 10
```

---

## 🗂️ Estrutura Sugerida do Repositório

```
.
├── Bubble correto.cpp         # Código-fonte principal (C)
├── Bubble correto.exe         # Executável (Windows) - opcional
├── Codigo caso precisar.docx  # Cópia do código (documento)
└── README.md                  # Este arquivo
```

---

## 🔧 Dicas de Desenvolvimento

- Use `-Wall -Wextra` para avisos úteis de compilação
- Ao ordenar, o algoritmo **troca os campos dos nós** (nome, matrícula, time, número), evitando mexer nos ponteiros da lista. fileciteturn0file0
- Antes de sair, o programa **libera toda a memória** percorrendo a lista e chamando `free` em cada nó. fileciteturn0file0

---

## 🧭 Próximos Passos (Ideias)
- Persistência em arquivo (`.csv`/`.txt`) para salvar e carregar a lista
- Validações adicionais de entrada (comprimento de strings, faixas válidas)
- Ordenações alternativas (por nome/time) e busca por matrícula
- Trocar a estratégia de ordenação para **relink de nós** (sem copiar campos)

---

## 👤 Autor
**Gustavo Almeida de Freitas**. fileciteturn0file1

---

## 📜 Licença
Defina a licença do projeto (ex.: MIT, GPL-3.0). Sugestão: crie um arquivo `LICENSE` na raiz do repositório.
