// Looks the simplest, is pretty bad in terms of randomness xd
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define uint64 unsigned long long int

uint64 m = 4294967296; // 2^32 used as our modulus value
uint64 a = 55797; // 0xd9f5 used our multiplier https://www.researchgate.net/publication/354960552_Computationally_easy_spectrally_good_multipliers_for_congruential_pseudorandom_number_generators 
uint64 c = 0; // I have no idea ima be honest
uint64 *arr;

uint64 LinearCongruentialGen(uint64 seed)
{
    return (a * seed + c) % m;
}

void RandomNumberGenerator(uint64 low, uint64 high, uint64 amount, uint64 seed)
{
    uint64 val = seed;
    uint64 diff = high-low;
    for (uint64 i = 0; i < amount; i++)
    {
        val = LinearCongruentialGen(val);
        arr[i] = low + (val % diff);
    }
}

int main()
{
    uint64 amount = 20000;
    arr = malloc(sizeof(uint64) * amount);
    RandomNumberGenerator(0,100,amount,34568);
    for (uint64 i = 0; i < amount; i++)
    {
        printf("%llu\n", arr[i]);
    }
    free(arr);
}