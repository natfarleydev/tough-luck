# The strength of a makefile is that it only compiles the objects that need to.
# This means that we can work on separate files, and then just makefile it when
# we need to!

CC=g++

# Both of these are based on `fltk-config --cxxflags` and 
# `fltk-config --use-images --ldflags` respectively. + -g for good luck (debug)
 CFLAGS=-pthread -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12   -I/usr/include/freetype2 -pthread -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12   -fstack-protector --param=ssp-buffer-size=4 -Wformat -Wformat-security -Werror=format-security  -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT -g 
LDFLAGS=-L/usr/lib/x86_64-linux-gnu -Wl,-Bsymbolic-functions -Wl,-z,relro -lfltk_images -lfltk

# Put a list of all the files we want here. It doesn't matter what order (I think).
# *ONLY* include cpp files, header files are included if they're mentioned in 
# the cpp file.                                                                                                                                                   
SOURCES=main.cpp card.cpp deck.cpp pile.cpp hand.cpp

# This line essentially says, take the list of SOURCES, and put an '.o' on the
# end instead of '.cpp'.
OBJECTS=$(SOURCES:.cpp=.o)

# This is the name of the executable.
EXECUTABLE=main

# These two instructions are essentially, build (the OBJECTS one) the project, 
# and stick it together (the EXECUTABLE one). DO NOT MODIFY, any problems are 
# likely with the program, not with this.
#
# Based on http://mrbook.org/tutorials/make/
 
$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)
