#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CITY_NAMES_COUNT 10

const char* cityNames[] = {
    "Seattle",
    "Chicago",
    "San Diego",
    "Orlando",
    "Anahiem",
    "Tampa",
    "Indianapolis",
    "Portland",
    "Chelan",
    "Sandusky"
};

void shuffleCities()
{
    int size = CITY_NAMES_COUNT;
    if (size > 1)
    {
        int i;
        //step through each index of the city name array
        for (i = 0; i < size - 1; i++)
        {
        //pick a random index (j) to swap it with
        //okay to pick same value as i
        int j = rand() % CITY_NAMES_COUNT; //random between 0 and 10
        const char* temp = cityNames[j];
        cityNames[j] = cityNames[i];
        cityNames[i] = temp;
        }
    }
}

int main(int argc, char* argv[])
{
    srand (time(NULL));
    shuffleCities();

    printf("SHUFFLED CITY NAME ARRAY\n");
    int p;
    for (p = 0; p < CITY_NAMES_COUNT; p++) {
        printf("%i: %s\n", p, cityNames[p]);
    }
}