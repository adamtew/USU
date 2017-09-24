let rec sum (x : int list) : int =
  match x with
  | [] -> 0
  | x :: tail -> x + (sum tail) ;;

sum([5; 6]);;

(* 
  Given a list of pairs of integers, produce the list of products of the pairs:

  prods [(2,3); (4,7); (5,2)] -> [6;28;10]
*)

let rec prods (x : (int * int) list) : int list =
  match x with
  | [] -> []
  | (a, b) :: tail -> a * b :: prods tail ;;

prods [(1, 2); (3, 4); (5, 6)];;

(* let rec countlist list =
  match list with
  | [] -> 0
  | x :: tail -> 1 + (countlist tail);; *)


(* 
Write a function to append two lists
- append[1; 2; 3][4; 5; 6] -> [1; 2; 3; 4; 5; 6]
*)

(* let rec append x y =
  match x, y with
  | [] -> [] *) 

(* Accessing variables by reference *)

let c = ref 0 ;;

let x = !c ;;

c := 42 ;;

let y = !c ;;



(* What does w evaluate to? *)

let x = ref 42 ;;
let y = ref 42 ;;
let z = x ;;
let x = 43 ;;
let w = (!y) + (!z) ;; (* 84 *)

(* What does w evaluate to? *)

let x = ref 42 ;;
let y = ref 42 ;;
let z = x ;;
x := 43 ;;
let w = (!y) + (!z) ;; (* 85 *)


(* Concurrency *)