#include <bits/stdc++.h>
#include <stdexcept>

typedef int GradeNum;
typedef std::pair<std::string, GradeNum> IdPair;

std::string NumToGrade(GradeNum num)
{
    switch(num)
    {
        case 0: return "F";
        case 1: return "D";
        case 2: return "D+";
        case 3: return "C";
        case 4: return "C+";
        case 5: return "B";
        case 6: return "B+";
        case 7: return "A";
        default: throw std::runtime_error("Invalid Gradenum");
    }
}

GradeNum GradeToNum(std::string& grade)
{
    if (grade == "F")  return 0;
    if (grade == "D")  return 1;
    if (grade == "D+") return 2;
    if (grade == "C")  return 3;
    if (grade == "C+") return 4;
    if (grade == "B")  return 5;
    if (grade == "B+") return 6;
    if (grade == "A")  return 7;
    throw std::runtime_error("Invalid grade");
}

std::vector<std::pair<std::string,GradeNum>> studentVector;

bool SortByGrade(IdPair a, IdPair b)
{
    return a.second > b.second;
}

int main()
{
    int students;
    std::cin >> students;

    studentVector.reserve(students);

    while (students--)
    {
        std::string id;
        std::string grade;
        GradeNum gradenum;

        std::cin >> id >> grade;

        gradenum = GradeToNum(grade);
        studentVector.push_back(std::pair(id,gradenum));

    }

    std::string operation;
    while (std::cin >> operation)
    {
        std::string opID = operation.substr(0, operation.size() - 1);
        char modifier = operation[operation.size()-1];

        for (IdPair& a: studentVector)
        {
            if (a.first == opID)
            {
                if (modifier == '+') a.second++;
                else if (modifier == '-') a.second--;
                else throw std::invalid_argument(std::string("Invalid opcode") + modifier);
                a.second = std::clamp(a.second, 0, 7); // Clamp every time it changes
            }
        }
    }

    std::sort(studentVector.begin(), studentVector.end(), SortByGrade);

    for (IdPair& a: studentVector)
        std::cout << a.first << ' ' << NumToGrade(a.second) << '\n';
}
