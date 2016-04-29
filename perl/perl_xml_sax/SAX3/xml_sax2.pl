#!/usr/bin/perl -w
#use strict;
use XML::SAX::ParserFactory;
use XML::SAX::Writer;
my $writer = XML::SAX::Writer->new;

$XML::SAX::ParserPackage = "XML::SAX::ExpatXS";
my $parser = XML::SAX::ParserFactory->parser(Handler => $writer);

#eval { $parser->parse_file('./pets2.xml') };
#eval { $parser->parse_file('/mnt/hgfs/share/project/tools/VcaTool_Yangzi/compiler/program/tmp/VDE_CN_20160308/City.xml') };
eval { $parser->parse_file('/mnt/hgfs/share/project/tools/VcaTool_Yangzi/compiler/program/tmp/VDE_CN_20160308/State_14120001/POI_1414000001.xml') };
die "can't parse Lizzie's stock file: $@" if $@;
