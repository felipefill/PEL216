Felipe Fill Cardoso 113.305-7

# Integração numérica
O objetivo deste trabalho é demonstrar o funcionamento do algoritmo de integração numérica de Newton-Cotes aplicado a alguns exemplos apresentados em classe.

## Regras de integração
O algoritmo foi implementado com três regras diferentes para o cálculo da aproximação da integral:

* Regra do Ponto Médio
* Regra do Trapézio
* Regra de Simpson

## Métodos
É possível fazer a aproximação através da aplicação do algoritmo com um número predeterminado de intervalos (implementação clássica) e através do método de quadratura adaptativa.

# Estrutura do projeto
O projeto é composto por três classes: `NumericalIntegrationBase`, `NewtonCotes` e `AdaptiveQuadrature`. Elas possuem uma relação de herança entre si, sendo que a primeira é a base para a segunda, e a segunda para a terceira. É possível observar essa relação no diagrama de classes.

# Descrição das classes

## NumericalIntegrationBase
* `NumericalIntegrationBase(double (*function)(double), float interval_begin, float interval_end, int slicing)`
* `virtual ~NumericalIntegrationBase()`
* `virtual double Integrate()`
* `float interval_begin() const`
* `float interval_end() const`
* `int slicing() const`
* `float step_size() const`
* `double function (double input) const`

## NewtonCotes
* `NewtonCotes(double (*function)(double), float interval_begin, float interval_end, int slicing)`
* `~NewtonCotes()`
* `double Integrate()`
* `double ErrorWithDerivative(double(*derivative)(double))`
* `double MidPointIntegration()`
* `double TrapezoidIntegration()`
* `double SimpsonIntegration()`
* `double MidPointError(double(*derivative)(double))`
* `double TrapezoidError(double(*derivative)(double))`
* `double SimpsonError(double(*derivative)(double))`
* `NewtonCotesIntegrationType integration_type() const`
* `void set_integration_type (NewtonCotesIntegrationType type)`

## AdaptiveQuadrature
* `AdaptiveQuadrature(double (*function)(double), float interval_begin, float interval_end)`
* `~AdaptiveQuadrature()`
* `double Integrate()`
* `double threshold() const`
* `void set_threshold(float threshold)`

# Resultados
Resultados apresentados após a execução do algoritmo (código de teste presente em `main.cc`):

#### Método “Clássico”
Exercício A:

* MidPoint: 1.71757 with error: 0.126042
* Trapezoid: 1.71971 with error: -0.252083
* Simpson: 1.71828 with error: -0.000766754

Exercício B:

* MidPoint: 0.788103 with error: -0.126042
* Trapezoid: 0.77613 with error: 0.252083
* Simpson: 0.784112 with error: 0.00230026

Exercício C:

* MidPoint: 0.747131 with error: -0.252083
* Trapezoid: 0.746211 with error: 0.504167
* Simpson: 0.746824 with error: -0.00920105

#### Método de Quadratura Adaptativa

Exercício A:

* MidPoint: 1.71828
* Trapezoid: 1.71828
* Simpson: 1.71828

Exercício B:

* MidPoint: 0.785398
* Trapezoid: 0.785398
* Simpson: 0.785398

Exercício C:

* MidPoint: 0.746824
* Trapezoid: 0.746824
* Simpson: 0.746824
