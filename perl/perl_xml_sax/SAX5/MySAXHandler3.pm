package MySAXHandler;
use base qw(XML::SAX::Base);
use Data::Dumper;
use strict;
binmode STDOUT, ":utf8";

my $country_id = undef;
my $country_num = undef;
my $country_name_value = undef;
my $country_name_lang = undef;
my $country_name_pronunciation_value = undef;
my $country_name_pronunciation_lang = undef;
my $country_name_pronunciation_format = undef;
my $count = 1;
my $FH = undef;

sub setFileHandler($){
	($FH) = @_;
	print "==\n";
	print $FH;
	print "==\n";
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
		print $FH $country_id."\t".$country_name_value;
		print $FH "\n";
		print $FH "$count===================================\n";
	}
}
sub start_element {
	my ($self, $el) = @_;
	if ("Country" eq $el->{LocalName}) {
		$country_id = $el->{Attributes}->{'{}Id'}->{Value};
	} elsif ("Name" eq $el->{LocalName}) {
		$country_name_value = $el->{Attributes}->{'{}Value'}->{Value};
	}
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
