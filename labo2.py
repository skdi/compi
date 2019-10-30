def Dtransicion(input):
	pos=0
	estado = 1
	simbolo = input[pos]
	while(pos!= len(input)-1):
		if(estado==1):
			if(simbolo.isnumeric()):
				estado=2;
			elif(simbolo.isalpha()):
				estado=3;
			else:
				error()
				return
		elif(estado==2):
			error()
			return
		elif ( estado==3):
			if(simbolo.isalpha()):
				estado=3
			elif(simbolo.isnumeric()):
				estado=3
			else:
				error()
				return
		pos=pos+1
	if(estado!=3):
		error()
		return
	else:
		print("OK")

def error():
	print("GG no funciono")

tabla2=[["1","2","error"],["error","error","error"],["2","2","aceptar"]]
def tablon(input):
	preestado=""
	estado=0
	entrada=0
	pos=0
	
	while(True):
		simbolo=input[pos]
		if(simbolo.isnumeric()):
			entrada=0
		elif(simbolo.isalpha()):
			entrada=1
		else:
			error()
			return
		if(pos==len(input)-1):
			entrada=2
		preestado=tabla2[estado][entrada]

		if(preestado=="error"):
			error()
			return
		elif(preestado=="aceptar"):
			print("OK")
			break
		else:
			pos=pos+1
			estado=int(preestado)

		

def MiDtransicion(input):
	pos=0
	estado = 1
	simbolo = input[pos]
	print("cadena:",input)
	while(pos!= len(input)-1):
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

def tablonArchivo(input):
	tabla=[]
	llenarTabla(tabla)
	condiciones=tabla.pop(0)
	pos=0
	preestado=""
	estado = 1
	print("cadena:",input)
	while(True):
		if(pos<len(input)):
			simbolo=input[pos]
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



#Dtransicion("temp")
#MiDtransicion("-.45")
#tablon("temp")
tablonArchivo("temp5")