#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::pair<int,int>> dirs = {{-1,0}, {0,1}, {1,0},{0,-1}};

void print_field(std::vector<std::string>& field, std::pair<int,int> pos, int row, int col){
    for(int m = 0; m < row; m++){
        for(int n = 0; n < col; n++){
            std::cout << field[m][n];
        }
        std::cout << "\n";
    }
    std::cout << "Pos: " << pos.first << " " << pos.second << "\n\n";
    return;
}

bool is_loop(const std::vector<std::string>& field, std::pair<int,int> pos, int dir, int row, int col){
    std::vector<bool> visited(row*col*4);
    while(true){
        int hash = (pos.first * col + pos.second) * 4 + dir;
        if(visited[hash]){
            return true;
        }
        visited[hash] = true;

        int r = pos.first + dirs[dir].first;
        int c = pos.second + dirs[dir].second;
        if(!(r>= 0 && r < row && c >=0 && c < col)){
            return false;
        }
        if(field[r][c] == '#'){
            dir = (dir + 1) % 4;
            continue;
        }
        pos = {r,c};        
    }
}

int main(){

    // Read input into a 2d vector
    std::vector<std::string> field;
    int row, col = -1;
    long int ans = 0;
    int dir = 0;
    std::pair<int,int> pos;

    std::ifstream file ("day6_in.txt");
    std::string s;
    while(std::getline(file,s)){
        field.push_back(s);
        size_t idx = s.find('^');
        if(idx != std::string::npos){
            pos.first = field.size()-1;
            pos.second = idx;
        }
    }
    field[pos.first][pos.second] = 'X';
    col = s.size();
    row = field.size();
    // print_field(field, pos, row, col);

    while(true){
        int r = pos.first + dirs[dir].first;
        int c = pos.second + dirs[dir].second;
        if(!(r>= 0 && r < row && c >=0 && c < col)){
            break;
        }
        if(field[r][c] == '#'){
            dir = (dir + 1) % 4;
            continue;
        }
        if(field[r][c] == '.'){
            field[r][c] = '#';
            if(is_loop(field, pos, dir, row, col)){
                ans++;
            }
            field[r][c] = 'X';
        }
        
        pos = {r,c};
        // std::cout << "ans " << ans << "\n";
        // print_field(field, pos, row, col);
    }
    std::cout << "ans " << ans << "\n";
    return 0;
}