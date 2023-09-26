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
        mp[temp] = cnt++;   // associando cada estado do jogo a um número (~1e6 numeros)
    }
    while(next_permutation(temp.begin(), temp.end()));

    int N = cnt;

    vector<int> par(N,0), lvl(N,0);     // vamso utilizar esses vetores para guardar o caminho mínimo e recuperá-lo para obtermos a solução de uma configuração
    vector<string> repr(N);

    for(auto [x, ind] : mp){
        repr[ind] = x;
    }

    vector<pair<int,int>> dir = { {1,0}, {0,1}, {-1,0}, {0,-1} };

    string ini = "012345678";
    queue<string> qw; qw.push(ini); 
    lvl[mp[ini]] = 1; par[mp[ini]] = mp[ini];

    pair<int,string> farthest = {0, "012345678"};       //utilizado para obter uma das configurações mais longes

    while(!qw.empty()){
        string cc = qw.front(); qw.pop();
        int x = -1, y = -1;
        for(int i = 0; i < 9; i++) {        //logica dos movimentos para gerar vértices vizinhos
            if(cc[i] == '0') {
                x = i/3; y = i%3; 
            }
        }

        int cc_lvl = lvl[mp[cc]], cc_id = mp[cc]; 

        if( lvl[cc_id] > farthest.first ) farthest = {lvl[cc_id], cc};

        for(auto [nx, ny] : dir){
            nx += x; ny += y;
            if(nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;

            swap( cc[nx*3 + ny], cc[x*3 + y] );

            if(!lvl[mp[cc]]){
                
                lvl[mp[cc]] = cc_lvl+1;
                par[mp[cc]] = cc_id;
                qw.push(cc);
            }


            swap( cc[nx*3 + ny], cc[x*3 + y] );
        }

    }

    // cout << mp["312475068"] << '\n';

    string req; cin >> req;

    if(lvl[mp[req]] == 0){
        cout << "Não é possível chegar nessa configuração. \n";
        return 0;
    }

    cout << '\n';
    cout << "Numero mínimo de jogadas: " << lvl[mp[req]]-1 << '\n';

    vector<string> ans(0);

    int id = mp[req];

    while(par[id] != id){
        ans.push_back(repr[id]);
        id = par[id];
    }

    ans.push_back(repr[id]);

    for(string s: ans){
        for(int i = 0; i < 10; i+=3) cout << s.substr(i, 3) << '\n';
        cout << '\n';
    }

    cout << farthest.second << '\n';    

    return 0;
}