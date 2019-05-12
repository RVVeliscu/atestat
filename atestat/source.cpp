#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

map <string, int> indici;
map <string, int>::iterator it;
vector <int> graf[1000];

string cit, film, act;
int numar_filme, k, id, nr_act, idf, ida;

int gaseste_in_graf(string);
void leaga(int, int);

int main()
{
	getline(f, cit, '\n');
	numar_filme = stoi(cit);

	for (int ind = 1; ind <= numar_filme; ++ind)
	{
		getline(f, film, '\n');

		idf = gaseste_in_graf(film);

		getline(f, act, '\n');
		nr_act = stoi(act);

		for (int j = 1; j <= nr_act; j++)
		{
			getline(f, act, '\n');
			ida = gaseste_in_graf(act);
			leaga(ida, idf);
		}

	}
	


	return 0;
}

int gaseste_in_graf(string nume)
{
	int id = 0;
	it = indici.find(nume);
	if (it == indici.end())
	{
		indici.insert(make_pair(nume, ++k));
		id = k;
	}
	else
	{
		id = it->second;
	}
	return id;
}

void leaga(int ida, int idf)
{
	graf[ida].insert(graf->end(), idf);
	graf[idf].insert(graf->end(), ida);
}