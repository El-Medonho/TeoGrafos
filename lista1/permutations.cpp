#include "bits/stdc++.h"

using namespace std;

int N;
vector<int> vis(0);
vector<string> ans(0);
string str = "";

void dfs(int layer){
    if(layer == N){
        ans.push_back(str);
        return;
    }

    for(int i = 0; i < N; i++){
        if(vis[i]) continue;
        str += '1'+ i;
        vis[i] = 1;
        
        dfs(layer+1);
        
        str.pop_back();
        vis[i] = 0;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> N;

    auto start = chrono::high_resolution_clock::now();

    vis.resize(N, 0);

    dfs(0);

    // for(string s: ans) {
    //     for(int j = 0; j < s.size(); j++) 
    //         cout << s[j] << " \n"[j == s.size()-1];
    // }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> tempo = (end - start); 

    cout << tempo.count() << '\n';

    return 0;
}