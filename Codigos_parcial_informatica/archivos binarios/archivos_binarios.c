#include<stdio.h>
#include<stdint.h>
#include<math.h>

#define archivo "007 0_190517095325.bin"

void obtener_latitud(uint8_t, uint8_t, uint8_t, uint8_t ;

int main()
{
	uint8_t unbyte, id, registro = 0x00;
	uint8_t tus1, tus2, ts1, ts2;
	uint16_t tus, ts;
	double timeStamp;
	int contador = 0;
	
	FILE *ptrBin;
	
	if((ptrBin = fopen(archivo, "rb")) == NULL)
		printf("\nEl archivo no se pudo abrir.\n");
	
	while(!feof(ptrBin))
	{
		fread(&unbyte, 1, 1, ptrBin);
		
		if(contador >= 16)
		{
			contador = 0;
			tus1=tus2=ts1=ts2=0;
			registro = 0x00;
		}
		
		if(unbyte == 0xFC && contador == 0) /*coloco a 1 el bit 0 de registro*/
			registro = 0x01;

		
		if(unbyte == 0x08 && contador == 1) /*coloco el registro en 0b00000011 = 0x03*/
			registro = registro | 0x02;
		
		
		if(registro == 3)
		{
			if(contador == 5)
				id = unbyte;
			
			else if(contador == 6)
				tus1 = unbyte;
			else if(contador == 7)
			{
				tus2 = unbyte;
				
				tus = (tus2<<8) + tus1;
			}
			
			else if(contador == 8)
				ts1 = unbyte;
			else if(contador == 9)
			{
				ts2 = unbyte;
				ts = (ts2<<8)+ts1;
				timeStamp = ts +(float)tus/1000000;
				printf("\nEl timestamp es %f", timeStamp);
			}	
		}
		
		contador++;
				
	}	

	return 0;
}	

void obtener_latitud(uint8_t byteA, uint8_t byteB, uint8_t byte, uint8_t byteD)
{
	int signo, exponente, entero, corrimiento;
	uint32_t aux=(byteD<<24)+(byteC<<16)+(byteB<<8)+byteA;
	uint8_t aux2;
	uint32_t aux3, divisor = 0xFFFFFFFF;
	float decimal, latitud;
	
	if(aux<<31)
		signo = -1;
	else
		signo = 1;
	
	aux2 = aux>>23;
	exponente = aux2-127;
	corrimiento = 23 - exponente;
	aux2 = aux >> corrimiento;
	aux2 = aux2 << (8-esponente);
	aux2 = aux2 >> (8-esponente);
	
	entero = pow(2, exponente) + aux2;
	aux3 = aux << (9 + exponente);
	aux3 = eux3 >> (9 + exponente);
	divisor = divisor << (9 + exponente);
	divisor = divisor << (9 + exponente);
	
	decimal = (float) aux3/divisor;
	
	latitud = signo*(entero+decimal);
	
	printf("\nEl valor de la latitud es %.7f",latitud);


}

























