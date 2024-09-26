#include<bits/stdc++.h>

typedef long long ll;


#define vi vector <int> 
#define pi pair <int,int> 
// #define ss set <string>
// #define si set <int> ::iterator 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i < b; i++)
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int n,m;



const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};


bool isValid(int x, int y,  vector<vector<char>> grid, 
              vector<vector<bool>> visited) {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
           grid[x][y] != 'X' && !visited[x][y];
}

vector<pair<int, int>> bfs( vector<vector<char>> grid, 
                            pair<int, int> start, pair<int, int> treasure,
                            vector<vector<bool>> visited) {
    queue<vector<pair<int, int>>> q; 
    
    

    q.push({start}); 
    
    visited[start.first][start.second]=true;

    while (!q.empty()) {
        vector <pair<int,int>> path = q.front(); 
        q.pop();
        pair<int,int> current = path.back(); 

        
        if (current == treasure) {
            return path; 
        }

        
        for (int i=0;i<4;i++) {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];

            if (isValid(newX, newY, grid, visited)) {
                visited[newX][newY]=true;
                vector <pair<int,int>> newPath = path; 
                newPath.emplace_back(newX, newY); 
                // cerr<<newY<<" "<<newY<<endl;
                q.push(newPath);
            }
        }
    }

    return {}; 
}

 void print_answer(vector<pair<int, int>> path){
    
        cout<<"Path found: [";
        for (const auto& p : path) {
            cout << "(" << p.first << ", " << p.second ;
            if(p!=path.back())
        cout<<"), ";
        else{
            cout<<")";
        }
        }
        cout <<"]"<< endl;
    } 
        
    
void Solve(){
    // vector<vector<char>> grid;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n,vector<bool>(m));

    pair<int, int> start; 
    pair<int, int> treasure ; 
       for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'T') {
                treasure = {i, j};
            }
        }
    }

 
     print_answer( bfs(grid, start, treasure,visited));

    
}

int main(){
    Fast;
    int t=1;
    //cin>>t;
    while(t--)
    Solve();
    return 0;
}
