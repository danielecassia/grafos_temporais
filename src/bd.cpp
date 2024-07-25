#include <bits/stdc++.h>
using namespace std;

#define ll long long int


const ll LINF = 1e18;
void disjkstra(int x){
    
    // Obtém o número de vértices no grafo
    // int N = g.size();
    int N = 4; //exemplo

    // Inicializa o vetor de distâncias com um valor muito alto (LINF) para todos os vértices
    vector<ll> dist;
    dist.assign(N, LINF);
    // priority_queue<pair<int,int>, greater<pair<int,int>>> pq;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    // Ditancia 0 para a vila inicial (que é x)
    pq.emplace(0, x);
    // pq.push({0,x});

    while(!pq.empty()){
        int distancia = pq.top().first;
        int vertice = pq.top().second;

        if(distancia > )
    }

}