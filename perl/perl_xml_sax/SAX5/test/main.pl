#!/usr/bin/perl

use Foo1;
#use do::Foo2;
use lib "./do";
use Foo2();

$Foo1::abc = 345;

Foo1::Hello1();
Hello2();

print "a";
print LINE_CHAR;
print "b";
print LINE_CHAR;
