#include <stdio.h>

int main(void)
{
    int opcao;
    int rpm = 850;
    int temperatura = 85;
    int velocidade = 0;
    int nivel_bateria = 14;
    int nivel_combustivel = 50;
    int atualizacoes = 0;

    do
    {
        printf("\n========== ECU VIRTUAL ==========\n\n");
        printf("1 - Exibir painel\n");
        printf("2 - Alterar RPM\n");
        printf("3 - Alterar temperatura\n");
        printf("4 - Alterar velocidade\n");
        printf("5 - Alterar tensão da bateria\n");
        printf("6 - Alterar nível de combustível\n");
	printf("7 - Exibir quantidade de atualizações\n");
	printf("8 - Simular aceleração\n");
	printf("9 - Simular aquecimento\n");
        printf("0 - Encerrar\n\n");
	printf("=================================\n\n");
	printf("  Escolha uma opção: ");
	scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("\n========== PAINEL ==========\n");
                printf("RPM.................. %d\n", rpm);
		if (rpm < 0 || rpm > 7999)
		{
		    printf("Aviso: Medição do RPM Incorreta\n");
		}
		else if (rpm > 6000)
		{
		    printf("Aviso: RPM próximo ao corte\n");
		}

                printf("Temperatura.......... %d °C\n", temperatura);
		if (temperatura < 0 || temperatura > 120)
		{
		    printf("Aviso: Medição da Temperatura Incorreta\n");
		}
		else if (temperatura >= 110)
		{
		    printf("Status térmico...... CRÍTICO\n"
			   "Ventoinha .......... Ligada\n");
		}
		else if (temperatura >= 95)
		{
		    printf("Status térmico...... ALERTA\n"
			   "Ventoinha .......... Ligada\n");
		}
		else
		{
		    printf("Status térmico...... NORMAL\n"
			   "Ventoinha ........ Desigada\n");
		}

                printf("Velocidade........... %d km/h\n", velocidade);
		if (velocidade < 0 || velocidade > 170)
	        {
		    printf("Aviso: Medição da Velocidade Incorreta\n");
	        }

                printf("Bateria.............. %d V\n", nivel_bateria);
	        if (nivel_bateria < 0 || nivel_bateria > 14)
	        {
		    printf("Aviso: Medição da Tensão da Bateria Incorreta\n");
	        }
	        else if (nivel_bateria < 12)
	        {
		    printf("Aviso: Tensão da Bateria baixa\n");
	        }

                printf("Combustível.......... %d %%\n", nivel_combustivel);
		if (nivel_combustivel < 0 || nivel_combustivel > 100)
	        {
		    printf("Aviso: Medição do Combustível Incorreta\n");
	        }
        	else if (nivel_combustivel <= 15)
	        {
		    printf("Aviso: Combustível na reserva\n");
		}

		printf("============================\n");
                break;

            case 2:
                printf("Digite o novo RPM: ");
                scanf("%d", &rpm);
		atualizacoes++;
                break;

            case 3:
                printf("Digite a nova temperatura: ");
                scanf("%d", &temperatura);
		atualizacoes++;
                break;

            case 4:
                printf("Digite a nova velocidade: ");
                scanf("%d", &velocidade);
		atualizacoes++;
                break;

            case 5:
                printf("Digite a nova tensão da bateria: ");
                scanf("%d", &nivel_bateria);
		atualizacoes++;
                break;

            case 6:
                printf("Digite o novo nível de combustível: ");
                scanf("%d", &nivel_combustivel);
		atualizacoes++;
                break;

	    case 7:
		printf("\nQuantidade de atualizações: %d\n", atualizacoes);
	        break;

	    case 8:
	        printf("\n===== SIMULAÇÃO DE ACELERAÇÃO =====\n");

	        for (rpm = 1000; rpm <= 5000; rpm += 500)
	        {
	            printf("RPM: %d\n", rpm);
		}

		rpm = 850;
		atualizacoes++;

		printf("Retorno à marcha lenta: %d RPM\n", rpm);
		break;

	    case 9:
		printf("\n===== SIMULAÇÃO DE AQUECIMENTO =====\n");

		temperatura = 70;

		while (temperatura < 100)
		{
		    printf("Temperatura: %d °C\n", temperatura);
		    temperatura += 5;
		}

		printf("Temperatura: %d °C\n", temperatura);
		printf("Temperatura elevada. Ventoinha acionada.\n");

		atualizacoes++;
		break;

            case 0:
                printf("\nEncerrando a ECU virtual...\n");
                break;

            default:
                printf("\nOpção inválida.\n");
                break;

	}

    } while (opcao != 0);

    return 0;

}
