# Demo and test for the BASE opentype feature using Harfbuzz

The goal of this repository is to:
- test the [harfbuzz](https://github.com/behdad/harfbuzz) implementation of the BASE feature handling
- provide a demo of how applications should handle the BASE feature
- provide models for font designers

See also [resources on the BASE feature](https://github.com/eroux/otf-base-hang).

## Building

First build harfbuzz in the submodule (see [harfbuzz build doc](https://github.com/behdad/harfbuzz/blob/master/BUILD.md)):

```
$ git submodule update --init
$ cd harfbuzz
$ ./autogen.sh
$ make
```

Then build fonts (see [fonts/](fonts/) directory).

Then you can [run tests](tests/) or see the demo (TODO).

## License

All material in this repository is under the [MIT License](LICENSE).