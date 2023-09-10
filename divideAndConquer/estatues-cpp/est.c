#include <stdio.h>

#define MAX 100001
int statues[MAX];

int binary_find_next_statue(int beg, int end, int key)
{
        int pos = beg;
        while (statues[pos] <= key && pos < end) {
                pos++;
        }
        return pos;
}

int binary_range_find(int current_range, int n)
{
        int initial_pos = 0;
        int initial_statue = statues[initial_pos];

        int final_pos = n - 1;
        int final_statue = statues[final_pos];

        int next_statue = initial_statue + 2 * current_range;
        int interval_num = 1;
        while (next_statue < final_statue) {

                int next_statue_pos = binary_find_next_statue(
                    initial_pos, final_pos, next_statue);

                next_statue = statues[next_statue_pos];
                interval_num++;
                initial_pos = next_statue_pos;
                next_statue += 2 * current_range;
        }
        return interval_num;
}

int binary_search_range(int interval_num, int statue_num)
{

        int min_range = 0;
        int max_range = (statues[statue_num - 1] - statues[0]) / interval_num;
        int current_range;
        int current_interval_num;
        int smallest_valid_range;

        while (min_range <= max_range) {
                current_range = (max_range + min_range) / 2;
                current_interval_num =
                    binary_range_find(current_range, statue_num);

                if (current_interval_num > interval_num) {
                        min_range = current_range + 1;
                } else {
                        max_range = current_range - 1;
                        smallest_valid_range = current_range;
                }
        }
        return smallest_valid_range;
}

int main(void)
{

        int statue_num;
        scanf(" %d", &statue_num);

        int interval_num;
        scanf(" %d", &interval_num);

        for (int i = 0; i < statue_num; i++) {
                scanf(" %d", &statues[i]);
        }
        int range = binary_search_range(interval_num, statue_num);
        printf("%d\n", range);
}