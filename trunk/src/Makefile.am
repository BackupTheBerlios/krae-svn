# set the include path for X, qt and KDE
INCLUDES = $(all_includes)

# these are the headers for your project
noinst_HEADERS = krae.h

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/krae.pot

KDE_ICON = krae

#########################################################################
# APPLICATION SECTION
#########################################################################
# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = krae

# the application source, library search path, and link libraries
krae_SOURCES = main.cpp krae.cpp
krae_LDFLAGS = $(KDE_RPATH) $(all_libraries)
krae_LDADD = $(LIB_KDEUI)

# this is where the desktop file will go 
shelldesktopdir   = $(kde_appsdir)/Utilities
shelldesktop_DATA = krae.desktop

# this is where the shell's XML-GUI resource file goes
shellrcdir   = $(kde_datadir)/krae
shellrc_DATA = kraeui.rc

