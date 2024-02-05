# file: investimenti.mod
# Model section
set Investimenti;		# Insiemi
var x {j in Investimenti} >= 0;	# Variabili decisionali
param ritorno {j in Investimenti};	# Parametri
param minimo  {j in Investimenti};
param proporzione {i in Investimenti, j in Investimenti};
param budget >= 0;
maximize f_o: sum {j in Investimenti} ritorno[j]*x[j]; # F. o.
s.t.  capitale_investito: sum {j in Investimenti} x[j] <= budget;
      investimento_min {j in Investimenti} :   x[j] >= minimo[j];
      relazione {i in Investimenti, j in Investimenti : i<>j} :
		x[i] >= proporzione[i,j]*x[j];
end;

