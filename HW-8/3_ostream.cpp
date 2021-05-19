//
// Created by Петр on 19.05.2021.
//
#include <iostream>
#include <list>
#include <array>
#include <numeric>
#include <iterator>

int main() {
    std::array<int, 4> myarray = {1, 2, 3, 4};
    std::list<int> myset(4);
    std::partial_sum(std::begin(myarray), std::end(myarray), std::begin(myset));
    copy(std::begin(myset), std::end(myset), std::ostream_iterator<int>(std::cout," "));
    return 0;
}
