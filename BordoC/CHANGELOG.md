# Histórico de versões do BordoC

Este arquivo registra as principais alterações de cada versão do projeto.

## [Não lançado]

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
