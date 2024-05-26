-------------------------------------------------------------------------------
                                         dc
-------------------------------------------------------------------------------

This is a dc(1) clone I made for fun. Most of the POSIX spec is missing, but
the basics are already done. Here's what's left to implement, based on the info
page for GNU dc:

- Arbitrary precision; for now, numbers are stored as doubles;

- Command line flags;

- Miscellaneous: !, #, :, etc.;

- Parameters: precision / input and output bases.

- Registers: S and L;

- Stack control: r, R;

- Status inquiry;

- Strings.

-------------------------------------------------------------------------------
                                     building
-------------------------------------------------------------------------------

Simply run make to build it. The dc binary will be placed at the src folder.
Use make DEBUG=1 to build with debug symbols and sanitizers. Use make test to
run tests. Those tests don't really test every single edge case; they just
guarantee that the program runs decently enough. For the rest, I use a
fuzzy tester that was recommended to me by u/skeeto (thanks).

-------------------------------------------------------------------------------
                                     license
-------------------------------------------------------------------------------

All of the code is licensed under the CC0 license as specified in the LICENSE
file.
