#include <stdio.h>
#include <string.h>

int main(void)
{
	char estado_motor[2];
	int rpm;
	int temperatura;
	int velocidade;
	int nivel_bateria;
	int nivel_combustivel;
	char estado_farol[2];
	char status_ecu[20] = "NORMAL";

	printf("O Motor está ligado? (S ou N): ");
	scanf("%1s", estado_motor);

        printf("Digite o RPM (0-7000): ");
        scanf("%d", &rpm);

        printf("Digite a Temperatura (0-120°C): ");
        scanf("%d", &temperatura);

        printf("Digite a Velocidade atual (0-170Km/h): ");
        scanf("%d", &velocidade);

	printf("Digite o nível de Tensão atual da Bateria (0-14V): ");
	scanf("%d", &nivel_bateria);

	printf("Digite o nível atual de Combustível (0-100%%): ");
	scanf("%d", &nivel_combustivel);

	printf("O farol está aceso? (S ou N): ");
	scanf("%1s", estado_farol);

        printf("\n================ ECU ==============\n");

	if (strcmp(estado_motor, "s") == 0 || strcmp(estado_motor, "S") == 0)
	{
		printf("..... MOTOR EM FUNCIONAMENTO .....\n\n");
	}
	else if (strcmp(estado_motor, "n") == 0 || strcmp(estado_motor, "N") == 0)
	{
		printf("........ MOTOR DESLIGADO .........\n\n");
	}
	else
	{
		strcpy(status_ecu, "CRITICO");
		printf("... ESTADO DO MOTOR DESCONHECIDO ...\n\n");
	}

	printf("RPM...................... %i\n\n", rpm);
	if (rpm < 0 || rpm > 7000)
	{
		strcpy(status_ecu, "CRITICO");
		printf(".. VALOR DE RPM DO MOTOR INVALIDO ..\n\n");
	}
	else if (rpm > 6000)
	{
		if (strcmp(status_ecu, "CRITICO") != 0)
		{
			strcpy(status_ecu, "ALERTA");
		}
		printf("RPM PRÓXIMO AO PONTO DE CORTE\n\n");
	}

	printf("Temperatura.............. %i °C\n", temperatura);
	if (temperatura < 0 || temperatura > 120)
        {
		strcpy(status_ecu, "CRITICO");
		printf(". VALOR DA TEMPERATURA INVÁLIDO .\n\n");
        }
        else if (temperatura >= 110)
	{
		strcpy(status_ecu, "CRITICO");
                printf("...... SUPERAQUECIMENTO!! ......\n\n");
                printf("Ventoinha............... LIGADA\n\n");
	}
        else if (temperatura >= 95)
	{
		if (strcmp(status_ecu, "CRITICO") != 0)
		{
			strcpy(status_ecu, "ALERTA");
		}
		printf("..... Temperatura elevada! .....\n");
		printf("Ventoinha............... LIGADA\n\n");
        }
	else
	{
                printf("Ventoinha............ DESLIGADA\n\n");
	}

	printf("Velocidade............... %i Km/h\n\n", velocidade);
	if (velocidade < 0 || velocidade > 170)
	{
		strcpy(status_ecu, "CRITICO");
		printf("..... VELOCIDADE DESCONHECIDA .....\n\n");
	}

	printf("Tensão da Bateria........ %i V\n", nivel_bateria);
	if (nivel_bateria < 0 || nivel_bateria > 14)
        {
		strcpy(status_ecu, "CRITICO");
		printf("..... VALOR DE TENSÃO INCORRETO .....\n\n");
        }
	else if (nivel_bateria < 12)
	{
		if (strcmp(status_ecu, "CRITICO") != 0)
		{
			strcpy(status_ecu, "ALERTA");
		}
		printf("... Tensão da Bateria baixa! ...\n\n");
        }
	else
	{
		printf("... Nível de Tensão da Bateria OK ...\n\n");
	}

	printf("Nível de Combustível..... %i %%\n", nivel_combustivel);
        if (nivel_combustivel < 0 || nivel_combustivel > 100)
        {
		strcpy(status_ecu, "CRITICO");
                printf("... NÍVEL DE COMBUSTIVEL INCORRETO ...\n\n");
        }
        else if (nivel_combustivel <= 15)
	{
		if (strcmp(status_ecu, "CRITICO") != 0)
		{
			strcpy(status_ecu, "ALERTA");
		}
                printf("..... Combustível na reserva .....\n\n");
        }
	else
	{
		printf("... Nível de Combustível OK ...\n\n");
	}

	if (strcmp(estado_farol, "n") == 0 || strcmp(estado_farol, "N") == 0)
        {
		printf("Farol................. DESLIGADO\n\n");
	}
	else if (strcmp(estado_farol, "s") == 0 || strcmp(estado_farol, "S") == 0)
	{
		printf("Farol.................... LIGADO\n\n");
        }
	else
	{
		strcpy(status_ecu, "CRITICO");
		printf("... ESTADO DO FAROL DESCONHECIDO ...\n\n");
	}

        printf("Status da ECU ............ %s\n", status_ecu);

        printf("===================================\n\n");

	return 0;
}
