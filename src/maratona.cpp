#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

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
    for (int i = 0; i < MAX; i++) {
        d[i] = LINF;
        parent[i] = -1;
    }
    d[v] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, v);

    while (!pq.empty()) {
        auto [ndist, u] = pq.top(); pq.pop();
        if (-ndist > d[u]) continue;

        for (auto [idx, edgeIdx] : g[u]) {
            ll weight;
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

            if (d[idx] > d[u] + weight) {
                d[idx] = d[u] + weight;
                parent[idx] = edgeIdx;
                pq.emplace(-d[idx], idx);
            }
        }
    }
}

void printGraph(vector<ii> g[], int N) {
    for (int i = 0; i < N; i++) {
        cout << "Vila " << i + 1 << ": ";
        for (auto [v, idx] : g[i]) {
            cout << "(" << v + 1 << ", " << idx << ") ";
        }
        cout << endl;
    }
}

void printEdges(vector<Edge> &e, int M) {
    for (int i = 0; i < M; i++) {
        auto [a, l, c] = e[i];
        cout << "Aresta " << i<< ": (" << a << ", " << l << ", " << c << ")" << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M; // Lê o número de vilas (N) e o número de conexões (M)

    int u, v;
    ll a, l, c;

    for (int i = 0; i < M; i++) { // Itera sobre todas as conexões
        // Faz leitura dos dados
        cin >> u >> v >> a >> l >> c;

        // v-- && u-- -> converte índice de volta para 0-based
        v--; u--;

        // Adiciona vértices no grafo
        g[u].push_back({v, i}); // Adiciona a conexão (u -> v)
        g[v].push_back({u, i}); // Adiciona a conexão (v -> u)

        // Adiciona aresta de conexão entre os vértices
        e.push_back({a, l, c}); // Adiciona os dados da aresta
    }

    // Imprime os dados do grafo e das arestas
    cout << "Dados do Grafo:" << endl;
    printGraph(g, N);
    cout << endl;

    cout << "Dados das Arestas:" << endl;
    printEdges(e, M);
    cout << endl;

    // 1. Distância mínima do palácio real -> cada vila
    cout << "Distância mínima do palácio real para cada vila:" << endl;
    dijkstra(0, 0); // Supondo que o palácio real está na vila 0
    for (int i = 0; i < N; i++) {
        cout << "Vila " << i + 1 << ": " << d[i] << endl;
    }
    cout << endl;

    // 1 (a). Primeiro ano em que todas as distâncias podem ser realizadas ao mesmo tempo
    cout << "Primeiro ano em que todas as distâncias podem ser realizadas ao mesmo tempo:" << endl;
    dijkstra(0, 0); // Reutilizamos o Dijkstra da métrica de distância
    ll maxYear = 0;
    for (int i = 0; i < N; i++) {
        if (parent[i] != -1) {
            maxYear = max(maxYear, get<1>(e[parent[i]]));
        }
    }
    cout << "Ano: " << maxYear << endl;
    cout << endl;

    // 2. Primeiro ano em que todo o reino é alcançável a partir do palácio real
    cout << "Primeiro ano em que todo o reino é alcançável a partir do palácio real:" << endl;
    dijkstra(0, 1); // Supondo que o palácio real está na vila 0
    for (int i = 0; i < N; i++) {
        cout << "Vila " << i + 1 << ": " << d[i] << endl;
    }
    cout << endl;

    // 3. Menor custo pra conectar todas as vilas
    cout << "Menor custo para conectar todas as vilas:" << endl;
    dijkstra(0, 2); // Supondo que o palácio real está na vila 0
    for (int i = 0; i < N; i++) {
        cout << "Vila " << i + 1 << ": " << d[i] << endl;
    }
    cout << endl;

    return 0;
}
