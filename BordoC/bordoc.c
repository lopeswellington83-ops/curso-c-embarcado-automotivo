#include <stdio.h>
#include "bordoc.h"

static int valor_dentro_da_faixa(
    int valor,
    int minimo,
    int maximo
);

static int valor_dentro_da_faixa(
    int valor,
    int minimo,
    int maximo)
{
    if (valor >= minimo && valor <= maximo)
    {
        return 1;
    }

    return 0;
}
void inicializar_veiculo(DadosVeiculo *veiculo)
{
    if (veiculo == NULL)
    {
	return;
    }
    veiculo->rpm = RPM_PADRAO;
    veiculo->temperatura = TEMPERATURA_PADRAO;
    veiculo->velocidade = VELOCIDADE_PADRAO;
    veiculo->nivel_bateria = BATERIA_PADRAO;
    veiculo->nivel_combustivel = COMBUSTIVEL_PADRAO;
    veiculo->posicao_acelerador = ACELERADOR_PADRAO;
}

void inicializar_viagem(DadosViagem *viagem)
{
    if (viagem == NULL)
    {
        return;
    }

    viagem->tempo_segundos = 0;
    viagem->distancia_metros = 0.0;
    viagem->velocidade_maxima = 0;
    viagem->rpm_maximo = 0;
}

void atualizar_tempo_viagem(DadosViagem *viagem)
{
    if (viagem == NULL)
    {
        return;
    }

    viagem->tempo_segundos++;
}

void atualizar_maximos(
    const DadosVeiculo *veiculo,
    DadosViagem *viagem)
{
    if (veiculo == NULL || viagem == NULL)
    {
	return;
    }
    if (veiculo->rpm > viagem->rpm_maximo)
    {
	viagem->rpm_maximo = veiculo->rpm;
    }
    if (veiculo->velocidade > viagem->velocidade_maxima)
    {
	viagem->velocidade_maxima = veiculo->velocidade;
    }
}

void exibir_menu(void)
{
    printf("\n========== BORDOC ==========\n\n");
    printf("%d - Exibir painel\n", OPCAO_EXIBIR_PAINEL);
    printf("%d - Alterar RPM\n", OPCAO_ALTERAR_RPM);
    printf("%d - Alterar temperatura\n", OPCAO_ALTERAR_TEMPERATURA);
    printf("%d - Alterar velocidade\n", OPCAO_ALTERAR_VELOCIDADE);
    printf("%d - Alterar tensão da bateria\n", OPCAO_ALTERAR_BATERIA);
    printf("%d - Alterar nível de combustível\n", OPCAO_ALTERAR_COMBUSTIVEL);
    printf("%d - Exibir quantidade de atualizações\n", OPCAO_EXIBIR_ATUALIZACOES);
    printf("%d - Simular aceleração\n", OPCAO_SIMULAR_ACELERACAO);
    printf("%d - Simular aquecimento\n", OPCAO_SIMULAR_AQUECIMENTO);
    printf("%d - Alterar posição do acelerador\n", OPCAO_ALTERAR_ACELERADOR);
    printf("%d - Restaurar dados padrão\n", OPCAO_RESTAURAR_DADOS);
    printf("%d - Computador de Viagem\n", OPCAO_EXIBIR_VIAGEM);
    printf("%d - Encerrar\n\n", OPCAO_ENCERRAR);
    printf("============================\n\n");
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
    if (!valor_dentro_da_faixa(veiculo->rpm, RPM_MINIMO,RPM_MAXIMO))
    {
        printf("Aviso: Medição do RPM Incorreta\n");
    }
    else if (veiculo->rpm > RPM_ALERTA)
    {
        printf("Aviso: RPM próximo ao corte\n");
    }

    printf("Temperatura.......... %d °C\n", veiculo->temperatura);
    if (!valor_dentro_da_faixa(veiculo->temperatura, TEMPERATURA_MINIMA,TEMPERATURA_MAXIMA))
    {
        printf("Aviso: Medição da Temperatura Incorreta\n");
    }
    else if (veiculo->temperatura >= TEMPERATURA_CRITICA)
    {
        printf("Status térmico...... CRÍTICO\n"
               "Ventoinha........... LIGADA\n");
    }
    else if (veiculo->temperatura >= TEMPERATURA_ALERTA)
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
    if (!valor_dentro_da_faixa(veiculo->velocidade, VELOCIDADE_MINIMA, VELOCIDADE_MAXIMA))
    {
        printf("Aviso: Medição da Velocidade Incorreta\n");
    }

    printf("Bateria.............. %d V\n", veiculo->nivel_bateria);
    if (!valor_dentro_da_faixa(veiculo->nivel_bateria, BATERIA_MINIMA, BATERIA_MAXIMA))
    {
        printf("Aviso: Medição da Tensão da Bateria Incorreta\n");
    }
    else if (veiculo->nivel_bateria < BATERIA_BAIXA)
    {
        printf("Aviso: Tensão da Bateria baixa\n");
    }

    printf("Combustível.......... %d %%\n", veiculo->nivel_combustivel);
    if (!valor_dentro_da_faixa(veiculo->nivel_combustivel, COMBUSTIVEL_MINIMO, COMBUSTIVEL_MAXIMO))
    {
        printf("Aviso: Medição do Combustível Incorreta\n");
    }
    else if (veiculo->nivel_combustivel <= COMBUSTIVEL_RESERVA)
    {
        printf("Aviso: Combustível na reserva\n");
    }

    printf(
        "Acelerador........... %d %%\n",
        veiculo->posicao_acelerador
    );

    if (!valor_dentro_da_faixa(
            veiculo->posicao_acelerador, ACELERADOR_MINIMO, ACELERADOR_MAXIMO))
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

    for (veiculo->rpm = RPM_SIMULACAO_INICIAL;
         veiculo->rpm <= RPM_SIMULACAO_FINAL;
	 veiculo->rpm += RPM_SIMULACAO_PASSO)
    {
	printf("RPM: %d\n", veiculo->rpm);
    }
    veiculo->rpm = RPM_PADRAO;
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

    veiculo->temperatura = TEMPERATURA_SIMULACAO_INICIAL;

    while (veiculo->temperatura < TEMPERATURA_SIMULACAO_FINAL)
    {
	printf("Temperatura: %d °C\n", veiculo->temperatura);

	veiculo->temperatura += TEMPERATURA_SIMULACAO_PASSO;
    }

    printf("Temperatura: %d °C\n", veiculo->temperatura);
    printf("Status térmico...... ALERTA\n"
           "Ventoinha........... LIGADA\n");
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

void exibir_viagem(const DadosViagem *viagem)
{
    if (viagem == NULL)
    {
	printf("\nErro: Dados da viagem indisponíveis.\n");
	return;
    }
    printf("\n======= COMPUTADOR DE VIAGEM =======\n");
    printf("Tempo................ %lu s\n",
	viagem->tempo_segundos);
    printf("Distância............ %.2f m\n",
	viagem->distancia_metros);
    printf("Velocidade média..... %.2f km/h\n",
        calcular_velocidade_media(viagem));
    printf("Velocidade Máxima.... %d km/h\n",
	viagem->velocidade_maxima);
    printf("RPM máximo........... %d\n",
	viagem->rpm_maximo);
    printf("======================================\n");
}

void atualizar_distancia(
    const DadosVeiculo *veiculo,
    DadosViagem *viagem)
{
    if (veiculo == NULL || viagem == NULL)
    {
        return;
    }

    viagem->distancia_metros +=
        (double)veiculo->velocidade / 3.6;
}

double calcular_velocidade_media(
    const DadosViagem *viagem)
{
    if (viagem == NULL || viagem->tempo_segundos == 0)
    {
        return 0.0;
    }

    return
        (viagem->distancia_metros /
         (double)viagem->tempo_segundos) * 3.6;
}
