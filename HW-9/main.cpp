#include <iostream>
#include <map>
#include <list>

class Students {
public:
    Students() {};

    void insert(std::string surname, int mark) {
        marks[surname] = mark;
    }
    void list_of_students() {
        for (auto i : marks)
            std::cout << i.first << " gets " << i.second << std::endl;
    }
    auto find(std::string surname) {
        auto pos = marks.find(surname);
        return pos->second;
    }
    std::list<std::string> range(int x) {
        std::list<std::string> l;
        for (auto i : marks) {
            if (i.second == x) {
                l.push_back(i.first);
            }
        }
        return l;
    }
    void standings() {
        std::map<int, std::list<std::string>, std::greater<int>> sortMarks;
        for (auto i : marks) {
            sortMarks[i.second].push_back(i.first);
        }

        for (auto i : sortMarks) {
            std::cout << i.first << "  ";
            for (auto j : i.second) {
                std::cout << j << std::endl;
                std::cout << std::endl;
            }
        }
    }
private:
    std::map<std::string, int> marks;
};

int main() {
    Students banda;
    banda.insert("ahahhaha", 228);
    banda.insert("AHAHAHAHA", 666);
    banda.list_of_students();
    banda.standings();
    std::cout << "ahahhaha " << banda.find("ahahhaha");
    return 0;
}