set Accessi;
set Fasi;

param q {j in Accessi} >= 0;   # portata media
param s {j in Accessi} >= 0;   # flussi di saturazione
param p {j in Accessi} >0, <1; # correzione
param Gmin {i in Fasi} >0;     # tempo minimo fase
param L {i in Fasi} >0;        # tempi persi fase
param C0 >= 0;		       # durata del ciclo
param b {j in Accessi} :=
  (q[j]*C0)/(p[j]*s[j]);       # parametro calcolato
param A {i in Fasi,
	 j in Accessi} binary; # matrice delle fasi
var G {i in Fasi} >= 0;        # tempo verde effettivo
var mu >= 0;

maximize moltiplicatore: mu;

s.t. verde_offerto {j in Accessi}:
  sum {i in Fasi} A[i,j]*G[i] >= mu * b[j];

s.t. tempo_minimo {i in Fasi}:
	G[i] >= Gmin[i];

s.t. congruenza:
 sum {i in Fasi} (G[i] + L[i]) = C0;

end;
