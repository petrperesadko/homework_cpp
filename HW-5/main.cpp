#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <direct.h>
//#include <experimental/filesystem>
int main() {

    mkdir("C:\\C++\\homework_cpp\\HW-5\\processed");
    std::string output;
    std::ofstream outf("C:\\C++\\homework_cpp\\HW-5\\processed\\SomeText.txt");
    if (!outf){exit(1);}
    outf << "aBc Abc abC" << std::endl;
    std::ifstream inf("C:\\C++\\homework_cpp\\HW-5\\processed\\SomeText.txt");
    if (!inf){exit(1);}

    std::ofstream c_file("C:\\C++\\homework_cpp\\HW-5\\processed\\c.txt");
    std::ofstream even_file("C:\\C++\\homework_cpp\\HW-5\\processed\\even.txt");
    std::ofstream odd_file("C:\\C++\\homework_cpp\\HW-5\\processed\\odd.txt");

    int counter = 0;
    bool is_c = false;
    std::string strOutput;
    std::string c;
    while (inf)
    {
        getline(inf, strOutput);
        c = strOutput;
        for(auto it = 0; it < strOutput.size(); it++){
            if('A' <=  strOutput[it] && strOutput[it] <= 'Z'){
                strOutput[it] = tolower(strOutput[it]);
                c[it] = tolower(c[it]);
            }
            if(strOutput[it] != ' '){
                counter++;
            }
            if(c[it] == 'c'){
                is_c = true;
                c[it] = 'C';
            }
        }
        if(is_c){
            c_file << c << std::endl;
        }
        if(counter % 2 == 0 && !is_c){
            even_file << strOutput << std::endl;
            std::cout << "even file" << std::endl;
        }
        if(!is_c && counter % 2 != 0){
            odd_file << strOutput << std::endl;
            std::cout << "odd file" << std::endl;
        }
    }
    std::cout << strOutput << std::endl;
    std::cout << c << std::endl;
    std::cout << "counter is " << counter << std::endl;
    return 0;
}
