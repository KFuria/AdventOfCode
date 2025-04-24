#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::pair<int,int>> hor   {{1,0},{2,0},{3,0}};
std::vector<std::pair<int,int>> hor_b   {{-1,0},{-2,0},{-3,0}};
std::vector<std::pair<int,int>> ver   {{0,1},{0,2},{0,3}};
std::vector<std::pair<int,int>> ver_b {{0,-1},{0,-2},{0,-3}};
std::vector<std::pair<int,int>> diag1 {{1,1},{2,2},{3,3}};
std::vector<std::pair<int,int>> diag2 {{1,-1},{2,-2},{3,-3}};
std::vector<std::pair<int,int>> diag3 {{-1,-1},{-2,-2},{-3,-3}};
std::vector<std::pair<int,int>> diag4 {{-1,1},{-2,2},{-3,3}};
std::vector<std::vector<std::pair<int,int>>> dirs {hor, hor_b, ver, ver_b, diag1, diag2, diag3, diag4};
int dir_l = dirs.size();


bool checkW(std::vector<std::string> &matrix, int row, int col, int k){
    std::vector<std::pair<int,int>> dir = dirs[k];
    std::string c = "MAS"; 
    for(int i = 0; i < 3; i++){
        int x = dir[i].first;
        int y = dir[i].second;
        if(matrix[row+y][col+x] != c[i]){
            return false;
        }
    }
    return true;

}

bool checkBounds(int row_l, int col_l, int row, int col, int k){
    std::vector<std::pair<int,int>> dir = dirs[k];
    for(int a = 0; a < 3; a++){
        int x = dir[a].first;
        int y = dir[a].second;
        // std::cout << "x, y: ";
        // std::cout << x << " " << y;
        // std::cout << " col, row: ";
        // std::cout << (col+x) << " " << (row+y) << "\n";
        if((col+x)>=col_l || (col+x)<0 || (row+y)>=row_l || (row+y)<0){
            return false;
        }
    }
    return true;
}

int main(){

    int count = 0;

    std::ifstream file ("day4_s.txt");
    if(file.is_open()){
        //read input into 2d array
        std::vector<std::string> matrix;
        std::string s;
        while(std::getline(file, s)){
            matrix.push_back(s);
        }
        int row_l = matrix.size();
        int col_l = s.size();

        for(int row = 0; row < row_l; row++){
            for(int col = 0; col < col_l; col++){
                if(matrix[row][col] == 'X'){
                    // std::cout << "X: " << row << col << "\n";
                    //for each direction
                    for(int k = 0; k < dir_l; k++){
                        //check bounds and check for word
                        if(checkBounds(row_l, col_l, row, col, k) && checkW(matrix, row, col, k)){
                            count++;
                        }
                    }                                          
                }
            }
        }

        std::cout << count << "\n";
    }
    file.close();
    

    return 0;
}