//onsidere o seguinte programa e responda:

   #include <stdio.h> 
   int a=0; 
   void p(int,int); 

   void main(){
      int a = 1;
      p(a,a);
   } 

   void p(int b, int c){
      a = a+1; 
      b = b+1; 
      c = c+1; 
      printf("%d\n",a+b+c);
   }
/*(a) Qual será o valor impresso?
O valor impresso será 5, já que o "a" se trata de uma variável global - que será modificada só localmente - e as variáveis "b"/"c" receberam o mesmo valor de "a = 1" - por passagem por valor - somado a 1.

(b) Suponha que a função p seja modificada para passar os parâmetros por referência. A nova assinatura da função ficaria: void p(int *b, int *c){...}. Nesse caso, qual seria o valor impresso?
O valor impresso seria 7, já que o "b" e "c" receberam a referência do "a" declarado na main que valia 1 até então (depois passa a valer 3 com os incrementos em "b" e "c"). Depois o conteúdo da referência de "b" e "c" - 3 - é somado ao conteúdo do "a" declarado na função. Logo, a + *b + *c = 1 + 3 + 3 = 7.*/