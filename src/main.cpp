#include <bits/stdc++.h>
using namespace std;  // Uso do namespace std para evitar a repetição de std::

#define all(X) begin(X), end(X)

struct Conexao {
    int v;  // vertice(vila) que estou conectado
    int a;  // ano final de construção;
    int l;  // tempo de travessia;
    int c;  // custo de construção;
};

// Define um struct para representar o grafo
typedef vector<Conexao> Grafo;


int main() {
  int N, M;
  cin >> N >> M;  // Lê o número de vila (N) e o número de conexões (M)
//   cout<< N << " | " << M<<endl;  // Lê o número de vila (N) e o número de conexões (M)

  Grafo g;
  g.resize(N);

  for (int i = 0; i < M; i++) {  // Itera sobre todos os vértices
    int u;
    // faz leituras
    cin >> u;
    cin >> g[u].v >> g[u].a >> g[u].l >> g[u].c;
  }

  //  imprime o grafo criado
  for (int i = 1; i <= N; i++) {
    cout << "Conexão entre " << i << " e " << g[i].v<<endl;
    cout << "Ano final da construção: "<< g[i].a<<endl;
    cout << "Tempo de travessia: "<< g[i].l<<endl;
    cout << "Custo da comstrução: "<< g[i].c<<endl;
    cout << "-----------------------------------------------------------";

    cout << endl;
  }

  return 0;  // Retorna 0 indicando que o programa terminou com sucesso

}