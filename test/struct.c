#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Element
{
    char carte;
    struct Element *suivant;
};

typedef struct Element Element;
typedef struct Element *Liste;


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
	//printf("%s", A);
    return A;
}


int main()
{
	
}