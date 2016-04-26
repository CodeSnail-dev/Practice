#!/usr/bin/perl -w
use strict;
use XML::LibXML;

my $parser = XML::LibXML->new;
my $doc = $parser->parse_file('pets.xml')
 or die "can't parse Rosie's stock file: $@";
my $root = $doc->documentElement();
sub addSubElm($$$) {
 my ($pet, $name, $body) = @_;
 my $subElm = $pet->addNewChild('', $name);
 $subElm->addChild( $doc->createTextNode($body) );
}
sub addPet($$$$) {
 my ($type, $name, $dob, $price) = @_;
 # addNewChild is non-compliant; could use addSibling instead
 my $pet = $root->addNewChild('', $type);
 addSubElm ( $pet, 'name', $name );
 addSubElm ( $pet, 'dob', $dob );
 addSubElm ( $pet, 'price', $price );
} 
addPet('gerbil', 'nasty', '15 February 2006', '5');
addPet('hamster', 'boris', '5 July 2006', '7.00');

my @nodeList = $doc->getElementsByTagName('price');
foreach my $priceNode (@nodeList) {
 my $curPrice = $priceNode->textContent;
 my $newPrice = sprintf "%6.2f", $curPrice * 1.2;
 my $parent = $priceNode->parentNode;
 my $newPriceNode = XML::LibXML::Element->new('price');
 $newPriceNode->addChild ( $doc->createTextNode( $newPrice ) );
 $parent->replaceChild ( $newPriceNode, $priceNode );
}
print $doc->toString(1); # pretty print
