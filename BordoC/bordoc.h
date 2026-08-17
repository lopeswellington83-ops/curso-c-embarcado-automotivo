#ifndef BORDOC_H
#define BORDOC_H

/* Limites dos dados do veículo */

#define RPM_MINIMO 0
#define RPM_MAXIMO 7000
#define RPM_ALERTA 6000

#define RPM_SIMULACAO_INICIAL 1000
#define RPM_SIMULACAO_FINAL 5000
#define RPM_SIMULACAO_PASSO 500

#define TEMPERATURA_MINIMA 0
#define TEMPERATURA_MAXIMA 120
#define TEMPERATURA_ALERTA 95
#define TEMPERATURA_CRITICA 110

#define TEMPERATURA_SIMULACAO_INICIAL 70
#define TEMPERATURA_SIMULACAO_FINAL 100
#define TEMPERATURA_SIMULACAO_PASSO 5

#define VELOCIDADE_MINIMA 0
#define VELOCIDADE_MAXIMA 170

#define BATERIA_MINIMA 0
#define BATERIA_MAXIMA 14
#define BATERIA_BAIXA 12

#define COMBUSTIVEL_MINIMO 0
#define COMBUSTIVEL_MAXIMO 100
#define COMBUSTIVEL_RESERVA 15

#define ACELERADOR_MINIMO 0
#define ACELERADOR_MAXIMO 100

/* Valores padrão */

#define RPM_PADRAO 850
#define TEMPERATURA_PADRAO 85
#define VELOCIDADE_PADRAO 0
#define BATERIA_PADRAO 14
#define COMBUSTIVEL_PADRAO 50
#define ACELERADOR_PADRAO 0

typedef enum
{
    OPCAO_ENCERRAR = 0,
    OPCAO_EXIBIR_PAINEL = 1,
    OPCAO_ALTERAR_RPM = 2,
    OPCAO_ALTERAR_TEMPERATURA = 3,
    OPCAO_ALTERAR_VELOCIDADE = 4,
    OPCAO_ALTERAR_BATERIA = 5,
    OPCAO_ALTERAR_COMBUSTIVEL = 6,
    OPCAO_EXIBIR_ATUALIZACOES = 7,
    OPCAO_SIMULAR_ACELERACAO = 8,
    OPCAO_SIMULAR_AQUECIMENTO = 9,
    OPCAO_ALTERAR_ACELERADOR = 10,
    OPCAO_RESTAURAR_DADOS = 11
} OpcaoMenu;

/* Estruturas */

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
