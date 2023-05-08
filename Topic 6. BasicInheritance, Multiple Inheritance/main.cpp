#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    size_t age;

public:
    Employee() {
        std::cout << "Employee()" << std::endl;
        name = "UNNAMED";
        age = 18;
    }

    Employee(const std::string &name, size_t age) : name(name), age(age) {
        std::cout << "Employee(" << name << ", " << age << ")" << std::endl;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Employee::name = name;
    }

    size_t getAge() const {
        return age;
    }

    void setAge(size_t age) {
        Employee::age = age;
    }
};

class Developer: public Employee {
protected:
    std::string department;
    std::string project;
    std::string language;

public:
    Developer() {
        std::cout << "Developer()" << std::endl;
        department = "UNNAMED";
        project = "UNNAMED";
        language = "UNNAMED";
    }

    Developer(const std::string &name,
              size_t age,
              const std::string &department,
              const std::string &project,
              const std::string &language) : Employee(name, age) {
        std::cout << "Developer(withParameters)" << std::endl;
        this->department = department;
        this->project = project;
        this->language = language;
    }

    const std::string &getDepartment() const {
        return department;
    }

    void setDepartment(const std::string &department) {
        Developer::department = department;
    }

    const std::string &getProject() const {
        return project;
    }

    void setProject(const std::string &project) {
        Developer::project = project;
    }

    const std::string &getLanguage() const {
        return language;
    }

    void setLanguage(const std::string &language) {
        Developer::language = language;
    }
};

class JavaDeveloper : public Developer{
public:
    JavaDeveloper(const std::string &name,
                  size_t age,
                  const std::string &department,
                  const std::string &project)
                  : Developer(name, age, department, project, "Java") {
        std::cout << "JavaDeveloper(withParameters)" << std::endl;
    }
};

class JavaDeveloper2 {
private:
    Developer developer;

public:
    JavaDeveloper2(const std::string &name,
                   size_t age,
                   const std::string &department,
                   const std::string &project) : developer(name, age, department, project, "Java") {
        std::cout << "JavaDeveloper2(withParameters)" << std::endl;
    }
};

class Departmental {
protected:
    std::string department;

public:
    Departmental(const std::string &department) : department(department) {
        std::cout << "Departmental(withParameter)" << std::endl;
    }
};

class QualityAssuarance : public Employee, public Departmental {
public:
    QualityAssuarance(const std::string &name, size_t age, const std::string &department)
    : Employee(name, age), Departmental(department) {
        std::cout << "QualityAssuarance(withParameters)" << std::endl;
    }
};

//Diamond problem
class A {
public:
    int a = 5;
};
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    D d;
    std::cout << d.a << std::endl;
    return 0;
}
