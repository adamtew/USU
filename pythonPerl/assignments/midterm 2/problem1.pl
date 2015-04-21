# Problem 1( 3 points)
# Recall that a prime number is a natural number greater than 1 that is divisible by 1 and itself. 
# The 1st prime number is 2. The 2nd prime number is 3. The 3rd prime number is 5, etc. 
# The list of the first 500 primes is given here. 
# Write a Perl script that prompts the user for an integer i and computes the i-th prime. 
# Use your script to compute the 20,005-th prime. 
# Your script must have strict identifier scoping, i.e. all identifiers must have explicit scope declarations.

use strict;

our @primes = ();
our $index = 0;
our @prime_ = ();

for(my $i = 1; $i <= 2000; $i++){
our $p=0;
    for(my $j = 1; $j <= $i; $j++){
        if($i % $j == 0){

            $prime_[$p] = "$j";
            $p++;
        }
        if ($prime_[1] == $i){
        	@primes[$index] = $i;
        	$index++;
        }
    }
}

print "@primes\n";

print "$primes[5]\n";


our $ui = <STDIN>;
# my $ui = 20;

for(my $i = 0; $i < @primes; $i++){
	if($ui == $i){
		print "The prime number at position $i == $primes[$i]\n";
	}
	if($i == 200){
		print "The prime number at position $i == $primes[$i]\n";	
	}
}

















