Felipe Fill Cardoso 113.305-7

# Formas Geométricas 
O objetivo desse trabalho é demonstrar, a partir do uso de formas geométricas, alguns conceitos de uma linguagem orientada a objetos, entre eles: composição, herança, encapsulamento e exceções.

## Estrutura do projeto
O projeto é composto por quatro classes, são elas:
- `Point`: representa um ponto no espaço;
- `Shape`: representa uma forma geométrica arbitrária;
- `Circle`: representa um circulo;
- `Triangle`: representa um triângulo.

No diagrama de classes (arquivo incluído neste projeto) é possível verificar a relação de composição entre as classes `Point` e `Shape`, além da relação de herança entre `Shape` e `Circle/Triangle`.

Basicamente, qualquer forma geométrica é composta por, no mínimo, um ponto. Dai surge a relação de composição entre as classes. `Shape` declara (ou implementa) membros em comum entre todas as formas geométricas, como area, número de lados e pontos. Por isso, as atuais formas geométricas circulo e triângulo são filhas de `Shape`.

Além dessas classes, o projeto também conta com três classes de exceções, são elas:
- `NotImplementedException`: lançada quando um método ainda não foi implementado, útil em casos onde a classe base (pai) tem um método que a classe filha deve implementar. Um bom exemplo é o caso do método `barulho` normalmente presente na classe base `Animal` em exemplos de orientação a objetos.
- `PointsOverflowException`: lançada quando o usuário tenta adicionar um número de pontos maior do que uma dada forma geométrica suporta. Exemplo seria um triângulo com mais de três pontos.
- `NotEnoughPointsException`: lançada quando o usuário tenta executar uma função que depende de todos os pontos de uma forma geométrica, porém eles ainda não estão configurados adequadamente. Exemplo: tentar calcular a area de um triângulo com apenas dois pontos adicionados à instancia.

PS: A nomenclatura utilizada é baseada no guia de estilo para C++, da Google, disponível em: http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml#General_Naming_Rules





# Descrição das Classes
Métodos que foram herdados ou sobrescritos das classes bases não são descritos novamente.

## Point
- `Point()`: construtor padrão da classe.
- `Point(double x, double y)`: construtor que aceita valores de x e y.
- `inline void set_x(double x)`: altera o valor do atributo `x`.
- `inline double x() const`: devolve o valor do atributo `x`.
- `inline void set_y(double y)`: altera o valor do atributo `y`.
- `inline double y() const`: devolve o valor do atributo `y`.
- `double operator-(Point &p)`: sobrecarga do operador “-“, devolve a distancia entre dois pontos.

## Shape
- `Shape()`: construtor padrão da classe.
- `void AddPoint(Point &p)`: adiciona um novo ponto à forma geométrica.
- `void Print() const`: imprime a descrição da forma.
- `int NumberOfSides() const`: devolve o número de lados da forma geométrica.
- `double Area() const`: devolve o valor da area da forma geométrica.
- `inline std::vector<Point> points() const`: devolve vetor de pontos que compõem a forma.

## Circle
- `Circle(double radius)`: construtor que aceita o valor do raio do circulo.
- `inline void set_radius(double radius)`: altera o valor do atributo `radius`.
- `inline double radius() const`: devolve o valor do atributo `radius`.

## Triangle
- `Triangle()`: construtor padrão da classe.
- `double Height() const`: devolve a altura do triângulo.

# Testes
O processo de teste do projeto é bem simples, basicamente é necessário construir um objeto do tipo `Circle` e outro do tipo `Triangle` e chamar o método `Print()`, que passa por todos os métodos da classe e imprime informações sobre os objetos.
Esses testes estão presentes no arquivo `main.cc`.

