#include <iostream>
#include <vector>
#include <string>

int main()
{
    int n;
    long long int c, k=0;
    std::cin >> n >> c;
    std::string s;
    std::cin >> s;
    int r = 0, left = 0, c_a = 0, c_b = 0, ans = 0;
    while (left < n) {
        while (r<n && k<=c) {
            if (s[r] == 'a') {
                ++c_a;
            }
            else if (s[r] == 'b') {
                ++c_b;
                k+=c_a;
            }
            ++r;
        }
        int len = r-left;
        if (k>c) --len;
        if (len > ans) {
            ans = len;
        }
        if (s[left] == 'b') {
            --c_b;
        } else
        if (s[left] == 'a') {
            --c_a;
            k-=c_b;
        }
        ++left;
    }
    std::cout << ans;
}
