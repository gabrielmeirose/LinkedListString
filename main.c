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
    printf("-> String[2]: %c\n", c);

    // getById, changeById e removeById retornam os StringNodes originais

    // Modificação de StringNodes
    changeById(&join, 3, ':');
    printString(&join);

    // Remoção de StringNodes
    for(int i = 4; i>=0; i--){
        removeById(&join, i);
    }

    printString(&join);

    return 0;
};