//
// Created by Петр on 10.02.2021.
//


#include <iostream>
#include <chrono>
#include <cmath>
class vremya{
public:

    vremya(){
        begin = clocks::now();
    }
    ~vremya(){
        end = clocks::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>  (end - begin).count();
    }

private:
    using clocks = std::chrono::steady_clock;
    using timepoint = clocks::time_point;
    using duration = clocks::duration;
    timepoint end;
    timepoint begin;
};

int main(){
    vremya a;
    for(auto idx = 0; idx < 1e6; idx++){

        auto x = std::sin(idx) * std::tan(idx);
    }
    return 0;
}
