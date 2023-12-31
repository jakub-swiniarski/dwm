X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

XINERAMALIBS  = -lXinerama
XINERAMAFLAGS = -DXINERAMA

FREETYPELIBS = -lfontconfig -lXft
FREETYPEINC = /usr/include/freetype2

INCS = -I$(X11INC) -I$(FREETYPEINC)
LIBS = -L$(X11LIB) -lX11 $(XINERAMALIBS) $(FREETYPELIBS)

CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L $(XINERAMAFLAGS)
CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -O2 $(INCS) $(CPPFLAGS)
LDFLAGS  = $(LIBS)

SRC = drw.c dwm.c util.c
OBJ = $(SRC:.c=.o)

dwm: $(OBJ)
	gcc -o dwm $(OBJ) $(LDFLAGS)

$(OBJ): config.h

clean:
	rm -f dwm $(OBJ)

install: dwm
	cp -f dwm /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/dwm 

.PHONY: clean install uninstall
