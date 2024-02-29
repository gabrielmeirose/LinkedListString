
// Implementação de Lista Encadeada para criação de strings

#include <stdio.h>
#include <stdlib.h>

// Struct que representa um caractere da String
typedef struct StringNode {
    char info;
    struct StringNode *proximo;
} StringNode;

// Struct que representa uma String Dinâmica
typedef struct {
    struct StringNode *primeiro;
} String;


// Mostra a string no formato "abcd..."
void printString(String *s){
    StringNode *atual = s->primeiro;

    while(atual->proximo != NULL){
        printf("%c", atual->info);
        atual = atual->proximo;
    };
    
    printf("%c\n", atual->info);
}

// Descobrir tamanho da lista
int strSize(String *s){

    if(s->primeiro == NULL){
        return 0;
    };

    StringNode *atual = s->primeiro;
    int i = 1;

    while(atual->proximo != NULL){
        i++;
        atual = atual->proximo;
    }

    return i;
}

// Retorna uma String Dicâmica para string normal
char *toStatic(String *s){ // TODO

    int size = strSize(s);
    char *str = (char *)malloc(sizeof(char) * size);

    StringNode *atual = s->primeiro;
    int i = 0;

    while(atual->proximo != NULL){
        str[i] = atual->info;
        i++;
    };

    return str;

}

// Cria um StringNode e adiciona ao final da lista
void appendStringNode(String *s, char c){
    // Passo 1: Alocar o novo item na memória com malloc

    StringNode *novo = (StringNode *)malloc(sizeof(StringNode));

    // (StringNode *) - malloc retorna um void *, então usamos casting para muda-lo para StringNode *
    // sizeof(StringNode) - determina o tamanho em bytes do struct

    if (novo == NULL){
        printf("ERRO");
        return;
    };

    //

    novo->info = c;
    novo->proximo = NULL;

    if(s->primeiro == NULL){
        s->primeiro = novo;

        return;
    };

    StringNode *ultimo = s->primeiro;

    while(ultimo->proximo != NULL){
        ultimo = ultimo->proximo;
    }

    ultimo->proximo = novo;
}

// Node com valor e proximo = NULL
StringNode strNode(char c){
    StringNode novo;

    novo.info = c;
    novo.proximo = NULL;

    return novo;
}

// Retorna uma nova string com primeiro = NULL
String initStr(){
    String novo;
    novo.primeiro = NULL;
    return novo;
}

// Cria uma string dinamica (lista encadeada) a partir de uma string normal
String dynamicStr(char c[]){

    String s = initStr();

    int i = 0;
    char current = c[i];
    while (current != '\0') {
        appendStringNode(&s, current);

        i++;
        current = c[i];
    };
    
    return s;
}

// Retorna uma referencia para ultimo caractere da String
StringNode *getLast(String *s){

    if(s->primeiro == NULL){
        printf("String Vazia");
        return NULL;
    };

    StringNode *ultimo = s->primeiro;

    while(ultimo->proximo != NULL){
        ultimo = ultimo->proximo;
    }

    return ultimo;
}

// Clona a String 1, adiciona a String 2 no final, e retorna a String 1
String joinStr(String s1, String *s2){

    StringNode *ultimo = getLast(&s1);

    ultimo->proximo = s2->primeiro;

    return s1;
}

// Retorna um StringNode baseado no id
StringNode *getById(String *s, int id){

    if(id > strSize(s)-1){
        return NULL;
    }

    StringNode *atual = s->primeiro;
    int i = 0;

    while(atual->proximo != NULL && i != id){
        atual = atual->proximo;
        i++;
    }

    return atual;
}

// Altera um StringNode baseado no id
void changeById(String *s, int id, char c){

    if(id > strSize(s)-1){
        printf("Erro - Id inválido");
        return;
    }

    StringNode *atual = s->primeiro;
    int i = 0;

    while(atual->proximo != NULL && i != id){
        atual = atual->proximo;
        i++;
    }

    atual->info = c;

}
