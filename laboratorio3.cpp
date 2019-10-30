#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
int preanalisis;

void parea(int);
void A();
void B();
void error();
void S();

void exp();
void resto();
void term();


int main(int argc, char const *argv[])
{
	preanalisis=getchar();
	//S();
	exp();
	return 0;
}

void S()
{
	if(preanalisis=='x')
	{
		parea('x');
		S();
	}
	else if(preanalisis =='a' )
	{
		A();
		B();
		parea('c');
	}
	else
		error();
}
void A()
{
	if(preanalisis=='a')
		parea('a');
	else
		error();
}
void B()
{
	if(preanalisis == 'b')
		parea('b');
	else
		error();
}
void error()
{
	cout<<"Error de sintaxis";
}
void parea(int t)
{
	if(preanalisis==t)
		preanalisis=getchar();
	else 
		error();
}

void exp()
{
	term();
	resto();
}

void resto()
{
	if(preanalisis=='+')
	{
		parea('+');
		term();
		cout<<"+";
		resto();
	}
	else if(preanalisis=='-')
	{
		parea('-');
		term();
		cout<<"-";
		resto();
	}
	else
		return;
}
void term()
{
	if(preanalisis=='0')
	{
		cout<<"0";
		parea('0');
		return;
	}
	else if(preanalisis=='1')
	{
		cout<<"1";
		parea('1');
		return;
	}
	else if(preanalisis=='2')
	{
		cout<<"2";
		parea('2');
		return;
	}
	else if(preanalisis=='3')
	{
		cout<<"3";
		parea('3');
		return;
	}
	else if(preanalisis=='4')
	{
		cout<<"4";
		parea('4');
		return;
	}
	else if(preanalisis=='5')
	{
		cout<<"5";
		parea('5');
		return;
	}
	else if(preanalisis=='6')
	{
		cout<<"6";
		parea('6');
		return;
	}
	else if(preanalisis=='7')
	{
		cout<<"7";
		parea('7');
		return;
	}
	else if(preanalisis=='8')
	{
		cout<<"8";
		parea('8');
		return;
	}
	else if(preanalisis=='9')
	{
		cout<<"9";
		parea('9');
		return;
	}
	else 
	{
		error();
	}
}