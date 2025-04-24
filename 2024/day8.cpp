#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>

void print_v(const std::vector<std::pair<int,int>>& v){
    for(const auto& x : v){
        std::cout << "(" << x.first << "," << x.second << ")";
    }
    std::cout << "\n";
}

int main(){
    std::set<std::pair<int,int>> nodes;
    std::vector<std::string> field;
    std::map<char,std::vector<std::pair<int,int>>> antennas;
    int row, col;

    std::ifstream file("day8_in.txt");
    if(file.is_open()){
        std::string s;
        while(std::getline(file, s)){
            field.push_back(s);
        }
        col = s.size();
        row = field.size();
    }

    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(field[r][c] != '.'){
                antennas[field[r][c]].emplace_back(r,c);
            }
        }
    }

    for(const auto& m : antennas){
        // print_v(m.second);
        int n = m.second.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                int x = 1;
                std::pair<int,int> node;
                std::pair<int,int> a, b;
                a = m.second[i];
                b = m.second[j];
                nodes.insert(a);
                nodes.insert(b);
                while(true){
                    node = {a.first + x * (a.first - b.first), a.second + x * (a.second - b.second)};
                    if(node.first >= 0 && node.first < row && node.second >= 0 && node.second < col){
                        nodes.insert(node);
                    }
                    else{
                        break;
                    }               
                    x++;
                }
            }
        }
    }
    std::cout << nodes.size() << "\n";
    return 0;
}