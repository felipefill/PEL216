Felipe Fill Cardoso 113.305-7

# Descida de Gradiente
O objetivo deste trabalho é demonstrar o algoritmo de descida de gradiente, utilizado para minimizarão de funções, aplicado a alguns exemplos apresentados em classe.

# Estrutura do Projeto
O projeto é composto por apenas uma classe: `GradientDescent`.
Ela é responsável por minimizar a função que é dada como entrada.

# Descrição das Classes

## GradientDescent
* `GradientDescent(std::vector<int> function, double initial_value)`: construtor da classe, recebe um vetor que representa a equação (polinomial) e o valor inicial, a partir do qual o algoritmo vai começar a “descida” do gradiente.
* `double F(double x)`: calcula o valor da função para uma entrada x.
* `double DerivatedFunctionOn(double x)`: calcula o valor da função derivada para o valor dado
* `double Calculate(double g, double learning_factor, long max_iterations)`: calcula a descida de gradiente, para alcançar o valor `g`, utilizando a taxa de aprendizado e o número máximo de iterações fornecidos; caso o algoritmo chegue ao número máximo de iterações sem encontrar um resultado, então uma exceção será lançada para que o programador saiba que o algoritmo falhou em encontrar uma solução satisfatória. 

# Testes
O processo de testes consiste em responder as questões apresentadas em sala. Para isso foi criada uma rotina no arquivo `main.cc`. Segue o resultado obtido pelo programa:

<b>Results for Exercise A: </b><br>
Step(0.1) = 0.00312036 <br>
Step(0.2) = 0.00291116 <br>
Step(0.3) = 0.0030046 <br>
Step(0.4) = 0.00309485 <br>
Step(0.5) = 0.00267571 <br>
Step(0.6) = 0.00227978 <br>
Step(0.7) = 0.00312414 <br>
Step(0.8) = 0.00261214 <br>
Step(0.9) = 0.00278625 <br>
Step(1) = 0.00195312 <br>
 <br>
<b>Results for Exercise B: </b> <br>
Step(0.1) = -0.839288 <br>
Step(0.2) = -0.839288 <br>
Step(0.3) = -0.839285 <br>
Step(0.4) = -0.839285 <br>
Step(0.5) = -0.839288 <br>
Step(0.6) = -0.839288 <br>
Step(0.7) = -0.839287 <br>
Step(0.8) = -0.839288 <br>
Step(0.9) = -0.839288 <br>
Step(1) = -0.839287 <br>
<br>

É possível observar que, para ambos os casos, a alteração da taxa de aprendizado (“step”) altera o resultado do algoritmo.