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


## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

ok

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Ok

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

ok

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**
ok

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

ok

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

ok

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

ok

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

OK

## Comentários gerais CP1
- Como eu comentei com vocês eu tenho alguns pontos para adicionar em temos de software, são dois pontos principais:
1. O primeiro diz respeito à criação de níveis, como eu sugeri um metódo estático encaixa muito bem nesse caso! Mostrei de propósito na aula para que vocês tivessem o insight, como conversamos esses métodos são chamados de métodos Fabrica, que também são um padrão de programação. Esses meétodos são usados para construir classes quando a construção não é trivial, que é o caso do vetor de níveis.
2. O outro ponto era melhorar a utilização do gameloop pattern, nesse caso vocês precisariam melhorar o uso do metodo get_input, para que ele simulasse melhor a interação da IA com o jogo. Nesse caso os métodos relacionados à player podem ficar todos em get_input, e a classe Game pode se encarregar de repassar a informação entre as classes interessadas no método update.