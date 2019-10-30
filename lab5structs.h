#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <bits/stdc++.h> 
using namespace std;
struct estado
{
	int name;
	bool aceptacion=false;
	bool marcado;
	vector<int> estaditos;
	estado(int n)
	{
		name=n;
		aceptacion=false;
		marcado=false;
	}
	estado(int n,bool a)
	{
		name=n;
		aceptacion=a;
		marcado=false;
	}
};

struct transicion
{
	int ini;
	int fin;
	string val;
	transicion(int i,int f,string cad)
	{
		ini = i;
		fin = f;
		val = cad;
	}
};


class Automata
{
	vector<estado> Estados;
	vector<transicion> Transiciones;
	vector<string> Entradas;
public:
	Automata();
	
	void NuevoEstado(int n);
	void NuevaEntrada(string ent){Entradas.push_back(ent);}
	void NuevaTransici(int ini,int fin, string cad);
	void EstadoAcepta(int n);
	void imprimirEstados();
	void imprimirEstaditos();
	void imprimirTransiciones();
	void imprimirEstadosAcep();
	int NumEstados(){return Estados.size();}
	int NumTransci(){return Transiciones.size();}
	vector<int> E_clausura(vector<int> &v);
	bool EstadoExistente(vector<int> &v)
	{
		for(int i=0;i<Estados.size();i++)
		{
			if(Estados[i].estaditos==v)
			{
				return true;
			}
		}
		return false;
	}
	bool AllEstadosMarc()
	{
		for(int i=0;i<Estados.size();i++)
		{
			if(Estados[i].marcado==false)
			{
				return false;
			}
		}
		return true;
	}
	Automata* ToDeterminist();

};