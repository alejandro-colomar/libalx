#!/usr/bin/make -f

################################################################################
VERSION		= 1
PATCHLEVEL	= 0
SUBLEVEL	=
EXTRAVERSION	= ~b24
NAME		=

export	VERSION
export	PATCHLEVEL
export	SUBLEVEL

LIBVERSION	= $(VERSION)$(if $(PATCHLEVEL),.$(PATCHLEVEL)$(if $(SUBLEVEL),.$(SUBLEVEL)))$(EXTRAVERSION)
export	LIBVERSION


## Package
package_name	= libalx
package_shortname = alx


################################################################################
# Copyright (C) 2019	Alejandro Colomar Andrés
# SPDX-License-Identifier:	LGPL-2.0-only
################################################################################
# *AUTHOR*

# FULL NAME	"Alejandro Colomar Andrés"
# EMAIL		"1903716@gmail.com"
################################################################################

################################################################################
# Beautify output
# ---------------------------------------------------------------------------
# Prefix commands with $(Q) - that's useful
# for commands that shall be hidden in non-verbose mode.
#
#	$(Q)some command here
#
# If BUILD_VERBOSE equals 0 then the above command will be hidden.
# If BUILD_VERBOSE equals 2 then the above command is displayed.
#
# To put more focus on warnings, be less verbose as default
# Use 'make V=1' to see some verbose output
# Use 'make V=2' to see the full commands

ifeq ("$(origin V)","command line")
  BUILD_VERBOSE = $(V)
endif
ifndef BUILD_VERBOSE
  BUILD_VERBOSE = 0
endif

ifeq ($(BUILD_VERBOSE), 2)
  Q =
  v = -v
else ifeq ($(BUILD_VERBOSE), 1)
  Q = @
  v = -v
else
  Q = @
  v =
endif

# If the user is running make -s (silent mode), suppress echoing of
# commands

ifneq ($(findstring s,$(filter-out --%,$(MAKEFLAGS))),)
  Q = @
  v =
endif

export	Q
export	BUILD_VERBOSE

################################################################################
# Do not print "Entering directory ..."
MAKEFLAGS += --no-print-directory

################################################################################
# Directories and related

LIBALX_DIR	= $(CURDIR)

BIN_DIR		= $(LIBALX_DIR)/bin
INC_DIR		= $(LIBALX_DIR)/include
INC_DIR_	= $(INC_DIR)/$(package_name)
SRC_DIR		= $(LIBALX_DIR)/src
LIB_DIR		= $(LIBALX_DIR)/lib
LIB_DIR_	= $(LIB_DIR)/$(package_name)
ETC_DIR		= $(LIBALX_DIR)/etc
ETC_DIR_	= $(ETC_DIR)/$(package_name)
SHARE_DIR	= $(LIBALX_DIR)/share
DOC_DIR		= $(SHARE_DIR)/doc
DOC_DIR_	= $(DOC_DIR)/$(package_name)
MAN_DIR		= $(SHARE_DIR)/man
BUILD_DIR	= $(LIBALX_DIR)/build
BUILD_TMP_DIR	= $(BUILD_DIR)/tmp
BUILD_LIB_DIR	= $(BUILD_DIR)/lib
BUILD_A_DIR	= $(BUILD_LIB_DIR)/static
BUILD_A_DIR_	= $(BUILD_A_DIR)/$(package_name)
BUILD_SO_DIR	= $(BUILD_LIB_DIR)/shared
BUILD_SO_DIR_	= $(BUILD_SO_DIR)/$(package_name)

export	LIBALX_DIR

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
# Make variables (CC, etc...)
  CC	= gcc
  CXX	= g++
  AS	= as
  AR	= ar
  LD	= ld
  SZ	= size

export	CC
export	CXX
export	AS
export	AR
export	LD
export	SZ

################################################################################
# cflags
CFLAGS_STD	= -std=gnu2x

CFLAGS_OPT	= -O3
## XXX: optimize for native if portability is not needed
#CFLAGS_OPT     += -march=native
#CFLAGS_OPT     += -flto

CFLAGS_W	= -Wall
CFLAGS_W       += -Wextra
CFLAGS_W       += -Wstrict-prototypes
CFLAGS_W       += -Wpedantic
CFLAGS_W       += -pedantic-errors
CFLAGS_W       += -fno-common
CFLAGS_W       += -fanalyzer
CFLAGS_W       += -Werror

CFLAGS_D	= -D _GNU_SOURCE
CFLAGS_D       += -D _POSIX_C_SOURCE=200809L
CFLAGS_D       += $(CPP_DEFINITIONS)

CFLAGS_PKG	= `pkg-config --cflags libbsd-overlay`

CFLAGS_I	= -I $(INC_DIR)

CFLAGS		= $(CFLAGS_STD)
CFLAGS         += $(CFLAGS_OPT)
CFLAGS         += $(CFLAGS_W)
CFLAGS         += $(CFLAGS_D)
CFLAGS         += $(CFLAGS_PKG)
CFLAGS         += $(CFLAGS_I)

export	CFLAGS

CFLAGS_A	= $(CFLAGS) -flto
CFLAGS_SO	= $(CFLAGS) -fpic

export	CFLAGS_A
export	CFLAGS_SO

################################################################################
# c++flags
CXXFLAGS_STD	= -std=gnu++20

CXXFLAGS_OPT	= -O3
## XXX: optimize for native if portability is not needed
#CXXFLAGS_OPT   += -march=native
#CXXFLAGS_OPT   += -flto

CXXFLAGS_W	= -Wall
CXXFLAGS_W     += -Wextra
CXXFLAGS_W     += -Wpedantic
CXXFLAGS_W     += -pedantic-errors
CXXFLAGS_W     += -fno-common
CXXFLAGS_W     += -Wno-vla
CXXFLAGS_W     += -Werror

CXXFLAGS_D	= -D _GNU_SOURCE
CXXFLAGS_D     += -D _POSIX_C_SOURCE=200809L
CXXFLAGS_D     += $(CPP_DEFINITIONS)

CXXFLAGS_PKG	= `pkg-config --cflags libbsd-overlay`

CXXFLAGS_I	= -I $(INC_DIR)

CXXFLAGS	= $(CXXFLAGS_STD)
CXXFLAGS       += $(CXXFLAGS_OPT)
CXXFLAGS       += $(CXXFLAGS_W)
CXXFLAGS       += $(CXXFLAGS_D)
CXXFLAGS       += $(CXXFLAGS_PKG)
CXXFLAGS       += $(CXXFLAGS_I)

export	CXXFLAGS

CXXFLAGS_A	= $(CXXFLAGS) -flto
CXXFLAGS_SO	= $(CXXFLAGS) -fpic

export	CXXFLAGS_A
export	CXXFLAGS_SO

################################################################################
# libs
LDFLAGS_OPT	= -O3
#LDFLAGS_OPT    += -flto
#LDFLAGS_OPT    += -fuse-linker-plugin

LDFLAGS_W	= -Wall
LDFLAGS_W	+= -Wextra
LDFLAGS_W	+= -fno-common
LDFLAGS_W	+= -Werror

LDFLAGS_L	= -L $(BUILD_LIB_DIR)/libalx/

LDFLAGS		= -shared
LDFLAGS        += $(LDFLAGS_OPT)
LDFLAGS        += $(LDFLAGS_W)
LDFLAGS        += $(LDFLAGS_L)

export	LDFLAGS

################################################################################
# compile

PHONY := all
all: base alx extra


COMPILE_VIRTUAL	=							\
	alx								\
	extra

COMPILE_TARGETS	=							\
	base								\
	data-structures							\
	robot								\
	curl								\
	cv								\
	gmp								\
	gsl								\
	ncurses								\
	ocr								\
	plot								\
	telnet-tcp							\
	zbar

$(COMPILE_VIRTUAL):
$(COMPILE_TARGETS):

PHONY	+= base_tmp
base: | base_tmp base_lib

PHONY	+= alx
alx: | data-structures
#alx: | npcomplete
alx: | robot
PHONY	+= data-structures
data-structures: | data-structures_tmp data-structures_lib
PHONY	+= npcomplete
npcomplete: | npcomplete_tmp npcomplete_lib
PHONY	+= robot
robot: | robot_tmp robot_lib

PHONY	+= extra
extra: | curl
extra: | cv
extra: | gmp
extra: | gsl
extra: | ncurses
extra: | ocr
extra: | plot
extra: | telnet-tcp
extra: | zbar
PHONY	+= curl
curl: | curl_tmp curl_lib
PHONY	+= cv
cv: | cv_tmp cv_lib
PHONY	+= gmp
gmp: | gmp_tmp gmp_lib
PHONY	+= gsl
gsl: | gsl_tmp gsl_lib
PHONY	+= ncurses
ncurses: | ncurses_tmp ncurses_lib
PHONY	+= ocr
ocr: | ocr_tmp ocr_lib
PHONY	+= plot
plot: | plot_tmp plot_lib
PHONY	+= telnet-tcp
telnet-tcp: | telnet-tcp_tmp telnet-tcp_lib
PHONY	+= zbar
zbar: | zbar_tmp zbar_lib

################################################################################
# compile actual

COMPILE_ACTUAL_TMP_TARGETS	= $(COMPILE_TARGETS:=_tmp)
COMPILE_ACTUAL_LIB_TARGETS	= $(COMPILE_TARGETS:=_lib)

$(filter-out base_lib, $(COMPILE_ACTUAL_LIB_TARGETS)): base_lib
curl_lib: data-structures_lib
cv_lib: gsl_lib

PHONY	+= $(COMPILE_ACTUAL_TMP_TARGETS)
$(COMPILE_ACTUAL_TMP_TARGETS): %_tmp:
	$(Q)$(MAKE) $*	-f tmp.mk	-C $(SRC_DIR)
PHONY	+= $(COMPILE_ACTUAL_LIB_TARGETS)
$(COMPILE_ACTUAL_LIB_TARGETS): %_lib: %_tmp
	$(Q)$(MAKE) $*	-f lib.mk	-C $(SRC_DIR)


################################################################################
# install

INSTALL_VIRTUAL	=							\
	install_alx							\
	install_extra							\
	install_sh							\
	install_py

INSTALL_TARGETS	=							\
	install-doc							\
	install-base							\
	install-data-structures						\
	install-robot							\
	install-curl							\
	install-cv							\
	install-gmp							\
	install-gsl							\
	install-ncurses							\
	install-ocr							\
	install-plot							\
	install-telnet-tcp						\
	install-zbar

$(INSTALL_VIRTUAL):
	$(Q)$(MAKE) conf_ld
$(INSTALL_TARGETS):
	$(Q)$(MAKE) conf_ld

PHONY	+= install
install: | install-base
install: | install_alx
install: | install_extra
install: | install_sh
install: | install_py
install: | install-doc

PHONY	+= install-doc
install-doc: | inst-share-doc
install-doc: | inst-share-man

PHONY	+= install-base
install-base: | inst-inc-base
install-base: | inst-libalx-base
install-base: | install-doc

PHONY	+= install_alx
install_alx: | install-data-structures
#install_alx: | install-npcomplete
install_alx: | install-robot
install_alx: | install-base

PHONY	+= install-data-structures
install-data-structures: | inst-inc-a-data-structures inst-libalx-data-structures
install-data-structures: | install-base
PHONY	+= install-npcomplete
install-npcomplete: | inst-inc-a-npcomplete inst-libalx-npcomplete install-base
PHONY	+= install-robot
install-robot: | inst-inc-a-robot inst-libalx-robot
install-robot: | install-base install-telnet-tcp

PHONY	+= install_extra
install_extra: | install-curl
install_extra: | install-cv
install_extra: | install-gmp
install_extra: | install-gsl
install_extra: | install-ncurses
install_extra: | install-ocr
install_extra: | install-plot
install_extra: | install-telnet-tcp
install_extra: | install-zbar
install_extra: | install-base

PHONY	+= install-curl
install-curl: | inst-inc-x-curl inst-libalx-curl install-base install-data-structures
PHONY	+= install-cv
install-cv: | inst-inc-x-cv inst-libalx-cv install-base install-gsl
PHONY	+= install-gmp
install-gmp: | inst-inc-x-gmp inst-libalx-gmp install-base
PHONY	+= install-gsl
install-gsl: | inst-inc-x-gsl inst-libalx-gsl install-base
PHONY	+= install-ncurses
install-ncurses: | inst-inc-x-ncurses inst-libalx-ncurses install-base
PHONY	+= install-ocr
install-ocr: | inst-etc-x-ocr inst-inc-x-ocr inst-libalx-ocr install-base
PHONY	+= install-plot
install-plot: | inst-inc-x-plot inst-libalx-plot install-base
PHONY	+= install-telnet-tcp
install-telnet-tcp: | inst-inc-x-telnet-tcp inst-libalx-telnet-tcp install-base
PHONY	+= install-zbar
install-zbar: | inst-inc-x-zbar inst-libalx-zbar install-base

PHONY	+= install-sh
install_sh: | inst-sh install-doc

PHONY	+= install-py
install_py: | inst-py install-doc

################################################################################
# install actual

PHONY	+= inst-sh
inst-sh:
	$(Q)mkdir -p		$(DESTDIR)/$(libdir_)/sh/
	@echo	"	CP -r	$(DESTDIR)/$(libdir_)/sh/"
	$(Q)cp -rf $(v) -t	$(DESTDIR)/$(libdir_)/sh/..	$(LIB_DIR_)/sh/

PHONY	+= inst-py
inst-py:
	$(Q)mkdir -p		$(DESTDIR)/$(libdir_)/py/
	@echo	"	CP -r	$(DESTDIR)/$(libdir_)/py/"
	$(Q)cp -rf $(v) -t	$(DESTDIR)/$(libdir_)/py/..	$(LIB_DIR_)/py/

PHONY += inst-share-doc
inst-share-doc:
	$(Q)mkdir -p		$(DESTDIR)/$(docdir_)/
	@echo	"	CP -r	$(DESTDIR)/$(docdir_)/"
	$(Q)cp -rf $(v) -t	$(DESTDIR)/$(docdir_)/..	$(DOC_DIR_)/

PHONY += inst-share-man
inst-share-man:
	$(Q)mkdir -p		$(DESTDIR)/$(mandir)/
	@echo	"	CP -r	$(DESTDIR)/$(mandir)/"
	$(Q)cp -rf $(v) -t	$(DESTDIR)/$(mandir)/..	$(MAN_DIR)/

PHONY += inst-etc-x-%
inst-etc-x-%:
	$(Q)mkdir -p		$(DESTDIR)/$(sysconfdir_)/extra/$*/
	@echo	"	CP -r	$(DESTDIR)/$(sysconfdir_)/extra/$*/"
	$(Q)cp -rf $(v) -t	$(DESTDIR)/$(sysconfdir_)/extra/$*/..	\
				$(ETC_DIR_)/extra/$*/

PHONY += inst-inc-base
inst-inc-base:
	$(Q)mkdir -p		$(DESTDIR)/$(includedir_)/base/
	@echo	"	CP -r	$(DESTDIR)/$(includedir_)/base/"
	$(Q)cp -rf $(v) -t	$(DESTDIR)/$(includedir_)/base/..	\
				$(INC_DIR_)/base/

PHONY += inst-inc-a-%
inst-inc-a-%:
	$(Q)mkdir -p		$(DESTDIR)/$(includedir_)/alx/$*/
	@echo	"	CP -r	$(DESTDIR)/$(includedir_)/alx/$*/"
	$(Q)cp -rf $(v) -t	$(DESTDIR)/$(includedir_)/alx/$*/..	\
				$(INC_DIR_)/alx/$*/

PHONY += inst-inc-x-%
inst-inc-x-%:
	$(Q)mkdir -p		$(DESTDIR)/$(includedir_)/extra/$*/
	@echo	"	CP -r	$(DESTDIR)/$(includedir_)/extra/$*/"
	$(Q)cp -rf $(v) -t	$(DESTDIR)/$(includedir_)/extra/$*/..	\
				$(INC_DIR_)/extra/$*/

LIB_FILES	= 
PHONY	+= inst-lib%
inst-lib%: | inst--lib%.a inst--lib%.so inst--lib%.pc
	@:

PHONY += inst--lib%.a
inst--lib%.a:
	$(Q)mkdir -p		$(DESTDIR)/$(libdir_)/
	@echo	"	CP	$(DESTDIR)/$(libdir_)/lib$*.a"
	$(Q)cp -f $(v) -t	$(DESTDIR)/$(libdir_)/	$(BUILD_A_DIR_)/lib$*.a

PHONY += inst--lib%.so
inst--lib%.so:
	$(Q)mkdir -p		$(DESTDIR)/$(libdir_)/
	@echo	"	CP	$(DESTDIR)/$(libdir_)/lib$*.so.$(LIBVERSION)"
	$(Q)cp -f $(v) -t	$(DESTDIR)/$(libdir_)/			\
				$(BUILD_SO_DIR_)/lib$*.so.$(LIBVERSION)
	@echo	"	LN -s	$(DESTDIR)/$(libdir_)/lib$*.so"
	$(Q)ln -sf -T		lib$*.so.$(VERSION)			\
					$(DESTDIR)/$(libdir_)/lib$*.so

PHONY += inst--lib%.pc
inst--lib%.pc:
	$(Q)mkdir -p		$(DESTDIR)/$(libdir)/pkgconfig/
	@echo	"	CP	$(DESTDIR)/$(libdir)/pkgconfig/lib$*.pc"
	$(Q)sed	"s/<version>/$(LIBVERSION)/"				\
				$(LIB_DIR)/pkgconfig/lib$*.pc		\
				>	$(DESTDIR)/$(libdir)/pkgconfig/lib$*.pc


################################################################################
# uninstall

PHONY += uninstall
uninstall:
	@echo	"	Uninstall:"
	@echo	"	RM -rf	$(DESTDIR)/$(sysconfdir_)/"
	$(Q)rm -f -r		$(DESTDIR)/$(sysconfdir_)/
	@echo	"	RM -rf	$(DESTDIR)/$(includedir_)/"
	$(Q)rm -f -r		$(DESTDIR)/$(includedir_)/
	@echo	"	RM -rf	$(DESTDIR)/$(libdir_)/"
	$(Q)rm -f -r		$(DESTDIR)/$(libdir_)/
	@echo	"	RM -rf	$(DESTDIR)/$(docdir_)/"
	$(Q)rm -f -r		$(DESTDIR)/$(docdir_)/
	@echo	"	RM -rf	$(DESTDIR)/$(mandir)/*$(package_shortname)"
	$(Q)rm -f		$(DESTDIR)/$(mandir)/*$(package_shortname)
	@echo	"	RM -rf	$(DESTDIR)/$(libdir)/pkgconfig/libalx*.pc"
	$(Q)mkdir -p		$(DESTDIR)/$(libdir)/pkgconfig/
	$(Q)find		$(DESTDIR)/$(libdir)/pkgconfig/		\
				-type f -name 'libalx*.pc' -exec rm '{}' '+'
	@echo	"	LDCONFIG"
	$(Q)ldconfig
	@echo	"	RM	$(DESTDIR)/etc/ld.so.conf.d/libalx*.conf"
	$(Q)find		$(DESTDIR)/etc/ld.so.conf.d/		\
				-type f -name 'libalx*.conf' -exec rm '{}' '+'
	@echo	"	LDCONFIG"
	$(Q)ldconfig
	@echo	"	Done"

################################################################################
# ldconfig

PHONY	+= conf_ld
conf_ld:
	@echo	"	LDCONFIG"
	$(Q)mkdir -p		$(DESTDIR)/etc/ld.so.conf.d/
	$(Q)cp -rf $(v) -t	$(DESTDIR)/etc/ld.so.conf.d/		\
				$(ETC_DIR)/ld.so.conf.d/

	$(Q)flock /tmp	-c ldconfig

################################################################################
# clean

PHONY += clean
clean:
	@echo	"	RM	$(BUILD_DIR)"
	$(Q)rm -rf	$(BUILD_DIR)

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################

