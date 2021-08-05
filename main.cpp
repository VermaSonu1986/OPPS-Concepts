#include <iostream>
using namespace std;
/*
    1. OPPs class concepts
    2. Inheritance
    3. Encupsulation
    4. Abstraction
    5. Polymorphism run time (function overriding)
    6. Polymorphism compile time (function overloading)
    7. Polymorphism compile time (function operator)
    8. Friends functions
*/
//base class
class SignBond{
    virtual void EmployeeBond()=0;
};

class Employee:SignBond {
private:
    string Name;
    string Company;
    unsigned Age;
    unsigned ExperienceLevel;
public:
    Employee(string name, string company, unsigned age, unsigned level)
    {
        // Constructor function
        Name = name;
        Company = company;
        Age = age;
        ExperienceLevel = level;
    }
    // Getter and Setter function
    string getName(void)
    {
        return Name;
    }
    void setName(string name)
    {
        Name = name;
    }
    string getCompany(void)
    {
        return Company;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    unsigned int getAge(void)
    {
        return Age;
    }
    void setAge(unsigned int age)
    {
        Age = age;
    }
    unsigned int getExperienceLevel(void)
    {
        return ExperienceLevel;
    }
    void setExperienceLevel(unsigned int experienceLevel)
    {
        ExperienceLevel = experienceLevel;
    }
    void EmployeeBond()
    {
        if (ExperienceLevel<=2)
        {
            cout<< Name << "Signed the Bond"<< endl;
        }
        else
        {
            cout<< Name << "No Bond"<< endl;
        }
    }
    void ShowEmployeeInfo()
    {
        cout<< "Name:           " <<Name << endl;
        cout<< "Company:        " <<Company << endl;
        cout<< "Age:            " <<Age << endl;
        cout<< "ExperienceLevel "<<ExperienceLevel << endl;
    }
    void Work()
    {
        cout<< Name << " is an employee of LANDIS+GYR"<<endl;
    }
    // function overloading
    void Print(int a)
    {
        cout<< "Calling Print(int a)"<<a<<endl;
    }
    void Print(double a)
    {
        cout<< "Calling Print(double a)"<<a<<endl;
    }
    void Print(char *a)
    {
        cout<< "Calling Print(char *a)"<<a<<endl;
    }

    friend void friendFunction(Employee &d);
};

void friendFunction(Employee &d)
{
    d.Name = "Friend";
}

class FWDeveloper: public Employee
{
public:
    bool IsWorkedOnRTOS;
    bool IsWorkedOnMCU;
    int HomeTown = 0;
    FWDeveloper(string name, string company, unsigned age, unsigned level, bool isWorkedOnRTOS, bool isWorkedOnMCU)
        :Employee(name, company, age, level)
        {
            IsWorkedOnRTOS = isWorkedOnRTOS;
            IsWorkedOnMCU = isWorkedOnMCU;
        }

    //member function of FWDeveloper
    void showFWDeveloperInfo()
    {
        cout<< "Name:           " <<getName() << endl;
        cout<< "Company:        " <<getCompany() << endl;
        cout<< "Age:            " <<getAge() << endl;
        cout<< "ExperienceLevel " <<getExperienceLevel() << endl;
        cout<< "IsWorkedOnRTOS  " <<IsWorkedOnRTOS << endl;
        cout<< "IsWorkedOnMCU   " <<IsWorkedOnMCU << endl;
    }
    // Function overriding concept of polymorphism
    void Work(int homeTown)
    {
        HomeTown = homeTown;
        cout<< getName() << " is an Developer employee of LANDIS+GYR and stay in "<< HomeTown<< endl;
    }
};

class FWTester: public Employee
{
public:
    bool IsWorkedOnAutomation;
    bool IsWorkedOnManualTesting;
    string ReportingTo = "XYZ";
    FWTester(string name, string company, unsigned age, unsigned level, bool isWorkedOnAutomation, bool isWorkedOnManualTesting)
        :Employee(name, company, age, level)
        {
            IsWorkedOnAutomation = isWorkedOnAutomation;
            IsWorkedOnManualTesting = isWorkedOnManualTesting;
        }

    //member function of FWDeveloper
    void showFWTesterInfo()
    {
        cout<< "Name:                   " <<getName() << endl;
        cout<< "Company:                " <<getCompany() << endl;
        cout<< "Age:                    " <<getAge() << endl;
        cout<< "ExperienceLevel         " <<getExperienceLevel() << endl;
        cout<< "IsWorkedOnAutomation    " <<IsWorkedOnAutomation << endl;
        cout<< "IsWorkedOnManualTesting " <<IsWorkedOnManualTesting << endl;
    }
    // Function overriding concept of polymorphism
    void Work(string reportingTo)
    {
        ReportingTo = reportingTo;
        cout<< getName() << " is an Tester employee of LANDIS+GYR and Report to "<< ReportingTo << endl;
    }
};
int main()
{
    FWDeveloper FWD("SONU VERMA","LANDIS+GYR", 35, 12, true,true);
    FWTester FWT("SIRAJ","LANDIS+GYR", 38, 14, true,true);
    Employee *ptrFWD = &FWD;
    Employee *ptrFWT = &FWT;
    ptrFWD->Work();
    ptrFWT->Work();
    cout<<""<<endl;
    ptrFWD->EmployeeBond();
    ptrFWT->EmployeeBond();
    cout<<""<<endl;
    FWD.showFWDeveloperInfo();
    FWD.Work(12345);
    cout<<""<<endl;
    FWT.showFWTesterInfo();
    FWT.Work("XYZ");
    cout<<""<<endl;
    ptrFWD->Print(7);
    ptrFWD->Print(7.556);
    ptrFWD->Print("String");
    friendFunction(FWT);
    cout<< ptrFWT->getName()<<endl;

    return 0;
}
