#include <iostream>
#include <array>
#include <algorithm>
#include <chrono>
#include <random>

std::uniform_int_distribution mnozhestvo(1, 100);
std::default_random_engine dvizhok(std::chrono::steady_clock::now().time_since_epoch().count());

int sluchainost(){
    return mnozhestvo(dvizhok);
}

int main() {
    std::array<int, 10> myarray{0};
    std::uniform_int_distribution mnozhestvo(1, 100);
    std::default_random_engine dvizhok(std::chrono::steady_clock::now().time_since_epoch().count());

    std::generate(std::begin(myarray), std::end(myarray), sluchainost);

    for(auto i : myarray){
        std::cout << i << ' ';
    }
    return 0;
}