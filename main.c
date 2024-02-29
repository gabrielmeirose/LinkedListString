#include "string.h"

int main(){

    // Exemplo de Uso

    // Criação de Strings
    String texto = dynamicStr("Hello World!");
    printString(&texto);

    // Junção de Strings
    String ola = dynamicStr("Ola, ");
    String nome = dynamicStr("Claudio!");

    String join = joinStr(ola, &nome);

    printString(&join);

    // Visualização de StringNodes
    char c = getById(&join, 3)->info;
    printf("String[2]: %c\n", c);

    // Modificação de StringNodes
    changeById(&join, 3, ':');

    printString(&join);

    c = getById(&join, 3)->info;
    printf("String[2]: %c\n", c);


    return 0;
};