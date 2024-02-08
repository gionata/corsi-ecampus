# file: modello_algebrico.mod
# Model section
set Prodotti;			# Insiemi
set Risorse;
var x {j in Prodotti} >= 0;	# Variabili decisionali
param profitto {j in Prodotti};	# Parametri
param disponibilita {i in Risorse};
param assorbimento {i in Risorse, j in Prodotti};
maximize f_o: sum {j in Prodotti} profitto[j]*x[j]; # F. obiettivo
s.t.   capacita {i in Risorse}:	# Vincoli. Uno per risorsa
	sum {j in Prodotti} assorbimento[i, j]*x[j]
		<=  disponibilita[i];
end;

