# Test fonts

This folder contains the source files for two fonts used for testing: `hbbasefont1` and `hbbasefont2`.

These fonts contain only 3 glyphs: 
- A (`romn` script, used to test the `romn` baseline)
- ཀ (`tibt` script, used to test the `hang` baseline)
- 藏 (`hani` script, used to test the `ideo` and `idtp` baselines)

Both fonts contain these glyphs at different heights, and set their baselines values accordingly.

## Building

You need [fontforge](http://fontforge.github.io) with python extension to build the fonts. Once installed run:

```
make
```