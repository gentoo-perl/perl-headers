#!perl
use strict;
use warnings;

sub slurp {
  open my $fh, '<' , $_[0] or die "Can't open $_[0] for reading, $!";
  my $content = do { local $/ = undef;  scalar <$fh>; };
  if ( not defined $content or not length $content ) {
    die "Reading $_[0] gave no content";
  }
  return $content;
}

sub spew {
  my $file = $_[0];
  my $misc_file = $_[0] . '.' . scalar time;
  open my $fh, '>', $misc_file or die "Cant open $misc_file for writing, $!";
  print { $fh } $_[1];
  close $fh or die "Error closing $misc_file, $!";
  rename $misc_file, $file or die "Error renaming $misc_file to $file";
}

my $orig  = slurp($ARGV[0]);
my $patch = slurp($ARGV[1]);

if ( $orig !~ /\n1;\s*\z/ ) {
  my ( @lines ) = split /\n/, $orig;
  print { *STDERR } "$_\n" for splice @lines, -3, 3;
  die "Cant find trailing 1 at eof of $ARGV[0] to inject before";
}
$orig =~ s{\n(1;\s*\z)}{ $patch . "\n$1" }ex;

spew( $ARGV[2], $orig );
