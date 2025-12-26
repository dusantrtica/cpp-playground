#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

enum class Studies {
   Mathematics,
   Informatics,
   Astrophysics,
};

class student {
public:
    student(const std::string& name, Studies studies) : m_name(name), m_studies(studies) {}
    virtual ~student() {
        std::cout << "~student()" << std::endl;
    }
    void add_grade(int grade) {
        m_grades.push_back(grade);
    }
    double average() const {
        if(m_grades.empty()) {
            return 0;
        }
        return static_cast<double>(std::accumulate(m_grades.cbegin(), m_grades.cend(), 0.0)) / m_grades.size();
    }

    virtual std::string name() const {
        return m_name + "(" + program_name() + ")";
    }
protected:
    std::string program_name() const {
        switch(m_studies) {
            case Studies::Mathematics:
                return "Mathematics";
            case Studies::Informatics:
                return "Informatics";
            case Studies::Astrophysics:
                return "Astrophysics";
            default:
                return "Unknown";
        }
    }
//private:
    std::string m_name;
    Studies m_studies;
    std::vector<int> m_grades;
};


class master_student : public student {
public:
    master_student(const std::string& name, const Studies studies, 
    const std::string& thesis, const std::string& mentor) : student(name, studies), m_thesis(thesis), m_mentor(mentor) {
        std::cout << "master_student(name=" << name << ", studies=" << static_cast<int>(studies) << ", thesis=" << thesis << ", mentor=" << mentor << ")" << std::endl;
    }
    ~master_student() {
        std::cout << "~master_student" << std::endl;
    }
    std::string name() const override {
        return student::name() + " (" + m_thesis + ")";
    }
private:
    std::string m_thesis;
    std::string m_mentor;
};

#endif
