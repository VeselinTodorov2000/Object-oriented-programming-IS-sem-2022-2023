#include <iostream>
#include <string>

/*
 * Искаме да имаме софтуерна компания, която трябва да има следните типове служители и информация свързана с тях:
    Developer - име, години, департамент, проект, основен програмен език
    QA - име, години, департамент, тип (manual/automation/hybrid)
    DevOps - име, години, проект
    BusinessDev - име, години, проект, имейл
 */
class Employee {
protected:
    std::string name;
    size_t age;

private:
public:
    Employee() {}

    Employee(const std::string &name, size_t age) : name(name), age(age) {
        std::cout << "Employee(withParameters)" << std::endl;
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

class DepartmentEmployee {
protected:
    std::string department;
public:
    DepartmentEmployee() {}

    DepartmentEmployee(const std::string &department) : department(department) {
        std::cout << "DepartmentEmployee(withParameters)" << std::endl;
    }

    const std::string &getDepartment() const {
        return department;
    }

    void setDepartment(const std::string &department) {
        DepartmentEmployee::department = department;
    }
};

class ProjectEmployee {
protected:
    std::string project;
public:
    ProjectEmployee(const std::string &project) : project(project) {
        std::cout << "ProjectEmployee(withParameters)" << std::endl;
    }

    const std::string &getProject() const {
        return project;
    }

    void setProject(const std::string &project) {
        ProjectEmployee::project = project;
    }
};

class Developer : public Employee, public DepartmentEmployee, public ProjectEmployee {
private:
    std::string language;

public:
    Developer(const std::string &name, size_t age, const std::string &department, const std::string &project,
              const std::string &language) : Employee(name, age), DepartmentEmployee(department),
                                             ProjectEmployee(project), language(language) {
        std::cout << "Developer(withParameters)" << std::endl;
    }
};

enum class Type {
    MANUAL,
    AUTOMATION,
    HYBRID
};

class QualityAssuarance : public Employee, public DepartmentEmployee {
private:
    Type qualityAssuaranceType;
public:
    QualityAssuarance(const std::string &name, size_t age, const std::string &department, Type qualityAssuaranceType)
            : Employee(name, age), DepartmentEmployee(department), qualityAssuaranceType(qualityAssuaranceType) {
        std::cout << "QualityAssuarance(withParameters)" << std::endl;
    }
};

class DevOps : public ProjectEmployee, public Employee {
public:
    DevOps(const std::string &project, const std::string &name, size_t age) : ProjectEmployee(project),
                                                                              Employee(name, age) {
        std::cout << "DevOps(withParameters)" << std::endl;
    }
};

class BusinessDeveloper : public Employee, public ProjectEmployee {
private:
    std::string email;
public:
    BusinessDeveloper(const std::string &name, size_t age, const std::string &project, const std::string &email)
            : Employee(name, age), ProjectEmployee(project), email(email) {
        std::cout << "BusinessDeveloper(withParameters)" << std::endl;
    }
};

int main() {
    std::cout << "Developer" << std::endl;
    Developer developer("Ivan", 30, "Delivery", "Project1", "C#");
    std::cout << "--------------------------" << std::endl;

    std::cout << "QA" << std::endl;
    QualityAssuarance qualityAssuarance("Ivan", 30, "Delivery", Type::MANUAL);
    std::cout << "--------------------------" << std::endl;

    std::cout << "DevOps" << std::endl;
    DevOps devOps("Project2", "Ivan", 30);
    std::cout << "--------------------------" << std::endl;

    std::cout << "BusinessDeveloper" << std::endl;
    BusinessDeveloper businessDeveloper("Ivan", 30, "Project3", "busdev@gmail.com");
    std::cout << "--------------------------" << std::endl;
    return 0;
}
