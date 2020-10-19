################################################################################
# Directories and related
PROJECT_DIR	= $(CURDIR)

BIN_DIR		= $(PROJECT_DIR)/bin
INC_DIR		= $(PROJECT_DIR)/include
INC_DIR_	= $(INC_DIR)/$(package_name)
SRC_DIR		= $(PROJECT_DIR)/src
LIB_DIR		= $(PROJECT_DIR)/lib
LIB_DIR_	= $(LIB_DIR)/$(package_name)
ETC_DIR		= $(PROJECT_DIR)/etc
ETC_DIR_	= $(ETC_DIR)/$(package_name)
SHARE_DIR	= $(PROJECT_DIR)/share
DOC_DIR		= $(SHARE_DIR)/doc
DOC_DIR_	= $(DOC_DIR)/$(package_name)
MAN_DIR		= $(SHARE_DIR)/man
BUILD_DIR	= $(PROJECT_DIR)/build
BUILD_TMP_DIR	= $(BUILD_DIR)/tmp
BUILD_LIB_DIR	= $(BUILD_DIR)/lib
BUILD_A_DIR	= $(BUILD_LIB_DIR)/static
BUILD_A_DIR_	= $(BUILD_A_DIR)/$(package_name)
BUILD_SO_DIR	= $(BUILD_LIB_DIR)/shared
BUILD_SO_DIR_	= $(BUILD_SO_DIR)/$(package_name)

export	PROJECT_DIR

export	BIN_DIR
export	INC_DIR
export	INC_DIR_
export	SRC_DIR
export	LIB_DIR
export	LIB_DIR_
export	ETC_DIR
export	ETC_DIR_
export	SHARE_DIR
export	DOC_DIR
export	DOC_DIR_
export	MAN_DIR
export	BUILD_DIR
export	BUILD_TMP_DIR
export	BUILD_LIB_DIR
export	BUILD_A_DIR
export	BUILD_A_DIR_
export	BUILD_SO_DIR
export	BUILD_SO_DIR_

## XXX: make ... prefix=/usr to build in /usr/
prefix		= /usr/local
exec_prefix	= $(prefix)
## Executable
bindir		= $(exec_prefix)/bin
sbindir		= $(exec_prefix)/sbin
libexecdir	= $(exec_prefix)/libexec/
libexecdir_	= $(libexecdir)/$(package_name)
## Data
datarootdir	= $(prefix)/share
datadir		= $(datarootdir)
sysconfdir	= $(prefix:/usr=)/etc
sysconfdir_	= $(sysconfdir)/$(package_name)
localstatedir	= $(prefix)/var
localstatedir_	= $(localstatedir)/$(package_name)
runstatedir	= $(localstatedir)/run
runstatedir_	= $(runstatedir)/$(package_name)
## Specific
includedir	= $(prefix)/include
includedir_	= $(includedir)/$(package_name)
oldincludedir	= /usr/include
oldincludedir_	= $(oldincludedir)/$(package_name)
docdir		= $(datarootdir)/doc
docdir_		= $(docdir)/$(package_name)
infodir		= $(datarootdir)/info
htmldir		= $(docdir)
htmldir_	= $(htmldir)/$(package_name)
dvidir		= $(docdir)
dvidir_		= $(dvidir)/$(package_name)
pdfdir		= $(docdir)
pdfdir_		= $(pdfdir)/$(package_name)
psdir		= $(docdir)
psdir_		= $(psdir)/$(package_name)
libdir		= $(exec_prefix)/lib
libdir_		= $(libdir)/$(package_name)
lispdir		= $(datarootdir)/emacs/site-lisp
localedir	= $(datarootdir)/locale
## man
mandir		= $(datarootdir)/man
man1dir		= $(mandir)/man1
man2dir		= $(mandir)/man2
man3dir		= $(mandir)/man3
man4dir		= $(mandir)/man4
man5dir		= $(mandir)/man5
man6dir		= $(mandir)/man6
man7dir		= $(mandir)/man7
man8dir		= $(mandir)/man8
man9dir		= $(mandir)/man9
man1ext		= .1
man1ext_	= $(man1ext)$(package_shortname)
man2ext		= .2
man2ext_	= $(man2ext)$(package_shortname)
man3ext		= .3
man3ext_	= $(man3ext)$(package_shortname)
man4ext		= .4
man4ext_	= $(man4ext)$(package_shortname)
man5ext		= .5
man5ext_	= $(man5ext)$(package_shortname)
man6ext		= .6
man6ext_	= $(man6ext)$(package_shortname)
man7ext		= .7
man7ext_	= $(man7ext)$(package_shortname)
man8ext		= .8
man8ext_	= $(man8ext)$(package_shortname)
man9ext		= .9
man9ext_	= $(man9ext)$(package_shortname)
manext		= $(man7ext)
manext_		= $(manext)$(package_shortname)
srcdir		= ./src


MAKE_DIR_VARIABLES	=						\
		package_name						\
		package_shortname					\
									\
		bindir							\
		sbindir							\
		libexecdir						\
		libexecdir_						\
									\
		datarootdir						\
		datadir							\
		sysconfdir						\
		sysconfdir_						\
		localstatedir						\
		localstatedir_						\
		runstatedir						\
		runstatedir_						\
									\
		includedir						\
		includedir_						\
		oldincludedir						\
		oldincludedir_						\
		docdir							\
		docdir_							\
		infodir							\
		htmldir							\
		htmldir_						\
		dvidir							\
		dvidir_							\
		pdfdir							\
		pdfdir_							\
		psdir							\
		psdir_							\
		libdir							\
		libdir_							\
		lispdir							\
		localedir						\
									\
		mandir							\
		man1dir							\
		man2dir							\
		man3dir							\
		man4dir							\
		man5dir							\
		man6dir							\
		man7dir							\
		man8dir							\
		man9dir							\
		man1ext							\
		man1ext							\
		man2ext							\
		man2ext_						\
		man3ext							\
		man3ext_						\
		man4ext							\
		man4ext_						\
		man5ext							\
		man5ext_						\
		man6ext							\
		man6ext_						\
		man7ext							\
		man7ext_						\
		man8ext							\
		man8ext_						\
		man9ext							\
		man9ext_						\
		manext							\
		manext_							\
		srcdir


## export
## Package
export	package_name
export	package_shortname
## Executable
export	bindir
export	sbindir
export	libexecdir
export	libexecdir_
## Data
export	datarootdir
export	datadir
export	sysconfdir
export	sysconfdir_
export	localstatedir
export	localstatedir_
export	runstatedir
export	runstatedir_
## Specific
export	includedir
export	includedir_
export	oldincludedir
export	oldincludedir_
export	docdir
export	docdir_
export	infodir
export	htmldir
export	htmldir_
export	dvidir
export	dvidir_
export	pdfdir
export	pdfdir_
export	psdir
export	psdir_
export	libdir
export	libdir_
export	lispdir
export	localedir
## man
export	mandir
export	man1dir
export	man2dir
export	man3dir
export	man4dir
export	man5dir
export	man6dir
export	man7dir
export	man8dir
export	man9dir
export	man1ext
export	man1ext
export	man2ext
export	man2ext_
export	man3ext
export	man3ext_
export	man4ext
export	man4ext_
export	man5ext
export	man5ext_
export	man6ext
export	man6ext_
export	man7ext
export	man7ext_
export	man8ext
export	man8ext_
export	man9ext
export	man9ext_
export	manext
export	manext_
export	srcdir


## cpp definitions
CPP_DEFINITIONS	=							\
		-D BINDIR=\"$(bindir)\"					\
		-D SBINDIR=\"$(sbindir)\"				\
		-D LIBEXECDIR=\"$(libexecdir)\"				\
		-D LIBEXECDIR_=\"$(libexecdir_)\"			\
									\
		-D DATAROOTDIR=\"$(datarootdir)\"			\
		-D DATADIR=\"$(datadir)\"				\
		-D SYSCONFDIR=\"$(sysconfdir)\"				\
		-D SYSCONFDIR_=\"$(sysconfdir_)\"			\
		-D LOCALSTATEDIR=\"$(localstatedir)\"			\
		-D LOCALSTATEDIR_=\"$(localstatedir_)\"			\
		-D RUNSTATEDIR=\"$(runstatedir)\"			\
		-D RUNSTATEDIR_=\"$(runstatedir_)\"			\
									\
		-D INCLUDEDIR=\"$(includedir)\"				\
		-D INCLUDEDIR_=\"$(includedir_)\"			\
		-D OLDINCLUDEDIR=\"$(oldincludedir)\"			\
		-D OLDINCLUDEDIR_=\"$(oldincludedir_)\"			\
		-D DOCDIR=\"$(docdir)\"					\
		-D DOCDIR_=\"$(docdir_)\"				\
		-D INFODIR=\"$(infodir)\"				\
		-D HTMLDIR=\"$(htmldir)\"				\
		-D HTMLDIR_=\"$(htmldir_)\"				\
		-D DVIDIR=\"$(dvidir)\"					\
		-D DVIDIR_=\"$(dvidir_)\"				\
		-D PDFDIR=\"$(pdfdir)\"					\
		-D PDFDIR_=\"$(pdfdir_)\"				\
		-D PSDIR=\"$(psdir)\"					\
		-D PSDIR_=\"$(psdir_)\"					\
		-D LIBDIR=\"$(libdir)\"					\
		-D LIBDIR_=\"$(libdir_)\"				\
		-D LISPDIR=\"$(lispdir)\"				\
		-D LOCALEDIR=\"$(localedir)\"				\
		-D MAN1DIR=\"$(man1dir)\"				\
		-D MAN2DIR=\"$(man2dir)\"				\
		-D MAN3DIR=\"$(man3dir)\"				\
		-D MAN4DIR=\"$(man4dir)\"				\
		-D MAN5DIR=\"$(man5dir)\"				\
		-D MAN6DIR=\"$(man6dir)\"				\
		-D MAN7DIR=\"$(man7dir)\"				\
		-D MAN8DIR=\"$(man8dir)\"				\
		-D MAN9DIR=\"$(man9dir)\"				\
		-D MANDIR=\"$(mandir)\"					\
		-D MAN1EXT=\"$(man1ext)\"				\
		-D MAN1EXT_=\"$(man1ext_)\"				\
		-D MAN2EXT=\"$(man2ext)\"				\
		-D MAN2EXT_=\"$(man2ext_)\"				\
		-D MAN3EXT=\"$(man3ext)\"				\
		-D MAN3EXT_=\"$(man3ext_)\"				\
		-D MAN4EXT=\"$(man4ext)\"				\
		-D MAN4EXT_=\"$(man4ext_)\"				\
		-D MAN5EXT=\"$(man5ext)\"				\
		-D MAN5EXT_=\"$(man5ext_)\"				\
		-D MAN6EXT=\"$(man6ext)\"				\
		-D MAN6EXT_=\"$(man6ext_)\"				\
		-D MAN7EXT=\"$(man7ext)\"				\
		-D MAN7EXT_=\"$(man7ext_)\"				\
		-D MAN8EXT=\"$(man8ext)\"				\
		-D MAN8EXT_=\"$(man8ext_)\"				\
		-D MAN9EXT=\"$(man9ext)\"				\
		-D MAN9EXT_=\"$(man9ext_)\"				\
		-D MANEXT=\"$(manext)\"					\
		-D MANEXT_=\"$(manext_)\"				\
		-D SRCDIR=\"$(srcdir)\"


################################################################################
######## End of file ###########################################################
################################################################################

