// I'm too lazy to implement delete so...
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef unsigned long long uint64; 
typedef long double ldouble;

typedef struct TableContent
{
    char* key;
    char* value;
} TableContent;

typedef struct HashTable 
{
    TableContent** arr;
    int* occupied;
    int occupiedLength;
}
HashTable;

const ldouble fractionConstant = 0.6180339887;
const int multiplier1 = 16384;
const int multiplier2 = 8192;
const int hashTableLength = 50;

uint64 IntRepresentationOfStr(char* string)
{
    int stringLength = strlen(string);
    uint64 base26String = 0;
    for (int i = 0; i < stringLength; i++)
    {
        base26String += (int)(string[i]);
        base26String *= 255;
    }
    return base26String;
}

int hash(char* string)
{
    uint64 base26String = IntRepresentationOfStr(string);
    // floor(m(kA mod 1))
    int hashValue = (int)(multiplier1 * fmodl(fractionConstant * (ldouble)base26String, 1.0)); 
    return hashValue;
}

int auxHash(char* string)
{
    uint64 base26String = IntRepresentationOfStr(string);
    return base26String % multiplier2;
}

int includes(int* arr,int arrLength, int value)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == value) return 1; 
    }
    return 0;
}

void InsertValue(HashTable* table,char* key, char* value)
{
    int i = 0;
    int index = -1;
    while (i<100)
    {
        index = (hash(key) + (i * auxHash(key))) % hashTableLength;
        printf("Hashed index : %d\n", index);
        if (!includes(table->occupied, table->occupiedLength, index)) break;
        i++;
    }
    if (i >= 100) 
    {
        puts("Error i exceeded limit in insertValue");
        exit(1);
    }
    TableContent* content = malloc(sizeof(TableContent));
    content->key = key;
    content->value = value;
    table->arr[index] = content;
    table->occupied[table->occupiedLength] = index;
    table->occupiedLength++;
}

void CheckValue(HashTable* table, char* key)
{
    int i = 0;
    int index = -1;
    while (i < 100)
    {
        index = (hash(key) + (i*auxHash(key))) % hashTableLength;
        printf("finding %d\n", index);
        if (!includes(table->occupied, table->occupiedLength, index))
        {
            puts("Key doesn't exist");
            return;
        }
        if (strcmp(table->arr[index]->key, key) == 0)
        {
            puts(table->arr[index]->value);
            return;
        }
        i++;
    }
    puts("Error i exceeeeeeded limit in checkValue");
    exit(1);
}

void VisualizeTable(HashTable* table)
{
    for (int i = 0; i < table->occupiedLength; i++)
    {
        printf("%d\n", table->occupied[i]);
    }
}

void FreeHashTable(HashTable* table)
{
    for (int i = 0; i < table->occupiedLength; i++)
    {
        TableContent* content = table->arr[table->occupied[i]];
        free(content->key);
        free(content->value);
        free(content);
    }
    free(table->occupied);
    free(table->arr);
}

int main()
{
    char inputBuffer1[50], inputBuffer2[50];
    // Initialize the hash table
    HashTable table = (HashTable)
    {
        malloc(sizeof(TableContent*) * hashTableLength),
        malloc(sizeof(int) * hashTableLength),
        0
    };
    HashTable* table_p = &table;
    puts("Insert mode");
    while (1)
    {
        scanf("%s %s", inputBuffer1, inputBuffer2);
        if (strcmp(inputBuffer1, "exit") == 0) break;
        char* key = malloc(sizeof(char) * 50);
        char* value = malloc(sizeof(char) * 50);
        strcpy(key, inputBuffer1);
        strcpy(value, inputBuffer2);
        InsertValue(table_p, key, value);
        VisualizeTable(table_p);
    }
    puts("Indexing mode");
    while (1)
    {
        scanf("%s", inputBuffer1);
        if (strcmp(inputBuffer1, "exit") == 0) break;
        CheckValue(table_p, inputBuffer1);
    }
    puts("Freeing hash table");
    FreeHashTable(table_p);
}