#!/usr/bin/perl
#
# File:   lab13.listgroups.p1
# Author: William Kelley
# Purpose: Linux stuff

use 5.010;
use warnings;

my $user shift || $ENV{"USER"};
say "user name is: $user";

@list = ( );

open (my $fh, "grep $user /etc/group |") or die "Error: $!\n";

while (my $group = <$fh> ) {
  chomp my $group;
  $group =~ s/(.*?):.*/$1/;
  push my (@list), $group;
}

my @sortedList = sort @list;
say @sortedList;

close $fh;