/* DP con manipulación de bits:
	Manipulación de bis:
	31 ...... 1 0
	0 0 0 0 0 0 0

	AND:
	1100 & 1010 = 1000
	OR:
	1100 OR 1010 = 1110
	XOR:
	1100 ^ 1010 = 0110

	REPRESENTAR EN NEGATIVO:
	5 = 0...0101
	PARA NEGATIVO: INVERTIR BITS Y SUMARLE UNO:
	-5 = 0...1010 MÁS 1 = 1...1011

	Corrimiento:
	Las operaciones aritmeticas tienen prioridad.
	5 << 2 = 00...010100
	5 >> 2 = 00...0001

	Cómo saber si un bit esta prendido:
	isSet(n, k) bool(n & (1 << k))
	Cómo prender un bit:
	setBit(n, k) (n || (1<<n))
	clearBit(n, k) (n &negar(1 << k))
	toggleBit(n, k) (n ^ (1 << k))
	lowestBit(n, k) (n & -n)
	2 a la k = (1 << k)
	setFirstk((1 << k) - 1)
	c++: __builtin_popcount(n); // int
	c++: __builtin_popcountll(n); // long long

	Máscaras de bits:
	Entero de 32 bits:
	

*/