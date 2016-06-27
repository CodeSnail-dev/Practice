package MySAXHandler;
use base qw(XML::SAX::Base);
use Data::Dumper;
use strict;
#use haha;
require "haha.pl";

binmode STDOUT, ":utf8";

#use constant {
#             JOIN_CHAR => "\t",
#             LINE_CHAR => "\n",
#             PY => "PY",
#             LH => "LH+",
#             }; 

sub EscapeQuote($){     #for sqlite import issue, double quote couldn't be the first character.
  my $ch = shift @_; 
  $ch =~ s/^/~/g;             
  $ch;
}

sub JoinStr{
    join haha::constant::JOIN_CHAR, @_; 
}

# File pass from caller
my $FH = undef;

# city id pass from caller
my $city_id = undef;

my $poi_id = undef;
my $poi_name_num = undef;
my $poi_name_id = undef;
my $poi_name_value = undef;
my $poi_name_lang = undef;

#$city_id,$poi_id,$poi_name_nu,$poi_lang,$poi_name_id,$poi_name_str;
##my $country_id = undef;
##my $country_num = undef;
##my $country_name_value = undef;
##my $country_name_lang = undef;
##my $country_name_pronunciation_value = undef;
##my $country_name_pronunciation_lang = undef;
##my $country_name_pronunciation_format = undef;
##my $count = 1;

sub setFileHandler($){
	($FH) = @_;
}

sub setCityId($){
	($city_id) = @_;
}

sub start_document {
  my ($self, $doc) = @_;
  # process document start event
  #print "start_document";
  #print "\n";
}

sub end_element {
	my ($self, $el) = @_;

	if ("Name" eq $el->{LocalName}) {
##		print $FH $country_id."\t".$country_name_value;
##		print $FH "\n";
##		print $FH "$count===================================\n";
		print JoinStr($city_id, $poi_id, $poi_name_num, $poi_name_lang, $poi_name_id, $poi_name_value);
		print LINE_CHAR;
	}
}
sub start_element {
	my ($self, $el) = @_;

	if ("Poi" eq $el->{LocalName}) {
		$poi_id = $el->{Attributes}->{'{}Id'}->{Value};
	} elsif ("Name" eq $el->{LocalName}) {
		$poi_name_num = 100;
		$poi_name_id = $el->{Attributes}->{'{}Id'}->{Value};
		$poi_name_value = $el->{Attributes}->{'{}Value'}->{Value};
		$poi_name_lang = $el->{Attributes}->{'{}Language'}->{Value};
	}

##	if ("Country" eq $el->{LocalName}) {
##		$country_id = $el->{Attributes}->{'{}Id'}->{Value};
##	} elsif ("Name" eq $el->{LocalName}) {
##		$country_name_value = $el->{Attributes}->{'{}Value'}->{Value};
##	}
  # process element start event
##  print "start_element:\n";
##  print "LocalName: $el->{LocalName}\n";
##  print "NamespaceURI: $el->{NamespaceURI}\n";
##  print "===================================\n";
##  print "Attributes: $el->{Attributes}->{'{}Value'}->{LocalName}\n";
##  print "===================================\n";
##  print "Name: $el->{Name}\n";
##  print "Prefix: $el->{Prefix}\n";
##  print "\n";
	#%h = (1, 2, 3, 4);
##	%h = $el->{Attributes};
##  #for $car (keys %el->{Attributes}) {
##  for $car (keys %h) {
##		print "$car\n";
##	}
##	print Dumper($el->{Attributes});
##	print "===================================\n";
##	print Dumper($el);
##	print "\n";
##	print $country_id."\t".$country_name_value;
##	print $country_name_value;
##	print "\n";
##	print "$count===================================\n";
##	$count++;
#	print Dumper($el);
}

1;
