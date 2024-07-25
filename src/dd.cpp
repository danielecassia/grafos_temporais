#include <bits/stdc++.h>
using namespace std;

#define all(X) begin(X), end(X)
#define ll long long int

struct Connection {
    int vertex;      // para qual vértice
    int edgeID;      // id da aresta
};

struct EdgeData {
    ll year;
    ll dist;
    ll cost;
};

typedef vector<vector<Connection>> Graph;
typedef vector<EdgeData> EdgesList;

void printGraph(const Graph &g, int N) {
    for (int i = 0; i < N; ++i) {
        cout << "Vértice " << i + 1 << ":";
        for (int j = 0; j < g[i].size(); j++) {
            cout << " -> (v: " << g[i][j].vertex + 1 << ", edgeID: " << g[i][j].edgeID << ")";
        }
        cout << endl;
    }
}

void printEdges(const EdgesList &e, int M) {
    for (int i = 0; i < M; ++i) {
        cout << "Aresta " << i << ": ano = " << e[i].year << ", distância = " << e[i].dist << ", custo = " << e[i].cost << endl;
    }
}

const ll LINF = 1e18;

void dijkstra(int start, Graph &g, const EdgesList &e, vector<ll> &dist) {
    // Obtém o número de vértices no grafo
    int N = g.size();
    // Inicializa o vetor de distâncias com um valor muito alto (LINF) para todos os vértices
    dist.assign(N, LINF);
    // Define a distância inicial do vértice de partida como 0
    dist[start] = 0;
    // Cria uma fila de prioridade para armazenar pares (distância, vértice), ordenada pela menor distância
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    // Insere o vértice inicial na fila com distância 0
    pq.emplace(0, start);

    // Enquanto a fila de prioridade não estiver vazia
    while (!pq.empty()) {
        // Obtém o vértice com a menor distância da fila
        auto [curDist, u] = pq.top();
        pq.pop();

        // Se a distância atual for maior que a distância registrada, continua para o próximo
        if (curDist > dist[u]) continue;

        // Para cada vértice conectado ao vértice u
        for (const auto &conn : g[u]) {
            // Obtém o vértice adjacente
            int v = conn.vertex;
            // Obtém o ID da aresta
            int edgeID = conn.edgeID;

            // Obtém o custo da aresta
            ll edgeCost = e[edgeID].cost;
            // Obtém a distância da aresta
            ll edgeDist = e[edgeID].dist;

            // Se a nova distância para v é menor que a distância atual registrada para v
            // ou se a nova distância é igual à atual mas o custo é menor
            if (dist[v] > dist[u] + edgeDist) {
                // Atualiza a distância para v
                dist[v] = dist[u] + edgeDist;
                // Insere o vértice v na fila com a nova distância
                pq.emplace(dist[v], v);
            }
        }
    }
}


int main() {
    int N, M;
    cin >> N >> M;
    
    Graph g(N);
    EdgesList e;

    int u, v;
    ll a, l, c;

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> a >> l >> c;
        v--; u--;

        g[u].push_back({v, i});
        g[v].push_back({u, i});

        e.push_back({a, l, c});
    }

    cout << "Dados do Grafo:" << endl;
    printGraph(g, N);
    cout << endl;

    cout << "Dados das Arestas:" << endl;
    printEdges(e, M);

    // 1. Distância mínima do palácio real -> cada vila
    vector<ll> dist;
    int startVertex = 0; // escolha o vértice de início (0, por exemplo)
    dijkstra(startVertex, g, e, dist);
    // cout << "Distâncias e Custos a partir do vértice " << startVertex + 1 << ":" << endl;
    for (int i = 0; i < N; ++i) {
        // cout << "Vila " << i + 1 << " Distância = " << dist[i] << ", Custo = " << cost[i] << endl;
        cout << dist[i] << endl;
    }


    // 1.(a) Primeiro ano em que todas as distâncias podem ser realizadas ao mesmo tempo
        // TODO: das aresta que sao usado no grafo retornado?, pegar o MAX dos anos

    // 2. Qual o primeiro ano em que todo o reino é alcançável a partir do palácio real? (todas as vilas são alcançáveis)
        // TODO: chamar o Dijkstra (ano, MAX)

    // 3. Menor custo pra conectar tds as vilas = uma vila -> qualquer outra?
        // TODO: chamar o Dijkstra (custo, +)

    return 0;
}
