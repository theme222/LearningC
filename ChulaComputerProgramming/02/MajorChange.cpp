#include <iostream>

inline bool IsPassing(char comprog, char cal1, char cal2)
{
    return comprog == 'A' && cal1 <= 'C' && cal2 <= 'C';
}

int main()
{
    std::string id_1,id_2;
    double gpa_1,gpa_2;
    char comprog_1, cal1_1, cal2_1;
    char comprog_2, cal1_2, cal2_2;

    std::cin >> id_1 >> gpa_1 >> comprog_1 >> cal1_1 >> cal2_1;
    std::cin >> id_2 >> gpa_2 >> comprog_2 >> cal1_2 >> cal2_2;

    // I am amazing at writing comments
    std::string choice = "Both"; // This sets choice to "Both" :)
    bool pass_1 = IsPassing(comprog_1, cal1_1, cal2_1); // This checks if first guy is passing
    bool pass_2 = IsPassing(comprog_2, cal1_2, cal2_2); // This checks if second guy is passing
    // This does stuff :D
    if (pass_1 && !pass_2) choice = id_1;
    else if (pass_2 && !pass_1) choice = id_2;
    else if (!pass_1 && !pass_2) choice = "None";
    else if (gpa_1 > gpa_2) choice = id_1;
    else if (gpa_1 < gpa_2) choice = id_2;
    else if (cal1_1 < cal1_2) choice = id_1;
    else if (cal1_1 > cal1_2) choice = id_2;
    else if (cal2_1 < cal2_2) choice = id_1;
    else if (cal2_1 > cal2_2) choice = id_2;
    // This prints it out hahahahahahhahahahah
    std::cout << choice << std::endl;
}
