#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void print_v(const std::vector<int>& v){
    for(const auto& x : v){
        std::cout << x;
    }
    std::cout << "\n";
}

int main() {
    std::ifstream file("day9_in.txt");
    if(file.is_open()){
        std::string s;
        std::getline(file, s);
        int n = s.size();

        std::vector<int> disk;
        std::vector<int> avail;
        for(int i = 0; i < n; i++){
            for(int m = 0; m < (s[i] - '0'); m++){
                if(i % 2 == 0){
                    disk.push_back(i/2);
                }
                else{
                    avail.push_back(disk.size());
                    disk.push_back(0);
                }
            }
        }
        std::reverse(avail.begin(), avail.end());
        for(int i = (int) disk.size() - 1; i >= 0; i--){
            if(disk[i]){
                if(!avail.empty() && avail.back() < i){
                    disk[avail.back()] = disk[i];
                    disk[i] = 0;
                    avail.pop_back();
                }
            }
        } 

        n = disk.size();
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += i * disk[i];
        }
        std::cout << ans << "\n";
    }
    return 0;
}