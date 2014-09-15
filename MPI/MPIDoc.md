Felipe Fill Cardoso  	113.305-7

# MPI

O objetivo deste trabalho é demonstrar o funcionamento de processamento paralelo, mais especificamente, através da interface de comunicação MPI (Message Passing Interface).

Para isso, o exercício de integração numérica foi refeito, para que o processamento de cálculo da integral seja feito de maneira paralela. Isso foi realizado atribuindo a cada processo um pedaço do intervalo de integração.

## Estrutura do projeto

O projeto tem apenas duas classes:
* `NumericalIntegrationBase`:  classe base para implementação de algoritmos de integração numérica com processamento paralelo.
* `NewtonCotes`: implementação do algoritmo de integração numérica de Newton-Cotes, com a utilização de processamento paralelo.

A relação entre as classes pode ser verificada no diagrama de classes.

## Descrição das classes

### NumericalIntegrationBase

* `NumericalIntegrationBase(double (*function)(double), float interval_begin, float interval_end, int slicing)`: construtor da classe, recebe a função a ser integrada, o começo e fim do intervalo e a quantidade de ‘pedaços’ em quais o intervalo deve ser dividido.
* `virtual ~NumericalIntegrationBase()`: destrutor virtual da classe
* `virtual void Integrate()`: método que as classes filhas devem implementar, executa a integração de fato.

### NewtonCotes

* `NewtonCotes(double (*function)(double), float interval_begin, float interval_end, int slicing)`: construtor da classe, apenas repassa os valores a classe base.
* `~NewtonCotes()`: implementação do destrutor, conforme especificado pela classe mãe.
* `double IntegrateInterval(float begin, float end)`: executa a integração de uma fatia do intervalo.
* `void Integrate()`: executa e exibe o resultado da integração.

## Resultados

O projeto tinha o objetivo de resolver alguns exemplos apresentados em classe.
Segue os resultados obtidos com o novo algoritmo:

Exercício A
```
There will be 2 tasks.
Each task is taking up an average of 5

I am task 0
Task 0: my interval begins with 0
Task 0 integrating interval 0 - 0.1
Task 0: slice 1 of 5
Task 0 integrating interval 0.1 - 0.2
Task 0: slice 2 of 5
Task 0 integrating interval 0.2 - 0.3
Task 0: slice 3 of 5
Task 0 integrating interval 0.3 - 0.4
Task 0: slice 4 of 5
Task 0 integrating interval 0.4 - 0.5
Task 0: slice 5 of 5
Task 0: my result = 0.648451

I am task 1
Task 1: my interval begins with 0.5
Task 1 integrating interval 0.5 - 0.6
Task 1: slice 1 of 5
Task 1 integrating interval 0.6 - 0.7
Task 1: slice 2 of 5
Task 1 integrating interval 0.7 - 0.8
Task 1: slice 3 of 5
Task 1 integrating interval 0.8 - 0.9
Task 1: slice 4 of 5
Task 1 integrating interval 0.9 - 1
Task 1: slice 5 of 5
Task 1: my result = 1.06912

>>>>>FINAL RESULT: 1.71757
```

Exercício B
```
There will be 2 tasks.
Each task is taking up an average of 5

I am task 0
Task 0: my interval begins with 0
Task 0 integrating interval 0 - 0.1
Task 0: slice 1 of 5
Task 0 integrating interval 0.1 - 0.2
Task 0: slice 2 of 5
Task 0 integrating interval 0.2 - 0.3
Task 0: slice 3 of 5
Task 0 integrating interval 0.3 - 0.4
Task 0: slice 4 of 5
Task 0 integrating interval 0.4 - 0.5
Task 0: slice 5 of 5
Task 0: my result = 0.478546

I am task 1
Task 1: my interval begins with 0.5
Task 1 integrating interval 0.5 - 0.6
Task 1: slice 1 of 5
Task 1 integrating interval 0.6 - 0.7
Task 1: slice 2 of 5
Task 1 integrating interval 0.7 - 0.8
Task 1: slice 3 of 5
Task 1 integrating interval 0.8 - 0.9
Task 1: slice 4 of 5
Task 1 integrating interval 0.9 - 1
Task 1: slice 5 of 5
Task 1: my result = 0.309557

>>>>>FINAL RESULT: 0.788103
```

Exercício C
```
There will be 2 tasks.
Each task is taking up an average of 5

I am task 0
Task 0: my interval begins with 0
Task 0 integrating interval 0 - 0.1
Task 0: slice 1 of 5
Task 0 integrating interval 0.1 - 0.2
Task 0: slice 2 of 5
Task 0 integrating interval 0.2 - 0.3
Task 0: slice 3 of 5
Task 0 integrating interval 0.3 - 0.4
Task 0: slice 4 of 5
Task 0 integrating interval 0.4 - 0.5
Task 0: slice 5 of 5
Task 0: my result = 0.461606

I am task 1
Task 1: my interval begins with 0.5
Task 1 integrating interval 0.5 - 0.6
Task 1: slice 1 of 5
Task 1 integrating interval 0.6 - 0.7
Task 1: slice 2 of 5
Task 1 integrating interval 0.7 - 0.8
Task 1: slice 3 of 5
Task 1 integrating interval 0.8 - 0.9
Task 1: slice 4 of 5
Task 1 integrating interval 0.9 - 1
Task 1: slice 5 of 5
Task 1: my result = 0.285525

>>>>>FINAL RESULT: 0.747131
```