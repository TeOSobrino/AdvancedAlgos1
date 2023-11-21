#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

map<string, string>::const_iterator find_first_match(const map<string, string> &mp,
                                               const string &search_for)
{
    map<string, string>::const_iterator i = mp.lower_bound(search_for);
    if (i != mp.end()) {
        const string &key = i->first;
        if (key.compare(0, search_for.size(), search_for) == 0)
            return i;
    }
    
    return mp.end();
}

bool is_prefix(string prefix, string full){
    auto res = mismatch(prefix.begin(), prefix.end(), full.begin());

    return res.first == prefix.end();
}

void find_prefix(const map<string, string> &mp, const string &search_for)
{

    auto i = find_first_match(mp, search_for);
    int count = 0;
    while (i != mp.end() && is_prefix(search_for, i->first)) {
        count++;
        i++;
    }
    cout << count << endl;
}

int main(void)
{
    map<string, string> dict;

    int n;
    cin >> n;

    char m;
    string str;
    pair<string, string> p;

    for (int i = 0; i < n; i++) {
        cin >> m;
        switch (m) {
        case '1':
            cin >> str;
            p = make_pair(str, str);
            dict.insert(p);
            break;

        case '2':
            cin >> str;
            dict.erase(str);
            break;

        case '3':
            cin >> str;
            find_prefix(dict, str);
            break;

        default:
            return 1;
        }
    }

    return 0;
}