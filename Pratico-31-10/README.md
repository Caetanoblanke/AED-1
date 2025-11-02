Caetano Blanke - M2 Algoritmos e estrutura de dados

Problema 605 do leetCode - Can Place Flowers

O problema consiste em você receber um vetor de numeros de 0 ou 1 onde, 1 se tem flor e 0 se não tem e um numero de flores que quer adcionar, porem não pode ter flores adjacentes, flores uma do lado da outra.


Ex 1: 
[1,0,0,0,1] 
n = 1
Aqui eu tenho duas flores no vetor e quero adcionar mais uma seguindo a regra adjacente, eu posso colocar no meio ficando [1,0,1,0,1] então retorna verdadeiro.

Ex 2:
[1,0,0,0,1]
n = 2
Duas flores e quero adcionar mais duas, porem nao ha espacos livres para as duas sem ficar uma do lado da outra, então retorna falso.

Ex 3:
[1,0,0,0,1,0,0,0,1]
n = 2
Tres flores e quero adcionar mais duas seguindo a regra adjacente, ficando [1,0,1,0,1,0,1,0,1], então retorna verdadeiro.
