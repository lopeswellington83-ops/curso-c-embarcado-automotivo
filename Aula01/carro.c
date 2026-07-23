#include <stdio.h>

int main()
{
	char marca[] = "Volkswagen";
	char modelo[] = "Gol G5";
	int ano = 2011;
	char motor[] = "1.0 8v";
	char fuel[] = "Flex";
	int potencia = 76;

	printf("\nMarca: %s\n\n", marca);
	printf("Modelo: %s\n\n", modelo);
        printf("Ano: %i\n\n", ano);
        printf("Motor: %s\n\n", motor);
        printf("Combustível: %s\n\n", fuel);
        printf("Potência: %i\n\n", potencia);

	return 0;
}
