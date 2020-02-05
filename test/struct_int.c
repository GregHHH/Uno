#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 108

 //10 = +2 
 //11 = changement de sens
 //12 = passe le tour
 //13 = joker
 //14 = +4
int Deckint[] =
{
	100,101,101,102,102,103,103,104,104,105,105,106,106,107,107,108,108,109,109,110,110,111,111,112,112,113,114,
	200,201,201,202,202,203,203,204,204,205,205,206,206,207,207,208,208,209,209,210,210,211,211,212,212,213,214,
	300,301,301,302,302,303,303,304,304,305,305,306,306,307,307,308,308,309,309,310,310,311,311,312,312,313,314,
	400,401,401,402,402,403,403,404,404,405,405,406,406,407,407,408,408,409,409,410,410,411,411,412,412,413,414,
};

struct Element
{
    int carte;
    struct Element *suivant;
};

typedef struct Element Element;
typedef struct Element *Liste;



void shuffleboard(int taille)
{
	int i;
    int size = taille;
	int j = rand() % SIZE;
    int temp = Deckint[j];
    if (size > 1)
    {
        for (i = 0; i < size - 1; i++)
		{
        	j = rand() % SIZE;
        	temp = Deckint[j];
        	Deckint[j] = Deckint[i];
        	Deckint[i] = temp;
        }
    }
}
char* translate(int t)
{
     if (t >= 100 && t < 115)
     {
         return "Red";
     }
     if (t >= 200 && t < 215)
     {
         return "Blue";
     }
     if (t >= 300 && t < 315)
     {
         return "Yellow";
     }
     if (t >= 400 && t < 415)
     {
         return "Green";
     }
     return 0;
}

void translateDisplay(void)
{
    int p; 
    for (p = 0; p < SIZE; p++) 	
	{
        printf("%i: %s\n", p, translate(Deckint[p]));
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

Element* initialisation(int value)
{

    Element *element = malloc(sizeof *element);
    element->carte = value;
    element->suivant = NULL;

    return element;
}


Liste add_value(Liste L, int value)
{
    Element *A = malloc(sizeof *A);
    A->carte= value;
    A->suivant = L;
	printf("%s\n", A);
    return A;
}

int main(int argc, char **argv)
{
	Liste Pioche;
    Liste Playeur1;
    Liste Playeur4;

	int premiereDistrib = 14;
	int indexDistrib;
	int compteurPCartes;
	int p;
	int i= 0;
	int temp;

	srand (time(NULL));
    shuffleboard(SIZE);
	
   for (p = 0; p < SIZE; p++) 	
	{
        printf("%i: %d\n", p, Deckint[p]);
	}
	
	temp = Deckint[0];
	printf("%d", temp);
	add_value(Pioche, temp);
	affichageListe(Pioche);
    translateDisplay();
}
