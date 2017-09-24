(* print_string "Hello World\n";; *)

let x = 1 + 1;;

(* print_string (string_of_int x) *)

(* repeated "Hello" 3;; *)

(* prompt_string ("Name please: ") *)

(* here is a comment *)

(*
Here is a multeline comment
*)

(* print_string x;; *)

let average a b = (a +. b) /. 2.0

let x = average 30.1985 20.678;;

(* print_string (string_of_float x ^ "\n");; *)


let rec sumTo (n:int) :int=
  match n with
    0 -> 0
    | n-> n + sumTo (n-1)

let y = sumTo 5;;

(* print_string (string_of_int y ^ "\n");; *)

(* let rec quicksort = function
    | [] -> []
    | x::xs -> let smaller, larger = List.partition (fun y -> y < x) xs
               in quicksort smaller @ (x::quicksort larger)
 *)
(* if true then 7;; *)

(*
    Exercise I 
- 7 * (1 + 2 + 3)
- "cs" ^ string_of_int (400 * 10 + 700)
- (+) 22 20
- (fun zar -> zar*zar) 42
*)

(* first_value = 7 * (1 + 2 + 3);; *)

(* Exercise II *)

(* 1. Make it so that x equals 42 by adding *)

(* Exercise III *)

(* Why doesn't the expression below tpe check? what small change can you make to it so *)

(* Day Two *)

(* Define a function, inc that increments its integer argument x
- x + 1 *)

let inc x = x + 1;;

(* Define a function, sum that returns the sum of two integers x and y
- x + y *)

let sum x y = x + y;;

(* Define a function, twice that takes an argument x from a function f and applies f twice
- f(f(x)) *)

let twice f x = f(f(x));;



(* let wtwice x = f = f x *)