#!/usr/bin/perl

# use module
use XML::Simple;
use Data::Dumper;

# create object
my $xml = new XML::Simple;

# read XML file
my $data = $xml->XMLin("data.xml");

# print output
print Dumper($data);
