#include <iostream>
#include "employee.hpp"

Employee::Employee(std::string const &name, std::string const &company, int const &age)
{
    m_Name=name;
    m_Company=company;
    m_Age=age;
}

void Employee::IntroduceYourself()
{
    std::cout << "Name : " << m_Name << std::endl;
    std::cout << "Age : " << m_Age << std::endl;
    std::cout << "Company : " << m_Company << std::endl;
}

void Employee::setName(std::string const &str)
{
    m_Name=str;
}

std::string Employee::getName()
{
    return m_Name;
}

void Employee::setCompany(std::string const &str)
{
    m_Company=str;
}

std::string Employee::getCompany()
{
    return m_Company;
}

void Employee::setAge(int const &age)
{
    if(age>=18)
        m_Age=age;
}

int Employee::getAge()
{
    return m_Age;
}

void Employee::AskForPromotion()
{
    if(m_Age>30)
    {
        std::cout << m_Name << " got promoted!" << std::endl;
    }
    else
    {
        std::cout << m_Name << ", sorry no promotion for you." << std::endl;
    }
}

Developer::Developer(std::string const &name, std::string const &company, int const &age, std::string const &FavProgLang)
    :Employee(name, company, age)
{
    m_FavProgrammingLanguage=FavProgLang;
}

void Developer::setFavProgLang(std::string const &str)
{
    m_FavProgrammingLanguage=str;
}

std::string Developer::getFavProgLang()
{
    return m_FavProgrammingLanguage;
}

void Developer::FixBug()
{
    std::cout << m_Name << " fixed bug using " << m_FavProgrammingLanguage << std::endl;
}

Teacher::Teacher(std::string const &name, std::string const &company, int const &age, std::string const &subject)
    :Employee(name, company, age)
{
    m_Subject=subject;
}

void Teacher::setSubject(std::string const &str)
{
    m_Subject=str;
}

std::string Teacher::getSubject()
{
    return m_Subject;
}

void Teacher::PrepareLesson()
{
    std::cout << m_Name << " is preparing " << m_Subject << " lesson." << std::endl;
}

void Employee::work()
{
    std::cout << m_Name << " is checking emails, task backlog, performing tasks..." << std::endl;
}

void Developer::work()
{
    std::cout << m_Name << " is writing " << m_FavProgrammingLanguage << std::endl;
}

void Teacher::work()
{
    std::cout << m_Name << " is teaching " << m_Subject << std::endl;
}