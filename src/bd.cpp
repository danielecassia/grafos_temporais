#include <bits/stdc++.h>
using namespace std;

#define all(X) begin(X), end(X)
#define ll long long int

struct Connection {
  int vertex;  // para qual vértice
  int edgeID;  // id da aresta
};

struct EdgeData {
  ll year;
  ll dist;
  ll cost;
};

typedef vector<vector<Connection>> Graph;
typedef vector<EdgeData> EdgesList;

typedef tuple<ll, int, int> CAV;

ll getMetric(Connection pv, int metricID, const EdgesList &edges) {
  if (metricID == 0) {
    return edges[pv.edgeID].year;
  } else if (metricID == 1) {
    return edges[pv.edgeID].dist;
  } else {
    return edges[pv.edgeID].cost;
  }
}

const ll LINF = 1e18;
void disjkstra(const int metricID, const string compare, const Graph &g,
               const EdgesList &edges, vector<ll> &weight, const int N,
               vector<int> &arestas) {
  // Inicializa o vetor de distâncias com um valor muito alto (LINF) para todos
  // os vértices
  weight.assign(N, LINF);
  // priority_queue<pair<int,int>, greater<pair<int,int>>> pq;

  // custo, aresta, vertice
  priority_queue<CAV, vector<CAV>, greater<CAV>> pq;

  // custo 0 para a vila inicial (que é x), nao utiliza nenhuma aresta(-1)
  pq.push({0, -1, 0});

  while (!pq.empty()) {
    ll peso = get<0>(pq.top());
    int aresta = get<1>(pq.top());
    int vertice = get<2>(pq.top());

    pq.pop();

    if (peso > weight[vertice]) continue;

    // Melhor distância (até agora)
    weight[vertice] = peso;
    arestas.push_back(aresta);

    // Olha os vizinhos do "vertice"
    for (Connection pv : g[vertice]) {
      ll peso_vertice_para_vizinho = getMetric(pv, metricID, edges);
      int aresta_do_vizinho = pv.edgeID;
      int vizinho = pv.vertex;

      // custo usando no vertice no caminho do vizinho
      ll w = 0;
      if (compare == "add") {
        w = peso + peso_vertice_para_vizinho;
      } else {
        w = max(peso, peso_vertice_para_vizinho);
      }

      // Se w melhora caminho do vizinho
      if (weight[vizinho] > w) {
        // Ponho na lista de sugestões
        // {custo, aresta, vertice}
        pq.push({w, aresta_do_vizinho, vizinho});
      }
    }
  }
}
// Função para imprimir os dados do grafo
void printGraph(const Graph &g, int N) {
  for (int i = 0; i < N; ++i) {
    // i+ 1 | g[i][j].vertex + 1 = u -> converte índice de volta para 1-based
    cout << "Vértice " << i + 1 << ":";
    for (int j = 0; j < g[i].size(); j++) {
      cout << " -> (v: " << g[i][j].vertex + 1 << ", edgeID: " << g[i][j].edgeID
           << ")";
    }
    cout << endl;
  }
}

// Função para imprimir os dados das arestas
void printEdges(const EdgesList &e, int M) {
  for (int i = 0; i < M; ++i) {
    cout << "Aresta " << i << ": ano = " << e[i].year
         << ", distância = " << e[i].dist << ", custo = " << e[i].cost << endl;
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
    v--;
    u--;

    // adiona vertices no grafo
    g[u].push_back({v, i});  // Adiciona a conexão (u -> v)
    g[v].push_back({u, i});  // Adiciona a conexão (v -> u)

    // adiciona aresta de conexao entre os vertices
    e.push_back({a, l, c});  // Adiciona os dados da aresta
  }

  // Imprime os dados do grafo e das arestas
  // cout << "Dados do Grafo:" << endl;
  // printGraph(g, N);
  // cout << endl;

  // cout << "Dados das Arestas:" << endl;
  // printEdges(e, M);

  // costID:
  // 0 = year;
  // 1 = dist;
  // 2 = cost;

  // 1. Distância mínima do palácio real -> cada vila
  // TODO: chamar o Dijkstra (dist, +)
  vector<ll> metric;
  vector<int> arestas;
  disjkstra(1, "add", g, e, metric, N, arestas);

  // for (int i = 0; i < N; i++) {
  //     // cout << "Vila " << i + 1 << " Distância = " << dist[i] << ", Custo =
  //     " << cost[i] << endl; cout << metric[i] << endl;
  // }
  // cout<< "Saiu do for";

  // (a) Primeiro ano em que todas as distâncias podem ser realizadas ao mesmo
  // tempo
  // TODO: das aresta que sao usado no grafo retornado, pegar o MAX dos anos
  ll o_maximo = 0;
  for (int i = 0; i < M; i++) {
    if (arestas[i] >= 0) {
        o_maximo = max(o_maximo,e[arestas[i]].year);
    }
  }
  cout << o_maximo << endl;

  // 2. Qual o primeiro ano em que todo o reino é alcançável a partir do palácio
  // real? (todas as vilas são alcançáveis)
  // TODO: chamar o Dijkstra (ano, MAX)
  metric.clear();
  disjkstra(0, "max", g, e, metric, N, arestas);

  // 3. Menor custo pra conectar tds as vilas = uma vila -> qualquer outra?
  // TODO: chamar o Dijkstra (custo, +)
  metric.clear();
  disjkstra(2, "add", g, e, metric, N, arestas);

  return 0;
}
