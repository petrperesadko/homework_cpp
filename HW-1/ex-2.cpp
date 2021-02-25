//
// Created by Петр on 10.02.2021.
//

#include <iostream>
#include <memory>

class Course
{
private:
    class Student{
    public:
        std::string name;
    };
    std::string Teachers_name;
    std::unique_ptr<Student[]> smart_pointer { new Student[16] };
public:
    Course(int amount_of_students) {    //
        int counter = 0;
        for (int i = 0; i < amount_of_students; i++) {
            smart_pointer[i].name = (char)('a' + 2 * i);
            counter++;
        }
        for(int i = counter; i < 15; i++){
            smart_pointer[i].name = "-";
        }
        smart_pointer[15].name = "-";
    }
    void show_the_class(){                                                  // shows the whole class with it's teacher
        for (int i = 0; i < 15; i++) {
            std::cout << i + 1 << ")" << '\t' << smart_pointer[i].name << std::endl;
        }
        std::cout << "Teacher:" << '\t' << Teachers_name;
        std::cout << std::endl;
    }
    void delete_student(std::string name){                                  // deleting a student using his name
        for(int i = 0; i < 15; i++){
            if(smart_pointer[i].name == name)
                smart_pointer[i].name ="-";
        }
    }
    void add_student(std::string name){                                   // adding new student to the first empty cell
        for(int i = 0; i < 15; i++){
            if(smart_pointer[i].name == "-"){
                smart_pointer[i].name = name;
            }
        }
        for(int j = 0; j < 15; j++){                                       //sorting student`s names in alphabet order
            for(int i = 0; i < 14; i++){
                for(int k = 0; k < 1; k++){
                    if((smart_pointer[i].name)[0] > (smart_pointer[i+1].name)[0]){
                        std::string temporary = "-";
                        temporary = smart_pointer[i+1].name;
                        smart_pointer[i+1].name = smart_pointer[i].name;
                        smart_pointer[i].name = temporary;
                    }
                }
            }
        }
        for(int j = 0; j < 16; j++){
            for(int i = 0; i < 14; i++){
                if((smart_pointer[i].name)[0] == (smart_pointer[i+1].name)[0]){
                    smart_pointer[i + 1].name = smart_pointer[i + 2].name;
                }
            }
        }
    }
    void set_teachers_name(std::string name){                                           // setting the teacher`s name
        Teachers_name = name;
    }
};

int main(){
    Course a(5);
    a.set_teachers_name("Petr");
    a.show_the_class();
    a.add_student("b");
    a.show_the_class();
    a.delete_student("a");
    a.show_the_class();


    return 0;
}