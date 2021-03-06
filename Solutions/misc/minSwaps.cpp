#include <bits/stdc++.h>

using namespace std;

int minSwaps(int arr[], int n){
    pair<int, int> pos[n];
    for(int i = 0; i < n; i++){
        pos[i].first = arr[i];
        pos[i].second = i;
    }
    sort(pos, pos+n);
    vector<bool> visited(n, false);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] || pos[i].second == i) continue;
        int cycle_size = 0;
        int j = i;
        while(!visited[j]){
            visited[j] = 1;
            j = pos[j].second;
            cycle_size++;
        }
        ans += cycle_size - 1;
    }
    return ans;
}
