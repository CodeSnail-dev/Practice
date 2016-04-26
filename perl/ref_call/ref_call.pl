#!/usr/bin/perl

my $scalar = 1 ;
my @array = (1, 2, 3) ;
my %hash = ('zdd' => 30, 'autumn' => 27) ;

my $sref = \$scalar ;   # scalar reference
my $aref = \@array ;    # array reference
my $href = \%hash ;     # hash reference

# 方法一
print $$sref, "\n" ;# 用$sref代替sref
print @$aref, "\n" ;# 用$aref代替aref 
print %$href, "\n" ;# 用$href代替href
