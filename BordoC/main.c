#include <stdio.h>
#include "bordoc.h"

int main(void)
{
    int opcao;
    int atualizacoes = 0;

    DadosVeiculo veiculo;
    inicializar_veiculo(&veiculo);

    DadosViagem viagem;
    inicializar_viagem(&viagem);

    do
    {
	exibir_menu();

	if (!ler_inteiro_na_faixa(
	        "  Escolha uma opção: ",
	        OPCAO_ENCERRAR,
		OPCAO_EXIBIR_VIAGEM,
	        &opcao))
	{
	    printf("\nEntrada encerrada.\n");
	    break;
	}

	switch (opcao)
	{
	    case OPCAO_EXIBIR_PAINEL:
	        exibir_painel(&veiculo);
	        break;

	    case OPCAO_ALTERAR_RPM:
	        /* leitura do RPM */
		if (ler_inteiro_na_faixa(
		    "Digite o novo RPM: ",
		    RPM_MINIMO,
		    RPM_MAXIMO,
		    &veiculo.rpm))
		{
		    atualizacoes++;
		}
	        break;

	    case OPCAO_ALTERAR_TEMPERATURA:
	        /* leitura da temperatura */
		if (ler_inteiro_na_faixa(
		    "Digite a nova temperatura: ",
		    TEMPERATURA_MINIMA,
		    TEMPERATURA_MAXIMA,
		    &veiculo.temperatura))
		{
		    atualizacoes++;
		}
	        break;

	    case OPCAO_ALTERAR_VELOCIDADE:
	        /* leitura da velocidade */
		if (ler_inteiro_na_faixa(
		    "Digite a nova velocidade: ",
		    VELOCIDADE_MINIMA,
		    VELOCIDADE_MAXIMA,
		    &veiculo.velocidade))
		{
		    atualizacoes++;
		}
	        break;

	    case OPCAO_ALTERAR_BATERIA:
	        /* leitura da bateria */
		if (ler_inteiro_na_faixa(
		    "Digite a nova tensão da bateria: ",
		    BATERIA_MINIMA,
		    BATERIA_MAXIMA,
		    &veiculo.nivel_bateria))
		{
		    atualizacoes++;
		}
	        break;

	    case OPCAO_ALTERAR_COMBUSTIVEL:
	        /* leitura do combustível */
		if (ler_inteiro_na_faixa(
		    "Digite o novo nível de combustível: ",
		    COMBUSTIVEL_MINIMO,
		    COMBUSTIVEL_MAXIMO,
		    &veiculo.nivel_combustivel))
		{
		    atualizacoes++;
		}
	        break;

	    case OPCAO_EXIBIR_ATUALIZACOES:
	        printf(
	            "\nQuantidade de atualizações: %d\n",
	            atualizacoes
	        );
	        break;

	    case OPCAO_SIMULAR_ACELERACAO:
	        simular_aceleracao(&veiculo);
	        atualizacoes++;
	        break;

	    case OPCAO_SIMULAR_AQUECIMENTO:
	        simular_aquecimento(&veiculo);
	        atualizacoes++;
	        break;

	    case OPCAO_ALTERAR_ACELERADOR:
	        /* leitura do acelerador */
		if (ler_inteiro_na_faixa(
		    "Digite a posição do acelerador (0-100%): ",
		    ACELERADOR_MINIMO,
		    ACELERADOR_MAXIMO,
		    &veiculo.posicao_acelerador))
		{
		    atualizacoes++;
		}
	        break;

	    case OPCAO_RESTAURAR_DADOS:
	        inicializar_veiculo(&veiculo);
	        atualizacoes++;
	        printf("\nDados do veículo restaurados.\n");
	        break;

	    case OPCAO_EXIBIR_VIAGEM:
		exibir_viagem(&viagem);
		break;

	    case OPCAO_ENCERRAR:
	        printf("\nEncerrando o BordoC...\n");
	        break;

	    default:
	        printf("\nOpção inválida.\n");
	        break;
	}

	if (opcao != OPCAO_ENCERRAR)
	{
	    atualizar_maximos(&veiculo, &viagem);
	    atualizar_distancia(&veiculo, &viagem);
	    atualizar_tempo_viagem(&viagem);
	}

    } while (opcao != OPCAO_ENCERRAR);

    return 0;
}
