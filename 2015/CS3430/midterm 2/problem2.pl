# Problem 2 (3 points)
# Write a Perl script to take an integer from the user and determine if the input is a palindrome.

use warnings;

print "Enter value: ";
my $num = <STDIN>;



# my $num = "102";
# $num =~ $num;
my @split = split //, $num;
# my @split = split(/\d/, $num);

print "\n@split\n";

my @reverse = reverse(@split);

print "@reverse\n";

for($i = 0; $i < @split; $i++){
	if($split[$i] ne $reverse[$i]){
		print "$split[$i] != $reverse[$i] therefore this is not a palandrome\n";
		die;
	}
}

print "Looks like it's a palandrome\n";