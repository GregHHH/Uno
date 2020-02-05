#include "includes.h"



int Deck[] =
{
	100,101,101,102,102,103,103,104,104,105,105,106,106,107,107,108,108,109,109,110,110,111,111,112,112,113,114,
	200,201,201,202,202,203,203,204,204,205,205,206,206,207,207,208,208,209,209,210,210,211,211,212,212,213,214,
	300,301,301,302,302,303,303,304,304,305,305,306,306,307,307,308,308,309,309,310,310,311,311,312,312,313,314,
	400,401,401,402,402,403,403,404,404,405,405,406,406,407,407,408,408,409,409,410,410,411,411,412,412,413,414,
};

void translateDisplay(void)
{
    int p;
	char *tr;
	tr = malloc(sizeof(char)*5);
    for (p = 0; p < SIZE; p++) 	
	{
		tr = translate(Deck[p]);
        printf("%i: %s\n", Deck[p], tr);
	}
	
}

void shuffleboard(int taille)
{
	int i;
    int size = taille;
	int j = rand() % SIZE;
    int temp = Deck[j];
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
        printf("%i: %d\n", p, Deck[p]);

	}
	printf("\n---------- TRADUCTION EN CARTES LISIBLES PAR L'UTILISATEUR ----------\n");
	translateDisplay();
}