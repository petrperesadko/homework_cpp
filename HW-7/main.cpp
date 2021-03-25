#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
int main() {

// 1 --------------------------------
    std::deque<int> deq;
    deq.resize(10);
    std::iota(deq.begin(), deq.end(), 1);
// 2 --------------------------------
    std::uniform_int_distribution<int> distr(1, 10);
    std::default_random_engine engine_1(
            std::chrono::steady_clock::now().time_since_epoch().count()
    );
    deq.push_front(distr(engine_1));
    deq.push_front(distr(engine_1));
// 3 --------------------------------
    std::vector<int> vec;
    vec.resize(deq.size());
    std::copy(deq.begin(), deq.end(), vec.begin());
// 4 --------------------------------
    std::sort(vec.begin(), vec.end(), [](auto x, auto y){return y < x;});
    std::cout << "list sorted" << std::endl;
    for(auto i : vec){
        std::cout << i <<' ';
    }
// 5 --------------------------------
    //std::shuffle(vec.begin(), vec.end(), engine_1); // ????????????????????????????????????????????
// 6 --------------------------------
    std::cout << "inner product is ";
    std::cout << std::inner_product(vec.begin(), vec.end(), deq.begin(), 0) << std::endl;
// 7 --------------------------------
    std::cout << "> than 4 ";
    std::cout << std::count_if(vec.begin(), vec.end(), [](auto x){return x > 4;}) << std::endl;
// 8 --------------------------------
    std::cout << " sum is ";
    std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;
    //[](auto x, auto y){return x + y;}
// 9 --------------------------------
    std:: cout << std::accumulate(deq.begin(), deq.end(), 1, [](auto x, auto y){return x * y;}) << std::endl;
// 10 --------------------------------
    auto start = std::remove_if(deq.begin(), deq.end(), [](auto x){if(x % 2 == 0 && x > 3) return true; else return false;});
    deq.erase(start, deq.end());
// 11 --------------------------------
    auto start_1 = std::remove(deq.begin(), deq.end(), 4);
    deq.erase(start_1, deq.end());

// 12 --------------------------------
    for( auto i : deq){
        std::cout << i << ' ';
    }
// 13 --------------------------------
    std::for_each(deq.begin(), deq.end(), [](auto x){std::cout << x << ' ';});
// 14 --------------------------------
    std::minmax_element(deq.begin(), deq.end());

    return 0;
}
