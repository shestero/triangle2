MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -O2 -Wall -W -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -std=gnu++11 -Wall -W -fPIC $(DEFINES)
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = triangle21.0.0
DISTDIR = /home/shestero/triangle2/.tmp/triangle21.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		point.cpp \
		segment.cpp \
		triangle.cpp 
OBJECTS       = main.o \
		point.o \
		segment.o \
		triangle.o

DESTDIR       = 
TARGET        = triangle2


first: all
####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)



all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/


clean: 
	$(RM) $(OBJS) 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile



####### Compile

main.o: main.cpp geomath.h \
		point.h \
		segment.h \
		triangle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

point.o: point.cpp point.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o point.o point.cpp

segment.o: segment.cpp segment.h \
		point.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o segment.o segment.cpp

triangle.o: triangle.cpp triangle.h \
		point.h \
		geomath.h \
		segment.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o triangle.o triangle.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

