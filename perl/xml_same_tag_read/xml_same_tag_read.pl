#!/usr/bin/perl

use XML::Simple qw(:strict);
#use XML::Simple;
use strict;
use Data::Dumper;

my $xml = new XML::Simple;
my $data = $xml->XMLin("data.xml", KeyAttr => {employee => "department"}, ForceArray => ['employee', ]);

print Dumper($data);
#print "$data->{employee}->[0]->{name}";
print "\n";
print $data->{employee}->{Operations}->{name};
print "\n";
#print "$data->{employee}->[2]";
#print "$data->{employee}->";
