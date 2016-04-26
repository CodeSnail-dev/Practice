#!/usr/bin/perl

#use module
use XML::Simple;
use strict;

# create object
my $xml = new XML::Simple;

# reade XML file
my $data = $xml->XMLin("data.xml");

# access XML data
print "$data->{name}->{content} is $data->{age} years old and works in the $data->{department} section\n";

