#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

int sukisugoi[100005];

// Yes I know the pass by reference keyword ok? &&&&&&&&
double GetMedian(std::vector<int> &vec)
{
    if (vec.size() % 2 == 0)
        return (double(vec[(vec.size()-1)/2]) +  double(vec[((vec.size()-1)/2)+1])) / 2;
    else 
        return vec[vec.size()/2];
}

bool IndexInRange(int n, int index)
{
    if (index < 0) return false;
    if (index >= n) return false;
    return true;
}

int main()
{
    int n, u, v;
    std::cin >> n >> u >> v;
    for (int i = 0; i < n; i++)
        scanf("%d", sukisugoi + i);
    
    // append the value of the thingg
    std::vector<int> visitedU;
    std::vector<int> visitedV;

    int indexU = 0;
    int indexV = n-1;
    while (true)
    {
        // printf("%d %d\n", indexU, indexV);
        visitedU.push_back(sukisugoi[indexU]);
        visitedV.push_back(sukisugoi[indexV]);

        indexU += u;
        indexV -= v;
        if (!IndexInRange(n,indexU) || !IndexInRange(n,indexV)) break;
    }

    // for (auto a: visitedU)
    //     printf("%d ", a);

    // puts("");
    // for (auto a: visitedV)
    //     printf("%d ", a);
    // puts("");

    // if (visitedU.size() != visitedV.size()) int a = 1/0;

    double average = 0;
    for (int i = 0; i < visitedU.size(); i++)
        average += visitedU[i] * visitedV[i];

    average /= (double)visitedU.size();
    average = round(average*100)/100;

    double medianU = GetMedian(visitedU);
    medianU = round(medianU*100)/100;
    double medianV = GetMedian(visitedV);
    medianV= round(medianV*100)/100;

    std::cout << std::fixed << std::setprecision(2) << average << ' ' << medianU <<  ' ' <<medianV << '\n';

}