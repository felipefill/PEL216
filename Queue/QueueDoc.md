# Fila (Queue)
A fila é uma estrutura de dados (E.D.) do tipo FIFO (First In First Out), que significa que o primeiro elemento a ser enfileirado vai ser o primeiro elemento a ser desenfileirado.
Para essa tarefa foi desenvolvida uma E.D. que enfileira qualquer tipo de elemento, desde que todos sejam do mesmo tipo/classe. Isto é, ela é uma classe do tipo template, e conta com os seguintes métodos:
- `Queue()`
 	- Construtor, responsável por inicializar a estrutura
- `bool isEmpty()`
	- Método que diz se a fila está vazia (`true` para vazia, `false` para fila com elementos).
- `int getSize()`
	- Devolve o tamanho atual da estrutura, isto é, a quantidade de elementos enfileirados.
- `void queue(T *value)`
	- Enfileira um elemento do tipo T, onde T é o tipo/classe com o qual esta estrutura trabalha.
- `T *dequeue()`
	- Desenfileira o primeiro elemento da estrutura e o devolve como valor de retorno.

PS: A implementação dos métodos é feita no arquivo .h (header) pois, para uma classe template, a compilador precisa da implementação dos métodos no momento da compilação, para que possa criar uma nova classe que trabalha com aquele tipo/classe especifica.