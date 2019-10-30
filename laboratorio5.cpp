#include "lab5.h"

Automata::Automata()
{

}
void Automata::NuevoEstado(int n)
{
	estado nuevo(n);
	this->Estados.push_back(nuevo);
}

void Automata::NuevaTransici(int ini,int fin, string cad)
{
	Transiciones.push_back(transicion(ini,fin,cad));
}
void Automata::Estados_aceptacion(int n)
{
	for(int i=0;i<Estados.size();i++)
	{
		if(Estados[i].name==n)
		{
			this->Estados[i].aceptacion=true;
		}
	}
}
void Automata::imprimirEstados()
{
	for(int i=0;i<Estados.size();i++)
	{
		cout<<Estados[i].name<<" "<<Estados[i].aceptacion<<endl;
	}
}
void Automata::imprimir_subestados()
{
	cout<<"Estados"<<endl;
	for(int i=0;i<Estados.size();i++)
	{
		cout<<Estados[i].name<<"={ ";
		for(int j=0;j<Estados[i].sub_estados.size();j++)
		{
			cout<<Estados[i].sub_estados[j]<<" ";
		}
		cout<<"}"<<endl;
	}

}
void Automata::imprimirTransiciones()
{
	cout<<"Transiciones de Estados (inicio entrada fin)"<<endl;
	for(int i=0;i<Transiciones.size();i++)
	{
		cout<<Transiciones[i].ini<<" "<<Transiciones[i].val<<" "<<Transiciones[i].fin<<endl;
	}
}
void Automata::imprimirEstadosAcep()
{
	cout<<"Estados de Aceptacion"<<endl;
	for(int i=0;i<Estados.size();i++)
	{
		if(Estados[i].aceptacion)
		{
			cout<<Estados[i].name<<" ";
		}
	}
	cout<<endl;
}
vector<int> Automata::E_clausura(vector<int> &v)
{
	stack<int> mipila;
	vector<int> result;
	for(int i=0;i<v.size();i++)
	{
		mipila.push(v[i]);
	}

	while(!mipila.empty())
	{
		int act;
		act=mipila.top();
		mipila.pop();
		result.push_back(act);
		for(int i=0;i<NumTransci();i++)
		{
			if(Transiciones[i].ini==act && Transiciones[i].val=="-1")
			{
				mipila.push(Transiciones[i].fin);
			}
		}
	}
	sort(result.begin(),result.end());
	return result;
}


void Inicializar(Automata *A)
{
	char cadena[128];
	string num="";
	ifstream archivo("entrada.txt");
	while(!archivo.eof())
	{

		archivo.getline(cadena,128);
		string aux(cadena);
		if(aux=="Estados")
		{
			archivo.getline(cadena,128);
			int n=atoi(cadena);

			archivo.getline(cadena,128);
			string lin(cadena);

			for(int i=0;i<lin.length();i++)
			{	
				if(lin[i]==' ' || lin[i]=='\n')
				{
					A->NuevoEstado(stoi(num));
					num="";
				}
				else
				{
					num+=lin[i];
				}
			}
			A->NuevoEstado(stoi(num));
			num="";
			if(n!=A->NumEstados())
			{
				cout<<"Error en cantidad de estados"<<endl;
			}
		}
		if(aux=="Estados_de_Aceptacion")
		{
			archivo.getline(cadena,128);
			int n=atoi(cadena);

			archivo.getline(cadena,128);
			string lin(cadena);
			int count=0;
			for(int i=0;i<lin.length();i++)
			{	
				if(lin[i]==' ' || lin[i]=='\n')
				{
					A->Estados_aceptacion(stoi(num));
					num="";
					count++;
				}
				else
				{
					num+=lin[i];
				}
			}
			A->Estados_aceptacion(stoi(num));
			num="";
			count++;
			if(n!=count)
			{
				cout<<"Error en cantidad de estados de aceptacion"<<endl;
			}
		}
		if(aux=="Transiciones_(x,y,z)_epsilon=-1")
		{
			archivo.getline(cadena,128);
			int n=atoi(cadena);

			int est1,est2,paso=1;
			string val;
			for(int i=0;i<n;i++)
			{
				archivo.getline(cadena,128);
				string lin(cadena);

				for(int i=0;i<lin.length();i++)
				{	
					if(lin[i]==' ' && paso==1)
					{
						est1=stoi(num);
						num="";
						paso++;
					}
					else if(lin[i]==' ' && paso==2)
					{
						val=num;
						num="";
						paso++;
					}
					else
					{
						num+=lin[i];
					}
				}
				est2=stoi(num);
				paso=1;
				A->NuevaTransici(est1,est2,val);
				num="";
			}

			if(n!=A->NumTransci())
			{
				cout<<"Error en cantidad de transiciones"<<endl;
			}
		}
		if(aux=="Entradas")
		{
			archivo.getline(cadena,128);
			int n=atoi(cadena);

			archivo.getline(cadena,128);
			string lin(cadena);
			int count=0;
			for(int i=0;i<lin.length();i++)
			{	
				if(lin[i]==' ' || lin[i]=='\n')
				{
					A->NuevaEntrada(num);
					num="";
					count++;
				}
				else
				{
					num+=lin[i];
				}
			}
			A->NuevaEntrada(num);
			num="";
			count++;
			if(n!=count)
			{
				cout<<"Error en cantidad de entradas"<<endl;
			}
		}
	}
	archivo.close();
}

Automata* Automata::AFD()
{
	Automata* Determinista=new Automata();
	Determinista->NuevoEstado(0);
	int estadoAct=0,nomEstado=1;
	vector<int> Aux,Aux2;
	Aux.push_back(this->Estados[0].name);
	Determinista->Estados[estadoAct].sub_estados=E_clausura(Aux);
	Aux.clear();
	while(!Determinista->Estados_marcados())
	{
		for(int i=0;i<Entradas.size();i++)
		{	
			for(int k=0;k<Determinista->Estados[estadoAct].sub_estados.size();k++)
			{
				for(int j=0;j<Transiciones.size();j++)
				{
					if(Transiciones[j].ini==Determinista->Estados[estadoAct].sub_estados[k] && Transiciones[j].val==Entradas[i])
					{
						Aux.push_back(Transiciones[j].fin);
					}
				}
			}
			Aux2=E_clausura(Aux);
			if(!Determinista->EstadoExistente(Aux2))
			{
				Determinista->NuevoEstado(nomEstado);
				Determinista->Estados[nomEstado].sub_estados=Aux2;
				Determinista->NuevaTransici(estadoAct,nomEstado,Entradas[i]);
				for(int l=0;l<Estados.size();l++)
				{
					for(int ll=0;ll<Aux2.size();ll++)
					{
						if(Estados[l].name==Aux2[ll] && Estados[l].aceptacion==true)
							Determinista->Estados[nomEstado].aceptacion=true;
					}
				}
				nomEstado++;
			}
			else
			{
				for(int l=0;l<Determinista->Estados.size();l++)
				{
					if(Aux2==Determinista->Estados[l].sub_estados)
						Determinista->NuevaTransici(estadoAct,Determinista->Estados[l].name,Entradas[i]);
				}
			}
			Aux.clear();
		}
		Determinista->Estados[estadoAct].marcado=true;
		estadoAct++;
	}

	return Determinista;
}




int main(int argc, char const *argv[])
{
	Automata* AFND=new Automata();	
	Inicializar(AFND);
	//AFND->imprimirEstados();
	//AFND->imprimirTransiciones();
	//AFND->AFD();
	
	Automata* Determinista=AFND->AFD();
	//Determinista->imprimirEstados();
	Determinista->imprimir_subestados();
	Determinista->imprimirEstadosAcep();
	Determinista->imprimirTransiciones();

	return 0;
}