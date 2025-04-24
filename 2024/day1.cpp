#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

int main (){

    std::ifstream file ("day1_input.txt");
    std::vector<int> first;
    std::vector<int> second;
    int val;
    int count = 0;

    while(file >> val){
        if(count%2 == 0){
            first.push_back(val);
        }
        else{
            second.push_back(val);
        }
        count++;
    }
    
    // Part 1
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
    long int sum = 0;
    for(int i = 0; i < first.size(); i++){
        sum += abs(first[i] - second[i]);
    }
    std::cout << sum << '\n';


    // Part 2
    sum = 0;
    std::map<int,int> freq;
    for(int x : second){
        freq[x]++;
    }
    for(int x : first){
        sum += x * freq[x];
    }
    std::cout << sum << '\n';
    return 0;
}