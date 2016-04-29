#!/usr/bin/perl

use strict;
use File::Path;

my $FH = undef;
my $FN = undef;

$FN = "liu.txt";
open($FH, ">$FN");

print $FH "123";
