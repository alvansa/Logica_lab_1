#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int evaluacion(unsigned int resultado);

struct nodo{
    char *data;
    struct nodo *sig;

};


struct cola {
    struct nodo *cabeza,*cola;
};


struct nodo *top = NULL;


//Crea un nuevo nodo
struct nodo *nuevo_nodo(char *info){
    struct nodo *temp=(struct nodo*)malloc(sizeof(struct nodo));
    temp->data = malloc(sizeof(char *));
    strcpy(temp-> data,info);
    temp->sig = NULL;
    return temp;
}


//Inicializa la cola
struct cola *crear_cola(){
    struct cola *p = (struct cola *)malloc(sizeof(struct cola *));
    p -> cabeza  = p -> cola = NULL;
    return p;
}

void insertar(struct cola *p, char *info){
    
    struct nodo *aux = nuevo_nodo(info);
    if(p->cola == NULL){
        p->cabeza = p -> cola = aux;
        return;
    }

    p -> cola -> sig = aux;
    p -> cola = aux;
    printf("\nNodo insertado\n");
}

void mostrar_cola(struct cola *q){
    struct nodo *aux;
    if((q->cabeza == NULL ) && (q->cola == NULL)){
        printf("\nLa cola esta vacia\n");
    }else{
        printf("\nLa cola es:\n");
        aux = q->cabeza;
        while(aux){
            printf("%s ",aux->data);
            aux = aux->sig;
        }
        printf("\nNULL\n");
        
    }
}


void push(char *str){
    struct nodo *NuevoNodo = malloc(sizeof(struct nodo));
    strcpy(NuevoNodo -> data,str);

    NuevoNodo -> sig = top;


    top = NuevoNodo; 
}

void pop(){
    struct nodo *temp;

    if(top = NULL){
        printf("Pila vacia");

    }else{
        printf("%s ",top -> data);

        temp = top;

        top = top -> sig;


        free(temp);
    }
}

void infixToPostfix(struct cola *expresion){
    
    //0ro: definir el nodo pivote
        struct nodo *p, *q;
        
    //1ero: definir el stack dentro de la funcion
        struct cola *stack = crear_cola();
        q = stack->cabeza;
    //2do: definir una cola vacia dentro de la funcion
        struct cola *cola_vacia = crear_cola();
    //3ro: ciclo que revisa la cola que llega, si es operando, va a la cola vacia, sino, al stack
        if(expresion == NULL)
        {
            printf("\nExpresion vacia. ");
            exit(0);
        }
        else
        {
             p = expresion -> cabeza;
             if(p == "\\neg" || p == "\\wedge" || p == "\\vee" || p == "\\rightarrow" || p== "\("|| p == "\)" )
             {
                if(p == "\)")
                {//4to: si el operando es ")", agregar signos entre ( y ) a la cola vacia
                    //las instrucciones turbias (borrar los elementos del stack hasta un ), si se encuentra un operando, se pushea a la cola)
                    // un for, un if y un push a la cola
                    while(stack)
                    {   
                        pop();
                        if(q == "\(")
                        {
                            break;
                        }
                        q=q->sig;
                    }
                }
                 //aqui va un push a la stack
                 // push(p); 
                 strcpy(p,stack->cabeza);
             }
             else
             {
                //aqui iria un insertar a la cola vacia 
                insertar(expresion, p); 
             }
             p = p->sig;
        }
    
    
}
// logica (\\neg|\\wedge|\\vee|\\rightarrow|\(|\))

int main(){
    unsigned int a,b;
    unsigned int bin = 0b1010;
    unsigned int final;
/*
    a = 1;
    b = 0b11;
    b = b << 2  ;
    //printf("primero -> %u, segundo -> %u",a,b);
    //printf("\nBinario -> %i",bin);
    bin = bin << 1;
    //printf("\nBinario -> %i",bin);

    unsigned int bin2,basic,and,or;
    basic = 0b1;
    bin2 = 0b1;
    printf("\nEl binario original %u",bin2);
    bin2 = bin2 << 2;
    bin2 = bin2 | basic;
    bin2 = bin2 << 1;
    printf("\nEl binario transformado %u",bin2);
    and = b & ~b;
    or = b | bin2;
    or = bin2 | ~bin2;
    printf("\nLa operacion P OR Q   %u",or);
    printf("\nLa operacion P AND Q   %u",and);
    final = evaluacion(or);
    if (final == 1)
        printf("\nLa evaluacion es una tautologia....\n");
    else if(final == 0)
        printf("\nLa Expresion es una cotradiccion....\n");
    else 
        printf("\nLa expresion es una contingencia....\n");
    */

    struct cola *q = crear_cola();
    insertar(q,"v_1");
    insertar(q,"\\vee");
    insertar(q,"v_2");
    insertar(q,"\\wedge");
    insertar(q,"v_3");
    mostrar_cola(q);


    push("v_1");
    push("\\vee");
    push("v_2");
    pop();
    pop();
    
    return 0;
}

int evaluacion(unsigned int resultado){
    
    unsigned int tau,contra,conti;
    tau = 0b11111111111111111111111111111111;
    contra = 0b0;
    //printf("\nla tautologia -> %u",tau);
    //printf("\nla contradiccion es  -> %u",contra);

    printf("\ncomparacion de resultado con contra -> %u\n",(resultado & contra) & contra);

    if ((resultado & tau) == tau){
        return 1;
    }
    else if((resultado & contra) == contra){
        return 0;
    }
    else{
        return 2;
    }
    
}


// 1 and 3 or -4  impl 5 or 1
// and = -1
//or  = -2
// impl = -3
// neg = -4

// 1 -1 3 -2 