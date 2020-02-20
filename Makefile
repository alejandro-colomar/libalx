#! /usr/bin/make -f

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

INC_DIR		= $(LIBALX_DIR)/include/
SRC_DIR		= $(LIBALX_DIR)/src/
LIB_DIR		= $(LIBALX_DIR)/lib/
ETC_DIR		= $(LIBALX_DIR)/etc/
SHARE_DIR	= $(LIBALX_DIR)/share/
MK_DIR		= $(LIBALX_DIR)/mk/
BUILD_DIR	= $(LIBALX_DIR)/build/
BUILD_TMP_DIR	= $(BUILD_DIR)/tmp/
BUILD_LIB_DIR	= $(BUILD_DIR)/lib/
TST_DIR		= $(LIBALX_DIR)/test/

export	LIBALX_DIR

export	INC_DIR
export	SRC_DIR
export	LIB_DIR
export	MK_DIR
export	BUILD_DIR
export	BUILD_TMP_DIR
export	BUILD_LIB_DIR
export	TST_DIR

# XXX: make ... LOCAL=local to build in /usr/local/
ifndef LOCAL
  LOCAL			=
endif
ifeq ("$(LOCAL)","local")
  INSTALL_ETC_DIR	= /usr/local/etc/
else
  INSTALL_ETC_DIR	= /etc/
endif
INSTALL_INC_DIR		= /usr/$(LOCAL)/include/
INSTALL_LIB_DIR		= /usr/$(LOCAL)/lib/
INSTALL_SHARE_DIR	= /usr/$(LOCAL)/share/
INSTALL_PKGCONFIG_DIR	= $(INSTALL_LIB_DIR)/pkgconfig/

export	INSTALL_ETC_DIR
export	INSTALL_INC_DIR
export	INSTALL_LIB_DIR
export	INSTALL_SHARE_DIR
export	INSTALL_PKGCONFIG_DIR

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
CFLAGS_STD	= -std=gnu17

CFLAGS_OPT	= -O3
CFLAGS_OPT     += -march=native
CFLAGS_OPT     += -flto

CFLAGS_W	= -Wall
CFLAGS_W       += -Wextra
CFLAGS_W       += -Wstrict-prototypes
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

CFLAGS_A	= $(CFLAGS)
CFLAGS_SO	= $(CFLAGS) -fpic

export	CFLAGS_A
export	CFLAGS_SO

################################################################################
# c++flags
CXXFLAGS_STD	= -std=gnu++17

CXXFLAGS_OPT	= -O3
CXXFLAGS_OPT   += -march=native
CXXFLAGS_OPT   += -flto

CXXFLAGS_W	= -Wall
CXXFLAGS_W     += -Wextra
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

CXXFLAGS_A	= $(CXXFLAGS)
CXXFLAGS_SO	= $(CXXFLAGS) -fpic

export	CXXFLAGS_A
export	CXXFLAGS_SO

################################################################################
# libs
LDFLAGS_OPT	= -O3
LDFLAGS_OPT    += -march=native
LDFLAGS_OPT    += -flto
LDFLAGS_OPT    += -fuse-linker-plugin

LDFLAGS_L	= -L $(BUILD_LIB_DIR)/libalx/

LDFLAGS		= -shared
LDFLAGS        += $(LDFLAGS_OPT)
LDFLAGS        += $(LDFLAGS_L)

export	LDFLAGS

################################################################################
# target: dependencies
#	action

PHONY := all
all: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)


PHONY := build_dir
build_dir:
	@echo	"	CP	build/*"
	$(Q)mkdir -p	$(BUILD_DIR)/
	$(Q)cp -rf	$(MK_DIR)/build/*	$(BUILD_DIR)/


PHONY += base
base: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)


PHONY += alx
alx: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)

PHONY += data-structures
data-structures: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)

PHONY += npcomplete
npcomplete: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)

PHONY += robot
robot: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)


PHONY += extra
extra: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)

PHONY += curl
curl: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)

PHONY += cv
cv: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)

PHONY += gmp
gmp: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)

PHONY += gsl
gsl: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)

PHONY += ncurses
ncurses: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)

PHONY += ocr
ocr: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)

PHONY += zbar
zbar: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)


PHONY += nix
nix: build_dir
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(BUILD_TMP_DIR)
	$(Q)$(MAKE) $@	-C $(BUILD_LIB_DIR)


PHONY += tst
tst: all
	@echo	"	MAKE	tst"
	$(Q)$(MAKE)	-C $(TST_DIR)


PHONY += install
install:
	@echo	"	Install:"
	@echo
	$(Q)$(MAKE)	install_base
	$(Q)$(MAKE)	install_alx
	$(Q)$(MAKE)	install_extra
	$(Q)$(MAKE)	install_sh
	$(Q)$(MAKE)	install_py
	$(Q)$(MAKE)	conf_ld
	@echo	"	Done"
	@echo

PHONY += install_base
install_base:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/*"
	$(Q)cp -rf $(v)		$(INC_DIR)/libalx/base/*		\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/*"
	$(Q)cp -rf $(v)		$(SHARE_DIR)/libalx/*			\
					$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/
	$(Q)$(MAKE)	libalx-base.a	libalx-base.so	libalx-base.pc
	@echo

PHONY += install_alx
install_alx:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/*"
	$(Q)cp -r -f $(v)	$(INC_DIR)/libalx/alx/*			\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/
	$(Q)$(MAKE)	libalx-data-structures.a			\
			libalx-data-structures.so			\
			libalx-data-structures.pc
#	$(Q)$(MAKE)	libalx-npcomplete.a				\
#			libalx-npcomplete.so				\
#			libalx-npcomplete.pc
	$(Q)$(MAKE)	libalx-robot.a	libalx-robot.so	libalx-robot.pc
	@echo

PHONY += install_extra
install_extra:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/*"
	$(Q)cp -r -f $(v)	$(ETC_DIR)/libalx/extra/*		\
					$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/*"
	$(Q)cp -r -f $(v)	$(INC_DIR)/libalx/extra/*		\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/
	$(Q)$(MAKE)	libalx-curl.a	libalx-curl.so	libalx-curl.pc
	$(Q)$(MAKE)	libalx-cv.a	libalx-cv.so	libalx-cv.pc
	$(Q)$(MAKE)	libalx-gmp.a	libalx-gmp.so	libalx-gmp.pc
	$(Q)$(MAKE)	libalx-gsl.a	libalx-gsl.so	libalx-gsl.pc
	$(Q)$(MAKE)	libalx-ncurses.a libalx-ncurses.so libalx-ncurses.pc
	$(Q)$(MAKE)	libalx-ocr.a	libalx-ocr.so	libalx-ocr.pc
	$(Q)$(MAKE)	libalx-zbar.a	libalx-zbar.so	libalx-zbar.pc
	@echo

PHONY += install_sh
install_sh:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/*"
	$(Q)cp -rf $(v)		$(LIB_DIR)/libalx/sh/*			\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/
	@echo

PHONY += install_py
install_py:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/*"
	$(Q)cp -rf $(v)		$(LIB_DIR)/libalx/py/*			\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/
	@echo

PHONY += conf_ld
conf_ld:
	@echo	"	CP -r	$(DESTDIR)/etc/ld.so.conf.d/*"
	$(Q)cp -r -f $(v)	$(ETC_DIR)/ld.so.conf.d/*		\
					$(DESTDIR)/etc/ld.so.conf.d/
	@echo	"	LDCONFIG"
	$(Q)ldconfig
	@echo

PHONY += libalx-%.a
libalx-%.a:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/$@"
	$(Q)cp -f $(v)		$(BUILD_LIB_DIR)/libalx/$@		\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/$@

PHONY += libalx-%.so
libalx-%.so:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/$@"
	$(Q)cp -f $(v)		$(BUILD_LIB_DIR)/libalx/$@		\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/$@

PHONY += libalx-%.pc
libalx-%.pc:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/$@"
	$(Q)cp -f $(v)		$(LIB_DIR)/pkgconfig/$@			\
					$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/

PHONY += uninstall
uninstall:
	@echo	"	Clean old installations:"
	@echo
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/libalx*.pc"
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/
	$(Q)find		$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/	\
				-type f -name 'libalx*.pc' -exec rm '{}' '+'
	@echo	"	RM	$(DESTDIR)/etc/ld.so.conf.d/libalx*.conf"
	$(Q)find		$(DESTDIR)/etc/ld.so.conf.d/		\
				-type f -name 'libalx*.conf' -exec rm '{}' '+'
	@echo	"	LDCONFIG"
	$(Q)ldconfig
	@echo	"	Done"
	@echo


PHONY += clean
clean:
	@echo	"	RM	$(BUILD_DIR)"
	$(Q)rm -rf	$(BUILD_DIR)
	@echo	"	RM	*-test"
	$(Q)find $(TST_DIR) -type f -name '*-test' -exec rm '{}' '+'

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
