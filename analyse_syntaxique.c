#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "analyse_lexicale.h"
#include "analyse_syntaxique.h"




void analyser( char * fichier){
  Etat etat=DEB;
  demarrer(fichier);
  Lexeme lex;
  while( !fin_de_sequence() && etat != ERR){
    lex=lexeme_courant();
    switch (etat) {
      case DEB :
      switch (lex.nature) {
        case ENTIER :
        etat=ACC;
        break;
        case MUL :
        case DIV :
        case PLUS :
        case MOINS :
        etat=ERR;
        break;
        default :
        break ;
      }
      break;
      case ACC :
      switch (lex.nature) {
        case ENTIER :
        etat=ERR;
        break;
        case MUL :
        case DIV :
        case PLUS :
        case MOINS :
        etat=DEB;
        break;

        default :
        break ;
      }
      break;
     default :
     break ;
    }
    avancer();
  }
  lex = lexeme_courant();
  if (etat == ACC && lex.nature == FIN_SEQUENCE) printf("SYNTAX OK ");
  else printf("ERROR !!!!!!! ,%d",etat);
}
