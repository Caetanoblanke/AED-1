Caetano Blanke M2
É-lhe dada a estrutura headde uma lista ligada com nnós.
Para cada nó na lista, encontre o valor do próximo nó maior . Ou seja, para cada nó, encontre o valor do primeiro nó adjacente a ele que tenha um valor estritamente maior que o seu.
Retorna um array de inteiros answeronde answer[i]é o valor do próximo nó maior que o nó ( indexado a partir de 1 ). Se o nó não tiver um próximo nó maior, defina como .ithithanswer[i] = 0
Exemplo 1:


Entrada: head = [2,1,5]
 Saída: [5,5,0]
Exemplo 2:


Entrada: head = [2,7,4,3,5]
 Saída: [7,0,5,5,0]
 

Restrições:

O número de nós na lista é n.
1 <= n <= 104
1 <= Node.val <= 109