# Problemas de Otimização em Grafos Temporais

## Resumo do Trabalho

### Objetivo:
Desenvolver um programa em C++ para resolver problemas de otimização em grafos temporais, focando na infraestrutura de uma nação fictícia chamada Baicônia. O programa deve calcular a distância mínima do palácio real para cada vila, o primeiro ano de alcançabilidade total e o menor custo de conectividade.

### Definições e Conceitos Importantes:

- **Grafo Temporal**: Grafo em que as arestas (conexões) têm tempos específicos de ativação.
- **Alcançabilidade**: Capacidade de atingir todas as vilas a partir do palácio real em um determinado ano.
- **Conectividade**: Garantia de que todas as vilas estão conectadas com o menor custo possível.

### Entrada:
- **N**: Número de vilas.
- **M**: Número de conexões.
- **Conexões**: Cada conexão é descrita por cinco inteiros \(u\), \(v\), \(a\), \(l\) e \(c\), onde:
  - \(u\) e \(v\): Vilas conectadas.
  - \(a\): Ano de conclusão da construção da via.
  - \(l\): Tempo de travessia em horas.
  - \(c\): Custo de construção em baconzitos.

### Saída:
1. Distâncias mínimas do palácio real para cada vila.
2. Primeiro ano em que todas as vilas são alcançáveis a partir do palácio real.
3. Menor custo para conectar todas as vilas.

### Exemplo de Entrada e Saída:

**Entrada**:
```
4 4
1 2 3 4 5
2 3 5 6 7
3 4 7 1 2
4 1 2 3 4
```

**Saída**:
```
0
4
4
7
5
11
```

## Passos para Implementação

### 1. Leitura dos Dados:
- Ler **N** (número de vilas) e **M** (número de conexões).
- Ler as próximas **M** linhas com as informações das conexões: \(u\), \(v\), \(a\), \(l\), e \(c\).

### 2. Representação do Grafo Temporal:
- Utilizar uma estrutura adequada para armazenar o grafo, como listas de adjacência, levando em conta os tempos de ativação das arestas.

### 3. Cálculo das Distâncias Mínimas:
- Implementar um algoritmo (como Dijkstra) para calcular a distância mínima do palácio real para cada vila.

### 4. Determinação do Primeiro Ano de Alcançabilidade Total:
- Analisar os anos de ativação das arestas para encontrar o primeiro ano em que todas as vilas são alcançáveis.

### 5. Cálculo do Menor Custo de Conectividade:
- Implementar um algoritmo (como Kruskal ou Prim) para calcular o menor custo necessário para garantir a conectividade entre todas as vilas.

### 6. Validação e Testes:
- Validar seu programa com os casos de teste fornecidos e criar novos casos para garantir a corretude do programa.
- Garantir que seu programa atende aos requisitos de tempo (3 segundos por caso de teste) e memória (100MB).

## Estruturas e Funções Úteis:

- **Estrutura de Dados para o Grafo**:
  - Utilize listas de adjacência para armazenar conexões.
  
- **Funções de Algoritmos**:
  - **Dijkstra**: Para calcular distâncias mínimas.
  - **Kruskal/Prim**: Para calcular o menor custo de conectividade.

## Considerações
- Comente seu código para facilitar a leitura e a manutenção.
- Certifique-se de seguir as restrições de tempo e memória.
- Faça testes exaustivos com diferentes grafos para garantir a correção do seu programa.
