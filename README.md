# Lista 6: Árvores e Arborescências (Parte 2) — Algoritmos de Kruskal e Prim

[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/Messias-Mendes-Oficial/Lista-de-Exercicios-6/blob/main/codigo/Lista_6_Teoria_dos_Grafos.ipynb)

📄 **Documentação e Relatórios**

* [Ver Código Completo e Execução no Google Colab](https://colab.research.google.com/github/Messias-Mendes-Oficial/Lista-de-Exercicios-6/blob/main/codigo/Lista_6_Teoria_dos_Grafos.ipynb)
* [Diário de Bordo — Uso de IA](./Di%C3%A1rio%20de%20Bordo%20%E2%80%94%20Uso%20de%20IA)
* [Respostas Completas em PDF e Manuscritas (`respostas/`)](./respostas)
* [Figuras e Gráficos Gerados (`prints/`)](./prints)

Este repositório contém a resolução da **Lista de Exercícios 6** da disciplina de **Teoria dos Grafos** (3º Período — 2026/2), ministrada pelo **Prof. Newarney T. Costa** no **Instituto Federal Goiano — Campus Iporá** (Bacharelado em Ciência da Computação).

O objetivo principal deste trabalho é estudar, comparar e implementar os algoritmos clássicos para obtenção de **Árvores Geradoras Mínimas (AGM / MST)** — **Algoritmo de Kruskal** e **Algoritmo de Prim** — analisando suas estruturas de dados (*Union-Find* vs. *Fila de Prioridade / Matriz de Custos*), complexidades assintóticas ($O(E \log E)$, $O(E \log V)$, $O(V^2)$ e a versão ingênua $O(V^3)$), o comportamento do algoritmo na ausência de atualização do conjunto de vértices visitados (`selected[y] = 1;`) e a aplicação prática na interligação ótima de 5 fábricas com cabos de fibra óptica (em **Python** e **C** no **Google Colab**).

## 👥 Integrantes

* **Messias Junio da Silva Mendes** (Messias-Mendes-Oficial) | **Bruno Alves Mendonça De Abreu Filho**

## 🛠️ Tecnologias Utilizadas

* **Python 3** (Implementação do Algoritmo de Prim, simulações de complexidade e visualização da AGM no Google Colab)
* **Linguagem C (`gcc`)** (Análise, depuração e implementação do esqueleto do Algoritmo de Prim com matriz de custos, compilado via `!gcc` dentro do Google Colab)
* **Google Colab** (Ambiente interativo em nuvem onde rodam todos os códigos em Python e C)
* **Matplotlib & NumPy** (Plotagem dos grafos ponderados e destaque das arestas da Árvore Geradora Mínima)

## 📂 Estrutura do Repositório

| Caminho / Arquivo | Descrição |
| :--- | :--- |
| `codigo/Lista_6_Teoria_dos_Grafos.ipynb` | Notebook principal configurado para rodar 100% no **Google Colab**, contendo a resolução, simulação e execução em Python e C das Questões 1, 2 e 3. |
| `prints/` | Diagramas gerados pelo notebook ilustrando a AGM da Questão 2 (custo 7) e a rede ótima de fibra óptica entre as 5 fábricas da Questão 3 (custo 16). |
| `respostas/` | Contém as fotos das resoluções manuscritas das Questões 1 e 2 (`1.jpeg` e `2.jpeg`) e o PDF completo digitado (`Respostas_Lista_6_Teoria_dos_Grafos.pdf`) com todas as questões (1, 2 e 3). |
| `Diário de Bordo — Uso de IA` | Registro detalhado do uso de IA nas sessões de estudo e reflexão crítica sobre o processo de resolução. |
| `LICENSE` | Licença MIT do repositório. |
| `README.md` | Documentação geral e guia de execução do projeto. |

## 📋 Resumo das Questões e Resultados

| Questão | Tópico Principal | Síntese da Resolução |
| :--- | :--- | :--- |
| **Questão 1** | Kruskal vs. Prim (Conceitos, Estruturas e Complexidade) | **(a)** Kruskal ordena arestas por peso evitando ciclos; Prim expande uma única árvore a partir de um vértice inicial. **(b)** Em grafos desconexos, Kruskal gera uma *floresta geradora mínima* naturalmente; Prim gera apenas a AGM da componente inicial (a menos que seja reiniciado para os demais componentes). **(c)** Kruskal: $O(E \log E)$ (ideal para grafos esparsos); Prim: $O(E \log V)$ com lista de adjacência + heap binário ou $O(V^2)$ com matriz de adjacência + vetor `key[]` (vantajoso em grafos densos). **(d)** Kruskal usa *Union-Find* (Conjuntos Disjuntos); Prim usa *Fila de Prioridade (Min-Heap)*. |
| **Questão 2** | Execução Manual e Comparação (Grafo $A, B, C, D$) | **(a) Kruskal:** Aceita $A\text{-}B(1)$, aceita $B\text{-}C(2)$, rejeita $A\text{-}C(3)$ (forma ciclo), aceita $B\text{-}D(4)$, rejeita $C\text{-}D(5)$. Peso total = **7**. **(b) Prim (início em A):** Passo 1: $A\text{-}B(1)$; Passo 2: $B\text{-}C(2)$; Passo 3: $B\text{-}D(4)$. Peso total = **7**. **(c)** Neste grafo as AGMs coincidem, mas em grafos com arestas de mesmo peso podem existir múltiplas AGMs distintas com o mesmo custo mínimo ótimo. |
| **Questão 3.1** | Leitura, Explicação e Complexidade do Código em C | O código implementa a **versão ingênua de Prim** com matriz de adjacência. Possui 3 laços aninhados (`while (edges < n - 1)`, `for i`, `for j`), resultando em complexidade **$O(n^3)$** (ou **$O(V^3)$**). Para reduzi-la a **$O(V^2)$** mantendo a matriz, basta usar um vetor `key[v]` que guarda o menor custo de conexão de cada $v \notin S$ à árvore, substituindo os dois laços `for` aninhados por dois laços `for` sequenciais de $O(V)$. Para chegar a **$O(E \log V)$**, usa-se lista de adjacência com Min-Heap. |
| **Questão 3.2** | Completar `// TRECHO FALTANTE` e Análise de Falha | A linha faltante na linha 78 é **`selected[y] = 1;`**. Se omitida, o programa **NÃO trava** (pois `edges++` continua sendo incrementado e o `while` encerra após $n-1$ passos), mas **termina fornecendo uma resposta errada**: como nenhum novo vértice é marcado como visitado, o conjunto selecionado permanece apenas com o vértice `0`, fazendo o algoritmo escolher e somar **a mesma aresta de menor peso incidente a `0` repetidamente $n-1$ vezes**. |
| **Questão 3.3** | Implementação: Rede de Fibra Óptica entre 5 Fábricas | Implementado em **Python** e **C** no Google Colab. Arestas escolhidas na ordem exata de entrada: **1º `(0, 1)` custo 2** $\to$ **2º `(1, 2)` custo 3** $\to$ **3º `(1, 4)` custo 5** $\to$ **4º `(0, 3)` custo 6**. **Custo mínimo total = 16**. |

## 🚀 Como Executar no Google Colab

1. Clique no botão **Open in Colab** no topo deste `README.md` (ou abra `codigo/Lista_6_Teoria_dos_Grafos.ipynb`).
2. No menu superior do Google Colab, clique em **Ambiente de execução > Executar tudo** (`Ctrl + F9`).
3. O notebook executará tanto os scripts em **Python 3** quanto a compilação e execução dos códigos em **C (`gcc`)** diretamente nas células do Colab.
