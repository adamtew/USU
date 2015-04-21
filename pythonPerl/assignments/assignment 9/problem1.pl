# 1) Write a Perl script that takes a scalar for the upper bound u from the user and returns the sum of all the multiples
# of 3 or 5 in the interval [1, u). For example, the sum of the multiples of 3 or 5 in [1, 10) is 23.

print "Enter the first value: ";
my $first = <STDIN>;
# my $first = 1;
print "Enter the second value: ";
# my $second = 10;
my $second = <STDIN>;
my $total = 0;

print "Within that range, the numbers divisible by 5 and 3 are: \n";
for($i = $first; $i < $second; $i++){
	if($i % 3 == 0 || $i % 5 == 0){
		print "$i, ";
		$total += $i;
	}
}

print "and your total is $total\n";