CPPFLAGS = `pkg-config --cflags freetype2` -I../harfbuzz/src/
LDFLAGS = `pkg-config --libs freetype2` -L../harfbuzz/src/

all: test-api

%.o: %.c
	$(CC) -ggdb3 -O0 -c -std=c99 $^ $(CPPFLAGS)

test-api: test-api.o
	libtool --mode=link gcc -o $@ $^ ../harfbuzz/src/libharfbuzz.la $(LDFLAGS)

clean:
	rm *.o
	rm -rf .libs
	rm test-api

debug: test-api
	libtool --mode=execute gdb test-api