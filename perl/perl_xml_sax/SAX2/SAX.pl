#!/usr/bin/perl -w
#use strict;
use XML::SAX::ParserFactory;
use XML::SAX::Writer;
use XML::SAX::ExpatXS;

my $writer = XML::SAX::Writer->new;

$XML::SAX::ParserPackage = "XML::SAX::ExpatXS";
my $parser = XML::SAX::ParserFactory->parser(Handler => $writer);

eval { $parser->parse_file('pets2.xml') };
die "can't parse Lizzie's stock file: $@" if $@;
