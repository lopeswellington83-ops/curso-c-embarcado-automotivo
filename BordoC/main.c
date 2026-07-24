#include <stdio.h>

void exibir_menu(void);

int valor_dentro_da_faixa(
    int valor,
    int minimo,
    int maximo
);

void exibir_painel(
    int rpm,
    int temperatura,
    int velocidade,
    int nivel_bateria,
    int nivel_combustivel
);

int simular_aceleracao(void);

int simular_aquecimento(void);

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
        exibir_menu();
        printf("  Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                exibir_painel(
                    rpm,
                    temperatura,
                    velocidade,
                    nivel_bateria,
                    nivel_combustivel);
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
                rpm = simular_aceleracao();
                atualizacoes++;
                break;

            case 9:
                temperatura = simular_aquecimento();
                atualizacoes++;
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

void exibir_painel(
    int rpm,
    int temperatura,
    int velocidade,
    int nivel_bateria,
    int nivel_combustivel)
{
    printf("\n========== PAINEL ==========\n");

    printf("RPM.................. %d\n", rpm);
    if (!valor_dentro_da_faixa(rpm, 0, 7000))
    {
        printf("Aviso: Medição do RPM Incorreta\n");
    }
    else if (rpm > 6000)
    {
        printf("Aviso: RPM próximo ao corte\n");
    }

    printf("Temperatura.......... %d °C\n", temperatura);
    if (!valor_dentro_da_faixa(temperatura, 0, 120))
    {
        printf("Aviso: Medição da Temperatura Incorreta\n");
    }
        else if (temperatura >= 110)
    {
        printf("Status térmico...... CRÍTICO\n"
                "Ventoinha .......... LIGADA\n");
    }
    else if (temperatura >= 95)
    {
        printf("Status térmico...... ALERTA\n"
                "Ventoinha .......... LIGADA\n");
    }
    else
    {
        printf("Status térmico...... NORMAL\n"
                "Ventoinha .......... DESLIGADA\n");
    }

    printf("Velocidade........... %d km/h\n", velocidade);
    if (!valor_dentro_da_faixa(velocidade, 0, 170))
    {
        printf("Aviso: Medição da Velocidade Incorreta\n");
    }

    printf("Bateria.............. %d V\n", nivel_bateria);
    if (!valor_dentro_da_faixa(nivel_bateria, 0, 14))
    {
        printf("Aviso: Medição da Tensão da Bateria Incorreta\n");
    }
    else if (nivel_bateria < 12)
    {
        printf("Aviso: Tensão da Bateria baixa\n");
    }

    printf("Combustível.......... %d %%\n", nivel_combustivel);
    if (!valor_dentro_da_faixa(nivel_combustivel, 0, 100))
    {
        printf("Aviso: Medição do Combustível Incorreta\n");
    }
    else if (nivel_combustivel <= 15)
    {
        printf("Aviso: Combustível na reserva\n");
    }

    printf("============================\n");
}

int simular_aceleracao(void)
{
    int rpm;
    printf("\n===== SIMULAÇÃO DE ACELERAÇÃO =====\n");

    for (rpm = 1000; rpm <= 5000; rpm += 500)
    {
        printf("RPM: %d\n", rpm);
    }

    rpm = 850;

    printf("Retorno à marcha lenta: %d RPM\n", rpm);

    return rpm;
}

int simular_aquecimento(void)
{
    int temperatura = 70;
    printf("\n===== SIMULAÇÃO DE AQUECIMENTO =====\n");

    while (temperatura < 100)
    {
        printf("Temperatura: %d °C\n", temperatura);
        temperatura += 5;
    }

    printf("Temperatura: %d °C\n", temperatura);
    printf("Temperatura elevada. Ventoinha acionada.\n");

    return temperatura;
}
