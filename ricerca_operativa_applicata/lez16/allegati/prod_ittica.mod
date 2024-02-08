set Specie;
set Vasche;

var x {i in Specie, j in Vasche} >= 0;
param ricavo {i in Specie} >= 0;	
param quota {i in Specie} >= 0;
param fabb_acqua {i in Specie} >= 0;
param fabb_mangime {i in Specie} >= 0;
param estensione {j in Vasche} >= 0;
param disp_acqua {j in Vasche} >= 0;
param disp_mangime >= 0;

maximize ricavo_tot:
 sum {i in Specie} ricavo[i] * (sum {j in Vasche} x[i,j]);

s.t.  sup_vasche {j in Vasche}: 
 sum {i in Specie} x[i,j] <= estensione[j];

s.t.  rinnovo    {j in Vasche}:
 sum {i in Specie} fabb_acqua[i] * x[i,j] <= disp_acqua[j];

s.t.  mangime:
 sum {i in Specie} fabb_mangime[i] * (sum {j in Vasche} x[i,j])
   <= disp_mangime;
   
s.t.  domanda {i in Specie}:
 sum {j in Vasche} x[i,j] <= quota[i];
 
s.t. equita {j in Vasche}:
 1/estensione[j]*(sum {i in Specie} x[i,j]) =
 1/estensione[if j=card(Vasche) then 1 else j+1]*
  (sum {i in Specie} x[i,if j=card(Vasche) then 1 else j+1]);

end;

