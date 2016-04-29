
#!/bin/perl -w

#########################################################################
#                                                                       #
#  This first example shows how to create a twig, parse a file into it  #
#  get the root of the document, its children, access a specific child  #
#  and get the text of an element                                       #
#                                                                       #
#########################################################################

use strict;
use XML::Twig;

my $field= $ARGV[0] || 'ppg';
my $twig= new XML::Twig;

$twig->parsefile( "/mnt/hgfs/share/project/tools/VcaTool_Yangzi/compiler/program/tmp/VDE_CN_20160308/State_14120001/POI_1414000001.xml");    # build the twig
my $root= $twig->root;           # get the root of the twig (stats)
my @players= $root->children;    # get the player list

                                 # sort it on the text of the field
my @sorted= sort {    $b->first_child( $field)->text 
                  <=> $a->first_child( $field)->text }
            @players;
                                 
print '<?xml version="1.0"?>';   # print the XML declaration
print '<!DOCTYPE stats SYSTEM "stats.dtd" []>';
print '<stats>';                 # then the root element start tag

foreach my $player (@sorted)     # the sorted list 
 { $player->print;               # print the xml content of the element 
   print "\n"; 
 }
print "</stats>\n";              # close the document
