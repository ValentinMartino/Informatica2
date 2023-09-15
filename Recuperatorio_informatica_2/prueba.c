#include <stdio.h>
#include <stdint.h>		
	
int main()
{		
	unsigned char inicio, chofer;
	uint8_t alarma;
	uint16_t interno;
	uint8_t byteA, byteB, byteC, byteD;
	uint8_t A, B, C, D;
	FILE *fd;
	
	fd = fopen("archivo.bin", "wb");	
		
	
		inicio = 0xFE; 
		interno = 222; 
		byteA = 2;
		byteB = 3;
		byteC = 4; 
		byteD = 5;
		A = 127;
		B = 255;
		C = 255;
		D = 247;
		chofer = 1;
		alarma = 1;
		
		//inicio
		fwrite(&inicio,1,1,fd);
		
		//interno
		fwrite(&interno,2,1,fd);

		//latitud
		fwrite(&byteA,1,1,fd);
		fwrite(&byteB,1,1,fd);
		fwrite(&byteC,1,1,fd);
		fwrite(&byteD,1,1,fd);
		
		//longitud
		fwrite(&byteA,1,1,fd);
		fwrite(&byteB,1,1,fd);
		fwrite(&byteC,1,1,fd);
		fwrite(&byteD,1,1,fd);
		
		//hora
		fwrite(&A,1,1,fd);
		fwrite(&B,1,1,fd);
		fwrite(&C,1,1,fd);
		fwrite(&D,1,1,fd);
		
		//alarma
		fwrite(&alarma,1,1,fd);
		
		//chofer
		fwrite(&chofer,1,1,fd);
		
				
return 0;		
}		
