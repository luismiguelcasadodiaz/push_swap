[4mSORT[24m(1)                                                                               User Commands                                                                               [4mSORT[24m(1)

[1mNAME[0m
       sort - sort lines of text files

[1mSYNOPSIS[0m
       [1msort [22m[[4mOPTION[24m]... [[4mFILE[24m]...
       [1msort [22m[[4mOPTION[24m]... [4m‐‐files0‐from=F[0m

[1mDESCRIPTION[0m
       Write sorted concatenation of all FILE(s) to standard output.

       With no FILE, or when FILE is -, read standard input.

       Mandatory arguments to long options are mandatory for short options too.  Ordering options:

       [1m-b[22m, [1m--ignore-leading-blanks[0m
              ignore leading blanks

       [1m-d[22m, [1m--dictionary-order[0m
              consider only blanks and alphanumeric characters

       [1m-f[22m, [1m--ignore-case[0m
              fold lower case to upper case characters

       [1m-g[22m, [1m--general-numeric-sort[0m
              compare according to general numerical value

       [1m-i[22m, [1m--ignore-nonprinting[0m
              consider only printable characters

       [1m-M[22m, [1m--month-sort[0m
              compare (unknown) < ’JAN’ < ... < ’DEC’

       [1m-h[22m, [1m--human-numeric-sort[0m
              compare human readable numbers (e.g., 2K 1G)

       [1m-n[22m, [1m--numeric-sort[0m
              compare according to string numerical value

       [1m-R[22m, [1m--random-sort[0m
              shuffle, but group identical keys.  See [1mshuf[22m(1)

       [1m--random-source[22m=[4mFILE[0m
              get random bytes from FILE

       [1m-r[22m, [1m--reverse[0m
              reverse the result of comparisons

       [1m--sort[22m=[4mWORD[0m
              sort according to WORD: general-numeric [1m-g[22m, human-numeric [1m-h[22m, month [1m-M[22m, numeric [1m-n[22m, random [1m-R[22m, version [1m-V[0m

       [1m-V[22m, [1m--version-sort[0m
              natural sort of (version) numbers within text

       Other options:

       [1m--batch-size[22m=[4mNMERGE[0m
              merge at most NMERGE inputs at once; for more use temp files

       [1m-c[22m, [1m--check[22m, [1m--check[22m=[4mdiagnose-first[0m
              check for sorted input; do not sort

       [1m-C[22m, [1m--check[22m=[4mquiet[24m, [1m--check[22m=[4msilent[0m
              like [1m-c[22m, but do not report first bad line

       [1m--compress-program[22m=[4mPROG[0m
              compress temporaries with PROG; decompress them with PROG [1m-d[0m

       [1m--debug[0m
              annotate the part of the line used to sort, and warn about questionable usage to stderr

       [1m--files0-from[22m=[4mF[0m
              read input from the files specified by NUL-terminated names in file F; If F is - then read names from standard input

       [1m-k[22m, [1m--key[22m=[4mKEYDEF[0m
              sort via a key; KEYDEF gives location and type

       [1m-m[22m, [1m--merge[0m
              merge already sorted files; do not sort

       [1m-o[22m, [1m--output[22m=[4mFILE[0m
              write result to FILE instead of standard output

       [1m-s[22m, [1m--stable[0m
              stabilize sort by disabling last-resort comparison

       [1m-S[22m, [1m--buffer-size[22m=[4mSIZE[0m
              use SIZE for main memory buffer

       [1m-t[22m, [1m--field-separator[22m=[4mSEP[0m
              use SEP instead of non-blank to blank transition

       [1m-T[22m, [1m--temporary-directory[22m=[4mDIR[0m
              use DIR for temporaries, not $TMPDIR or [4m/tmp[24m; multiple options specify multiple directories

       [1m--parallel[22m=[4mN[0m
              change the number of sorts run concurrently to N

       [1m-u[22m, [1m--unique[0m
              with [1m-c[22m, check for strict ordering; without [1m-c[22m, output only the first of an equal run

       [1m-z[22m, [1m--zero-terminated[0m
              line delimiter is NUL, not newline

       [1m--help [22mdisplay this help and exit

       [1m--version[0m
              output version information and exit

       KEYDEF  is  F[.C][OPTS][,F[.C][OPTS]] for start and stop position, where F is a field number and C a character position in the field; both are origin 1, and the stop position de‐
       faults to the line’s end.  If neither [1m-t [22mnor [1m-b [22mis in effect, characters in a field are counted from the beginning of the preceding whitespace.  OPTS is one or more single-letter
       ordering options [bdfgiMhnRrV], which override global ordering options for that key.  If no key is given, use the entire line as the key.  Use [1m--debug [22mto diagnose  incorrect  key
       usage.

       SIZE may be followed by the following multiplicative suffixes: % 1% of memory, b 1, K 1024 (default), and so on for M, G, T, P, E, Z, Y.

       *** WARNING *** The locale specified by the environment affects sort order.  Set LC_ALL=C to get the traditional sort order that uses native byte values.

[1mAUTHOR[0m
       Written by Mike Haertel and Paul Eggert.

[1mREPORTING BUGS[0m
       GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
       Report any translation bugs to <https://translationproject.org/team/>

[1mCOPYRIGHT[0m
       Copyright © 2022 Free Software Foundation, Inc.  License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.
       This is free software: you are free to change and redistribute it.  There is NO WARRANTY, to the extent permitted by law.

[1mSEE ALSO[0m
       [1mshuf[22m(1), [1muniq[22m(1)

       Full documentation <https://www.gnu.org/software/coreutils/sort>
       or available locally via: info '(coreutils) sort invocation'

GNU coreutils 9.1                                                                      January 2023                                                                               [4mSORT[24m(1)
