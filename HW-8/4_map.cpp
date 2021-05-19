//
// Created by Петр on 19.05.2021.
//
#include <iostream>
#include <list>
#include <array>
#include <numeric>
#include <map>

int main() {
    const int number = 7;
    std::array<int, number> myarray = {1, 2, 3, 4, 10, 3, 2};
    std::list<int> myset(number);
    std::partial_sum(std::begin(myarray), std::end(myarray), std::begin(myset));
    std::map <int, bool> chetnye;

    for(auto i : myset){
        chetnye.insert(std::pair<int, bool>(i, i % 2 == 0));
    }

    for(auto i : chetnye)
        std::cout << i.first << ' ' << i.second << std::endl;

    return 0;
}
