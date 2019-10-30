#include <stdio.h>
//#include <conio.h>
//#include <ctype>
#include<string.h>
//#define MAS '+'
//#define MENOS '-'
//#define NUM 256
//#define FIN -1
#define MAYOR '>'
#define PUNTOYCOMA ';'
#define PARI '('
#define ID 256
#define NUM 257
#define MAYORIGUAL 258
#define WHILE 259
#define IF 260

int scanner();
void mostrar(int);
int espaires();

FILE *f;
char lexema[80];

void main(int n,char *pal[]){
	int token;
	f=stdin; //entrada por teclado
	if(n==2){//especifico archivo de lectura
		f=fopen(pal[1],"rt")//lectura modo texto
		if(f=NULL)
			f=stdin;
	}
	if(f==stdin) //lectura por consola
		printf("Ingrese texto ..... termine con Ctrl z >:v \n");
	while(1){
		token=scanner();
		if(token==EOF) break;
		mostrar(token);
	}
	if(f!=stdin) //si la entrada fue de un archivo
		fclose(f); //cerrar archivo
}//fin del main

int scanner(){
	 int c;
	 int i;
	 do c=fgetc(f);while(isspace()); //ignora blancos
	 if(c==EOF) return EOF;
	 if(isalpha(c))//regla del id
	 {
	 	i=0;
	 	do{
	 		lexema[i++]=c;
	 		c=fgetc(f);
	 	}while(isalnum(c) || c=='_');
	 
	 lexema[i]=0;
	 ungetc(c,f); //se devulve c al flujo de entrada
	 i=espaires(); //verifica si es palabra reservada //WHILE, IF

	 if(i>=0)
	 	return i;
	 return ID; //se trata de un ID
	}
	if(isdigit(c))//regla del NUM
	{
		i=0;
		do{
			lexema[i++]=c;
			c=fgetc(f);
		}while(isdigit(c));
		lexema[i]=0;
		ungetc(c,f);
		return NUM;
	}
	//regla del punto y coma y pari
	if(c==';' || c=='(') return c;

	if(c=='>')//regla de ">" o ">="
	{
		c=fgetc(f);
		if(c== '=')//return mayorigual
		{
			lexema[0]='>'; lexema[1]='=';lexema[2]=0;
			return MAYORIGUAL;
		}
		ungetc(c,f);
		return MAYOR; //return MAYOR
	}
}// fin scanner


int espaires(){
	if(strcmp(lexema,'while')==0) return WHILE;
	if(strcmp(lexema,'if')==0) return IF;
	return -1;
}

void mostrar(int token){
	switch(token){
		case ID: printf("token=ID[%s]\n",lexema); break;
		case NUM: printf("token=NUM[%s]\n",lexema); break;
		case MAYORIGUAL: printf("token= MAYORIGUAL[%s] \n",lexema); break;
		case WHILE: printf("token=WHILE[%s]\n",lexema); break;
		case IF: printf("token=IF[%s]\n",lexema); break;
		case PARI: printf("token=PARI[%c]\n",token); break;
		case MAYOR: printf("token=MAYOR[%c]\n",token); break;
		case PUNTOYCOMA: printf("token=PUNTOYCOMA[%c]\n",token); break;
	}



}