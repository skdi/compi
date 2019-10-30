#include <stdio.h>
#include <iostream>
using namespace std;
//#include <conio.h>
//////////////////////////////
int preanalisis;
void parea(int);
void A();
void B();
void error();
//////////////////////////////
//EJER2
void resto();
void term();

//////////////////////////////

void S(){
	if(preanalisis == 'x'){
		parea('x');
		S();
	}else if(preanalisis == 'a'){
		A();
		B();
		parea('c');
	}else{
		error();
	}
}


void A(){
	if(preanalisis=='a'){
		parea('a');
	}else{
		error();
	}
}

void B(){
	if(preanalisis=='b'){
		parea('b');
	}else{
		error();
}
}

void error(){
	cout<<("ERROR :C");
}

void parea(int t){
	if(preanalisis==t){
		preanalisis=getchar();
	}else{
		error();
	}
}

//main ejer1

int main(){
	preanalisis=getchar();
	S();
}


///////////////////////////
void exp(){
	term();
	resto();
}

void resto(){
	if(preanalisis == '+'){
		parea('+');
		term();
		cout<<('+');
		resto();
	}
	else if(preanalisis == '-'){
		parea('-');
		term();
		cout<<('-');
		resto();
	}else if(preanalisis == ' '){
		cout<<(' ');
	}
	else{
		//error();
		return;
	}
}

void term(){
	switch(preanalisis){
		case '0':
			cout<<('0');
			parea('0');
			return;
		case '1':
			cout<<('1');
			parea('1');
			return;
		case '2':
			cout<<('2');
			parea('2');
			return;
		case '3':
			cout<<('3');
			parea('3');
			return;
		case '4':
			cout<<('4');
			parea('4');
			return;
		case '5':
			cout<<('5');
			parea('5');
			return;
		case '6':
			cout<<('6');
			parea('6');
			return;
		case '7':
			cout<<('7');
			parea('7');
			return;
		case '8':
			cout<<('8');
			parea('8');
			return;
		case '9':
			cout<<('9');
			parea('9');
			return;

	}


}
/*

//main ejer2
int main(){
	preanalisis = getchar();
	exp();
}*/