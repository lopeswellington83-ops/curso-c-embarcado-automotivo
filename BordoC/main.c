#include <stdio.h>
#include "bordoc.h"

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
