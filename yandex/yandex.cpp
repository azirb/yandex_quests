#include <iostream>
#include <string.h>
#include <math.h>
using namespace std; 

struct ingred
{
	char name[20];
	 double count;
	char unit[4];
};


struct ingredbel
{
	char name[20];
	double count;
	char unit[4];
	 double bel;
	 double jir;
	 double ugl;
	 double energy;
};


struct dish
{
	char name[20]; 
	int countFriends; 
	int countIngredients; 
	ingred *massiv;
	 double bel=0;
	 double jir=0;
	 double ugl=0;
	 double energy=0;
};


struct catalog
{
	char name[20];
	int price; 
	double count;
	char unit[4];
};


int main()
{
	int countdish, countcatalog, countingred;
	double price=0;

	cin >> countdish;

	dish *masdish = new dish[countdish];

	for (int i = 0; i < countdish; i++)
	{
		cin >> masdish[i].name >> masdish[i].countFriends >> masdish[i].countIngredients;
		masdish[i].massiv = new ingred[masdish[i].countIngredients];
		for (int j = 0; j < masdish[i].countIngredients; j++)
		{
			cin >> masdish[i].massiv[j].name >> masdish[i].massiv[j].count >> masdish[i].massiv[j].unit;
		}
	}

	cin >> countcatalog;
	catalog *mascatalog = new catalog[countcatalog]; 

	for (int i = 0; i < countcatalog; i++)
	{
		cin >> mascatalog[i].name >> mascatalog[i].price >> mascatalog[i].count >> mascatalog[i].unit; 
	}

	cin >> countingred; 

	ingredbel *masingredbel = new ingredbel[countingred]; 

	for (int i = 0; i < countingred; i++)
	{
		cin >> masingredbel[i].name >> masingredbel[i].count >> masingredbel[i].unit >> masingredbel[i].bel >> masingredbel[i].jir >> masingredbel[i].ugl >> masingredbel[i].energy; 
	}

	int *mas = new int[countcatalog];

	for (int i = 0; i < countcatalog; i++)
	{
		mas[i] = 0; 
	}

	for (int i = 0; i < countcatalog; i++)
	{
		for (int j = 0; j < countdish; j++)
		{
			for (int k = 0; k < masdish[j].countIngredients; k++)
			{
				if (strcmp(masdish[j].massiv[k].name, mascatalog[i].name) == 0)
				{
					mas[i] = mas[i] + (masdish[j].massiv[k].count*masdish[j].countFriends);

					if (strcmp(masdish[j].massiv[k].unit, mascatalog[i].unit) == 0)
					{
						continue; 
					}
					else
					{
						if (strcmp(masdish[j].massiv[k].unit, "ml") == 0)
						{
							mas[i] = (int)ceil((double)mas[i] / 1000.00);
						}

						if (strcmp(masdish[j].massiv[k].unit, "l") == 0)
						{
							mas[i] *= 1000;
						}

						if (strcmp(masdish[j].massiv[k].unit, "g") == 0)
						{
							mas[i] = (int)ceil((double)mas[i] / 1000.00);
						}

						if (strcmp(masdish[j].massiv[k].unit, "kg") == 0)
						{
							mas[i] *= 1000;
						}

						if (strcmp(masdish[j].massiv[k].unit, "cnt") == 0)
						{
							mas[i] = (int)ceil((double)mas[i] / 10.00);
						}

						if (strcmp(masdish[j].massiv[k].unit, "tens") == 0)
						{
							mas[i] *= 10;
						}
					}

				}
				else
					continue; 
			}
		}
	}

	for (int i = 0; i < countcatalog; i++)
	{
		mas[i] = (int)ceil((double)mas[i] / mascatalog[i].count);
		price += mas[i] * mascatalog[i].price;
	}


	for (int i = 0; i < countdish; i++)
	{
		for (int j = 0; j < masdish[i].countIngredients; j++)
		{
			for (int k = 0; k < countingred; k++)
			{
				if (strcmp(masdish[i].massiv[j].name, masingredbel[k].name) == 0)
				{
					if (strcmp(masdish[i].massiv[j].unit, masingredbel[k].unit) == 0)
					{
						masdish[i].bel = masdish[i].bel + (masdish[i].massiv[j].count / masingredbel[k].count)*masingredbel[k].bel;
						masdish[i].jir = masdish[i].jir + (masdish[i].massiv[j].count / masingredbel[k].count)*masingredbel[k].jir;
						masdish[i].ugl = masdish[i].ugl + (masdish[i].massiv[j].count / masingredbel[k].count)*masingredbel[k].ugl;
						masdish[i].energy = masdish[i].energy + (masdish[i].massiv[j].count / masingredbel[k].count)*masingredbel[k].energy;
					}
					else
					{
						if (strcmp(masdish[i].massiv[j].unit, "ml") == 0)
						{
							masdish[i].massiv[j].count = masdish[i].massiv[j].count / 1000.000;
						}

						if (strcmp(masdish[i].massiv[j].unit, "l") == 0.00)
						{
							masdish[i].massiv[j].count *= 1000.000;
						}

						if (strcmp(masdish[i].massiv[j].unit, "g") == 0)
						{
							masdish[i].massiv[j].count = masdish[i].massiv[j].count / 1000.000;
						}

						if (strcmp(masdish[i].massiv[j].unit, "kg") == 0.000)
						{
							masdish[i].massiv[j].count *= 1000.000;
						}

						if (strcmp(masdish[i].massiv[j].unit, "cnt") == 0.000)
						{
							masdish[i].massiv[j].count = masdish[i].massiv[j].count / 10;
						}

						if (strcmp(masdish[i].massiv[j].unit, "tens") == 0.000)
						{
							masdish[i].massiv[j].count *= 10.000;
						}

						masdish[i].bel = masdish[i].bel + (masdish[i].massiv[j].count / masingredbel[k].count)*masingredbel[k].bel;
						masdish[i].jir = masdish[i].jir + (masdish[i].massiv[j].count / masingredbel[k].count)*masingredbel[k].jir;
						masdish[i].ugl = masdish[i].ugl + (masdish[i].massiv[j].count / masingredbel[k].count)*masingredbel[k].ugl;
						masdish[i].energy = masdish[i].energy + (masdish[i].massiv[j].count / masingredbel[k].count)*masingredbel[k].energy;
					}
				}
				else
					continue; 
			}
		}
	}


	cout << price << endl;

	for (int i = 0; i < countcatalog; i++) 
	{
		cout << mascatalog[i].name << " " <<  mas[i] <<endl; 
	}

	for (int i = 0; i < countdish; i++)
	{
		cout << masdish[i].name << " " << masdish[i].bel << " " << masdish[i].jir << " " << masdish[i].ugl << " " << masdish[i].energy << endl;
	}
	system("pause");
	delete[]mas; 
	delete[]mascatalog; 
	delete[]masdish; 
	delete[]masingredbel; 
    return 0;
}