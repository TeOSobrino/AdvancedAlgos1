#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int> arr)
{
        for (int i = 0; i < arr.size(); i++)
                cout << endl << endl;
}

void find_all_subsets(set<int> &answer, vector<int> &curr_subset,
                      vector<int> &nums, int index)
{

        // na primeira iteracao, o elemento nulo sera inserido, porem eh menos
        // custoso retirar um da resposta final do que verificar a cada passo
        // recursivo
        answer.insert(accumulate(begin(curr_subset), end(curr_subset), 0));
        cout << "outside for loop\nindex = " << index << endl;
        print_arr(curr_subset);

        for (int i = index; i < (int)nums.size(); i++) {

                cout << "recursion forward\nindex = " << index << endl;
                print_arr(curr_subset);

                curr_subset.push_back(nums[i]);
                find_all_subsets(answer, curr_subset, nums, i + 1);
                curr_subset.pop_back();

                cout << "recursion return\nindex = " << index << endl;
                print_arr(curr_subset);
        }

        return;
}

int main(void)
{

        vector<int> subsets;
        set<int> answ;
        vector<int> nums;

        int size;
        cin >> size;

        nums.reserve(size);
        subsets.reserve(size);

        int num;

        for (int i = 0; i < size; i++) {
                cin >> num;
                nums.push_back(num);
        }
        find_all_subsets(answ, subsets, nums, 0);
        
        cout << answ.size() - 1 << endl; // descontamos um pelo elemento nulo
        return 0;
}
