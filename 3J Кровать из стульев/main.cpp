#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>

int main()
{
        long long int h, cur=0, ans = 0;
        int n;
        std::cin >> n >> h;
        std::vector<std::pair<long long int, long long int>> s(n);
        std::deque<std::pair<long long int, int>> d;
        for (int i=0; i<n; ++i) {
            long long int a;
            std::cin >> a;
            s[i].first = a;
        }
        for (int i=0; i<n; ++i) {
            long long int a;
           std::cin >> a;
            s[i].second = a;
        }
        std::sort(s.begin(), s.end());
        int i=1;
        cur+=s[0].second;
        while (i<n && cur<h) {
            long long int x = s[i].first-s[i-1].first;
            while (!d.empty() && x>d.back().first) {
                d.pop_back();
            }
            d.push_back(std::make_pair(x, i));
            cur+=s[i].second;
            ++i;
        } //получили окно от 0 до i-1 вкл
        if (!d.empty()) ans = d.front().first;
        int r = i, left = 1;
        while (r<n && left<n) {
            if (!d.empty() && d.front().second == left) {
                d.pop_front();
            }
            cur-=s[left-1].second;
            while (r<n && cur<h) {
                long long int x = s[r].first-s[r-1].first;
                while (!d.empty() && x>d.back().first) {
                    d.pop_back();
                }
                d.push_back(std::make_pair(x, r));
                cur+=s[r].second;
                ++r;
            }
            if (ans>d.front().first && cur>=h) {
                ans = d.front().first;
            }
            ++left;
        }
    std::cout << ans;
}
