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

CFLAGS_PKG	= `pkg-config --cflags libbsd`

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
######## End of file ###########################################################
################################################################################

