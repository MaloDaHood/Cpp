#include <iostream>
#include "employee.hpp"

int main()
{
    Employee employee {"Malo", "Google", 17};
    employee.setCompany("Facebook");
    employee.IntroduceYourself();

    Developer dev {"Dev", "Netflix", 25, "C++"};
    dev.FixBug();
    dev.IntroduceYourself();

    Teacher teacher {"Mac", "Notre Dame", 30, "LLCE"};
    teacher.IntroduceYourself();
    teacher.PrepareLesson();

    employee.work();
    dev.work();
    teacher.work();

    Employee *e1 {&dev};
    Employee *e2 {&teacher};
    e1->work();
    e2->work();

    return 0;
}