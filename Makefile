#!/usr/bin/make -f
SHELL	= /bin/sh

################################################################################
VERSION		= 1
PATCHLEVEL	= 0
SUBLEVEL	=
EXTRAVERSION	= ~b28
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
# Do not print "Entering directory ..."
MAKEFLAGS += --no-print-directory

################################################################################
include	$(CURDIR)/src/mk/verbose.inc.mk
include	$(CURDIR)/src/mk/dirs.inc.mk
include	$(CURDIR)/src/mk/commands.inc.mk
include	$(CURDIR)/src/mk/cflags.inc.mk
include	$(CURDIR)/src/mk/cxxflags.inc.mk
include	$(CURDIR)/src/mk/ldflags.inc.mk

################################################################################
# compile
COMPILE_TARGETS	=							\
	base								\
	data-structures							\
	robot-ur							\
	cv								\
	gmp								\
	gsl								\
	ncurses								\
	ocr								\
	plot								\
	telnet-tcp							\
	zbar


PHONY := all
all: $(COMPILE_TARGETS)

PHONY	+= $(COMPILE_TARGETS)
$(COMPILE_TARGETS):


base: | base_tmp base_lib

data-structures: | data-structures_tmp data-structures_lib
#npcomplete: | npcomplete_tmp npcomplete_lib
robot-ur: | robot-ur_tmp robot-ur_lib
#robot-kawasaki: | robot-kawasaki_tmp robot-kawasaki_lib

cv: | cv_tmp cv_lib
gmp: | gmp_tmp gmp_lib
gsl: | gsl_tmp gsl_lib
ncurses: | ncurses_tmp ncurses_lib
ocr: | ocr_tmp ocr_lib
plot: | plot_tmp plot_lib
telnet-tcp: | telnet-tcp_tmp telnet-tcp_lib
zbar: | zbar_tmp zbar_lib

################################################################################
# compile actual

COMPILE_ACTUAL_TMP_TARGETS	= $(COMPILE_TARGETS:=_tmp)
COMPILE_ACTUAL_LIB_TARGETS	= $(COMPILE_TARGETS:=_lib)

$(filter-out base_lib, $(COMPILE_ACTUAL_LIB_TARGETS)): base_lib
cv_lib: gsl_lib

PHONY += $(COMPILE_ACTUAL_TMP_TARGETS)
$(COMPILE_ACTUAL_TMP_TARGETS): %_tmp:
	$(Q)$(MAKE) $*	-f tmp.mk	-C $(SRC_DIR)
PHONY += $(COMPILE_ACTUAL_LIB_TARGETS)
$(COMPILE_ACTUAL_LIB_TARGETS): %_lib: %_tmp
	$(Q)$(MAKE) $*	-f lib.mk	-C $(SRC_DIR)

################################################################################
# prerequisites

PREREQ_TARGETS	= $(addprefix prereq-,$(COMPILE_TARGETS))

PHONY += prereq
prereq: $(PREREQ_TARGETS)

$(filter-out prereq-base, $(PREREQ_TARGETS)): prereq-base
prereq-cv: | prereq-gsl

PHONY += $(PREREQ_TARGETS)
prereq-base:
	apt-get install -V --no-install-recommends build-essential;
	apt-get install -V --no-install-recommends git;
	apt-get install -V --no-install-recommends libbsd-dev;
	apt-get install -V --no-install-recommends pkg-config;
prereq-cv:
	apt-get install -V --no-install-recommends libopencv-dev;
prereq-gmp:
	apt-get install -V --no-install-recommends libgmp-dev;
prereq-gsl:
	apt-get install -V --no-install-recommends libgsl-dev;
prereq-ncurses:
	apt-get install -V --no-install-recommends libncurses-dev;
prereq-ocr:
	apt-get install -V --no-install-recommends libtesseract-dev;
	apt-get install -V --no-install-recommends tesseract-ocr-eng;
prereq-plot:
	apt-get install -V --no-install-recommends gnuplot;
prereq-telnet-tcp:
	apt-get install -V --no-install-recommends telnet;
prereq-zbar:
	apt-get install -V --no-install-recommends libzbar-dev;

################################################################################
# install

install:
	$(Q)$(MAKE)	install-base
	$(Q)$(MAKE)	install-base-dev
	$(Q)$(MAKE)	install-data-structures
	$(Q)$(MAKE)	install-data-structures-dev
	$(Q)$(MAKE)	install-robot-ur
	$(Q)$(MAKE)	install-robot-ur-dev
	$(Q)$(MAKE)	install-gmp
	$(Q)$(MAKE)	install-gmp-dev
	$(Q)$(MAKE)	install-gsl
	$(Q)$(MAKE)	install-cv
	$(Q)$(MAKE)	install-gsl-dev
	$(Q)$(MAKE)	install-cv-dev
	$(Q)$(MAKE)	install-ncurses
	$(Q)$(MAKE)	install-ncurses-dev
	$(Q)$(MAKE)	install-ocr
	$(Q)$(MAKE)	install-ocr-dev
	$(Q)$(MAKE)	install-plot
	$(Q)$(MAKE)	install-plot-dev
	$(Q)$(MAKE)	install-telnet-tcp
	$(Q)$(MAKE)	install-telnet-tcp-dev
	$(Q)$(MAKE)	install-zbar
	$(Q)$(MAKE)	install-zbar-dev
	$(Q)$(MAKE)	install-doc

INSTALL_LIB_ALX =							\
	install-data-structures						\
	install-robot-ur

INSTALL_LIB_EXTRA =							\
	install-cv							\
	install-gmp							\
	install-gsl							\
	install-ncurses							\
	install-ocr							\
	install-plot							\
	install-telnet-tcp						\
	install-zbar

INSTALL_DEV_ALX = $(INSTALL_LIB_ALX:=-dev)
INSTALL_DEV_EXTRA = $(INSTALL_LIB_EXTRA:=-dev)

PHONY += install-doc
install-doc:
	@echo	"	INSTALL	$(DESTDIR)$(docdir_)/"
	$(Q)mkdir -p		"$(DESTDIR)$(docdir)/"
	$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(docdir)/"			\
				"$(DOC_DIR_)/"

PHONY += install-base
install-base: install-%: | _inst-%-etc _inst-%-lib _inst-ld
	$(Q)$(MAKE) ldconfig

PHONY += install-base-dev
PHONY += $(INSTALL_LIB_ALX)
PHONY += $(INSTALL_LIB_EXTRA)
PHONY += $(INSTALL_DEV_ALX)
PHONY += $(INSTALL_DEV_EXTRA)


$(INSTALL_LIB_ALX): install-%: | _inst-alx-%-etc _inst-%-lib _inst-ld
	$(Q)$(MAKE) ldconfig
$(INSTALL_LIB_EXTRA): install-%: | _inst-extra-%-etc _inst-%-lib _inst-ld
	$(Q)$(MAKE) ldconfig
install-base-dev: install-%-dev: | _inst-base-man _inst-base-inc _inst-%-pc
	@:
$(INSTALL_DEV_ALX): install-%-dev: | _inst-alx-%-man _inst-alx-%-inc _inst-%-pc
	@:
$(INSTALL_DEV_EXTRA): install-%-dev: | _inst-extra-%-man _inst-extra-%-inc _inst-%-pc
	@:

########################################################################
## Install helpers

PHONY	+= _inst-base-etc
_inst-base-etc:
	@echo	"	INSTALL	$(DESTDIR)$(sysconfdir_)/base/"
	$(Q)mkdir -p		"$(DESTDIR)$(sysconfdir_)/"
	-$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(sysconfdir_)/"		\
				"$(ETC_DIR_)/base/"			\
				2> /dev/null

PHONY	+= _inst-alx-%-etc
_inst-alx-%-etc:
	@echo	"	INSTALL	$(DESTDIR)$(sysconfdir_)/alx/$*/"
	$(Q)mkdir -p		"$(DESTDIR)$(sysconfdir_)/alx/"
	-$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(sysconfdir_)/alx/"		\
				"$(ETC_DIR_)/alx/$*/"			\
				2> /dev/null

PHONY	+= _inst-extra-%-etc
_inst-extra-%-etc:
	@echo	"	INSTALL	$(DESTDIR)$(sysconfdir_)/extra/$*/"
	$(Q)mkdir -p		"$(DESTDIR)$(sysconfdir_)/extra/"
	-$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(sysconfdir_)/extra/"	\
				"$(ETC_DIR_)/extra/$*/"			\
				2> /dev/null

PHONY	+= _inst-%-lib
_inst-%-lib: | _inst-%-lib-a _inst-%-lib-so
	@:

PHONY	+= _inst-%-lib-a
_inst-%-lib-a:
	@echo	"	INSTALL	$(DESTDIR)$(libdir_)/libalx-$*.a"
	$(Q)mkdir -p		"$(DESTDIR)$(libdir_)/"
	$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(libdir_)/"			\
				"$(BUILD_A_DIR_)/libalx-$*.a"

PHONY	+= _inst-%-lib-so
_inst-%-lib-so:
	@echo	"	INSTALL	$(DESTDIR)$(libdir_)/libalx-$*.so.$(LIBVERSION)"
	$(Q)mkdir -p		"$(DESTDIR)$(libdir_)/"
	$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(libdir_)/"			\
				"$(BUILD_SO_DIR_)/libalx-$*.so.$(LIBVERSION)"
	@echo	"	LN -s	$(DESTDIR)$(libdir_)/libalx-$*.so"
	$(Q)ln -sf -T		"libalx-$*.so.$(VERSION)"		\
					"$(DESTDIR)$(libdir_)/libalx-$*.so"

PHONY	+= _inst-base-man
_inst-base-man:
	@echo	"	INSTALL	$(DESTDIR)$(mandir)/"
	$(Q)mkdir -p		"$(DESTDIR)$(mandir)/"
	-$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(mandir)/"			\
				$(MAN_DIR)/base/*			\
				2> /dev/null

PHONY	+= _inst-alx-%-man
_inst-alx-%-man:
	@echo	"	INSTALL	$(DESTDIR)$(mandir)/"
	$(Q)mkdir -p		"$(DESTDIR)$(mandir)/"
	-$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(mandir)/"			\
				$(MAN_DIR)/alx/$*/*			\
				2> /dev/null

PHONY	+= _inst-extra-%-man
_inst-extra-%-man:
	@echo	"	INSTALL	$(DESTDIR)$(mandir)/"
	$(Q)mkdir -p		"$(DESTDIR)$(mandir)/"
	-$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(mandir)/"			\
				$(MAN_DIR)/extra/$*/*			\
				2> /dev/null

PHONY	+= _inst-base-inc
_inst-base-inc:
	@echo	"	INSTALL	$(DESTDIR)$(includedir_)/base/"
	$(Q)mkdir -p		"$(DESTDIR)$(includedir_)/"
	$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(includedir_)/"		\
				"$(INC_DIR_)/base/"

PHONY	+= _inst-alx-%-inc
_inst-alx-%-inc:
	@echo	"	INSTALL	$(DESTDIR)$(includedir_)/alx/$*/"
	$(Q)mkdir -p		"$(DESTDIR)$(includedir_)/alx/"
	$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(includedir_)/alx/"		\
				"$(INC_DIR_)/alx/$*/"

PHONY	+= _inst-extra-%-inc
_inst-extra-%-inc:
	@echo	"	INSTALL	$(DESTDIR)$(includedir_)/extra/$*/"
	$(Q)mkdir -p		"$(DESTDIR)$(includedir_)/extra/"
	$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)$(includedir_)/extra/"	\
				"$(INC_DIR_)/extra/$*/"

PHONY	+= _inst-%-pc
_inst-%-pc:
	@echo	"	INSTALL	$(DESTDIR)$(libdir)/pkgconfig/libalx-$*.pc"
	$(Q)sed	"s/<version>/$(LIBVERSION)/"				\
				"$(LIB_DIR)/pkgconfig/libalx-$*.pc"		\
				> "$(LIB_DIR)/pkgconfig/libalx-$*.pc.$(LIBVERSION)"
	$(Q)mkdir -p		"$(DESTDIR)$(libdir)/pkgconfig/"
	$(Q)$(INSTALL_DATA) -T	"$(LIB_DIR)/pkgconfig/libalx-$*.pc.$(LIBVERSION)" \
				"$(DESTDIR)$(libdir)/pkgconfig/libalx-$*.pc"

PHONY	+= _inst-ld
_inst-ld:
	@echo	"	INSTALL	$(DESTDIR)/etc/ld.so.conf.d/libalx.conf"
	$(Q)mkdir -p		"$(DESTDIR)/etc/ld.so.conf.d/"
	$(Q)$(INSTALL_DATA) -t	"$(DESTDIR)/etc/ld.so.conf.d/"		\
				"$(ETC_DIR)/ld.so.conf.d/libalx.conf"


################################################################################
# uninstall

PHONY += uninstall
uninstall:
	@echo	"	Uninstall:"
	@echo	"	RM -rf	$(DESTDIR)$(sysconfdir_)/"
	$(Q)rm -f -r		$(DESTDIR)$(sysconfdir_)/
	@echo	"	RM -rf	$(DESTDIR)$(includedir_)/"
	$(Q)rm -f -r		$(DESTDIR)$(includedir_)/
	@echo	"	RM -rf	$(DESTDIR)$(libdir_)/"
	$(Q)rm -f -r		$(DESTDIR)$(libdir_)/
	@echo	"	RM -rf	$(DESTDIR)$(docdir_)/"
	$(Q)rm -f -r		$(DESTDIR)$(docdir_)/
	@echo	"	RM -rf	$(DESTDIR)$(mandir)/*$(package_shortname)"
	$(Q)rm -f		$(DESTDIR)$(mandir)/*$(package_shortname)
	@echo	"	RM -rf	$(DESTDIR)$(libdir)/pkgconfig/libalx*.pc"
	$(Q)mkdir -p		$(DESTDIR)$(libdir)/pkgconfig/
	$(Q)find		$(DESTDIR)$(libdir)/pkgconfig/		\
				-type f -name 'libalx*.pc' -exec rm '{}' '+'
	@echo	"	LDCONFIG"
	$(Q)$(LDCONFIG)
	@echo	"	RM	$(DESTDIR)/etc/ld.so.conf.d/libalx*.conf"
	$(Q)find		$(DESTDIR)/etc/ld.so.conf.d/		\
				-type f -name 'libalx*.conf' -exec rm '{}' '+'
	@echo	"	LDCONFIG"
	$(Q)$(LDCONFIG)
	@echo	"	Done"

################################################################################
# ldconfig

PHONY	+= ldconfig
ldconfig:
	@echo	"	LDCONFIG"
	$(Q)$(LDCONFIG)

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

