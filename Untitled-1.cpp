#include <iostream>
#include <cstdlib>

int main() {
     
    int a = 4, opcao  = 3;
    float b = 2,5;
    char c = 'x';

        //condicao simples
    if (a == 5){
        std ::cout <<"\n A variavel a = 5";
    }
    if (b == 2,5){
        std ::cout <<"\n A variavel b = 2,5";
    }
    if (c == 'x'){
        std ::cout <<"\n variavel c = letra x";
    }
    //condicao composta, verificar valores impar e par

    if (a % 2 == 1){
        std ::cout <<"\n A variavel a eh impar: ";
    }else{
        std ::cout <<"\n A variavel a eh par: ";
    }
     
    //condicao composta
    if(opcao == 1){
        std ::cout << "\n A opcao = 1" ;
    }else if(opcao == 2){
        std ::cout <<"\n A opcao 2 " ;
    }else{
        std ::cout <<"\n A opcao nao igual a 1 e nem 2 ";
    }
    std ::cout <<"\n";
    std :: system("pause");

    return 0;
}