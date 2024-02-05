# file: modello_instanziato.mod
/* variabili decisionali */
var x1 'prodotto tipo 1' >= 0;
var x2 'prodotto tipo 2' >=0;
/* Funzione obiettivo */
maximize    profitto_tot: 120*x1 + 40*x2;
/* Vincoli */
subject to materie_prime:  40*x1 + 20*x2 <= 2200;
s.t.              lavoro:   8*x1 +  2*x2 <=  320; 
                 mercato:     x1 +    x2 <=  100;
end;

