#!/usr/bin/perl
use strict;
use warnings;
use Data::Dumper;
use XML::SAX::ParserFactory;
use XML::SAX::PurePerl;

my $characters;
my @firstnames;

my $factory = new XML::SAX::ParserFactory;
#Let's see which handlers we have available
#print Dumper $factory;
my $handler = new XML::SAX::PurePerl;
my $parser = $factory->parser(
              Handler => $handler,
              Methods => {
                  characters => sub {
                      $characters = shift->{Data};
                  },
                  end_element => sub {
                      push @firstnames, $characters if shift->{LocalName} eq 'firstname';
                  }
              }
          );

$parser->parse_uri("sample.xml");
print Dumper \@firstnames;
