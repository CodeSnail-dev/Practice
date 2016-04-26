#!/usr/bin/perl

# use module
use XML::Simple;
use Data::Dumper;

#create object
$xml = new XML::Simple(KeyAttr=>[]);

#read XML file
$data = $xml->XMLin("data.xml");

# dereference hash ref
# access <employee> array
foreach $e (@{$data->{employee}})
{
	print $e->{name}, "\n";
	print "Age/Sex: ", $e->{age}, "/", $e->{sex}, "\n";
	print "Department: ", $e->{department}, "\n";
	print "\n";
}
