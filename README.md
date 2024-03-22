# compile-time-crc32
A header-only library that allows a crc32 hash to be computed for constant strings at compile time.

Please note that this is a bit of a failed experiment since C macros are highly limited. It works with two pretty big caveats:

1. Longer strings absolutely tank compile time in GCC.
2. You have to supply the length of the string as an actual number. `CT_CRC32("foo", sizeof("foo"))` will not expand properly, you have to do `CT_CRC32("foo", 3)`.
