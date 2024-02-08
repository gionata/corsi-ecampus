#Esercio Lezione 8 Sessione di studio 2
clc
# Matrice A
disp ('Matrice di partenza')
A = [

         40         20          0       2200
          8          2          0        320
          1          1          1        100
	]

disp ('Step 1.')
## Step 1.
   # Elimino l'elemento (2, 1)
A(2, :) = A(2, :) - A(1, :) / 5;
   # Elimino l'elemento (3, 1)
A(3, :) = A(3, :) - A(1, :) / 40

disp('Step 2.')
## Step 2.
   # Elimino l'elemento (3, 2)
A(3, :) = A(3, :) + A(2, :) / 4
