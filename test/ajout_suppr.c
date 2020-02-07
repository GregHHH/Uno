#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 108


int Deck[] =
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
    A->carte=value;
    A->suivant = L;
	// printf("%s", A);
    return A;
}

Liste piocher(Liste A, Liste B)
{
    A = add_value(A, B->carte);
    A = add_value(A, B->suivant->carte);

    return A;

}

delete_value(Liste A, int value)
{
    Element B;
    if (A != NULL)
    {
        if(A->suivant != NULL)
            if(A->suivant->carte == value)
        {
            B.suivant = A->suivant;
            A->suivant = A->suivant->suivant;
        }
        else
        {
            delete_value(A->suivant, value);
        }
    }
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
	int temp;

	srand (time(NULL));
    shuffleboard(SIZE);

	for (p = 0; p < SIZE; p++)
    {
        temp = Deck[p];
        Pioche = add_value(Pioche, temp);
    }

    Playeur1 = add_value(Playeur1, 200);
    Playeur1 = add_value(Playeur1, 202);
    Playeur1 = add_value(Playeur1, 205);

    Playeur2 = add_value(Playeur2, 204);
    Playeur2 = add_value(Playeur2, 209);

    //Playeur1 = piocher(Playeur1, Playeur2);

    //Playeur1 = delete_value(Playeur1, 204);
    //
    Playeur1 = delete_value(Playeur1, 205);

    //affichageListe(Playeur2);
    affichageListe(Playeur1);

	printf("\n");
	printf("\n");

}
