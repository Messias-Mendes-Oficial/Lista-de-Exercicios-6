# Diário de Bordo — Uso de IA

* **Disciplina:** Teoria dos Grafos — Lista 6 (Árvores e Arborescências — Parte 2 • 3º Período — 2026/2 • Prof. Newarney T. Costa)
* **Dupla:** Bruno Alves Mendonça de Abreu Filho + Messias Junio da Silva Mendes
* **Chat utilizado:** ChatGPT / Gemini

## Entrada 1 — 22/10/2026

* **Questões:** 1 e 2 — Kruskal e Prim.
* **Onde travamos / objetivo da conversa:** Diferenças entre os algoritmos e escolha das arestas da árvore geradora mínima.
* **O que perguntamos ao tutor (resumo):** Como funcionam os algoritmos, suas complexidades e como aplicá-los ao grafo proposto.
* **O que o tutor respondeu ou perguntou (resumo):** Explicou as diferenças entre Kruskal e Prim, as estruturas de dados utilizadas (*Union-Find* no Kruskal e *Fila de Prioridade / Matriz de Custos* no Prim) e os passos de aplicação.
* **O que fizemos com isso (aceitamos? questionamos? corrigimos?):** Analisamos as explicações e comparamos os resultados dos dois algoritmos passo a passo no caderno.
* **A IA tentou dar a resposta pronta ou errou? Como percebemos e reagimos?** Forneceu respostas diretas, sem conduzir totalmente por perguntas. Não identificamos erros específicos, mas conferimos manualmente cada aresta aceita e rejeitada.
* **O que aprendemos:** Kruskal seleciona arestas de menor peso globalmente evitando ciclos, enquanto Prim expande a árvore conectada a partir de um vértice inicial.

## Entrada 2 — 25/10/2026

* **Questões:** 3 (Alíneas 1, 2 e 3) — Implementação, análise de complexidade e depuração do Algoritmo de Prim em C e Python (Google Colab).
* **Onde travamos / objetivo da conversa:** Precisávamos justificar rigorosamente por que a implementação em C fornecida na questão tem complexidade $O(V^3)$ em vez de $O(V^2)$ ou $O(E \log V)$, analisar se a omissão da linha `selected[y] = 1;` na Alínea 2 causaria loop infinito ou término com resultado incorreto, e completar o código das 5 fábricas no Google Colab.
* **O que perguntamos ao tutor (resumo):** Pedimos para analisar os três laços aninhados (`while`, `for i`, `for j`) do código em C, explicar o que mudaria na estrutura de dados para cair para $O(V^2)$ mantendo matriz de custos, verificar o efeito exato da falta de `selected[y] = 1;` e estruturar o notebook do Google Colab com as implementações em Python e C.
* **O que o tutor respondeu ou perguntou (resumo):** Mostrou que os três laços aninhados realizam $(n-1) \times n \times n = O(n^3)$ operações porque recalculam a aresta mínima do corte do zero a cada passo; explicou que manter um vetor `key[v]` com o menor peso ligando cada vértice fora da árvore à árvore elimina o laço aninhado e reduz a complexidade para $O(V^2)$. Na Alínea 2, destacou que o programa **não trava** porque `edges++` continua sendo executado, mas termina após $n-1$ iterações escolhendo repetidamente a mesma aresta `(0, y)` de menor custo incidente ao vértice 0.
* **O que fizemos com isso (aceitamos? questionamos? corrigimos?):** Testamos os três códigos (em Python e compilando em C com `gcc` no Google Colab), inclusive simulando a execução sem a linha `selected[y] = 1;` para comprovar que o programa imprime 4 vezes a aresta `(0, 1)` de custo 2 e retorna custo 8 em vez de 16.
* **A IA tentou dar a resposta pronta ou errou? Como percebemos e reagimos?** O assistente estruturou o código e a explicação detalhada; nós validamos o rastreamento de mesa (*trace*) passo a passo na matriz $5 \times 5$ das fábricas para confirmar a ordem de entrada das arestas: `(0,1)` custo 2 $\to$ `(1,2)` custo 3 $\to$ `(1,4)` custo 5 $\to$ `(0,3)` custo 6 (total = 16).
* **O que aprendemos:** Aprendemos a diferença prática entre uma implementação ingênua $O(V^3)$ e a versão clássica $O(V^2)$ de Prim em matrizes, além de compreender como o controle de estado (`selected[y] = 1`) é separado do controle de parada (`edges++`).

## Reflexão Final (~½ página)

* **Onde a IA mais ajudou:** A IA ajudou tanto na consolidação teórica das diferenças entre Kruskal e Prim (Questões 1 e 2) quanto na análise algorítmica do código em C e configuração do ambiente no **Google Colab** (Questão 3). Foi muito útil para contrastar visualmente por que três laços aninhados levam a $O(V^3)$ e como a introdução de um único vetor auxiliar de distâncias (`key[]`) elimina um nível de aninhamento, baixando o custo para $O(V^2)$.
* **Onde ela entregou a resposta pronta e como redirecionamos:** Nas etapas iniciais, o chat tendeu a entregar diretamente a sequência de arestas da AGM. Para garantir o aprendizado real da dupla, fizemos o teste de mesa manual ordenando todas as arestas no papel (na Questão 2) e simulando iteração por iteração os valores de `min`, `x`, `y` e `selected[]` na matriz de custos das 5 fábricas (na Questão 3).
* **Onde ela errou e como verificamos:** Não identificamos erros conceituais ou de cálculo nas respostas geradas, mas fizemos questão de compilar o código em C com `gcc` e rodar o script em Python no Google Colab (inclusive removendo propositalmente a linha `selected[y] = 1;`) para verificar empiricamente todas as afirmações.
* **O que faríamos diferente na próxima lista:** Nas próximas listas, pediríamos dicas graduais antes de solicitar a explicação completa do código e faríamos primeiro o rascunho da análise de complexidade de laços antes de confirmar com o tutor.
