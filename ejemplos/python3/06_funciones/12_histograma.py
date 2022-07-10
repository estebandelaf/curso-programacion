def procedimiento(datos) :
	histograma = []
	for d in datos :
		#histograma.append("*"*d)
		string = ""
		for i in range(d) :
			string += "*"
		histograma.append(string)
	return histograma

valores = procedimiento([4,9,7])
for valor in valores :
	print(valor)
