#include <iostream>
#include <deque>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::deque<int> s;
    std::vector<int> w(n);
    for (int i=0; i<n; ++i) {
        std::cin >> w[i];
    }
    for (int i=0; i<k; ++i) {
        int x = w[i];
        while (!s.empty() && x<s.back()) {
            s.pop_back();
        }
        s.push_back(x);
    }
    std::cout << s.front() << "\n";
    for (int i=1; i+k-1<n; ++i) {
        if (!s.empty() && w[i-1]==s.front()) {
            s.pop_front();
        }
        while (!s.empty() && w[i+k-1]<s.back()) {
            s.pop_back();
        }
        s.push_back(w[i+k-1]);
        std::cout << s.front() << "\n";
    }
}
