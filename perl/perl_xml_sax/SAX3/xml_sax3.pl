use XML::Parser;

$currentLine = 0;

$parser = new XML::Parser(Handlers => {Start => \&start_handler,
        End   => \&end_handler,
        Char  => \&char_handler,
        Proc  => \&proc_handler,
        XMLDecl => \&XMLDecl_handler,
        Final => \&final_handler});
          
$parser->parsefile("sample.xml");
  
sub XMLDecl_handler
{
    $xmlString[$currentLine++] = "<?xml version=\"$_[1]\"?>";
}

sub start_handler
{
    $xmlString[$currentLine] = $indent . "<$_[1]";
    for ($i = 2; $i <= $#_ - 1; $i += 2){
        $xmlString[$currentLine] .= " " . $_[$i] . "=\"". $_[$i + 1] . "\"";
    }
    $xmlString[$currentLine++] .= ">";
    $indent .= "    ";
}

sub end_handler
{
    $indent = substr($indent, 0, length($indent) - 4);
    $xmlString[$currentLine++] = $indent . "</$_[1]>";
}

sub char_handler
{
    if($_[1] =~ /[^ \n\t\r]/g) {
        $xmlString[$currentLine++] = $indent . "$_[1]";
    }
}

sub proc_handler
{
    $xmlString[$currentLine++] = "<?$_[1] $_[2]?>";
}

sub final_handler
{
    for ($i = 0; $i < $currentLine; $i++){
        print $xmlString[$i] . "\n";
    }
}
