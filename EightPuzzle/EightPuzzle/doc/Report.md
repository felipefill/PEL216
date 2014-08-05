Felipe Fill Cardoso 113.305-7

# Jogo dos Oito (Eight Puzzle)
O objetivo desse trabalho é demonstrar, a partir da utilização do Jogo dos Oito, o funcionamento de cinco tipos diferentes de busca, além de diversos conceitos de orientação a objetos.

## Estrutura do Projeto
Esse trabalho implementa a resolução do Puzzle através da utilização de cinco algoritmos diferentes de busca, são eles:

* Busca em largura (Breadth-First Search)
* Busca em profundidade (Depth-First Search)
* Busca subida da encosta (Hill-Climbing Search)
* Busca melhor escolha (Best-First Search)
* Busca A* (A* Star)

Os dois primeiros métodos são buscas não informadas (cegas) e os demais são buscas informadas (heurísticas).

A solução conta com algumas classes utilizadas para representar os tipos de busca:

* `SearchInterface`: classe virtual que serve como “contrato” para qualquer implementação de busca. Qualquer classe que herdar uma classe virtual deve, obrigatoriamente, implementar todos seus métodos virtuais, caso contrário será impossível instanciar tal classe. Isso se assemelha um pouco às “interfaces”, da linguagem de programação Java.

* `SearchBase`: classe base para implementação de qualquer busca; é filha da classe virtual `SearchInterface`

* `BreadthFirstSearch`: classe que representa o algoritmo de busca não informada “Busca em Largura”

* `DepthFirstSearch`: classe que representa o algoritmo de busca não informada “Busca em profundidade”

* `HeuristicSearch`: classe que serve como base para qualquer busca heurística; é filha de `SearchBase`

* `HillClimbingSearch`: classe que representa o algoritmo de busca informada “Subida da Encosta”

* `BestFirstSearch`: representa o algoritmo de busca heurística “Melhor Escolha”

* `AStarSearch`: classe que implementa o algoritmo de busca “A*”

Também conta com classes para representar o jogo:

* `Puzzle`: contém métodos estáticos para geração de estados, por exemplo, objetivo, estado aleatório, estado de fácil resolução, entre outros.

* `PuzzleState`: representa um estado do jogo, i.e. o tabuleiro com as peças distribuídas de uma forma determinada

* `SquareMatrix`: representa uma matriz quadrada, tem uma relação de composição com `PuzzleState`

* `Line`: representa uma linha de uma matriz, tem uma relação de composição com `SquareMatrix`

* `ElementPosition`: representa a posição de um elemento dentro da matriz

Além de algumas estruturas de dados utilizadas para a implementação das buscas:

* `Stack`: representa uma pilha
* `Queue`: representa uma fila
(Ambos implementado com a utilização de “templates”)

Por fim, o trabalho também inclui três classes de exceção:

* `NotImplementedException`: jogada quando um método que não foi implementado é invocado
* `InvalidOperationException`: jogada na tentativa de realizar uma operação ilegal no tabuleiro do jogo
* `NoBlankSpaceException`: jogada quando um estado não possui a peça “vazia”

É possível verificar as relações entre essas classes no Diagrama de Classes, incluído neste projeto.

PS: A nomenclatura utilizada é baseada no guia de estilo para C++, da Google, disponível em: http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml#General_Naming_Rules

## Descrição das Classes

Métodos que foram herdados ou sobrescritos das classes bases não são descritos novamente, assim como métodos e propriedades privadas/protegidas, além de estruturas já abordadas em outros projetos.

##  Line
* `Line()`: construtor vazio da classe
* `Line(int capacity)`: construtor que recebe a quantidade de elementos da linha
* `T operator[] (int index) const`: sobrecarga do operador [], utilizado para acessar  o enésimo elemento da linha
* `T & operator[] (int index)`: sobrecarga do operador [], utilizado para alterar o valor do enésimo elemento da linha

## SquareMatrix
* `SquareMatrix(int capacity)`: construtor que recebe a capacidade da matriz
* `Line<T> operator[] (int index) const`: sobrecarga do operador [], utilizado para acessar a enésima coluna da matriz
* `Line<T> & operator[] (int index)`: sobrecarga do operador [], utilizado para obter uma referência para a enésima coluna da matriz
* `int capacity()`: devolve a capacidade da matriz
* `int square_capacity()`: devolve a raiz quadrada da capacidade da matriz

## PuzzleState
* `PuzzleState()`: construtor vazio da classe
* `~PuzzleState()`: destrutor vazio da classe
* `bool operator == (PuzzleState & p)`: sobrecarga do operador ==, utilizado para verificar se dois estados são equivalentes
* `PuzzleState * operator + (PuzzleOperations operation)`: sobrecarga do operador +, utilizado para aplicar uma operação ao estado atual
* `Line<int> operator [] (int index) const`: apenas repassa o valor obtido da classe `SquareMatrix`
* `Line<int> & operator [] (int index)`: apenas repassa o valor obtido da classe `SquareMatrix`
* `int capacity()`: apenas repassa o valor obtido da classe `SquareMatrix`
* `int square_capacity()`: apenas repassa o valor obtido da classe `SquareMatrix`
* `ElementPosition blank_space_position()`: devolve a posição do espaço em branco
* `void Print()`: imprime o estado na saída padrão
* `std::vector<PuzzleState *> BuildPathToRoot()`: constrói o caminho desse nó até o nó raiz
* `std::vector<PuzzleState *> Children()`: devolve um array com todos os possível estados a partir do estado atual
* `inline PuzzleState * parent_state() const`: devolve o estado pai
* `inline void set_parent_state(PuzzleState * parent_state)`: atribui valor ao estado pai

## Puzzle
* `static PuzzleState * GenerateRandomState()`: gera um estado aleatório
* `static PuzzleState * GenerateEasyInitialState()`: gera um estado de fácil resolução
* `static PuzzleState * GenerateTestInitialState()`: gera o estado utilizado para realização dos testes
* `static PuzzleState * GenerateGoalState()`: gera o estado objetivo do jogo

## SearchInterface
* `virtual std::vector<PuzzleState*> DoSearch()`: define a assinatura do método que as classes de busca devem implementar

## SearchBase
* `SearchBase(PuzzleState * initial_state)`: construtor que recebe o estado inicial do jogo
* `std::vector<PuzzleState*> DoSearch()`: método utilizado para executar a busca do estado objetivo na árvore de estados, a partir do estado inicial
* `inline PuzzleState * initial_state() const`: devolve o estado inicial do jogo
* `inline void set_initial_state(PuzzleState * initial_state)`: atribui o estado inicial do jogo
* `inline PuzzleState * goal_state() const`: devolve o estado objetivo do jogo

## BreadthFirstSearch
* `BreadthFirstSearch(PuzzleState * initial_state)`: construtor que recebe o estado inicial do jogo

## DepthFirstSearch
* `DepthFirstSearch(PuzzleState * initial_state)`: construtor que recebe o estado inicial do jogo

## HeuristicSearch
* `HeuristicSearch(PuzzleState * initial_state)`: construtor que recebe o estado inicial do jogo

## HillClimbingSearch
* `HillClimbingSearch(PuzzleState * initial_state)`: construtor que recebe o estado inicial do jogo

## BestFirstSearch
* `BestFirstSearch(PuzzleState * initial_state)`: construtor que recebe o estado inicial do jogo

## AStarSearch
* `AStarSearch(PuzzleState * initial_state)`: construtor que recebe o estado inicial do jogo

PS: A classe `HeuristicSearch` implementa métodos protegidos que são exclusivos de algoritmos de busca informada.

# Testes

Os algoritmos de busca foram testados utilizando o mesmo estado inicial e final. Após cada execução é possível verificar se o algoritmo encontrou uma solução, qual foi essa solução e quanto tempo ele levou para obte-la.

Os testes estão disponíveis para consulta no arquivo `main.cc`.
