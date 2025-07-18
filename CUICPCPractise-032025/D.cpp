#include <iostream>
#include <queue>

using pair = std::pair<int,int>;

// candle, student num
std::queue<pair> q1;
std::queue<pair> q2;

int main()
{
    int children, candle;
    std::cin >> children >> candle;

    for (int i = 1; i <= children; i++)
    {
        int studentCandle;
        std::cin >> studentCandle;
        q1.push(pair(studentCandle,i));
    }

    int lastStudentId = -1;
    std::queue<pair> *currentQ = &q1;
    std::queue<pair> *nextQ = &q2;
    while (!q1.empty() || !q2.empty())
    {
        int currentSize = currentQ->size();
        for (int i = 0; i < currentSize; i++)
        {
            pair student = currentQ->front();
            currentQ->pop();
            student.first -= candle;
            if (student.first <= 0)
            {
                lastStudentId = student.second;
                continue;
            }
            nextQ->push(student);
        }
        std::queue<pair> *temp = currentQ;
        currentQ = nextQ;
        nextQ = temp;
    }
    std::cout << lastStudentId << std::endl;
}
