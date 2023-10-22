#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, long long> Item;

int n, w;
void print_memo(long long **memo)
{
        cout << endl;
        for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= w; j++) {
                        cout << memo[i][j] << " ";
                }
                cout << endl;
        }
        cout << endl;

        return;
}

long long find_max_value(long long weight, vector<Item> &items,
                         long long **&memo, int index, int capacity)
{
        if (index < 0)
                return 0;

        if (memo[index][capacity] != -1)
                return memo[index][capacity];

        if (get<0>(items[index]) > capacity) {
                memo[index][capacity] =
                    find_max_value(weight, items, memo, index - 1, capacity);
                return memo[index][capacity];
        }

        long long v1 = find_max_value(weight, items, memo, index - 1, capacity);
        long long v2 = get<1>(items[index]) +
                       find_max_value(weight, items, memo, index - 1,
                                      capacity - get<0>(items[index]));

        if ((v1) > (v2)) {
                memo[index][capacity] = v1;
                print_memo(memo);
                return memo[index][capacity];
        }

        memo[index][capacity] = v2;
        print_memo(memo);
        return memo[index][capacity];
}

int main(void)
{

        scanf(" %d %d", &n, &w);
        long long init = 0;

        vector<Item> items;

        long long **memo = (long long **)malloc(sizeof(long long *) * (n + 1));
        for (int i = 0; i <= n; i++) {
                memo[i] = (long long *)malloc(sizeof(long long) * (w + 1));
        }

        int k, l;

        for (int i = 0; i < n; i++) {

                scanf(" %d %d", &k, &l);
                items.push_back(make_tuple(k, l));
        }

        for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= w; j++) {
                        memo[i][j] = -1;
                }
        }

        long long v = find_max_value(init, items, memo, n - 1, w);

        cout << v;

        return 0;
}