#ifndef BORDOC_H
#define BORDOC_H

typedef struct
{
    int rpm;
    int temperatura;
    int velocidade;
    int nivel_bateria;
    int nivel_combustivel;
    int posicao_acelerador;
} DadosVeiculo;

void inicializar_veiculo(DadosVeiculo *veiculo);

void exibir_menu(void);

void exibir_painel(const DadosVeiculo *veiculo);

void simular_aceleracao(DadosVeiculo *veiculo);

void simular_aquecimento(DadosVeiculo *veiculo);

int ler_inteiro_na_faixa(
    const char *mensagem,
    int minimo,
    int maximo,
    int *destino
);

#endif
