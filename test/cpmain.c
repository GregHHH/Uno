#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 108


char *Deck[] =  
{
	"B0","B1","B1","B2","B2","B3","B3","B4","B4","B5","B5","B6","B6","B7","B7","B8","B8","B9","B9", "B+2","B+2","Brev","Brev","Bpasse","Bpasse","Joker","+4",
	"J0","J1","J1","J2","J2","J3","J3","J4","J4","J5","J5","J6","J6","J7","J7","J8","J8","J9","J9","J+2","J+2","Jrev","Jrev","Jpasse","Jpasse","Joker","+4",
	"V0","V1","V1","V2","V2","V3","V3","V4","V4","V5","V5","V6","V6","V7","V7","V8","V8","V9","V9","V+2","V+2","Vrev","Vrev","Vpasse","Vpasse","Joker","+4",
	"R0","R1","R1","R2","R2","R3","R3","R4","R4","R5","R5","R6","R6","R7","R7","R8","R8","R9","R9","R+2","R+2","Rrev","Rrev","Rpasse","Rpasse","Joker","+4"
};

struct Element
{
    char carte;
    struct Element *suivant;
};

typedef struct Element Element;
typedef struct Element *Liste;



void shuffleboard(int taille)
{
	int i;
    int size = taille;
	int j = rand() % SIZE;
    char* temp = Deck[j];
    if (size > 1)
    {
        for (i = 0; i < size - 1; i++)
		{
        	j = rand() % SIZE;
        	temp = Deck[j];
        	Deck[j] = Deck[i];
        	Deck[i] = temp;
        }
    }
}


void affichageListe(Liste *A)
{
    Element *B = A;
    while(B)
    {
        printf("%c\n", B->carte);
        B = B->suivant;
    }
}

Element* initialisation(char value)
{

    Element *element = malloc(sizeof *element);
    element->carte = value;
    element->suivant = NULL;

    return element;
}


Liste add_value(Liste L, char *value)
{
    Element *A = malloc(sizeof *A);
    A->carte=*value;
    A->suivant = L;
	printf("%s", A);
    return A;
}

int main(int argc, char **argv)
{
	Liste Pioche;
    Liste Playeur1;
    Liste Playeur2;

	int premiereDistrib = 14;
	int indexDistrib;
	int compteurPCartes;
	int p;
	int i= 0;
	char *temp;

	srand (time(NULL));
    shuffleboard(SIZE);
	
   for (p = 0; p < SIZE; p++) 	
	{
        printf("%i: %s\n", p, Deck[p]);
	}
	
	temp = Deck[0];
	printf("%s", temp);
	add_value(Pioche, temp);
	affichageListe(Pioche);
}
