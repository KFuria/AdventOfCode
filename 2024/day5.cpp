#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

int main(){
    //read input
    std::map<int, std::vector<int>> rules;
    long int total_correct_sum = 0;

    std::ifstream file ("day5_s.txt");
    
    if(file.is_open()){
        std::string s;
        while(std::getline(file, s)){
            if(s.empty() || !isdigit(s[0])){
                continue;
            }
            if(s[2]=='|'){
                int a = (s[0] - '0') * 10 + (s[1] - '0');
                int b = (s[3] - '0') * 10 + (s[4] - '0');
                rules[a].push_back(b);
            }
            if(s[2] == ','){
                int s_size = s.size();
                std::set<int> earlier;
                std::vector<int> update;
                bool correct = true;
                
                for(int i = 0; i < s_size; i+=3){
                    int a = (s[i] - '0') * 10 + (s[i+1] - '0');
                    update.push_back(a); // add page num to update vector
                    // check rule for current page num 
                    for(int b: rules[a]){
                        if(earlier.count(b)){
                            correct = false;
                        }
                    }
                    earlier.insert(a);
                }
                if(correct){
                    total_correct_sum += update[update.size()/2];
                }
            }
        }
    }
    std::cout << total_correct_sum << "\n";
    return 0;
}