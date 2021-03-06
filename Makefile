#############################################################################
# Makefile for building: test
# Generated by qmake (2.01a) (Qt 4.8.6) on: Mon Oct 24 02:44:32 2016
# Project:  test.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile test.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++11 -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = Bag.cpp \
		Board.cpp \
		Dictionary.cpp \
		main_window.cpp \
		mainNext_window.cpp \
		naming_window.cpp \
		player.cpp \
		Square.cpp \
		starting_window.cpp \
		testmain.cpp moc_main_window.cpp \
		moc_mainNext_window.cpp \
		moc_naming_window.cpp \
		moc_starting_window.cpp
OBJECTS       = Bag.o \
		Board.o \
		Dictionary.o \
		main_window.o \
		mainNext_window.o \
		naming_window.o \
		player.o \
		Square.o \
		starting_window.o \
		testmain.o \
		moc_main_window.o \
		moc_mainNext_window.o \
		moc_naming_window.o \
		moc_starting_window.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		test.pro
QMAKE_TARGET  = test
DESTDIR       = 
TARGET        = test

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: test.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile test.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile test.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/test1.0.0 || $(MKDIR) .tmp/test1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/test1.0.0/ && $(COPY_FILE) --parents Bag.h Board.h Dictionary.h main_window.h mainNext_window.h naming_window.h player.h Square.h starting_window.h Tile.h .tmp/test1.0.0/ && $(COPY_FILE) --parents Bag.cpp Board.cpp Dictionary.cpp main_window.cpp mainNext_window.cpp naming_window.cpp player.cpp Square.cpp starting_window.cpp testmain.cpp .tmp/test1.0.0/ && (cd `dirname .tmp/test1.0.0` && $(TAR) test1.0.0.tar test1.0.0 && $(COMPRESS) test1.0.0.tar) && $(MOVE) `dirname .tmp/test1.0.0`/test1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/test1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_main_window.cpp moc_mainNext_window.cpp moc_naming_window.cpp moc_starting_window.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_main_window.cpp moc_mainNext_window.cpp moc_naming_window.cpp moc_starting_window.cpp
moc_main_window.cpp: Bag.h \
		Tile.h \
		Dictionary.h \
		Board.h \
		Square.h \
		player.h \
		mainNext_window.h \
		main_window.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) main_window.h -o moc_main_window.cpp

moc_mainNext_window.cpp: Bag.h \
		Tile.h \
		Dictionary.h \
		Board.h \
		Square.h \
		player.h \
		mainNext_window.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) mainNext_window.h -o moc_mainNext_window.cpp

moc_naming_window.cpp: main_window.h \
		Bag.h \
		Tile.h \
		Dictionary.h \
		Board.h \
		Square.h \
		player.h \
		mainNext_window.h \
		naming_window.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) naming_window.h -o moc_naming_window.cpp

moc_starting_window.cpp: naming_window.h \
		main_window.h \
		Bag.h \
		Tile.h \
		Dictionary.h \
		Board.h \
		Square.h \
		player.h \
		mainNext_window.h \
		starting_window.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) starting_window.h -o moc_starting_window.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

Bag.o: Bag.cpp Bag.h \
		Tile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Bag.o Bag.cpp

Board.o: Board.cpp Board.h \
		Square.h \
		Tile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Board.o Board.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Dictionary.o Dictionary.cpp

main_window.o: main_window.cpp main_window.h \
		Bag.h \
		Tile.h \
		Dictionary.h \
		Board.h \
		Square.h \
		player.h \
		mainNext_window.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main_window.o main_window.cpp

mainNext_window.o: mainNext_window.cpp mainNext_window.h \
		Bag.h \
		Tile.h \
		Dictionary.h \
		Board.h \
		Square.h \
		player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainNext_window.o mainNext_window.cpp

naming_window.o: naming_window.cpp naming_window.h \
		main_window.h \
		Bag.h \
		Tile.h \
		Dictionary.h \
		Board.h \
		Square.h \
		player.h \
		mainNext_window.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o naming_window.o naming_window.cpp

player.o: player.cpp Bag.h \
		Tile.h \
		player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o player.o player.cpp

Square.o: Square.cpp Square.h \
		Tile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Square.o Square.cpp

starting_window.o: starting_window.cpp starting_window.h \
		naming_window.h \
		main_window.h \
		Bag.h \
		Tile.h \
		Dictionary.h \
		Board.h \
		Square.h \
		player.h \
		mainNext_window.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o starting_window.o starting_window.cpp

testmain.o: testmain.cpp starting_window.h \
		naming_window.h \
		main_window.h \
		Bag.h \
		Tile.h \
		Dictionary.h \
		Board.h \
		Square.h \
		player.h \
		mainNext_window.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o testmain.o testmain.cpp

moc_main_window.o: moc_main_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_main_window.o moc_main_window.cpp

moc_mainNext_window.o: moc_mainNext_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainNext_window.o moc_mainNext_window.cpp

moc_naming_window.o: moc_naming_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_naming_window.o moc_naming_window.cpp

moc_starting_window.o: moc_starting_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_starting_window.o moc_starting_window.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

