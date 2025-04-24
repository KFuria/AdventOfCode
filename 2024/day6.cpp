#include <iostream>
#include <fstream>
#include <vector>
#include <string>


void print_field(std::vector<std::string>& field, std::pair<int,int> pos, int row, int col){
    for(int m = 0; m < row; m++){
        for(int n = 0; n < col; n++){
            std::cout << field[m][n];
        }
        std::cout << "\n";
    }
    std::cout << "Pos: " << pos.first << " " << pos.second << "\n";
    return;
}

int main(){

    // Read input into a 2d vector
    std::vector<std::string> field;
    int row, col = -1;
    long int cov = 1;
    std::vector<std::pair<int,int>> dirs = {{-1,0}, {0,1}, {1,0},{0,-1}};
    int dir = 0;
    std::pair<int,int> pos;

    std::ifstream file ("day6_s.txt");
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
    print_field(field, pos, row, col);

    while(true){
        int r = pos.first + dirs[dir].first;
        int c = pos.second + dirs[dir].second;
        // std::cout << r << " " << c<<"\n";
        if(!(r>= 0 && r < row && c >=0 && c < col)){
            break;
        }
        if(field[r][c] == '.'){
            cov += 1;
            field[r][c] = 'X';
        }
        if(field[r][c] == '#'){
            dir = (dir + 1) % 4;
            continue;
        }
        pos = {r,c};
        
        // print_field(field, pos, row, col);
        // std::cout << "Cov " << cov << "\n";
    }
    std::cout << "Cov " << cov << "\n";
    return 0;
}