# 2) Write a Perl script that computes and prints out the smallest integer 
# greater than 0 that is evenly divisible by all numbers in [1, 20]. 
# You may want to use the keyword last to break out of the loop and the keyword die to terminate the script.

my $theOne = (2 ** 4) * (3 ** 2) * 5 * 7 * 11 * 13 * 17 * 19; # here's your number.
print "the number without looping: $theOne\n";

for($i = 1; $i < 232792561; $i++){
	for($j = 1; $j <= 20; $j++){
		if($i % $j == 0){
			$theOne = $i;
			if($j == 20){
				print "$theOne\n";
				die;
			}
		}
		else{
			last;
		}
	}	
}

print "The number with looping: $theOne\n";