#include <bits/stdc++.h>
using namespace std;  // Uso do namespace std para evitar a repetição de std::

#define all(X) begin(X), end(X)
#define ll long long int

// struct que representa a conexão entre um vértice a e outro b
struct Connection {
    int vertex;      // para qual vértice
    int edgeID;     // id da aresta
};

// struct para coletar os dados de custo da conexão
struct EdgeData {
    ll year;
    ll dist;
    ll cost;
};

// representação do grafo
typedef vector<vector<Connection>> Graph;

// representação da aresta
typedef vector<EdgeData> EdgesList;

// Função para imprimir os dados do grafo
void printGraph(const Graph &g, int N) {
    for (int i = 0; i < N; ++i) {
        // i+ 1 | g[i][j].vertex + 1 = u -> converte índice de volta para 1-based
        cout << "Vértice " << i + 1 << ":";
        for (int j=0; j< g[i].size(); j++) {
            cout << " -> (v: " << g[i][j].vertex + 1 << ", edgeID: " << g[i][j].edgeID << ")";
        }
        cout << endl;
    }
}

// Função para imprimir os dados das arestas
void printEdges(const EdgesList &e, int M) {
    for (int i = 0; i < M; ++i) {
        cout << "Aresta " << i << ": ano = " << e[i].year << ", distância = " << e[i].dist << ", custo = " << e[i].cost << endl;
    }
}

// Dijkstra
//
// encontra menor distancia de x
// para todos os vertices
// se ao final do algoritmo d[i] = LINF,
// entao x nao alcanca i
//
// O(m log(n))
const int MAX = 1e5 + 5;
const ll LINF = 1e18;

// Parâmetro: o vértice de origem a partir do qual as métricas (distância, ano e custo)
// para todos os outros vértices do grafo serão calculadas
void dijkstra(int v, int metric, const Graph &g, const EdgesList &e, vector<ll> &d, vector<int> &parent) {
    fill(d.begin(), d.end(), LINF);
    fill(parent.begin(), parent.end(), -1);
    d[v] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, v);

    while (!pq.empty()) {
        auto [ndist, u] = pq.top(); pq.pop();
        if (-ndist > d[u]) continue;

        for (const auto &conn : g[u]) {
            ll weight;
            switch (metric) {
                case 0: // Distância
                    weight = e[conn.edgeID].dist;
                    break;
                case 1: // Ano
                    weight = e[conn.edgeID].year;
                    break;
                case 2: // Custo
                    weight = e[conn.edgeID].cost;
                    break;
                default:
                    weight = LINF;
                    break;
            }

            if (d[conn.vertex] > d[u] + weight) {
                d[conn.vertex] = d[u] + weight;
                parent[conn.vertex] = conn.edgeID;
                pq.emplace(-d[conn.vertex], conn.vertex);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;  // Lê o número de vilas (N) e o número de conexões (M)
    
    Graph g(N);
    EdgesList e;

    int u, v;
    ll a, l, c;

    for (int i = 0; i < M; i++) {  // Itera sobre todas as conexões
        // faz leitura dos dados
        cin >> u >> v >> a >> l >> c;

        // v-- && u-- -> converte índice de volta para 0-based
        v--; u--;

        // adiciona vertices no grafo
        g[u].emplace_back(Connection{v, i});  // Adiciona a conexão (u -> v)
        g[v].emplace_back(Connection{u, i});  // Adiciona a conexão (v -> u)

        // adiciona aresta de conexao entre os vertices
        e.push_back({a, l, c});  // Adiciona os dados da aresta
    }

    // Imprime os dados do grafo e das arestas
    cout << "Dados do Grafo:" << endl;
    printGraph(g, N);
    cout << endl;

    cout << "Dados das Arestas:" << endl;
    printEdges(e, M);
    cout << endl;

    vector<ll> d(N);
    vector<int> parent(N);

    // 1. Distância mínima do palácio real -> cada vila
    cout << "Distância mínima do palácio real para cada vila:" << endl;
    dijkstra(0, 0, g, e, d, parent); // Supondo que o palácio real está na vila 0
    for (int i = 0; i < N; i++) {
        cout << "Vila " << i + 1 << ": " << d[i] << endl;
    }
    cout << endl;

    // 1 (a). Primeiro ano em que todas as distâncias podem ser realizadas ao mesmo tempo
    cout << "Primeiro ano em que todas as distâncias podem ser realizadas ao mesmo tempo:" << endl;
    dijkstra(0, 0, g, e, d, parent); // Reutilizamos o Dijkstra da métrica de distância
    ll maxYear = 0;
    for (int i = 0; i < N; i++) {
        if (parent[i] != -1) {
            maxYear = max(maxYear, e[parent[i]].year);
        }
    }
    cout << "Ano: " << maxYear << endl;
    cout << endl;

    // 2. Qual o primeiro ano em que todo o reino é alcançável a partir do palácio real?
    cout << "Primeiro ano em que todo o reino é alcançável a partir do palácio real:" << endl;
    dijkstra(0, 1, g, e, d, parent); // Supondo que o palácio real está na vila 0
    for (int i = 0; i < N; i++) {
        cout << "Vila " << i + 1 << ": " << d[i] << endl;
    }
    cout << endl;

    // 3. Menor custo pra conectar todas as vilas
    cout << "Menor custo para conectar todas as vilas:" << endl;
    dijkstra(0, 2, g, e, d, parent); // Supondo que o palácio real está na vila 0
    for (int i = 0; i < N; i++) {
        cout << "Vila " << i + 1 << ": " << d[i] << endl;
    }
    cout << endl;

    return 0;
}
