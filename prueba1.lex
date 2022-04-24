%{
    #include<stdio.h>
    #include<string.h>
    void revisar(char *);

    struct nodo{
    char *data;
    struct nodo *sig;

    };

    struct cola {
        struct nodo *cabeza,*cola;
    };

    void insertar_expresion();
    struct cola *p ;
    int cont = 0;

%}

logica (\\neg|\\wedge|\\vee|\\rightarrow|\(|\))
proposicion (v_[1-9][0-9]*)
%%
         
{logica}   {insertar_expresion();
            cont++;}

{proposicion}   {insertar_expresion(cont);
                cont++;}
%%

//Inicializa la cola
struct cola *crear_cola(){
    struct cola *p = (struct cola *)malloc(sizeof(struct cola *));
    p -> cabeza  = p -> cola = NULL;
    return p;
}

//Crea un nuevo nodo
struct nodo *nuevo_nodo(char *info){
    struct nodo *temp=(struct nodo*)malloc(sizeof(struct nodo));
    temp->data = malloc(sizeof(char *));
    strcpy(temp-> data,info);
    temp->sig = NULL;
    return temp;
}

//Inserta un nuevo item en la cola
void insertar(struct cola *p, char *info){
    //printf("pase por aca");
    struct nodo *aux = nuevo_nodo(info);
    if(p->cola == NULL){
        p->cabeza = p -> cola = aux;
        return;
    }

    p -> cola -> sig = aux;
    p -> cola = aux;
    printf("\nNodo insertado\n");
}


//Funcion para insertar expresion desde lex
void insertar_expresion(){
    char *str;
    str = malloc(sizeof(char *));
    strcpy(str,yytext);
    insertar(p,str);
}

//Funcion para mostrar la cola
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


void notacion_postfix(struct cola *p){
    /*
        pila 
        leer la cola
        "a+b+c*d-e"
        "ab+cd*+e-"

    */

}

int yywrap(){
    return 1;
}

int main(){

    
    p = crear_cola();
    yylex();
    mostrar_cola(p);

    printf("hay %i elementos ",cont);
    return 0;
}
