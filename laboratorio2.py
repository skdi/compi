#laboratorio2

def automata(cadena):
	estado = 1
	print("cadena:",cadena)
	for simbolo in cadena:
		if(estado == 1):
			if(simbolo.isnumeric()):
				estado = 2
			elif(simbolo.isalpha()):
				estado = 3
			else:
				error()
		elif(estado == 2):
			error()
		elif(estado == 3):
			if(simbolo.isalpha()):
				estado = 3
			elif(simbolo.isnumeric()):
				estado = 3
			else:
				error()
	if(estado != 3):
		error()
	else:
		print("Ok")

def error():
	print("ERROR")

automata("t*")




Tabla = [["1","2","error"],["error","error","error"],["2","2","aceptar"]]

def tablita(cadena):
	estado = 0
	estado_c = ""
	entrada = 0
	i = 0
	print("cadena:",cadena)
	while True:
		simbolo = cadena[i]
		if(i == len(cadena)-1):
			error()
			break
		if(simbolo.isnumeric()):
			entrada = 0
		elif(simbolo.isalpha()):
			entrada = 1
		elif(simbolo is None):
			entrada = 2
		else:
			error()
			break
		estado_c = Tabla[estado][entrada]
		if(estado_c == "error"):
			error()
			break
		elif(estado_c == "aceptar"):
			print("aceptado")
			break
		else:
			estado = int(estado_c)
			i+=1
#tablita("t*")


def ejercicio3(cadena):
	pos=0
	estado = 1
	simbolo = cadena[pos]
	while(pos!= len(cadena)-1):
		if(estado==1):
			if(simbolo=="-"):
				estado=2
			elif(simbolo.isnumeric()):
				estado=2
			elif(simbolo=="."):
				estado=3
			else:
				error()
				return
		elif(estado==2):
			if(simbolo.isnumeric()):
				estado=2
			elif(simbolo=="."):
				estado=3
		elif(estado==3):
			if(simbolo.isnumeric()):
				estado=4
		elif(estado==4):
			if(simbolo.isnumeric()):
				estado=4
		pos=pos+1
	if(estado==2):
		print("OK")
	elif(estado==4):
		print("OK")
	else:
		error()
		return

def llenarTabla(tabla):
	f = open("tabla.txt","r")
	palabra=""
	for linea in f:
		tabla.append([])
		for letra in linea:
			if(letra!=" " and letra!="\n"):
				palabra=palabra+letra

			if(letra==" "):
				tabla[len(tabla)-1].append(palabra)
				palabra=""

			if(letra=="\n"):
				tabla[len(tabla)-1].append(palabra)
				palabra=""
	tabla[len(tabla)-1].append(palabra)


def condicion(condiciones,simbolo):
	Ncondi=0
	for condi in condiciones:
		if(condi=="digito" and simbolo.isnumeric()):

			entrada=Ncondi
			return Ncondi
		
		if(condi=="letra" and simbolo.isalpha() and simbolo!="FDC"):

			entrada=Ncondi
			return Ncondi
		
		if(condi==simbolo):

			entrada=Ncondi
			return Ncondi
		
		if(condi=="FDC" and simbolo=="FDC"):

			entrada=Ncondi
			return Ncondi
		Ncondi=Ncondi+1
		
	return -1

def ejer4(cadena):
	tabla=[]
	llenarTabla(tabla)
	condiciones=tabla.pop(0)
	pos=0
	preestado=""
	estado = 1
	
	while(True):
		if(pos<len(cadena)):
			simbolo=cadena[pos]
		else:
			simbolo="FDC"
		entrada=condicion(condiciones,simbolo)
		
		if(entrada==-1):
			error()
			return
		else:
			preestado=tabla[estado-1][entrada]

		if(preestado=="error"):
			error()
			return
		elif(preestado=="aceptar"):
			print("OK")
			break
		else:
			pos=pos+1
			estado=int(preestado)