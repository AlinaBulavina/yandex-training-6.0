#include <iostream>
#include <vector>

void solve(int in, int par, std::vector<std::vector<int>>& tree, std::vector<int>& ans) {
    ans[in] = 1;
    for (int c : tree[in]) {
        if (c!=par) {
            solve(c, in, tree, ans);
            ans[in]+=ans[c];
        }
    }
}

int main()
{
    int v;
    std::cin >> v;
    std::vector<std::vector<int>> tree(v);
    for (int i=1; i<v; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    std::vector<int> ans(v, 0);
    solve(0, 0, tree, ans);
    for (int i=0; i<v; ++i) {
        std::cout << ans[i] << " ";
    }
}
