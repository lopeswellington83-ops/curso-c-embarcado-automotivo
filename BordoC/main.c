#include <stdio.h>

/* Estruturas de Dados */

typedef struct
{
    int rpm;
    int temperatura;
    int velocidade;
    int nivel_bateria;
    int nivel_combustivel;
    int posicao_acelerador;
} DadosVeiculo;

/* Prototipos */

void inicializar_veiculo(DadosVeiculo *veiculo);

void exibir_menu(void);

int valor_dentro_da_faixa(
    int valor,
    int minimo,
    int maximo
);

void exibir_painel(const DadosVeiculo *veiculo);

void simular_aceleracao(DadosVeiculo *veiculo);
void simular_aquecimento(DadosVeiculo *veiculo);

int ler_inteiro_na_faixa(
    const char *mensagem,
    int minimo,
    int maximo,
    int *destino
);

/* Funcao principal */

int main(void)
{

    int opcao;
    int atualizacoes = 0;

    DadosVeiculo veiculo;

    inicializar_veiculo(&veiculo);

    do
    {
	exibir_menu();

	if (!ler_inteiro_na_faixa(
	        "  Escolha uma opção: ",
	        0,
	        11,
	        &opcao))
	{
	    printf("\nEntrada encerrada.\n");
	    break;
	}

        switch (opcao)
        {
            case 1:
                exibir_painel(&veiculo);
                break;

	    case 2:
	        if (ler_inteiro_na_faixa(
	            "Digite o novo RPM: ",
	            0,
	            7000,
	            &veiculo.rpm))
	        {
	            atualizacoes++;
		}
		break;

	    case 3:
	        if (ler_inteiro_na_faixa(
	            "Digite a nova temperatura: ",
	            0,
	            120,
	            &veiculo.temperatura))
	        {
	            atualizacoes++;
		}
		break;

	    case 4:
	        if (ler_inteiro_na_faixa(
	            "Digite a nova velocidade: ",
	            0,
	            170,
	            &veiculo.velocidade))
	        {
	            atualizacoes++;
		}
		break;

	    case 5:
	        if (ler_inteiro_na_faixa(
	            "Digite a nova tensão da bateria: ",
	            0,
	            14,
	            &veiculo.nivel_bateria))
	        {
	            atualizacoes++;
		}
		break;

	    case 6:
	        if (ler_inteiro_na_faixa(
	            "Digite o novo nível de combustível: ",
	            0,
		    100,
	            &veiculo.nivel_combustivel))
	        {
	            atualizacoes++;
		}
		break;

            case 7:
                printf("\nQuantidade de atualizações: %d\n", atualizacoes);
                break;

	    case 8:
		simular_aceleracao(&veiculo);
		atualizacoes++;
		break;

            case 9:
                simular_aquecimento(&veiculo);
                atualizacoes++;
                break;

	    case 10:
	        if (ler_inteiro_na_faixa(
	           "Digite a posição do acelerador (0-100%): ",
	            0,
                    100,
	            &veiculo.posicao_acelerador))
	        {
	            atualizacoes++;
		}
		break;

	    case 11:
	        inicializar_veiculo(&veiculo);
		atualizacoes++;
		printf("\nDados do veículo restaurados.\n");
		break;

            case 0:
                printf("\nEncerrando o BordoC...\n");
                break;

            default:
                printf("\nOpção inválida.\n");
		break;

        }

    } while (opcao != 0);

    return 0;
}

void exibir_menu(void)
{
    printf("\n========== BORDOC ==========\n\n");
    printf("1 - Exibir painel\n");
    printf("2 - Alterar RPM\n");
    printf("3 - Alterar temperatura\n");
    printf("4 - Alterar velocidade\n");
    printf("5 - Alterar tensão da bateria\n");
    printf("6 - Alterar nível de combustível\n");
    printf("7 - Exibir quantidade de atualizações\n");
    printf("8 - Simular aceleração\n");
    printf("9 - Simular aquecimento\n");
    printf("10 - Alterar posição do acelerador\n");
    printf("11 - Restaurar dados padrão\n");
    printf("0 - Encerrar\n\n");
    printf("============================\n\n");
}

int valor_dentro_da_faixa(int valor, int minimo, int maximo)
{
    if (valor >= minimo && valor <= maximo)
    {
        return 1;
    }

    return 0;
}

void exibir_painel(const DadosVeiculo *veiculo)
{
    if (veiculo == NULL)
    {
	printf("\nErro: dados do veículo indisponíveis.\n");
	return;
    }

    printf("\n========== PAINEL ==========\n");

    printf("RPM.................. %d\n", veiculo->rpm);
    if (!valor_dentro_da_faixa(veiculo->rpm, 0, 7000))
    {
        printf("Aviso: Medição do RPM Incorreta\n");
    }
    else if (veiculo->rpm > 6000)
    {
        printf("Aviso: RPM próximo ao corte\n");
    }

    printf("Temperatura.......... %d °C\n", veiculo->temperatura);
    if (!valor_dentro_da_faixa(veiculo->temperatura, 0, 120))
    {
        printf("Aviso: Medição da Temperatura Incorreta\n");
    }
    else if (veiculo->temperatura >= 110)
    {
        printf("Status térmico...... CRÍTICO\n"
               "Ventoinha........... LIGADA\n");
    }
    else if (veiculo->temperatura >= 95)
    {
        printf("Status térmico...... ALERTA\n"
               "Ventoinha........... LIGADA\n");
    }
    else
    {
        printf("Status térmico...... NORMAL\n"
               "Ventoinha........... DESLIGADA\n");
    }

    printf("Velocidade........... %d km/h\n", veiculo->velocidade);
    if (!valor_dentro_da_faixa(veiculo->velocidade, 0, 170))
    {
        printf("Aviso: Medição da Velocidade Incorreta\n");
    }

    printf("Bateria.............. %d V\n", veiculo->nivel_bateria);
    if (!valor_dentro_da_faixa(veiculo->nivel_bateria, 0, 14))
    {
        printf("Aviso: Medição da Tensão da Bateria Incorreta\n");
    }
    else if (veiculo->nivel_bateria < 12)
    {
        printf("Aviso: Tensão da Bateria baixa\n");
    }

    printf("Combustível.......... %d %%\n", veiculo->nivel_combustivel);
    if (!valor_dentro_da_faixa(veiculo->nivel_combustivel, 0, 100))
    {
        printf("Aviso: Medição do Combustível Incorreta\n");
    }
    else if (veiculo->nivel_combustivel <= 15)
    {
        printf("Aviso: Combustível na reserva\n");
    }

    printf(
        "Acelerador........... %d %%\n",
        veiculo->posicao_acelerador
    );

    if (!valor_dentro_da_faixa(
            veiculo->posicao_acelerador,
            0,
            100))
    {
        printf("Aviso: posição do acelerador inválida\n");
    }
    printf("============================\n");
}

void simular_aceleracao(DadosVeiculo *veiculo)
{
    if (veiculo == NULL)
    {
	return;
    }

    printf("\n===== SIMULAÇÃO DE ACELERAÇÃO =====\n");

    for (veiculo->rpm = 1000;
	 veiculo->rpm <= 5000;
	 veiculo->rpm += 500)
    {
	printf("RPM: %d\n", veiculo->rpm);
    }

    veiculo->rpm = 850;

    printf(
	"Retorno à marcha lenta: %d RPM\n",
	veiculo->rpm);
}

void simular_aquecimento(DadosVeiculo *veiculo)
{
    if (veiculo == NULL)
    {
	return;
    }

    printf("\n===== SIMULAÇÃO DE AQUECIMENTO =====\n");

    veiculo->temperatura = 70;

    while (veiculo->temperatura < 100)
    {
        printf("Temperatura: %d °C\n",
	    veiculo->temperatura);
        veiculo->temperatura += 5;
    }

    printf("Temperatura: %d °C\n", veiculo->temperatura);
    printf("Status térmico...... ALERTA\n"
           "Ventoinha........... LIGADA\n");
}

void inicializar_veiculo(DadosVeiculo *veiculo)
{
    if (veiculo == NULL)
    {
	return;
    }

    veiculo->rpm = 850;
    veiculo->temperatura = 85;
    veiculo->velocidade = 0;
    veiculo->nivel_bateria = 14;
    veiculo->nivel_combustivel = 50;
    veiculo->posicao_acelerador = 0;
}

int ler_inteiro_na_faixa(
    const char *mensagem,
    int minimo,
    int maximo,
    int *destino)
{
    char linha[100];
    char caractere_extra;
    int valor;

    if (mensagem == NULL || destino == NULL)
    {
        return 0;
    }

    while (1)
    {
        printf("%s", mensagem);

        if (fgets(linha, sizeof linha, stdin) == NULL)
        {
            return 0;
        }

        if (sscanf(
                linha,
                " %d %c",
                &valor,
                &caractere_extra) != 1)
        {
            printf(
                "Entrada inválida. Digite apenas um número inteiro.\n"
            );

            continue;
        }

        if (!valor_dentro_da_faixa(valor, minimo, maximo))
        {
            printf(
                "Valor fora da faixa permitida: %d a %d.\n",
                minimo,
                maximo
            );

            continue;
        }

        *destino = valor;

        return 1;
    }
}
