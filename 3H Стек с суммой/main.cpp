#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int n;
    std::stack<int> s;
    std::vector<long long int> v(1), ans;
    std::cin >> n;
    for (int i=0; i<n; ++i) {
        char c;
        std::cin >> c;
        if (c=='-') {
            ans.push_back(s.top());
            s.pop();
            v.pop_back();
        } else if (c=='+') {
            int x;
            std::cin >> x;
            s.push(x);
            int n = (int)v.size();
            v.push_back(x+v[n-1]);
        } else if (c=='?') {
            int x;
            std::cin >> x;
            int n = (int)v.size();
            ans.push_back(v[n-1]-v[n-x-1]);
        }
    }
    for (int i=0; i<(int)ans.size(); ++i) {
        std::cout << ans[i] << "\n";
    }
}
