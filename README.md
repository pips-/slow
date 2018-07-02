slow
====

Slow down input to output

Install
-------

    # make clean install

Usage
-----

    $ slow [-t usec] [-f]

-t usec : Define sleep between each bytes in micro-second. Default to 1 second.

-f : Force flushing after each byte. Useful with buffered stdout like ttys.
