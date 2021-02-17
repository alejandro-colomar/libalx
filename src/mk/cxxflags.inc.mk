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

CXXFLAGS_PKG	= `pkg-config --cflags libbsd`

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
######## End of file ###########################################################
################################################################################

