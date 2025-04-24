#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void rec(int i, long long res, long long target, const std::vector<int> & v, bool& ok){
    if(i == (int)v.size()){
        if(res == target){
            ok = true;
        }
        return;
    }
    rec(i+1, res + v[i], target, v, ok);
    rec(i+1, res * v[i], target, v, ok);
    rec(i+1, stoll(std::to_string(res) + std::to_string(v[i])), target, v, ok); // part 2
}

int main(){
    std::ifstream file("day7_in.txt");
    std::string s;
    long long total = 0;
    if(file.is_open()){
        while(std::getline(file, s)){
            long long num = 0;
            long long target = 0;
            std::vector<int> v;
            for(int i = 0; i < s.size(); i++){
                if(isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                }
                if(s[i] == ':'){
                    target = num;
                    num = 0;
                }
                else if(s[i] == ' ' && isdigit(s[i+1]) && num != 0){
                    v.push_back(num);
                    num = 0;
                }
            }
            v.push_back(num);

            bool ok = false;
            rec(1, v[0], target, v, ok);
            if(ok){
                total += target;
            }
        }
    }
    std::cout << total << "\n";
    return 0;
}