# Questão 3.3 — Implementação Completa em Python (Google Colab)
INF = float('inf')
N = 5
cost = [
    [0, 2, INF, 6, INF],
    [2, 0, 3, 8, 5],
    [INF, 3, 0, INF, 7],
    [6, 8, INF, 0, 9],
    [INF, 5, 7, 9, 0],
]
selected = [False] * N
selected[0] = True

edges, mincost = 0, 0
while edges < N - 1:
    # Encontrar a aresta (x, y) de menor custo ligando um vértice selecionado a um não selecionado
    min_val = INF
    x, y = 0, 0
    for i in range(N):
        if selected[i]:
            for j in range(N):
                if not selected[j] and cost[i][j] > 0:
                    if min_val > cost[i][j]:
                        min_val = cost[i][j]
                        x, y = i, j

    # Imprimir a aresta escolhida, somar ao mincost, marcar y como selecionado e incrementar edges
    print(f"Aresta ({x}, {y}) incluida de custo {min_val}")
    mincost += min_val
    selected[y] = True
    edges += 1

print(f"Custo minimo = {mincost}")
