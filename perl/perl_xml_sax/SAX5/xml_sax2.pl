#!/usr/bin/perl

use strict;
use XML::SAX;
use MySAXHandler;

my $FH = undef;
my $FN = "ll.txt";
open($FH, ">$FN");
print $FH;

#MySAXHandler::setFileHandler($FH);
setFileHandler($FH);
MySAXHandler::setCityId("0987654321");

my $parser = XML::SAX::ParserFactory->parser(
      Handler => MySAXHandler->new
);

#$parser->parse_uri("sample.xml");
#$parser->parse_uri("Country.xml");
$parser->parse_uri("/mnt/hgfs/share/project/tools/VcaTool_Yangzi/compiler/program/tmp/VDE_CN_20160308/State_14120001/POI_1414000001.xml");
