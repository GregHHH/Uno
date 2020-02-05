#include "includes.h"



char* GetValue(int t)
{
	int c;
		if (t >= 100 && t < 115)
        	c = t - 100;
		else if (t >= 200 && t < 215)
        	c = t - 200;
		else if (t >= 300 && t < 315)
        	c = t - 300;
		else if (t >= 400 && t < 415)
        	c = t - 400;


        if (c == 0)
            return "0";
         if (c == 1)
            return "1";
         if (c == 2)
            return "2";
         if (c == 3)
            return "3";
         if (c == 4)
            return "4";
         if (c == 5)
            return "5";
         if (c == 6)
            return "6";
         if (c == 7)
            return "7";
         if (c == 8)
            return "8";
         if (c == 9)
            return "9";
        if (c == 10)
            return "+2";
        if (c == 11)
            return "reverse";
        if (c == 12)
            return "Passe";
        if (c == 13)
            return "Joker";
        if (c == 14)
            return "+4";
    return 0;
}

char* translate(int t)
{
    char *value;
    char *color;
    char *inter = " ";
    char *cat;
	int c;
	value = malloc(sizeof(char) * 5);

     if (t >= 100 && t < 115)
     {
		color = "R";
		value = GetValue(t);
		
     }

     else if (t >= 200 && t < 215)
     {
         color = "B";
		 value = GetValue(t);
		
     }

     else if (t >= 300 && t < 315)
     {
         color = "J";
		 value = GetValue(t);
     }

     else if (t >= 400 && t < 415)
     {
         color = "V";
		 value = GetValue(t);
     }

	cat = malloc(strlen(value)+strlen(color)+1);
    strcat(cat, color);
    strcat(cat, inter);
    strcat(cat, value);
	
	return(cat);
}
