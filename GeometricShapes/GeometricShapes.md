Felipe Fill Cardoso 113.605-7

# Formas Geométricas 
O objetivo desse trabalho é demonstrar, a partir do uso de formas geométricas, alguns conceitos de uma linguagem orientada a objetos, entre eles: composição, herança, encapsulamento e exceções são demonstrados.

## Estrutura do projeto
O projeto é composto por quatro classes, são elas:
- `Point`: representa um ponto no espaço;
- `Shape`: representa uma forma geométrica arbitrária;
- `Circle`: representa um circulo;
- `Triangle`: representa um triângulo.

No diagrama de classes (arquivo incluído neste projeto) é possível verificar a relação de composição entre as classes `Point` e `Shape`, além da relação de herança entre `Shape` e `Circle/Triangle`.

Além dessas classes, o projeto também conta com três classes de exceções, são elas:
- `NotImplementedException`: lançada quando um método ainda não foi implementado, útil em casos onde a classe base (pai) tem um método que a classe filha deve implementar. Um bom exemplo é o caso do método `barulho` normalmente presente na classe base `Animal` em exemplos de orientação a objetos.
- `PointsOverflowException`: lançada quando o usuário tenta adicionar um número de pontos maior do que uma dada forma geométrica suporta. Exemplo seria um triângulo com mais de três pontos.
- `NotEnoughPointsException`: lançada quando o usuário tenta executar uma função que depende de todos os pontos de uma forma geométrica, porém eles ainda não estão configurados adequadamente. Exemplo: tentar calcular a area de um triângulo com apenas dois pontos adicionados à instancia.

PS: A nomenclatura utilizada é baseada no guia de estilo para C++, da Google, disponível em: http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml#General_Naming_Rules


