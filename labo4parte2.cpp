/*#include <stdio.h>
#include <conio.h>

#include <string>
#include <cstring>


#define MAYOR '>'
#define PUNTOYCOMA ';'
#define PARI '('
#define ID 256
#define NUM 257
#define MAYORIGUAL 258
#define WHILE 259
#define IF 260
#define MAS '+'
#define MENOS '-'
#define FIN -1

FILE *f;
char lexema[80];
int tok;


int palres();
int scanner();
void mostrar(int);



int main(int n,char *pal[]){

	int token;
	f=stdin;
	if(n==1)
	{
		f=fopen(pal[1],"rt");
		if(f==NULL)
		{
			printf("Error al abrir archivo\n");
			f=stdin;
		}
	}
	if(f==stdin)
		printf("Ingrese texto..... termine con Ctrl z\n");
	while(1)
	{
		token=scanner();
		if(token==EOF)break;
		mostrar(token);
	}
	if(f!=stdin)
	{
		fclose(f);
	}
}




int scanner(){
	int c,i;
	do c=getchar(); while(c==' ');
	if(c=='\n')
		return FIN;
	if(c==MAS || c==MENOS)
		return c;

	if(isalpha(c))
	{
		i=0;
		do{
			lexema[i++]=c;
			c=fgetc(f);
		}while(isalnum(c) || c=='_');
		lexema[i]=0;
		ungetc(c,f);
		i=palres();
		if(i>=0)
			return i;
		else
			return ID;
	}


	if(isdigit(c)){
		i=0;
		do{lexema[i++]=c; c=getchar();}
		while(isdigit(c));
		lexema[i]=0;
		ungetc(c,f);
		return NUM;
	}
	if((c==';')||(c=='('))
	{
		lexema[0]=c;//lexema[1]='0';
		return c;
	}
	if(c=='>')
	{
		c=fgetc(f);
		if(c=='=')
		{
			lexema[0]='>';lexema[1]='=';//lexema[2]='0';
			return MAYORIGUAL;
		}
		ungetc(c,f);
		lexema[0]='>';
		return MAYOR;
	}
}

int palres()
{
	if(strcmp(lexema,"while")==0) return WHILE;
	if(strcmp(lexema,"if")==0) return IF;
	return -1;
}
void limpiarArray(char arr[],int n=80)
{
	for(int i=0;i<n;i++)
	{
		arr[i]=0;
	}
}
void mostrar(int token)
{
	switch(token)
	{
		case ID:printf("token=ID[%s]\n",lexema );limpiarArray(lexema);break;
		case NUM:printf("token=NUM[%s]\n",lexema);limpiarArray(lexema);break;
		case MAYORIGUAL:printf("token=MAYORIGUAL[%s]\n",lexema );limpiarArray(lexema);break;
		case WHILE:printf("token=WHILE[%s]\n",lexema );limpiarArray(lexema);break;
		case IF:printf("token=IF[%s]\n",lexema );limpiarArray(lexema);break;
		case PARI:printf("token=PARI[%s]\n",lexema );limpiarArray(lexema);break;
		case MAYOR:printf("token=MAYOR[%s]\n",lexema );limpiarArray(lexema);break;
		case PUNTOYCOMA:printf("token=PUNTOYCOMA[%s]\n",lexema );limpiarArray(lexema);break;
	}
}
*/
#include <stdio.h>
#include <conio.h>

#include <string>
#include <cstring>


#define MAYOR '>'
#define MAYORIGUAL 258
#define MENOR '<'
#define MENORIGUAL 261
#define IGUAL '='
#define DOBIGUAL 262
#define DIFERENT 263

#define PUNTOYCOMA ';'
#define COMA ','

#define PARI '('
#define PARD ')'
#define LLAVI '{'
#define LLAVD '}'
#define CORI '['
#define CORD ']'


#define ID 256
#define NUM 257

#define WHILE 259
#define IF 260
#define ELSE 264
#define DO 265
#define SWITCH 266
#define FOR 267

#define FIN -1

#define MAS '+'
#define MENOS '-'
#define MULT '*'
#define DIV '/'


FILE *f;
char lexema[80];
int tok;


int palres();
int scanner();
void mostrar(int);



int main(int n,char *pal[]){

	int token;
	f=stdin;
	if(n==2)
	{
		f=fopen(pal[1],"rt");
		if(f==NULL)
		{
			printf("Error al abrir archivo\n");
			f=stdin;
		}
		else
		{
			printf("Se abrio correctamente\n");
		}
	}
	if(f==stdin)
		printf("Ingrese texto..... termine con Ctrl z\n");
	while(1)
	{

		token=scanner();
		if(feof(f))break;
		mostrar(token);
	}
	if(f!=stdin)
	{
		fclose(f);
	}

	return 0;
}




int scanner(){
	int c,i,c2;
	do c=fgetc(f); while(c==' ');
	if(c=='\n')
		return FIN;
	if(c==MAS || c==MENOS)
		return c;

	if(isalpha(c))
	{
		i=0;
		do{
			lexema[i++]=c;
			c=fgetc(f);
		}while(isalnum(c) || c=='_');
		lexema[i]=0;
		ungetc(c,f);
		i=palres();
		if(i>=0)
			return i;
		else
			return ID;
	}


	if(isdigit(c)){
		i=0;
		do{lexema[i++]=c; c=fgetc(f);}
		while(isdigit(c));
		lexema[i]=0;
		ungetc(c,f);
		return NUM;
	}
	if(c=='/')
	{
		c=fgetc(f);
		if(c=='/')
		{
			do{c=fgetc(f);}while(c!='\n');
			return -1;

		}
		else if(c=='*')
		{
			while(1)
			{
				c=fgetc(f);
				if(c=='*')
				{
					c=fgetc(f);
					if(c=='/')
						break;
				}
			}
			c=fgetc(f);
			return -1;
		}
		else
			return c;
	}
	if((c==';')||(c==',')||(c=='(')||(c==')')||(c=='{')||(c=='}')||(c=='[')||(c==']'))
	{
		lexema[0]=c;//lexema[1]='0';
		return c;
	}
	if((c=='+')||(c=='-')||(c=='*'))
	{
		//lexema[0]=c;//lexema[1]='0';
		return c;
	}
	if(c=='>')
	{
		c=fgetc(f);
		if(c=='=')
		{
			lexema[0]='>';lexema[1]='=';//lexema[2]='0';
			return MAYORIGUAL;
		}
		ungetc(c,f);
		lexema[0]='>';
		return MAYOR;
	}
	if(c=='<')
	{
		c=fgetc(f);
		if(c=='=')
		{
			lexema[0]='<';lexema[1]='=';//lexema[2]='0';
			return MENORIGUAL;
		}
		ungetc(c,f);
		lexema[0]='>';
		return MENOR;
	}
	if(c=='=')
	{
		c=fgetc(f);
		if(c=='=')
		{
			lexema[0]='=';lexema[1]='=';//lexema[2]='0';
			return DOBIGUAL;
		}
		ungetc(c,f);
		lexema[0]='=';
		return IGUAL;
	}
	if(c=='!')
	{
		c=fgetc(f);
		if(c=='=')
		{
			lexema[0]='!';lexema[1]='=';//lexema[2]='0';
			return DIFERENT;
		}
		ungetc(c,f);
		
	}
}

int palres()
{
	if(strcmp(lexema,"while")==0) return WHILE;
	if(strcmp(lexema,"if")==0) return IF;
	if(strcmp(lexema,"for")==0) return FOR;
	if(strcmp(lexema,"switch")==0) return SWITCH;
	if(strcmp(lexema,"else")==0) return ELSE;
	if(strcmp(lexema,"do")==0) return DO;
	return -1;
}
void limpiarArray(char arr[],int n=80)
{
	for(int i=0;i<n;i++)
	{
		arr[i]=0;
	}
}
void mostrar(int token)
{
	switch(token)
	{
		case ID:printf("token=ID[%s]\n",lexema );limpiarArray(lexema);break;
		case NUM:printf("token=NUM[%s]\n",lexema);limpiarArray(lexema);break;
		case MAYOR:printf("token=MAYOR[%s]\n",lexema );limpiarArray(lexema);break;
		case MAYORIGUAL:printf("token=MAYORIGUAL[%s]\n",lexema );limpiarArray(lexema);break;
		case MENOR:printf("token=MENOR[%s]\n",lexema );limpiarArray(lexema);break;
		case MENORIGUAL:printf("token=MENORIGUAL[%s]\n",lexema );limpiarArray(lexema);break;
		case IGUAL:printf("token=IGUAL[%s]\n",lexema );limpiarArray(lexema);break;
		case DOBIGUAL:printf("token=DOBIGUAL[%s]\n",lexema );limpiarArray(lexema);break;
		case WHILE:printf("token=WHILE[%s]\n",lexema );limpiarArray(lexema);break;
		case IF:printf("token=IF[%s]\n",lexema );limpiarArray(lexema);break;
		case ELSE:printf("token=ELSE[%s]\n",lexema );limpiarArray(lexema);break;
		case DO:printf("token=DO[%s]\n",lexema );limpiarArray(lexema);break;
		case SWITCH:printf("token=SWITCH[%s]\n",lexema );limpiarArray(lexema);break;
		case FOR:printf("token=FOR[%s]\n",lexema );limpiarArray(lexema);break;
		case PARI:printf("token=PARI[%s]\n",lexema );limpiarArray(lexema);break;
		case PARD:printf("token=PARD[%s]\n",lexema );limpiarArray(lexema);break;
		case LLAVI:printf("token=LLAVI[%s]\n",lexema );limpiarArray(lexema);break;
		case LLAVD:printf("token=LLAVD[%s]\n",lexema );limpiarArray(lexema);break;
		case CORI:printf("token=CORI[%s]\n",lexema );limpiarArray(lexema);break;
		case CORD:printf("token=CORD[%s]\n",lexema );limpiarArray(lexema);break;
		case PUNTOYCOMA:printf("token=PUNTOYCOMA[%s]\n",lexema );limpiarArray(lexema);break;
		case COMA:printf("token=COMA[%s]\n",lexema );limpiarArray(lexema);break;
		case MAS:printf("token=MAS[+]\n");break;
		case MENOS:printf("token=MENOS[-]\n");break;
		case MULT:printf("token=MULT[%s]\n",lexema );limpiarArray(lexema);break;
		case DIV:printf("token=DIV[%s]\n",lexema );limpiarArray(lexema);break;
	}
}