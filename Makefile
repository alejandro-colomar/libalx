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
# directories

LIBALX_DIR	= $(CURDIR)

BIN_DIR		= $(LIBALX_DIR)/bin
INC_DIR		= $(LIBALX_DIR)/include
SRC_DIR		= $(LIBALX_DIR)/src
LIB_DIR		= $(LIBALX_DIR)/lib
ETC_DIR		= $(LIBALX_DIR)/etc
SHARE_DIR	= $(LIBALX_DIR)/share
BUILD_DIR	= $(LIBALX_DIR)/build
BUILD_TMP_DIR	= $(BUILD_DIR)/tmp
BUILD_LIB_DIR	= $(BUILD_DIR)/lib
BUILD_A_DIR	= $(BUILD_LIB_DIR)/static
BUILD_SO_DIR	= $(BUILD_LIB_DIR)/shared

export	LIBALX_DIR

export	BIN_DIR
export	INC_DIR
export	SRC_DIR
export	LIB_DIR
export	ETC_DIR
export	SHARE_DIR
export	BUILD_DIR
export	BUILD_TMP_DIR
export	BUILD_LIB_DIR
export	BUILD_A_DIR
export	BUILD_SO_DIR

## XXX: make ... LOCAL= to build in /usr/
ifndef LOCAL
  LOCAL			= local
endif
ifeq ("$(LOCAL)","local")
  INSTALL_ETC_DIR	= /usr/local/etc
else
  INSTALL_ETC_DIR	= /etc
endif
INSTALL_INC_DIR		= /usr/$(LOCAL)/include
INSTALL_LIB_DIR		= /usr/$(LOCAL)/lib
INSTALL_SHARE_DIR	= /usr/$(LOCAL)/share
INSTALL_PC_DIR		= $(INSTALL_LIB_DIR)/pkgconfig

export	INSTALL_ETC_DIR
export	INSTALL_INC_DIR
export	INSTALL_LIB_DIR
export	INSTALL_SHARE_DIR
export	INSTALL_PC_DIR

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
CFLAGS_D       += -D INSTALL_ETC_DIR=\"$(INSTALL_ETC_DIR)\"

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
CXXFLAGS_D     += -D INSTALL_ETC_DIR=\"$(INSTALL_ETC_DIR)\"

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
install-doc: | inst-share

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
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/*"
	$(Q)cp -rf $(v)		$(LIB_DIR)/libalx/sh/*			\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/

PHONY	+= inst-py
inst-py:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/*"
	$(Q)cp -rf $(v)		$(LIB_DIR)/libalx/py/*			\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/

PHONY += inst-share
inst-share:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/*"
	$(Q)cp -r -f $(v)	$(SHARE_DIR)/libalx/*		\
					$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/

PHONY += inst-etc-x-%
inst-etc-x-%:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/$*/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/$*/*"
	$(Q)cp -r -f $(v)	$(ETC_DIR)/libalx/extra/$*/*		\
					$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/$*/

PHONY += inst-inc-base
inst-inc-base:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/*"
	$(Q)cp -r -f $(v)	$(INC_DIR)/libalx/base/*		\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/

PHONY += inst-inc-a-%
inst-inc-a-%:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/$*/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/$*/*"
	$(Q)cp -r -f $(v)	$(INC_DIR)/libalx/alx/$*/*		\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/$*/

PHONY += inst-inc-x-%
inst-inc-x-%:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/$*/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/$*/*"
	$(Q)cp -r -f $(v)	$(INC_DIR)/libalx/extra/$*/*		\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/$*/

LIB_FILES	= 
PHONY	+= inst-lib%
inst-lib%: | inst--lib%.a inst--lib%.so inst--lib%.pc
	@:

PHONY += inst--lib%.a
inst--lib%.a:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/lib$*.a"
	$(Q)cp -f $(v)		$(BUILD_A_DIR)/libalx/lib$*.a		\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/

PHONY += inst--lib%.so
inst--lib%.so:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/lib$*.so.$(LIBVERSION)"
	$(Q)cp -f $(v)		$(BUILD_SO_DIR)/libalx/lib$*.so.$(LIBVERSION)	\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	LN -s	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/lib$*.so"
	$(Q)ln -sf -T		lib$*.so.$(VERSION)			\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/lib$*.so

PHONY += inst--lib%.pc
inst--lib%.pc:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_PC_DIR)/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_PC_DIR)/lib$*.pc"
	$(Q)sed	"s/<version>/$(LIBVERSION)/"				\
				$(LIB_DIR)/pkgconfig/lib$*.pc		\
				>	$(DESTDIR)/$(INSTALL_PC_DIR)/lib$*.pc


################################################################################
# uninstall

PHONY += uninstall
uninstall:
	@echo	"	Uninstall:"
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_PC_DIR)/libalx*.pc"
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_PC_DIR)/
	$(Q)find		$(DESTDIR)/$(INSTALL_PC_DIR)/	\
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
	$(Q)cp -r -f $(v)	$(ETC_DIR)/ld.so.conf.d/*		\
					$(DESTDIR)/etc/ld.so.conf.d/
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

