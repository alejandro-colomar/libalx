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
######## End of file ###########################################################
################################################################################

