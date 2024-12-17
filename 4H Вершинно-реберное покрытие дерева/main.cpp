#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class node {
public:
    std::vector<int> neib;
};

void solve(int par, int k, std::vector<node>& v, std::vector<std::vector<long long int>>& cnt,
           std::vector<long long int>& cost, std::set<int>& res) {
    cnt[k][0] = 0;
    cnt[k][1] = cost[k];
    bool isleaf = (v[k].neib.size()==1);
        for (int child : v[k].neib) {
            if (child != par) {
                solve(k, child, v, cnt, cost, res);
                cnt[k][0]+=cnt[child][1];
                if (cnt[child][0]<cnt[child][1]) {
                    cnt[k][1]+=cnt[child][0];
                } else {
                    cnt[k][1]+=cnt[child][1];
                }
            }
        }
    if (cnt[k][0]>cnt[k][1]) {
        res.insert(k);
    }
}

void cnt_res(int par, int k, std::vector<node>& v, std::vector<std::vector<long long int>>& cnt, std::set<int>& res) {
    bool marked = (res.find(k)!=res.end());
    for (int child : v[k].neib) {
        if (child!=par) {
            if (!marked && cnt[child][1]>=cnt[child][0]) {
                res.insert(child);
            }
            cnt_res(k, child, v, cnt, res);
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    if (n>1) {
    std::vector<long long int> cost(n);
    std::vector<node> v(n);
    std::vector<std::vector<long long int>> cnt(n, std::vector<long long int>(2, 0));
    std::set<int> res;
    for (int i=0; i<n-1; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        v[a].neib.push_back(b);
        v[b].neib.push_back(a);
    }
    for (int i=0; i<n; ++i) {
        std::cin >> cost[i];
    }
    solve(-1, 0, v, cnt, cost, res);
    cnt_res(-1, 0, v, cnt, res);
    if (cnt[0][0]<cnt[0][1]) {
        std::cout << cnt[0][0] << " " << res.size() << "\n";

        for (int i : res) {
            std::cout << i+1 << " ";
        }
    } else {
        std::cout << cnt[0][1] << " " << res.size() << "\n";

        for (int i: res) {
            std::cout << i+1 << " ";
        }
    }
    } else {
        int cost;
        std::cin >> cost;
        std::cout << cost << " " << 1 << "\n" << 1;
    }
}
