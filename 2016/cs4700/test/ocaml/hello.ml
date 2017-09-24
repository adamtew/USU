(* Mini Homework

Total 20 points

1. (2 pt) Declare a variable random with the value 17. It should have type int
2. (2 pt) Declare a variable pi with a value of 3.14159. It should have the type of float.
3. (4 pts) Write a function myFirstFun that returns the result of multiplying the sum of a given integer and 3 by 4.
# let myFirstFun n = ... ;;
val myFirstFun : int -> int = <fun>
# myFirstFun 17;;
- int = 80 
*)

let random = 17;;

let pi = 3.14159;;

let myFirstFun a = (a + 3) * 4

let new_value = myFirstFun(17);;

print_string (string_of_int new_value ^ "\n");;

(* 
4. (4 pts) Write a function circumference that, when given a radius as a float, 
  returns the circumference of a circle of that radius. You should use the value 
  given in problem 2 for π.

# let circumference r = ...;; 
val circumference : float -> float = <fun> 
# circumference 1.0;; 
- : float = 6.28318
*)

let circumference r:float = 2.00 *. pi *. r

let circumference_value = circumference 7.0;;

print_string (string_of_float circumference_value ^ "\n");;

(* 
5. (4 pts) Write a function double that takes an int and returns the pair of ints 
  where the first is the number given and the second is two times that.
# let double n = (n, 2*n);; 
val double : int -> int * int = <fun> 
# double 0;; 
- : int * int = (0, 0) 
*)

let double x = x, 2 * x

let double_value = double 0;;

print_string "\n";;

(* print_string (string_of_int double_value) *)
print_string double_value;;

(* 
  6. (4 pts) Write a function make_bigger that takes a float and if it is less than 0.0, 
      multiplies it by (-1.0) (use the parentheses), it is at least 0.0, but less 
      than 1.0, adds 0.5 to it, and if it is at least 1.0, squares it.
# let make_bigger x = ... 
val make_bigger : float -> float = <fun> 
# make_bigger 12.0;; 
- : float = 144.
*)

(* let make_bigger x:float = if x < 0.0 then (-1.0) * x else x * x;; *)
let make_bigger a = 
  if a < 0.00 then ((-1.0) *. a) 
  else if a > 0.00 && a < 1.00 then a +. 0.5
  else a*.a;;

let maket_bigger_value = make_bigger(12.0);;

print_string (string_of_float maket_bigger_value ^ "\n");;

