#include <iostream>
#include <vector>
using namespace std;

vector<int> pre_order;

vector<int> build_tree(int start, int end) {
    if (start > end) return {};
    int root = pre_order[start];
    if (start == end) return {root};
    
    int mid = start + 1;
    while (mid < end && pre_order[mid] < root) mid++;
    
    vector<int> left = build_tree(start + 1, mid - 1);
    vector<int> right = build_tree(mid, end);
    
    left.insert(left.end(), right.begin(), right.end());
    left.push_back(root);
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    pre_order.resize(n);
    for (int i = 0; i < n; ++i) cin >> pre_order[i];
    
    vector<int> post_order = build_tree(0, n - 1);
    for (int num : post_order) cout << num << "\n";
    
    return 0;
}