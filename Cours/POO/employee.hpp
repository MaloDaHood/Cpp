#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class AbstractEmployee
{
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee
{
    public:
        Employee(std::string const &name, std::string const &company, int const &age);
        void IntroduceYourself();
        void setName(std::string const &str);
        std::string getName();
        void setCompany(std::string const &str);
        std::string getCompany();
        void setAge(int const &age);
        int getAge();
        void AskForPromotion();
        virtual void work();
    protected:
        std::string m_Name;
        std::string m_Company;
        int m_Age;
};

class Developer:public Employee
{
    public:
        Developer(std::string const &name, std::string const &company, int const &age, std::string const &FavProgLang);
        void setFavProgLang(std::string const &str);
        std::string getFavProgLang();
        void FixBug();
        void work();
    private:
        std::string m_FavProgrammingLanguage;
};

class Teacher:public Employee
{
    public:
        Teacher(std::string const &name, std::string const &company, int const &age, std::string const &subject);
        void setSubject(std::string const &str);
        std::string getSubject();
        void PrepareLesson();
        void work();
    private:
        std::string m_Subject;
};

#endif