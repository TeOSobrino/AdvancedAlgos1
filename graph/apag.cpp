//a very simple implementation of kruskel's algorithm
#include <bits/stdc++.h>
using namespace std;

//used for getting the weight value and sorting accordingly
template <class T> bool weightCompare(T x1, T x2)
{
        return get<2>(x1) <= get<2>(x2);
}

//a Disjoint-Set can be used to represent the three and avoid cycles
class DSU
{
        int *parent;
        int *rank;

public:
        DSU(int n)
        {
                parent = new int[n];
                rank = new int[n];

                memset(parent, -1, n * sizeof(int));
                memset(rank, 0, n * sizeof(int));
        }

        int find(int i)
        {
                if (parent[i] == -1)
                        return i;

                return parent[i] = find(parent[i]);
        }

        void unite(int x, int y)
        {
                int s1 = find(x);
                int s2 = find(y);

                if(s1 == s2) 
                        return;
                
                if (rank[s1] < rank[s2]) {
                        parent[s1] = s2;
                } else if (rank[s1] > rank[s2]) {
                        parent[s2] = s1;
                } else {
                        parent[s2] = s1;
                        rank[s1] += 1;
                }
        }
};

int main(void)
{

        int edge_num, vertex_num;
        cin >> vertex_num >> edge_num;

        if (edge_num + 1 < vertex_num) {
                cout << -1;
                return 0;
        }

        vector<tuple<int, int, int>> graph;
        graph.reserve(edge_num);

        int e1, e2, w;
        for (int i = 0; i < edge_num; i++) {
                cin >> e1 >> e2 >> w;
                graph.push_back({e1, e2, w});
        }

        // kruskel's algorithm for determinig the value of MST
        sort(graph.begin(), graph.end(), weightCompare<tuple<int, int, int>>);

        long long int cost = 0;
        int edges_inserted = 0;
        DSU dsu(vertex_num);
        for (int i = 0; i < edge_num; i++) {
                int x = get<0>(graph[i]);
                int y = get<1>(graph[i]);

                if (dsu.find(x) != dsu.find(y)) {
                        dsu.unite(x, y);
                        cost += get<2>(graph[i]);
                        edges_inserted++;
                }
        }

        if (edges_inserted != vertex_num - 1)
                cost = -1;
        cout << cost;

        return 0;
}