#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

int solve(std::string name, std::map<std::string, std::vector<std::string>>& t, std::map<std::string, int>& counted) {
    int k = 0;
    for (std::string c : t[name]) {
        k += 1+solve(c, t, counted);
    }
    counted[name] = k;
    return k;
}

int main(){
    int n;
    std::cin >> n;
	std::map<std::string, std::vector<std::string>> t;
	std::map<std::string, std::string> par;
	std::map<std::string, int> counted;
	std::set<std::string> all;
	std::set<std::string> children;
	for (int i=1; i<n; ++i) {
        std::string child, parent;
        std::cin >> child >> parent;
        t[parent].push_back(child);
        par[child] = parent;
        all.insert(parent);
        all.insert(child);
        children.insert(child);
	}
	std::string root;
	for (std::string s : all) {
        if (children.find(s) == children.end()) {
            root = s;
            break;
        }
	}
	solve(root, t, counted);
	for (auto s : all) {
        std::cout << s << " " << counted[s] << "\n";
	}
}
