# file: modello_algebrico_e_dati.mod
/* variabili decisionali */

set Prodotti;
set Risorse;

var x {j in Prodotti} >= 0;

param profitto {j in Prodotti};
param disponibilita {i in Risorse};
param assorbimento {i in Risorse, j in Prodotti};

/* Funzione obiettivo */
maximize f_o: sum {j in Prodotti} profitto[j]*x[j];
/* Vincoli */
s.t.   capacita {i in Risorse}:
	sum {j in Prodotti} assorbimento[i, j]*x[j] <=  disponibilita[i];

data;
set Prodotti := prod_1 prod_2;
set Risorse  := materie_prime lavoro mercato;
param profitto := prod_1 120 prod_2 40;
param disponibilita :=
	materie_prime	2200
	lavoro		 320
	mercato		 100;
param assorbimento : prod_1 prod_2 :=
	materie_prime	40 20
	lavoro		 8  2
	mercato		 1  1;

end;

