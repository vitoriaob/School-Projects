

(*Homework 2*)

(*------------------Exercise 1-----------------------*)

datatype expr = NUM of int
	      | PLUS of expr * expr
	      | MINUS of expr * expr;
	      
datatype formula = TRUE
		 | FALSE
		 | NOT of formula
		 | ANDALSO of formula * formula
		 | ORELSE of formula * formula
		 | IMPLY of formula * formula
		 | LESS of expr * expr;

(*Auxiliary function to perform the operations of the type expr, will be needed in the LESS case for the eval function*)
fun operation(NUM(o1)) = o1
		| operation(PLUS(o1, o2)) = operation(o1)+operation(o2)
		| operation(MINUS(o1, o2)) = operation(o1)-operation(o2);
		

fun eval(TRUE) = true
	      | eval(FALSE) = false
	      | eval(NOT(e1)) = not (eval e1)	
	      | eval(ANDALSO(e1,e2)) = (eval e1) andalso (eval e2)
	      | eval(ORELSE(e1,e2)) = (eval e1) orelse (eval e2)
	      | eval(IMPLY(e1,e2)) = not(eval e1) orelse (eval e2)
	      | eval(LESS(e3,e4)) = operation(e3) < operation(e4);
	      
	      
	      
(*-------------Exercise 2--------------*)
type name = string

datatype metro =  STATION of name
		| AREA of name * metro
		| CONNECT of metro * metro;
		
		

(*auxiliary function to check the list of stations in given areas*)

fun is_in_list(areas, metro) =
  let fun in_list(areas, station) = 
      if null(areas) then false 
      else in_list(tl(areas),station) orelse (hd(areas) = station) 
  in
  	case metro of  
 	   STATION n1 => in_list(areas,n1)
 	 | AREA (n1, m1) => is_in_list(n1::areas, m1)
         | CONNECT (m1, m2) => is_in_list(areas, m1) andalso is_in_list(areas, m2)
  
  end;

fun checkMetro(metro_arg) = 
  case metro_arg of
    STATION n1 => false
  | CONNECT (m1, m2) => checkMetro(m1) andalso checkMetro(m2)
  | AREA (n1, m1) => is_in_list(n1::[],m1) ;
  
  

(*--------------------------Exercise 3 ----- part(i)-------------------------------*)

datatype 'a lazyList = nullList
		     | cons of 'a * (unit -> 'a lazyList);
		     
		     
		     
fun seq(first,last) = cons(first, fn()=> seq(first+1,last));

fun infSeq first = cons(first, fn()=>infSeq(first+1));

fun firstN (lazyListVal, n) = 

    let fun it (lazyListVal, tmp, last) =
        case lazyListVal of nullList => []
         	 | cons(value, tail) =>  if tmp = last then []
				         else value::it(tail(),tmp+1,last)
    in
        it(lazyListVal,0,n)
    end;          

fun Nth(lazyList, n) =
    case lazyList of
         nullList => NONE
       | (cons(value,tmp)) => if n=1 then SOME value
       				 else Nth(tmp(), n-1);
 
 
 fun filterMultiples(lazyListVal, n) =
		case lazyListVal of nullList => nullList
		|cons(first,last) => if first mod n = 0 then filterMultiples(last(),n)
				     else cons(first, fn() => filterMultiples(last(),n));
				     
				     
					     
(*----------------Exercise 3 ----- part(ii)------------------*)

(*auxiliary function with sieve method*)

fun sieve(lazyListVal) =
	case lazyListVal of nullList => nullList
	|cons(first,last) => cons(first,fn()=> (sieve(filterMultiples(last(),first))));

fun primes() = sieve(infSeq(2));