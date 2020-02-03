#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gestion.h"
#define SIZE 108


const char *Deck[] =  
{
	"B0","B1","B1","B2","B2","B3","B3","B4","B4","B5","B5","B6","B6","B7","B7","B8","B8","B9","B9", "B+2","B+2","Brev","Brev","Bpasse","Bpasse","Joker","+4",
	"J0","J1","J1","J2","J2","J3","J3","J4","J4","J5","J5","J6","J6","J7","J7","J8","J8","J9","J9","J+2","J+2","Jrev","Jrev","Jpasse","Jpasse","Joker","+4",
	"V0","V1","V1","V2","V2","V3","V3","V4","V4","V5","V5","V6","V6","V7","V7","V8","V8","V9","V9","V+2","V+2","Vrev","Vrev","Vpasse","Vpasse","Joker","+4",
	"R0","R1","R1","R2","R2","R3","R3","R4","R4","R5","R5","R6","R6","R7","R7","R8","R8","R9","R9","R+2","R+2","Rrev","Rrev","Rpasse","Rpasse","Joker","+4"
};


void shuffleboard(int taille)
{
    int size = taille;
    if (size > 1)
    {
    	int i;

        for (i = 0; i < size - 1; i++)
		{
        	int j = rand() % SIZE;
        	const char* temp = Deck[j];
        	Deck[j] = Deck[i];
       		Deck[i] = temp;
        }
    }
}


int main(int argc, char **argv)
{
	srand (time(NULL));
    shuffleboard(SIZE);
	int premiereDistrib = 14;
	int indexDistrib;
	int compteurPCartes;
	int p;
    for (p = 0; p < SIZE; p++) 	
	{
        printf("%i: %s\n", p, Deck[p]);

	}

}