#include <bits/stdc++.h>
using namespace std;  // Uso do namespace std para evitar a repetição de std::

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<ll, ll, ll> Edge; // {a, l, c}

const ll LINF = 1e18;
const int MAX = 1e5 + 5;

vector<ii> g[MAX]; // {vizinho, índice da aresta}
vector<Edge> e;    // {a, l, c}
ll d[MAX];         // Distâncias
int parent[MAX];   // Para rastrear o caminho

void dijkstra(int v, int metric) {
    // Inicializa todas as distâncias com um valor infinito (LINF) e os pais com -1
    for (int i = 0; i < MAX; i++) {
        d[i] = LINF;
        parent[i] = -1;
    }
    // Define a distância do vértice inicial como 0
    d[v] = 0;
    
    // Cria uma fila de prioridade para armazenar pares de (distância, vértice)
    priority_queue<pair<ll, int>> pq;
    // Adiciona o vértice inicial na fila com distância 0
    pq.emplace(0, v);

    // Enquanto a fila de prioridade não estiver vazia
    while (!pq.empty()) {
        // Remove o elemento do topo da fila (menor distância)
        auto [ndist, u] = pq.top(); pq.pop();
        // Se a distância armazenada na fila for maior que a distância conhecida, continua
        if (-ndist > d[u]) continue;

        // Para cada vizinho do vértice atual u
        for (auto [idx, edgeIdx] : g[u]) {
            ll weight;
            // Escolhe a métrica a ser usada para o peso da aresta com base no parâmetro 'metric'
            switch (metric) {
                case 0: // Distância
                    weight = get<0>(e[edgeIdx]);
                    break;
                case 1: // Primeiro ano
                    weight = get<1>(e[edgeIdx]);
                    break;
                case 2: // Custo
                    weight = get<2>(e[edgeIdx]);
                    break;
            }

            // Se a distância do vizinho for maior que a distância do vértice atual + peso da aresta
            if (d[idx] > d[u] + weight) {
                // Atualiza a distância do vizinho
                d[idx] = d[u] + weight;
                // Armazena o índice da aresta que leva ao vizinho
                parent[idx] = edgeIdx;
                // Adiciona o vizinho na fila com a nova distância (negativa para inversão)
                pq.emplace(-d[idx], idx);
            }
        }
    }
}
