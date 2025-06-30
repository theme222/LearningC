#include <iostream>

void printAccept()
{
    puts("Ingredient accepted!");
    exit(0);
}

void printReject()
{
    puts("Ingredient rejected!");
    exit(0);
}

int main()
{
    std::string season, moon, ingredient;
    std::cin >> season >> moon >> ingredient;

    if (season == "spring" || season == "summer")
    {
        if (moon == "full")
        {
            if (ingredient == "honey" || ingredient == "milk") printAccept(); 
            else printReject();
        }
        else
        {
            if (moon == "new" && ingredient != "chocolate") printReject();
            else printAccept();
        }
    }
    else
    {
        if (season == "autumn" || season == "winter") 
        {
            if (moon == "waning" || moon == "new") 
            {
                if (ingredient == "chocolate" || ingredient == "milk") printAccept();
                else printReject(); 
            }
            else
            {
                printAccept();
            }

        }
        else printReject();
    }
}