#include <iostream>
#include <vector>

int main()
{
    int n, m, k;
    std::cin >> n;
    std::vector<int> a(n), ans(n, 0);
    for (int i=0; i<n; ++i) {
        std::cin >> a[i];
    }
    std::cin >> m >> k;
    std::vector<int> x(m);
    for (int i=0; i<m; ++i) {
        std::cin >> x[i];
    }
    int num = 0, cur = 0;
    for (int i=1; i<n; ++i) {
        if (a[i]<a[i-1]) {
            ans[i] = i;
            num = 0;
            cur = i;
        } else {
            if (a[i]==a[i-1]) {
                ++num;
            }
            if (num<=k) {
                ans[i] = cur;
            } else {
                while (cur<i && num>k) {
                    ++cur;
                    if (a[cur]==a[cur-1]) {
                        --num;
                    }
                }
                ans[i] = cur;
            }
        }
    }
    for (int i=0; i<m; ++i) {
        std::cout << ans[x[i]-1]+1 << " ";
    }
}
