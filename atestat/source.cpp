#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>

#define Max 99999999

using namespace std;

ifstream f("date.in");
ifstream h("querry.in");
ofstream g("date.out");

struct drum {
	int dist;
	bool viz;
};

map <string, int> indici;
map <string, int>::iterator it;

vector <int> graf[1000];
vector <drum> viz;

queue <int> c;

string cit, film, act, linie, prim, ult;
int numar_filme, k, id, nr_act, idf, ida, st, fin;

int gaseste_in_graf(string);
void leaga(int, int);
void bfs(int);

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
	
		
	//while(!h.eof())
	//{
		/*
		getline(h, prim, '-');
		getline(h, prim, '-');
		getline(h, ult, '\n');

		st = indici[prim];
		fin = indici[ult];
		bfs(st);

		if (viz[fin].viz)
			g << "Distanta intre actorii" << prim << " si " << ult << " este de " << viz[fin].dist / 2;
		else
			g << "Actorii " << prim << " si " << ult << " nu sunt conectati.";
			*/
	//}

	return 0;
}

int gaseste_in_graf(string nume)
{
	int id = 0;
	it = indici.find(nume);
	if (it == indici.end())
	{
		indici.insert(it, pair<string, int>(nume, ++k));
		id = k;
	}
	else
	{
		id = it->second;
		//g << nume << '\n';
	}
	return id;
}

void leaga(int ida, int idf)
{
	graf[ida].insert(graf[ida].end(), idf);
	graf[idf].insert(graf[idf].end(), ida);
}

void bfs(int start)
{
	int nc;
	viz[start].viz = true;
	viz[start].dist = 0;

	c.push(start);

	while (!c.empty())
	{
		nc = c.front();
		viz[nc].viz = true;
		
		for (int i = 0; i < graf[nc].size(); ++i)
		{
			if (viz[graf[nc][i]].viz == false)
			{
				viz[graf[nc][i]].viz = true;
				viz[graf[nc][i]].dist = viz[nc].dist + 1;
				c.push(graf[nc][i]);
			}
			else
			{
				if (viz[graf[nc][i]].dist > viz[nc].dist + 1)
				{
					viz[graf[nc][i]].dist = viz[nc].dist + 1;
					c.push(graf[nc][i]);
				}
			}
		}

		c.pop();
	}
}