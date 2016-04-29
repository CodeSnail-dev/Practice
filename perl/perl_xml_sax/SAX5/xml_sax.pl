#!/usr/bin/perl

use XML::SAX;
use MySAXHandler;

my $parser = XML::SAX::ParserFactory->parser(
      Handler => MySAXHandler->new
);

#$parser->parse_uri("sample.xml");
$parser->parse_uri("/mnt/hgfs/share/project/tools/VcaTool_Yangzi/compiler/program/tmp/VDE_CN_20160308/State_14120001/POI_1414000001.xml");
