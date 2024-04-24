SRC = $(wildcard *.c)
HDR = $(wildcard *.h)
OBJ = $(SRC:.c=.o)

all: dwm

%.o: %.c
	gcc -c -O2 -pedantic -Wall -Wno-deprecated-declarations -O2 -I/usr/X11R6/include -I/usr/include/freetype2 -DXINERAMA $<

$(OBJ): $(HDR)

dwm: $(OBJ)
	gcc -o $@ $(OBJ) -L/usr/X11R6/lib -lX11 -lXinerama -lfontconfig -lXft

clean:
	rm *.o dwm

install: all
	cp dwm /usr/local/bin/

uninstall:
	rm /usr/local/bin/dwm

.PHONY: all clean install uninstall
