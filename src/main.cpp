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

// TODO: implementar o Dijkstra (+ ou MAX)
    // ele ira retornar um subgrafo?
// https://github.com/brunomaletta/Biblioteca/blob/master/Codigo/Grafos/dijkstra.cpp

// Dijkstra
//
// encontra menor distancia de x
// para todos os vertices
// se ao final do algoritmo d[i] = LINF,
// entao x nao alcanca i
//
// O(m log(n))
const int MAX= 6;
const ll LINF = 1e18;
ll d[MAX];
vector<pair<int, int>> g[MAX]; // {vizinho, peso}

int n;
 
void dijkstra(int v) {
	for (int i = 0; i < n; i++) d[i] = LINF;
	d[v] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0, v);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.emplace(-d[idx], idx);
		}
	}
}

int main() {
    int N, M;
    cin >> N >> M;  // Lê o número de vilas (N) e o número de conexões (M)
    cout << M; 
    
    Graph g(N);
    EdgesList e;

    int u, v;
    ll a, l, c;


    for (int i = 0; i < M; i++) {  // Itera sobre todas as conexões
        // faz leitura dos dados
        cin >> u >> v >> a >> l >> c;

        // v-- && u-- -> converte índice de volta para 0-based
        v--; u--;

        // adiona vertices no grafo
        g[u].push_back({v, i});  // Adiciona a conexão (u -> v)
        g[v].push_back({u, i});  // Adiciona a conexão (v -> u)

        // adiciona aresta de conexao entre os vertices
        e.push_back({a, l, c});  // Adiciona os dados da aresta
    }

    // Imprime os dados do grafo e das arestas
    cout << "Dados do Grafo:" << endl;
    printGraph(g, N);
    cout << endl;

    cout << "Dados das Arestas:" << endl;
    printEdges(e, M);



    // 1. Distância mínima do palácio real -> cada vila
        // TODO: chamar o Dijkstra (dist, +)
    // (a) Primeiro ano em que todas as distâncias podem ser realizadas ao mesmo tempo
        // TODO: das aresta que sao usado no grafo retornado, pegar o MAX dos anos

    // 2. Qual o primeiro ano em que todo o reino é alcançável a partir do palácio real? (todas as vilas são alcançáveis)
        // TODO: chamar o Dijkstra (ano, MAX)

    // 3. Menor custo pra conectar tds as vilas = uma vila -> qualquer outra?
        // TODO: chamar o Dijkstra (custo, +)

    return 0;
}

