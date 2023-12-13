#README Por: Brunno W Rocha
#Get_next_line

versao: 1.2 | 13/12/2023

Github: BrunnoCode

#README GNL PARA INICIANTES E QUEM TEM DIFICULDADES DE CRIAR ALGORITMOS.

A Funcao GNL retorna apenas ate um \n (salto de linha).
Se a funcao é chamada em um loop, retornará todo conteúdo de um fd (File Descriptor, um file.txt por exemplo).

#Lembrando que a funcao read(int fd, char *buffer_lectura, BUFFER_SIZE),
sempre ler ate BUFFER_SIZE, exemplo visual:
        int fd = 3 #Numero referente a localizacao do arquivo.
        BUFFER_SIZE = 5
        char *buffer_lectura = "hola'\n'buenos dias"
        BUFFER_SIZE vai ler: 1="h", 2="o", 3="l", 4="a", 5='\n' #lembrando que neste caso aqui, BUFFER_SIZE = 5 #apenas conta numeros.
        buffer_lectura vai receber = "hola'\n'" ('\n) -> nao e visivel, é o salto de linha.

Temos o seguinte problema abaixo, imagine que nosso buffer no processo de leitura seja: buffer[bon|/n|/n|dia] ? como salvaremos a ultima posicao?

buffer -> ho\nla
buffer -> com\n\nest\nas
buffer -> \n
buffer -> Hola\n + \0<- #Sempre adicionamos '\0' no final de toda String

CONSTRUINDO UM ALGORITMO DE UM GET_NEXT_LINE FUNCIONAL

1-Primeiro declaramos uma variavel static, esta que, por sua vez guardara sempre as ultimas letras lidas, neste guia irei usar o nome static que é o tipo da variável, mas na realidade sería algo assim: static char *variavel.
*Pode receber um tamanho definido static[BUFFER_SIZE + 1]
*Ou pode reinicializa-la com NULL.

*Tambem criamos um char *linha para a linha de retorno final.
    

2-Verificamos errores iniciais
    *Se BUFFER_SIZE iguala a 0, ou seja menor que 0, ou se a funcao read() nao encontra fd retornando um valor de -1, a funcao read() tem 3 valores de rotorno que sao: read(-1) nao leu = error, read(n(qualquer numero positivo) que é a quantidade lidas segundo o que vale BUFFER_SIZE), read(0) terminou de ler tudo em fd, entao retornamos NULL em todos estes casos, nao ha nada para leitura e a funcao se acaba por aqui.

3-Nossa static recebe um punteiro char * que provém de uma funcao que retornará a concatenacao da proxima leitura até \n. Passamos fd como argumento da funcao porque dentro iremos usar read(funcao standar de leitura) O prototipo desta funcao pode ser: funcao(int fd, char *static)
        char    *funcao(fd, static)
                {
                    #Aqui criamos la logica
                    *Criamos um char *buffer de leitura
                    *Criamos um int num_control que ira controlar erros e  quantidade de bytes lidos.

                    *Nosso buffer de leitura recebe um malloc do tamanho que temos em nossa macro BUFFER_SIZE que está definida no nosso get_next_line.h, BUFFER_SIZE pode ser qualquer quantidade numerica, numero que definira quantos bytes serao lidos. Ou seja malloc de BUFFER_SIZE + 1 (adicionamos +1 para o \0 no fim de cada string)

                    *Verificamos se o malloc retornou corretamente.
                        Se buffer nao tem memoria reservada, entao é um erro, liberamos nossa statica com a funcao de free especial, algo assim: my_free(&static); em seguida retornamos NULL. Tudo se acaba por aqui.
                    
                    *Se nao deu erro no passo anterior, entao asignamos o primeiro indice de buffer_lectura \0, para limpar qualquer caracter que tenha por azar, pois se tiver um \n dentro, nao acederemos á funcao() seguinte.
                    *Tambem inicializamos nosso num_control com 1, para poder entrar no seguinte loop.

                    *Fazemos entao um loop while()
                      -Enquanto: 
                        num_control seja maior que 0 e nao encontremos um \n dentro de buffer_lectura...Faremos:
                            num_control recebe o resultado numerico da 
                            funcao read(vai retornar quantas letras leu, ou seja: a quantidade de BUFFER_SIZE valor em numero, e vai escreve-las dentro de buffer_lectura em caracteres)

                      *Verificamos se num_control é -1, isto que dizer que nossa funcao read(-1) encontrou um erro e nada foi lido. Entao com este resultado, liberamos buffer_lectura com free() normal, e retornamos liberando com my_free(&static), pois nossa static pode haver datos lidos ex: return(my_free(&static)).

                      *Se o num_control é maior que 0, entao obtemos leitura e nosso buffer_lectura tem conteúdo, entao adicionamos um '\0' no indice final de buffer_lectura, assim indicamos que finalizamos uma string. Em seguida nossa static recebe um strjoin(static, buffer_lectura) salvando um pedaço de linha lida e também temos um checkpoint da ultima leitura, porque o proximo passo será cortar o resultado lido até o primeiro \n.
                }
                *Liberamos(buffer_lectura);
                *retornamos(static);

4-Verificamos se nossa static contem algo lido
    *Se static nao tem nada, retornamos NULL.

5-Agora utilizamos nossa variavel char *linha de retorno
    *linha de retorno recebe um ponteiro char * do retorno de uma funcao que vai processar os datos lidos da nossa static
     -  linha = funcao(static)
        {
            *Criamos um novo char *line, para manipular a transferência de static -> line.
            *Criamos um indice inteiro (int i = 0), iniciamos a 0, pois pode conter numeros aleatorios.

            *Verificamos se existe nossa static, para garantir que nao iremos cometer erros, caso nao exista, simplesmente retorna NULL, e Tudo se acaba por aqui.

            *Se static tem conteúdo, entao fazemos um loop while():
                -Enquanto: 
                   Nossa static na posicao de i nao seja igual a \n e também nao seja o fim da static:
                   somamos valor a i, i += 1, ou um atalho: i++;
                   chegamos a nao cumprir com a condiçao?, o loop quebra, mas devemos somar i uma vez mais, porque queremos guardar \n e prevenir que \0 enteja depois de \n.
                
                *Saindo do loop finalizado completamente ou interrompido, entao fazemos um substring de static desde o inicio até o ultimo valor de i. O prototipo da funcao é substring(char *static, posicao inicial da string que é 0, e passmos i que terá um valor que foi somado);
                
                *Retornamos line.

        }
    #Agora linha pode ter lido algo ou nao.

    *Se linha nao leu nada
      -liberamos static e entao retornamos NULL.
        podemos usar um free() ou um especial_free se quiser personalizar, e Tudo se acaba por aqui.
    
    *Caso linha tenha recebido corretamente o resultado da funcao anterior entao vamos ao passo 6 a seguir.

6-Nossa static agora recebe um char * de uma funcao que vai atualizar o valor da static, esta atualizacao ocorre para apagar ate o primeiro \n encontrado e guardar apenas o que sobrou, lembrando que devemos sempre adicionar um \0 no final da string sobrante. O prototipo sera char *funcao(char *static)
   
     *Assim seria em codigo:
        static = funcao_atualizar_static(static);

        Exemplo do que faz a funcao_atualizar_static(static)

            char    *funcao(char *static)
            {
                #Aplicamos a logica aqui.

                *Criamos uma nova variável de retorno de tipo char *nova_linha.
                *Criamos tambem um indice para contar posicoes: (int i = 0).

                  Nosso indice i vale 0;

                  fazemos um controle se static existe, se static nao tem valor nenhum, retornamos NULL, e tudo termina por aqui.
                  
                  *Caso contrário iremos iniciar um loop while() com as seguintes condicoes:
                    -Enquanto: 
                       static na posicao de i, ou seja, posicao inicial, é diferente de \n e também nao chegou ao indice final, entao:
                            somamos i =+ 1;
                    *Completamos o loop ou foi interrompido, somamos i =+ 1 denovo, porque queremos garantir que \n esteja dentro da static, para logo fazer uma substring(static, i, strlen(static)), o valor retornado por esta substring será recebido por nova_linha, feito isto liberamos static com free(static), e retornamos nova_linha que conterá o valor sobrado que estava após o primeiro \n
                    exemplo: 
                            imagine que temos: "Ola'\n'tudo";
                            linha leu e retornou: "Ola'\n'"; #Oquê faremos com o resto?
                            Exatamente o que esta funcao faz:
                              nova_linha conterá: "tudo"
            }

7-Finalmente retornamos linha de retorno.
    return (line);


