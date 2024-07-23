// #include <bits/stdc++.h>
// using namespace std;  // Uso do namespace std para evitar a repetição de std::

// #define all(X) begin(X), end(X)
// #define ll long long int

// // struct que representa a conexão entre um vertice a e outro b
// struct Connection {
//     pair<int, int> mudar;
//     // int vertex;     // para qual vertice
//     // int id;         // id da aresta
// };

// // struct para coletar os dsdos de custo da conexão
// struct Bridge {
//     ll year;
//     ll dist;
//     ll cost;
// };

// // representação do grafo
// typedef vector<vector<Connection>> Graph;
// // typedef vector<vector<pair<int, int>>> Graph;

// // representação da aresta
// typedef vector<Bridge> Edge;


// int main(){

//     int N, M;
//     cin >> N >> M;  // Lê o número de vilas (N) e o número de conexões (M)
//     Graph g;
//     g.resize(N);

//     Edge e;
//     int u, v;
//     ll a, l, c;
//     for (int i = 0; i < M; i++) {  // Itera sobre todos as conexões
//         cin >> u >> v >> a >> l >>c;
//         g[i].push_back(v-1,i);
//         g[v-1].push_back(i,i);
//         e.push_back(a, l, c);
//     }
// }

#include <bits/stdc++.h>
using namespace std;  // Uso do namespace std para evitar a repetição de std::

#define all(X) begin(X), end(X)
#define ll long long int

// struct que representa a conexão entre um vértice a e outro b
struct Connection {
    int vertex;  // para qual vértice
    int id;      // id da aresta
};

// struct para coletar os dados de custo da conexão
struct Bridge {
    ll year;
    ll dist;
    ll cost;
};

// representação do grafo
typedef vector<vector<Connection>> Graph;

// representação da aresta
typedef vector<Bridge> Edge;

// Função para imprimir os dados do grafo
void printGraph(const Graph &g) {
    for (int i = 0; i < g.size(); ++i) {

        // i+ 1 | g[i][j].vertex + 1 = u -> converte índice de volta para 1-based
        cout << "Vértice " << i + 1 << ":";
        for (int j=0; j< g[i].size(); j++) {
            cout << " -> (v: " << g[i][j].vertex + 1 << ", id: " << g[i][j].id << ")";
        }
        cout << endl;
    }
}

// Função para imprimir os dados das arestas
void printEdges(const Edge &e) {
    for (int i = 0; i < e.size(); ++i) {
        cout << "Aresta " << i << ": ano = " << e[i].year << ", distância = " << e[i].dist << ", custo = " << e[i].cost << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;  // Lê o número de vilas (N) e o número de conexões (M)
    
    Graph g(N);
    Edge e;

    int u, v;
    ll a, l, c;
    for (int i = 0; i < M; i++) {  // Itera sobre todas as conexões
        cin >> u >> v >> a >> l >> c;
        // v-1 = i -> converte índice de volta para 0-based
        g[u - 1].push_back({v - 1, i});  // Adiciona a conexão (u -> v)
        g[v - 1].push_back({u - 1, i});  // Adiciona a conexão (v -> u)
        e.push_back({a, l, c});  // Adiciona os dados da ponte
    }

    // Imprime os dados do grafo e das arestas
    cout << "Dados do Grafo:" << endl;
    printGraph(g);
    cout << endl;

    cout << "Dados das Arestas:" << endl;
    printEdges(e);

    return 0;
}

