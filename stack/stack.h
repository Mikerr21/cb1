#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define SIZE 128

/* *** Strukturen *********************************************************** */

/**@brief Struktur des Stacks.
 */
typedef struct {
    int dataOfStack[SIZE];
    int top; // pointer of the most top element of the stack
   
} IntStack;

/* *** öffentliche Schnittstelle ******************************************** */

/**@brief Initialisiert einen neuen Stack.
 * @param self  der zu initialisierende Stack
 * @return 0, falls keine Fehler bei der Initialisierung aufgetreten sind,
 *      != 0, ansonsten
 */
extern int
stackInit(IntStack *self){
    
    self->top = -1;// creation of empty stack with top point of -1
    return 0;
}
/**@brief Gibt den Stack und alle assoziierten Strukturen frei.
 * @param self  der Stack
 */
extern void
stackRelease(IntStack *self){

    for (int i=0;i<=self->top;i++){

     self->dataOfStack[i]=0;
    }
}
/**@brief Legt einen Wert auf den intstack.
 * @param self  der intstack
 * @param i     der Wert
 */
extern void
stackPush(IntStack *self, int i){
    if ( self->top != SIZE-1){
        self-> top = self->top+1 ;
        self-> dataOfStack[self->top] = i;  
    } 
    else {
        printf("Fehlermeldung, da IntStack voll")
    }
}
/**@brief Gibt das oberste Element des Stacks zurück.
 * @param self  der Stack
 * @return das oberste Element
 */
extern int
stackTop(const IntStack *self){
   if(self->top==-1) {
     printf("<<Fehlermeldung, da IntStack leer>>");
}
        return self->dataOfStack[self->top];
    
}

/**@brief Entfernt und liefert das oberste Element des Stacks.
 * @param self  der Stack
 * @return das oberste Element
 */
extern int
stackPop(IntStack *self){
    if(self->top==-1) {
     printf("<<Fehlermeldung, da IntStack leer>>");
}
  return self->dataOfStack[self->top--]; //decrement stack size by 1 and return that element
}

/**@brief Gibt zurück, ob der Stack leer ist.
 * @param self  der Stack
 * @return 0, falls nicht leer,
        != 0, falls leer
 */
extern int
stackIsEmpty(const IntStack *self){
    if ( self->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

/**@brief Gibt den Inhalt des Stacks beginnend mit dem obersten Element auf der
 * Standardausgabe aus.
 * @param self  der Stack
 */
extern void
stackPrint(const IntStack *self){
    
	printf("The elements of the stack are:");
	for(int i=self->top ;i>=0;i--)
	{
		printf("%d ",self->dataOfStack[i]);
		 
	}
	printf("\n");	
}

#endif /* STACK_H_INCLUDED */
