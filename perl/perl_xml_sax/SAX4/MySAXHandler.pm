 package MySAXHandler;
  use base qw(XML::SAX::Base);
  
  sub start_document {
    my ($self, $doc) = @_;
    # process document start event
	print "start_document";
	print "\n";
  }
  
  sub start_element {
    my ($self, $el) = @_;
    # process element start event
	print "start_element";
	print "\n";
  }

1;
