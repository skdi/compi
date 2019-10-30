
#EJERCICIO 1
def leer_consola():
	cadena = input("introducir texto...")
	for i in cadena:
		print (i)



##EJERCICIO 2
def leer_archivo():
	f = open("archivo.txt")
	for linea in f:
		for x in linea:
			print(x)
	f.close()

#leer_consola()
#leer_archivo()


ABC = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZabcdefghijklmnñopqrstuvwxyz1234567890+=*/"


def cesar_cif(key):
	alfabeto_len = len(ABC)
	letra = ""
	cifrado = ""
	f = open("archivo.txt")
	g = open("cifrado.txt","w")
	for palabra in f:
		for i in palabra:
			if(i != "\n" or i !="\t" or i!=" "):
				letra = (ABC.find(i) + key)%alfabeto_len
				cifrado += ABC[letra]
			else:
				g.write(i)
		g.write(cifrado)
		cifrado = ""

def cesar_desc(key):
	alfabeto_len = len(ABC)
	letra = ""
	cifrado = ""
	f = open("cifrado.txt")
	g = open("descifrado.txt","w")
	for palabra in f:
		for i in palabra:
			if(i != "\n" or i !="\t" or i!=" "):
				letra = (ABC.find(i) - key)%alfabeto_len
				cifrado += ABC[letra]
		g.write(cifrado)
		cifrado = ""



cesar_cif(3)
cesar_desc(3)

def ejer4():
	f = open("prueba.txt")
	palabra = ""
	for linea in f:
		for i in linea:
			if(i== " " or i == "\n" or i == "\t"):
				if(palabra.isalnum()):
					print(palabra,"-palabra")
				elif(palabra.isnumeric()):
					print(palabra,"-palabra")
				else:
					print(palabra,"-caracter especial")
				palabra = ""
			else:
				palabra += i

	f.close()
	
ejer4()

