
use XML::Twig;

my $twig = XML::Twig->new ();
$twig->parsefile ('sample.xml');

my @firstname = map { $_->text } $twig->findnodes ('//firstname');
