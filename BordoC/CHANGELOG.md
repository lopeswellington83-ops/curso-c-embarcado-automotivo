# Histórico de versões do BordoC

Este arquivo registra as principais alterações de cada versão do projeto.

## [Não Lançado]

# [0.8.0] - 2026-08-13

### Adicionado

- Constantes simbólicas para limites dos dados do veículo.
- Constantes para valores padrão do BordoC.
- Constantes para parâmetros das simulações.
- Enumeração `OpcaoMenu` para representar as opções do menu.

### Alterado

- Números mágicos foram substituídos por nomes descritivos.
- O menu e o `switch` passaram a utilizar valores da enumeração.
- Validações e inicializações passaram a utilizar constantes compartilhadas.
- As simulações passaram a utilizar parâmetros simbólicos.

# [0.7.0] - 2026-08-02

### Adicionado

- Makefile para automatizar a compilação.
- Alvos para compilar, executar e limpar o projeto.
- Compilação incremental por arquivos-objeto.

### Alterado

- A compilação manual foi substituída por comandos do Make.

# [0.6.0] - 2026-08-02

### Adicionado

- Cabeçalho público `bordoc.h`.
- Arquivo de implementação `bordoc.c`.
- Proteção contra inclusão múltipla no cabeçalho.

### Alterado

- O código deixou de estar concentrado apenas em `main.c`.
- A estrutura `DadosVeiculo` passou a ser declarada no cabeçalho.
- As funções do BordoC foram movidas para um módulo separado.
- A função de validação passou a ser privada ao módulo com `static`.
- A compilação passou a utilizar múltiplos arquivos-fonte.

# [0.5.0] - 2026-08-01

### Adicionado

- Função para leitura segura de números inteiros.
- Validação de formato das entradas.
- Validação de faixa antes de atualizar os dados do veículo.
- Detecção de caracteres adicionais em entradas numéricas.

### Alterado

- As entradas deixaram de utilizar `scanf()` diretamente.
- Valores inválidos não são mais gravados em `DadosVeiculo`.
- O contador é incrementado somente após uma atualização válida.
- O menu passou a aceitar somente opções entre 0 e 11.

### Corrigido

- Tratamento de entradas com letras ou conteúdo não numérico.
- Prevenção de valores inválidos persistentes nos campos do veículo.

## [0.4.0]

### Adicionado

- Função para inicializar os dados do veículo.
- Opção para restaurar os valores padrão.
- Verificação de ponteiros nulos.

### Alterado

- O painel passou a receber um ponteiro constante para `DadosVeiculo`.
- As simulações passaram a modificar diretamente a estrutura do veículo.
- As funções de simulação deixaram de retornar valores inteiros.

## [0.3.0] - 2026-07-25

### Adicionado

- Estrutura `DadosVeiculo`.
- Campo de posição do acelerador.
- Nova opção para alterar a posição do acelerador.

### Alterado

- O painel passa a receber os dados agrupados em uma estrutura.

## [0.2.0] - 2026-07-24

### Adicionado

- Função `exibir_menu`.
- Função `exibir_painel`.
- Função reutilizável `valor_dentro_da_faixa`.
- Funções de simulação de aceleração e aquecimento.

### Alterado

- A função `main` passou a coordenar as demais funções.
- O código foi reorganizado para separar responsabilidades.

### Corrigido

- Formatação da exibição do estado térmico.
- Mensagem de encerramento atualizada para o nome BordoC.

## [0.1.0]

### Adicionado

- Menu interativo inicial.
- Painel com RPM, temperatura, velocidade, bateria e combustível.
- Contador de atualizações.
- Simulações de aceleração e aquecimento.
