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
                                     license
-------------------------------------------------------------------------------

All of the code is licensed under the CC0 license as specified in the LICENSE
file.
