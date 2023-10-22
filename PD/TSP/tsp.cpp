// TSP using dp, adapted to the case in which the salesman does not has to 
//return to the initial vertex, but this can be easily changed.
#include <bits/stdc++.h>
using namespace std;

void setup(vector<vector<int>> &adj, vector<vector<int>> &memo, int s, int n)
{
    for (int i = 0; i < n; i++) {
        if (i == s || adj[s][i] == -1)
            continue;
        memo[i][(1 << s) | (1 << i)] = adj[s][i];
    }

    return;
}

bool not_in(int x, int y) { return !((1 << x) & y); }

/**
 * @brief finds all subsets in a path of n vertex containing exactly r vertexes
 * (sets r bits in an n bit number, returns it in a vector)
 * @param subsets vector to be filled with all paths, each path is represented
 * as an integer
 * @param r number of vertexes in the path
 * @param n total number of vertexes in the graph
 */
void find_subsets(vector<int> &subsets, int r, int n)
{

    int s = 1 << n;
    for (int i = 0; i < s; i++) {
        int set_bits = 0;
        for (int j = 0; j < n; j++) {
            int mask = 1 << j;
            if (i & mask)
                set_bits++;
        }

        if (set_bits == r)
            subsets.push_back(i);
    }
}

/**
 * @brief fills up the memoization table
 *
 * @param adj adjacency matrix
 * @param memo memoization table
 * @param s starting vertex
 * @param n number of vertexes
 */
void solve(vector<vector<int>> &adj, vector<vector<int>> &memo, int s, int n)
{
    vector<int> subsets;

    //r is the number of vertexes set, meaning the ones that are being visited 
    //r = 3 because the analisys requires the start, end and next vertexes so 
    //at least 3 vertexes must be set
    for (int r = 3; r <= n; r++) {

        find_subsets(subsets, r, n);

        //there are 2^n subsets, hence the complexity is O(2^n * n^2)
        for (int i : subsets) {
            if (not_in(s, i))
                continue;

            //next vertex can be any vertex in the subset, except the starting
            //this determines the next vertex "included" in the best path
            for (int next = 0; next < n; next++) {
                if (next == s || not_in(next, i))
                    continue;
                //state is the subset excluding the next vertex
                int state = i ^ (1 << next);
                int min_dist = INT32_MAX;

                //the end vertex can be any in the subset, except start and next
                //this is the last vertex when next is removed
                for (int e = 0; e < n; e++) {
                    if (next == s || e == next || not_in(next, i))
                        continue;
                    //no link between vertexes
                    if(memo[e][state] == -1 || adj[e][next] == -1)
                        continue;

                    //the cost is the sum of path from s ending in e through the
                    //current subset excluding next, + cost from e -> next
                    int new_dist = memo[e][state] + adj[e][next];
                    
                    if(new_dist < min_dist){
                        min_dist = new_dist;
                    }
                }

                if(min_dist == INT32_MAX)
                    min_dist = -1;
                
                memo[next][i] = min_dist;
            }
        }
    }
    return;
}

/**
 * @brief finds the cost of minimum tour after the memo table is filled up
 *
 * @param adj adjancecy matrix
 * @param memo memoization table
 * @param s starting vertex
 * @param n number of vertexes
 * @return int cost
 */
int find_min_cost(vector<vector<int>> &adj, vector<vector<int>> &memo, int s,
                  int n)
{
    int end_state = (1 << n) - 1;
    int min_cost = INT32_MAX;

    for(int e = 0; e < n; e++){
        if(e == s) 
            continue;
        
        if(memo[e][end_state] == -1 || adj[e][s] == -1)
            continue;

        int tour_cost = memo[e][end_state] + adj[e][s];
        if( tour_cost < min_cost)
            min_cost = tour_cost;
    }

    if(min_cost == INT32_MAX)
        min_cost = -1;
    return min_cost;
}

/**
 * @brief tsp using dp
 *
 * @param adj adjancency matrix
 * @param s starting vertex
 * @return int cost of minimum tour
 */
int tsp(vector<vector<int>> adj, int s)
{
    int n = adj[0].size();

    //memo[i][j] = minimal cost of path j that connects s to i
    //ex: memo[2][5]: caminho = (0...0101) = 0 -> 2; custo mínimo será adj[0][2]
    //ex: memo[3][15]: camiho = (0...1111) = 0 -> (?) -> 3; custo mínimo será
    //min(memo[2][7] + adj[2][3], memo[1][7] + adj[1][3])
    //in the end, the best paths will be memo last column
    vector<vector<int>> memo(n, vector<int>(1 << n, -1));

    setup(adj, memo, s, n);
    solve(adj, memo, s, n);

    return find_min_cost(adj, memo, s, n);
}

int main(void)
{
    int v, l;
    scanf(" %d %d", &v, &l);

    vector<vector<int>> adj(v, vector<int>(v, -1));

    int p, j, w;
    for (int i = 0; i < l; i++) {
        scanf(" %d %d %d", &p, &j, &w);
        adj[p - 1][j - 1] = adj[j - 1][p - 1] = w;
    }

    //here we are setting all connections from vertexes n to start (vertex 0) 
    //to be valued 0, this is equivalent to the salesman no returning to the 
    //start if the salesman has to return (classic TSP), remove this loop
    for (int i = 0; i < v; i++) {
        adj[i][0] = 0;
    }

    int min = tsp(adj, 0);
    printf("%d\n", min);

    return 0;
}