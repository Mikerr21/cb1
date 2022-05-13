#ifndef SYNTREE_H_INCLUDED
#define SYNTREE_H_INCLUDED
#define MAX_SIZE = 128;

/* *** Strukturen *********************************************************** */

typedef int SyntreeNodeID;

/**@brief Struktur des abstrakten Syntaxbaumes.
 */
typedef struct {
    int literalKnoten[MAX_SIZE];
    int value;
    int nodes[MAX_SIZE];
    SyntreeNodeID *id;
} Syntree;

/* *** öffentliche Schnittstelle ******************************************** */

/**@brief Initialisiert einen neuen Syntaxbaum.
 * @param self  der zu initialisierende Syntaxbaum
 * @return 0, falls keine Fehler bei der Initialisierung aufgetreten sind,
 *      != 0 ansonsten
 */
extern int
syntreeInit(Syntree *self){
    if ( self->id!=0){
       self->id=0;
     return 0
    }
    else return -1;
};

/**@brief Gibt den Syntaxbaum und alle assoziierten Strukturen frei.
 * @param self  der freizugebende Syntaxbaum
 */
extern void
syntreeRelease(Syntree *self){
     self = NULL;
     
};

/**@brief Erstellt einen neuen Knoten mit einem Zahlenwert als Inhalt.
 * @param self    der Syntaxbaum
 * @param number  die Zahl
 * @return ID des neu erstellten Knoten
 */
extern SyntreeNodeID
syntreeNodeNumber(Syntree *self, int number){          // Alle LiteralKnoten in einem eigenen Array einsetzen und id inkrementieren, 
  if ( number !=NULL){
     self->value=number;
     self->literalKnoten[self->id]=self->value
     self->id=+1: 
  }
    return self->id; 
};

/**@brief Kapselt einen Knoten innerhalb eines anderen Knotens.
 * @param self  der Syntaxbaum
 * @param id    der zu kapselnde Knoten
 * @return ID des neu erstellten Knoten
 */
extern SyntreeNodeID
syntreeNodeTag(Syntree *self, SyntreeNodeID id){
     if ( id!=NULL){
     self->nodes[self->id+1]=self->literalKnoten[self->id];
     }
     return self->id=+1;
};

/**@brief Kapselt zwei Knoten innerhalb eines Knoten.
 * @param self  der Syntaxbaum
 * @param id1   erster Knoten
 * @param id2   zweiter Knoten
 * @return ID des neu erstellten Knoten
 */
extern SyntreeNodeID
syntreeNodePair(Syntree *self, SyntreeNodeID id1, SyntreeNodeID id2){
    if ( ( id 1== id2) || ( id1==NULL) || ( id2==NULL) ){
       return -1;
    }
   
};


/**@brief Hängt einen Knoten an das Ende eines Listenknotens.
 * @param self  der Syntaxbaum
 * @param list  Listenknoten
 * @param elem  anzuhängender Knoten
 * @return ID des Listenknoten
 */
extern SyntreeNodeID
syntreeNodeAppend(Syntree *self, SyntreeNodeID list, SyntreeNodeID elem){
    
     self->data[list][list]={elem};
     self->pointer = self->pointer+1
    
    return pointer; 
};

/**@brief Hängt einen Knoten an den Anfang eines Listenknotens.
 * @param self  der Syntaxbaum
 * @param elem  anzuhängender Knoten
 * @param list  Listenknoten
 * @return ID des Listenknoten
 */
extern SyntreeNodeID
syntreeNodePrepend(Syntree *self, SyntreeNodeID elem, SyntreeNodeID list);

/**@brief Gibt alle Zahlenknoten rekursiv (depth-first) aus.
 * @param self  der Syntaxbaum
 * @param root  der Wurzelknoten
 */
extern void
syntreePrint(const Syntree *self, SyntreeNodeID root);

#endif /* SYNTREE_H_INCLUDED */
