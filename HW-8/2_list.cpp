//
// Created by Петр on 19.05.2021.
//
#include <iostream>
#include <list>
#include <array>
#include <numeric>

int main() {
    std::array<int, 4> massiv = {2, 3, 4, 5};
    std::list<int> myset(4);
    std::partial_sum(std::begin(massiv), std::end(massiv), std::begin(myset));
    for(auto i : myset)
        std::cout << i << ' ';
    return 0;
}
