LA TEORIA DELLA DUALITÀ (3)
===========================

In questa lezione saranno enunciati i principali teoremi della teoria
della dualità.

Il duale del problema duale
---------------------------

**Teo (i)**: Il duale del problema duale è il problema primale.

Dato un problema primale si formuli il suo problema duale. Riconducendo
il problema duale alla forma primale e applicando le corrispondenze
viste nella lezione precedente si riotterrà una formulazione equivalente
del problema primale di partenza.

Teorema della dualità in forma debole
-------------------------------------

**Teo (ii)**: Data una coppia di problemi l’uno duale dell’altro ed
entrambi dotati di soluzioni ammissibili *x*’ e *y*’, allora si ha che
<img src="media/image1.wmf" style="width:0.81944in;height:0.23611in" />
per ogni soluzione ammissibile del primale e del duale, dove z è la
funzione obiettivo del problema primale di massimo e ν la funzione
obiettivo del problema duale di minimo.

*Dimostrazione*: Si considerino il problema primale

<img src="media/image2.wmf" style="width:0.97222in;height:0.72222in" />

e il suo problema duale

<img src="media/image3.wmf" style="width:0.94375in;height:0.77778in" />

Ipotizziamo che
<img src="media/image4.wmf" style="width:0.16667in;height:0.19375in" />e
<img src="media/image5.wmf" style="width:0.18056in;height:0.22222in" />
siano soluzioni ammissibili rispettivamente per il primale e per il
duale e quindi avremo: .

Moltiplicando il vincolo del problema primale per il numero non negativo
<img src="media/image7.wmf" style="width:0.26389in;height:0.25in" /> e
moltiplicando il vincolo del duale per il numero non negativo
<img src="media/image8.wmf" style="width:0.25in;height:0.25in" /> si
ottiene:

<img src="media/image9.wmf" style="width:0.58333in;height:0.5in" /><img src="media/image11.wmf" style="width:1.15278in;height:0.52778in" />

Le espressioni a desta del simbolo di diseguaglianza, e , sono uguali in
quanto prodotto scalari di *Ax*’ e *y*’.

Il valore è il valore della funzione obiettivo del problema primale in
quanto trasposto di mentre è il valore della funzione obiettivo del
problema duale.

<img src="media/image17.wmf" style="width:1.44375in;height:0.25in" />
poiché sappiamo che
<img src="media/image18.wmf" style="width:1.15278in;height:0.25in" /> si
ha che:
<img src="media/image19.wmf" style="width:1.13889in;height:0.25in" />.
Ora essendo: si ottiene che
<img src="media/image21.wmf" style="width:0.95833in;height:0.25in" />.
Poiché per ipotesi
<img src="media/image22.wmf" style="width:2.09653in;height:0.25in" />.
Visto però che
<img src="media/image23.wmf" style="width:1.36111in;height:0.25in" />
allora si ha che:

<img src="media/image1.wmf" style="width:0.81944in;height:0.23611in" />
∎

Relazioni fra ottimo primale e ottimo duale
-------------------------------------------

**Teo (iii)**: Se il problema primale di programmazione lineare o il
problema duale di programmazione lineare hanno una soluzione ottima
illimitata, allora il problema associato (rispettivamente duale o
primale) non ha soluzioni ammissibili.

*Dimostazione*: Se il problema primale di massimo tende a +∞, il duale
non può tendere ad un numero finito, in quanto deve essere maggiore del
primale. Il duale di un problema di massimo è un problema di minimo, che
non può tendere a +∞. Ne segue che l’insieme delle soluzioni del
problema duale è l’insieme vuoto. ∎

**Teo (iv)**: Se una coppia di problemi primale e duale di
programmazione lineare ammettono entrambi soluzioni ammissibili allora
ammettono soluzioni ottime finite.

*Dimostrazione*: Per ipotesi esistono soluzioni ammissibili *x*’ e *y*’,
rispettivamente per il primale e per il duale, e quindi il teorema della
dualità debole assicura che
<img src="media/image1.wmf" style="width:0.81944in;height:0.23611in" />.
Allora qualsiasi soluzione ammissibile del problema duale è un limite
superiore per il problema primale, che pertanto non può essere
illimitata superiormente. Analogamente il duale non può essere
illimitato inferiormente in quanto ogni soluzione ammissibile del
primale è un limite inferiore per il duale. ∎

**Teo (v)**: Entrambi i problemi primale e duale possono non avere
soluzioni ammissibile.

Se un problema non ha soluzioni ammissibili ciò non è sufficiente per
affermare che il suo duale sia illimitato. Basta un esempio per
affermare la validità di questo teorema.

Esempio:

<img src="media/image25.wmf" style="width:2.77639in;height:2.74792in" />

Regione ammissibile dei problemi (*P*) e (*D*) è l’insieme vuoto.

∎

Dal teorema della dualità in forma debole si ricavano le seguenti
relazioni:

PRIMALE OTTIMO FINITO DUALE OTTIMO FINITO

PRIMALE NON LIMITATO DUALE NON AMMISSIBILE

DUALE NON LIMITATO PRIMALE NON AMMISSIBILE

PRIMALE NON AMMISSIBILE DUALE NON LIM. O NON AMM.

DUALE NON AMMISSIBILE PRIMALE NON LIM. O NON AMM.

Teorema della dualità in forma forte
------------------------------------

**Teo (vi)**: Data una coppia di problemi primale e duale, condizione
necessaria e sufficiente perché una soluzione ammissibile
*x*<sup>\*</sup> del primale (o *y*<sup>\*</sup> del duale) sia ottima è
che esiste almeno una soluzione ammissibile *y*<sup>\*</sup> del duale
(o *x*<sup>\*</sup> del primale) tale che *c<sup>T</sup> x*<sup>\*</sup>
= *b<sup>T</sup> y*<sup>\*</sup>. La *y*<sup>\*</sup> e la
*x*<sup>\*</sup> sono soluzioni ottime del problema duale e primale.

*Dimostrazione*:

(Sufficienza) Si consideri il problema primale di massimo. Nell’ipotesi
che si ha, per la dualità in forma debole, che e quindi *x*<sup>\*</sup>
è soluzione ottima del problema primale . Analogamente e quindi
*y*<sup>\*</sup> è soluzione ottima del problema duale. □

(Necessità) Nell’ipotesi che *x*<sup>\*</sup> e *y*<sup>\*</sup> siano
soluzioni ottime del primale e del duale, riportando il primale ad un
problema di minimo

il cui duale è

Volendo dimostrare che all’ottimo *z*(*x*) = *ν*(*y*) consideriamo la
tabella della forma matriciale del simplesso che si ricava partizionando
la matrice *A* dei vincoli in matrice di base *B* (non singolare) e
matrice non di base *N*, le variabili in variabili di base
(*x*<sub>*B*</sub>) e variabili non di base (*x*<sub>*N*</sub>) e i
coefficienti di costo in coefficienti in corrispondenza delle variabili
di base (*c*<sub>*B*</sub>) e coefficienti in corrispondenza delle
variabili non in base (*c*<sub>*N*</sub>). Quindi partizionando in
questo modo, il problema di programmazione lineare può essere riscritto
nella seguente forma:

$\\begin{matrix}
\\text{Bx}\_{B} + \\text{Nx}\_{N} = b \\\\
x\_{B} \\geq 0,\\ x\_{N} \\geq 0 \\\\
\\end{matrix}$

alla quale corrisponde la seguente matrice tableau dopo aver calcolato
*x*<sub>*B*</sub> dai vincoli e sostituito nella funzione obbiettivo:

<table>
<tbody>
<tr class="odd">
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td></td>
<td>I</td>
<td></td>
</tr>
</tbody>
</table>

Per il criterio di ottimalità sulla tabella primale la soluzione di base
è ottima se:

-   i coefficienti di costo ridotto delle variabili di base sono nulli:

0<sup>*T*</sup> = *c*<sub>*B*</sub><sup>*T*</sup> − *c*<sub>*B*</sub><sup>*T*</sup>*B*<sup> − 1</sup>*B*,
essendo *B*<sup> − 1</sup>*B* = *I*

-   le variabili fuori base devono avere i coefficienti non negativi:  
    (*c*<sub>*N*</sub><sup>*T*</sup>−*c*<sub>*B*</sub><sup>*T*</sup>*B*<sup> − 1</sup>⋅*N*) ≥ 0

Mettendo a sistema queste due condizioni si ha:

Considerando elemento per elemento il vettore dei costi ridotti
all’ottimo deve risultare
*c*<sup>*T*</sup> = *c*<sup>*T*</sup> − *c*<sub>*B*</sub><sup>*T*</sup>*B*<sup> − 1</sup>*A* ≥ 0.
Da questa espressione si ricava che:
(*c*<sub>*B*</sub><sup>*T*</sup>*B*<sup> − 1</sup>) *A* ≤ *c*<sup>*T*</sup>
posto quindi come vettori riga il vettore:
*y*<sup>*T*</sup> = (*c*<sub>*B*</sub><sup>*T*</sup>*B*<sup> − 1</sup>) 
(se il problema di partenza è di minimo) si ottiene
*y*<sup>*T*</sup>*A* ≤ *c*<sup>*T*</sup>.

Facendo il trasposto di tale espressione otteniamo
*A*<sup>*T*</sup>*y* ≤ *c* che viene definita relazione
dell’ammissibilità duale.

Quindi visto che dalla forma matriciale del simplesso
*z* = (*c*<sub>*B*</sub><sup>*T*</sup>⋅*B*<sup> − 1</sup>) ⋅ *b* per la
relazione dell’ammissibilità duale abbiamo che:
*z* = *y*<sup>*T*</sup> ⋅ *b* e visto che nel duale
*ν* = *y*<sup>*T*</sup> ⋅ *b* si può vedere che i due risultati sono
uguali e di conseguenza si ha che *z*(*x*) = *ν*(*y*).

Nota: la tabella ottima del primale è stata ottenuta trasformando il
problema di partenza in un problema di minimo e quindi le variabili
duali vanno cambiate di segno se si riferiscono al problema di partenza
. ∎

**Cor**: Se una coppia di problemi di programmazione lineare primale e
duale ammettono soluzioni ammissibili allora entrambi hanno soluzioni
ammissibili ottime ed all’ottimo i valori assunti dalla funzione
obiettivo sono uguali.
