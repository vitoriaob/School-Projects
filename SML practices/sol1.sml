


(*Auxiliry Functions for Homework 1*)

(*Concatenate 2 integer lists*)
fun concat(x: int list, y: int list) = 
    if x = [] then y
    else (hd x):: concat((tl x), y); 
    
(*Factorial*)
fun f 0 = 1 |
    f n = n * f(n-1);
    
(*Sums the values on an integer lists*)
fun sumList(L: int list) =
    if null (tl L) then hd L
    else hd L + sumList(tl L);
    
 
    
(*Homework 1 Functions*)


fun merge(L1 : int list, L2 : int list) = 
    if null L2 then L1
    else if null L1 then L2
    else if (hd L1) < (hd L2)  then (hd L1)::merge(tl L1, L2)
    else (hd L2)::merge(L1, tl L2);

fun reverse(L: int list) =
    if null L then L
    else concat(reverse(tl (L)),[hd(L)]);
    
fun pi (a : int, b : int, f)=
    if a = b then (f b)
    else (f b ) * pi(a,b-1,f);
    
fun digits(x: int)=
    if x < 10 then concat([x],[])
    else concat(digits(x div 10),[x mod 10]);  

fun additivePersistence(n: int)=
    if n < 10 then 0
    else 1 + (additivePersistence(sumList(digits(n))));

fun digitalRoot(n: int) =
    if (sumList(digits(n))) < 10 then (sumList(digits(n)))
    else digitalRoot(sumList(digits(n)));