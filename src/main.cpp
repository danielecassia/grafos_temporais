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
void printGraph(const Graph &g, int M) {
    for (int i = 0; i < M; ++i) {

        // i+ 1 | g[i][j].vertex + 1 = u -> converte índice de volta para 1-based
        cout << "Vértice " << i + 1 << ":";
        for (int j=0; j< g[i].size(); j++) {
            cout << " -> (v: " << g[i][j].vertex + 1 << ", id: " << g[i][j].id << ")";
        }
        cout << endl;
    }
}

// Função para imprimir os dados das arestas
void printEdges(const Edge &e, int N) {
    for (int i = 0; i < N; ++i) {
        cout << "Aresta " << i << ": ano = " << e[i].year << ", distância = " << e[i].dist << ", custo = " << e[i].cost << endl;
    }
}

// TODO: implementar o Dijkstra (+ ou MAX)
    // ele ira retornar um subgrafo?

int main() {
    int N, M;
    cin >> N >> M;  // Lê o número de vilas (N) e o número de conexões (M)
    
    Graph g(N);
    Edge e;

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
    printGraph(g, M);
    cout << endl;

    cout << "Dados das Arestas:" << endl;
    printEdges(e, N);



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

