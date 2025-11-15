Caetano Blanke - M2 Algoritmos e estrutura de dados

Faça uma agenda com o seguinte menu:
1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair
 
O desafio é não poder criar variáveis e sim um buffer de memória (void *pBuffer). Nisso vocês terão que fazer o trabalho que o Sistema Operacional faz para vocês ao organizar a memória.
 
Regras:
1.Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.

2.Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
Não pode usar struct em todo o programa.

Minha ideia foi inicializar um buffer com espaço para 2 inteiros, um para quantidade de pessoas e outro para opcao, e uma area temporaria de para não inserir diretamente no buffer, tendo espaco para 50 chars para nome, 1 inteiro para idade e mais 50 char para email, ficando assim:

Inicial:
4 bytes | 4 bytes | 104 bytes

E de acordo com que for adcionando pessoas, adciona mais 104 bytes, 50 char nome, 4 inteiros idade, 50 char email.
