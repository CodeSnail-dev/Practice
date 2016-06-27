#!/usr/bin/perl

use strict;
my $str1 = "VDE_CN_20160308//State_14120031/POI_1414003195.xml";
my $str2 = $str1;
my ($str3) = $str1 =~ s/VDE/abc/g;


print "\n";
print '$str1 = '.$str1;
print "\n";
print '$str2 = '.$str2;
print "\n";
print '$str3 = '.$str3;
print "\n";
