#include <stdio.h>

int main()
{
	char estado_motor[10];
	int rpm;
	int temperatura;
	int velocidade;
	int nivel_bateria;
	int nivel_combustivel;
	char estado_farol[10];

	printf("Digite o Estado do Motor\n"
		"(LIGADO ou DESLIGADO): ");
	scanf("%9s", estado_motor);

        printf("Digite o RPM: ");
        scanf("%d", &rpm);

        printf("Digite a Temperatura: ");
        scanf("%d", &temperatura);

        printf("Digite a Velocidade atual: ");
        scanf("%d", &velocidade);

	printf("Digite o nível de Tensão atual da Bateria: ");
	scanf("%d", &nivel_bateria);

	printf("Digite o nível atual de Combustível: ");
	scanf("%d", &nivel_combustivel);

	printf("Digite o estado do farol\n"
		"(LIGADO ou DESLIGADO): ");
	scanf("%9s", estado_farol);

        printf("\n================ ECU ==============\n");
	printf("\nMotor.................... %s\n", estado_motor);
	printf("\nRPM...................... %i\n", rpm);
        printf("\nTemperatura.............. %i °C\n", temperatura);
        printf("\nVelocidade............... %i Km/h\n", velocidade);
	printf("\nTensão da Bateria (V).... %i V\n", nivel_bateria);
	printf("\nNível de Combustível (%%) %i %%\n", nivel_combustivel);
	printf("\nFarol.................... %s\n", estado_farol);
        printf("\n===================================\n\n");

	if (temperatura > 95)
	{
	printf("\nALERTA:"
	"\nTemperatura elevada!"
	"\nVentoinha acionada.\n\n");
	}

	if (nivel_bateria < 12)
	{
	printf("\nALERTA:"
	"\nBateria com tensão baixa.\n\n");
	}

	if (nivel_combustivel < 15)
	{
	printf("\nALERTA:"
	"\nCombustível na reserva.\n\n");
	}

	return 0;
}

