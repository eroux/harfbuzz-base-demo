# This is a fontforge python script; use fontforge -lang=py -script to run it
# coding=utf-8
# pylint: disable=import-error

"""
    Tiny python fontforge script to convert an UFO into TTF.

    Copyright (C) 2017 Elie Roux, MIT License.

    Basic use :
         fontforge -script ufo2ttf.py fontfile
"""


from __future__ import print_function

import getopt, sys
import fontforge


def usage():
    "Prints help message."
    print("""
Python fontforge script to convert an ufo into ttf.

Usage:
    fontforge -script ufo2ttf.py fontfile
""")

def main():
    "Main function."
    try:
        opts, args = getopt.gnu_getopt(sys.argv[1:], "h", ["help"])
    except getopt.GetoptError:
        # print help information and exit:
        usage()
        sys.exit(2)
    outputfile = None
    for opt, arg in opts:
        if opt in ("-h", "--help"):
            usage()
            sys.exit()
    if len(args) == 0:
        usage()
        sys.exit(2)
    fontfile = args[0]
    font = fontforge.open(fontfile)
    outfile = os.path.splitext(fontfile)[0]+".ttf"
    font.generate(outfile)
    font.close()

if __name__ == "__main__":
    main()