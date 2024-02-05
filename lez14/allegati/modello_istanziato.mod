# file: modello_istanziato.mod
/* variabili decisionali */
var x1 'prodotto tipo 1' >= 0;
var x2 'prodotto tipo 2' >=0;
/* Funzione obiettivo */
maximize f_o: 4*x1 + 2*x2;
/* Vincoli */
s.t.   primo: 3*x1 + 6*x2 >= 18;
s.t. secondo:   x1 - 2*x2 <=  4; 
end;

