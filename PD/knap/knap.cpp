#include<bits/stdc++.h>
using namespace std;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int find_value(vector<tuple<long long int, long long int>> &items,int weight, 
        int n, int best, vector<vector<long long int>> &used)
{

        int max_val = 0;
        int curr_val = 0;
        
        int curr_w = 0;
        int curr_index = -1;
        
        for(int i = 0; i < n; i++){
                curr_val = get<1>(items[i]);
                curr_w = get<0>(items[i]);

                if(curr_val > max_val && curr_w <= weight){

                        if(used[best][i] != 0){
                                continue;
                        }
                        else{
                                max_val = curr_val;
                                curr_index = i;
                        }
                }
        }

        if(curr_index != -1){
                used[weight+best][curr_index] = 1;
                //cout << weight << " zeroed " << curr_index << endl;
        }

        return max_val;
}

struct sort_keys
{
        bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
};

int main (void)
{
        vector<tuple<long long int, long long int>> items;
        vector<long long int> best;
        vector<long long int> ultimate;

        int n, w;
        scanf(" %d %d", &n, &w);
        w++;

        items.reserve(n);
        best.reserve(w);
        vector<vector<long long int>> used;
        used.reserve(w);

        int k, l;
        for(int i = 0; i < n; i++){
                
                scanf(" %d %d", &k, &l);
                items.push_back(make_tuple(k, l));                
        }

        for(int i = 0; i < w; i++){
                for(int j = 0; j < n; j++){
                        used[i].push_back(0);
                }
                best.push_back(0);
        }

        long long int max = 0;
        for(int i = 0; i < w; i++){
                max = 0;
                int best_index = -1;
                for(int j = 0; j < i; j++){
                        max = MAX(max, find_value(items, i-j, n, j, used)+best[j]);
                        
                        if(max > best[i]){
                                best[i] = max;
                                best_index = j;
                        }
                }
                
                if(best_index != -1){
                        for(int j = 0; j < n; j++){
                                used[i][j] += used[best_index][j];
                        }
                }

                ultimate.push_back(max);
        }

        cout << ultimate[w-1];
        return 0;
}