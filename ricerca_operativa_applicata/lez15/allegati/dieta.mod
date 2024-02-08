# file: dieta.mod
# Model section
set Nutrienti;			# Insiemi
set Alimenti;
var x {j in Alimenti} >= 0;	# Variabili decisionali
param costo {j in Alimenti};	# Parametri
param req_nutrizionale {i in Nutrienti};
param apporto {i in Nutrienti, j in Alimenti};
minimize f_o: sum {j in Alimenti} costo[j]*x[j]; # F. obiettivo
s.t.    requisito {i in Nutrienti}:  # Vincoli. Uno per nutriente
	sum {j in Alimenti} apporto[i, j]*x[j]
		>=  req_nutrizionale[i];
end;

