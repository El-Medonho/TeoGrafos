// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string temp = "012345678";

    int cnt = 0;
    map<string, int> mp;

    do{
        mp[temp] = cnt++;
    }
    while(next_permutation(temp.begin(), temp.end()));

    int N = cnt;

    vector<int> par(N,0), lvl(N,1e9);
    vector<string> repr(N);

    for(auto [x, ind] : mp){
        repr[ind] = x;
    }

    vector<pair<int,int>> dir = { {1,0}, {0,1}, {-1,0}, {0,-1} };

    string req; cin >> req;
    string ini = "012345678";

    function<int(string)> heur;

    heur = [&](string a){

        int val = 0;

        for(int i = 0; i < 9; i++) val += a[i] == ini[i];

        return val;
    };

    priority_queue<pair<int,string>> pq;
    pq.push({heur(req), req});
    lvl[mp[req]] = 1; par[mp[req]] = mp[req];

    while(!pq.empty()){
        string cc = pq.top().second; pq.pop();
        int x = -1, y = -1;
        for(int i = 0; i < 9; i++) {
            if(cc[i] == '0') {
                x = i/3; y = i%3; 
            }
        }

        if(cc == ini) break;

        int cc_lvl = lvl[mp[cc]], cc_id = mp[cc]; 

        for(auto [nx, ny] : dir){
            nx += x; ny += y;
            if(nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;

            swap( cc[nx*3 + ny], cc[x*3 + y] );

            if(lvl[mp[cc]] > cc_lvl + 1){
                
                lvl[mp[cc]] = cc_lvl+1;
                par[mp[cc]] = cc_id;
                pq.push({heur(cc), cc});
            }


            swap( cc[nx*3 + ny], cc[x*3 + y] );
        }

    }

    // cout << mp["312475068"] << '\n';


    if(lvl[mp[req]] == 0){
        cout << "Não é possível chegar nessa configuração. \n";
        return 0;
    }

    cout << '\n';
    cout << "Numero mínimo de jogadas: " << lvl[mp[ini]]-1 << '\n';

    vector<string> ans(0);

    int id = mp[ini];

    while(par[id] != id){
        ans.push_back(repr[id]);
        id = par[id];
    }

    ans.push_back(repr[id]);

    reverse(ans.rbegin(), ans.rend());

    for(string s: ans){
        // cout << '\n';
        for(int i = 0; i < 10; i+=3) cout << s.substr(i, 3) << '\n';
        cout << '\n';
    }

    return 0;
}