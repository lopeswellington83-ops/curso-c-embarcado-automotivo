#include <stdio.h>

int main()
{

	char estado_motor[] = "LIGADO";
	int rpm = 850;
	int temp = 22;
	int velocidade = 0;

        printf("\n======= ECU =======\n");
	printf("\nMotor..........%s\n", estado_motor);
	printf("\nRPM............%i\n", rpm);
        printf("\nTemperatura....%i\n", temp);
        printf("\nVelocidade.....%i\n", velocidade);
        printf("\n===================\n\n");

	return 0;
}

