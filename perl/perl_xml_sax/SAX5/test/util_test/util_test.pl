#!/bin/usr/perl

sub JoinStr{
    join "\t", @_; 
}

print JoinStr("123skfdjldsjflajdkljfksjl", "a", "b");
