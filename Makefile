SOURCES=$(wildcard *.c)
HEADERS=$(wildcard *.h)
OBJECTS=$(SOURCES:.c=.o)

dwm: $(OBJECTS)
	gcc -o dwm $(OBJECTS) -L/usr/X11R6/lib -lX11 -lXinerama -lfontconfig -lXft

$(OBJECTS): $(SOURCES) $(HEADERS)
	gcc -c $(SOURCES) -pedantic -Wall -Wno-deprecated-declarations -O2 -I/usr/X11R6/include -I/usr/include/freetype2 -DXINERAMA

.PHONY: clean install uninstall

clean:
	rm -f dwm $(OBJECTS)

install: dwm
	cp -f dwm /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/dwm 
