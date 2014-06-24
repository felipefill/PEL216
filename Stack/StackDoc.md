# Pilha (Stack)
A pilha é uma estrutura de dados (E.D.) do tipo LIFO (Last In First Out), que significa que o primeiro elemento a ser empilhado vai ser o primeiro elemento a ser desempilhado.
Para essa tarefa foi desenvolvida uma E.D. que empilha qualquer tipo de elemento, desde que todos sejam do mesmo tipo/classe. Isto é, ela é uma classe do tipo template, e conta com os seguintes métodos:
- `Stack()`
 	- Construtor, responsável por inicializar a estrutura
- `bool isEmpty()`
	- Método que diz se a fila está vazia (`true` para vazia, `false` para fila com elementos).
- `T *getTop()`
	- Devolve o primeiro elemento da pilha, sem remove-lo da estrutura.
- `int getSize()`
	- Devolve o tamanho atual da estrutura, isto é, a quantidade de elementos empilhados.
- `void push(T *value)`
	- Empilha um elemento do tipo T, onde T é o tipo/classe com o qual esta estrutura trabalha.
- `T *pop()`
	- Desempilha o primeiro elemento da estrutura e o devolve como valor de retorno.

PS: A implementação dos métodos é feita no arquivo .h (header) pois, para uma classe template, a compilador precisa da implementação dos métodos no momento da compilação, para que possa criar uma nova classe que trabalha com aquele tipo/classe especifica.