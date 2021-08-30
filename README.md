# LP1 Trabalho 3 - Snaze

Repositório do Snaze implementado em c++ para a disciplina de Linguagem de Programação 1.

Comentários das funções podem ser encontrados nos seus respectivos [headers](./include). TODO

Informações dos autores podem ser encontrados em [autor.md](./autor.md).

## Compilando o jogo

Clone este repositório em sua máquina, tenha `make` instalado no sistema e faça:
```
$ make clean install
```

## Entrada do jogo

O programa requer o caminho para um arquivo de níveis (obrigatório) e um modo de jogo `snake` ou `pacman` (opcional, default = `snake`).

Um nível no arquivo de jogo deve ser configurado no seguinte formato:
```
5 8 3
########
#    ###
# #  ###
#     *#
########
END
```
1. Na primeira linha, deve haver 3 números inteiros separados por espaços: o nº de linhas, o nº de colunas, e a quant. de maçãs necessárias para completar o nível.

2. A partir da linha seguinte, deve haver o desenho do labirinto, onde `#` representa uma parede e `*` indica a posição de spawn da cobra.

3. Na última linha, deve haver um `END`, para indicar o fim da descrição do nível.

Esse modelo de configuração de níveis pode ser repetido várias vezes dentro de um único arquivo, de modo a rodar o jogo para todos os níveis, na ordem em que são descritos no arquivo. Basta apenas repetir o processo, começando na linha abaixo do `END` do nível anterior.

Arquivos exemplos de teste podem ser encontrados no diretório [data](./data).

## Executando o jogo

Faça:
```
$ make run F="FILE_PATH MODE"
```
Ou:
```
$ ./bin/snaze FILE_PATH MODE
```
Onde `FILE_PATH` é o caminho do arquivo de níveis e `MODE` é o modo de jogo.

## Limitações e funcionalidades não implementadas

Paredes invisíveis ainda não foram implementadas.

Um sistema de validação para arquivo de níveis ainda não foi implementado.

A inteligência artificial da cobra nem sempre irá seguir o melhor caminho até a maçã.
