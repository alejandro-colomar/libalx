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
# dependencies

MK_DEPS	=								\
	$(SRC_DIR)/base/Makefile					\
	$(SRC_DIR)/tmp.mk						\
	$(PROJECT_DIR)/Makefile

MODULES	=								\
	base/assert/array						\
	base/assert/assert						\
	base/assert/char						\
	base/assert/pointer						\
	base/assert/must_be						\
	base/assert/stddef						\
	base/assert/stdint						\
	base/assert/type						\
	base/compiler/attribute						\
	base/compiler/size						\
	base/compiler/type						\
	base/compiler/unused						\
	base/errno/error						\
	base/errno/perror						\
	base/float/constant						\
	base/float/printf						\
	base/float/scanf						\
	base/libgen/basename						\
	base/libgen/dirname						\
	base/linux/membarrier						\
	base/math/array_division					\
	base/math/array_multiplication					\
	base/math/array_sum						\
	base/math/binomial_coefficient					\
	base/math/matrix_addition					\
	base/math/matrix_subtraction					\
	base/math/pascal_triangle					\
	base/math/scale_linear						\
	base/signal/sigpipe						\
	base/signal/sigterm						\
	base/stdint/constants						\
	base/stdint/mask/bit						\
	base/stdint/mask/field						\
	base/stdint/mask/mask						\
	base/stdint/types						\
	base/stdio/fgets						\
	base/stdio/freads						\
	base/stdio/get							\
	base/stdio/printf/b						\
	base/stdio/printf/sbprintf					\
	base/stdio/printf/snprintfs					\
	base/stdio/seekc						\
	base/stdio/sscan						\
	base/stdio/tmpfname						\
	base/stdlib/alloc/callocs					\
	base/stdlib/alloc/frees						\
	base/stdlib/alloc/mallocarray					\
	base/stdlib/alloc/mallocarrays					\
	base/stdlib/alloc/mallocs					\
	base/stdlib/alloc/reallocarrayf					\
	base/stdlib/alloc/reallocarrayfs				\
	base/stdlib/alloc/reallocarrays					\
	base/stdlib/alloc/reallocfs					\
	base/stdlib/alloc/reallocs					\
	base/stdlib/array_split_pos_neg					\
	base/stdlib/avg							\
	base/stdlib/bsearch						\
	base/stdlib/clz							\
	base/stdlib/cmp							\
	base/stdlib/ctz							\
	base/stdlib/getenv/getenv_f					\
	base/stdlib/getenv/getenv_i					\
	base/stdlib/getenv/getenv_u					\
	base/stdlib/lmax						\
	base/stdlib/popcnt						\
	base/stdlib/pow							\
	base/stdlib/search						\
	base/stdlib/strto/strtof_s					\
	base/stdlib/strto/strtoi_s					\
	base/stdlib/strto/strtou_s					\
	base/stdlib/swap						\
	base/string/memchr/memchrend					\
	base/string/strbool/strbool					\
	base/string/strcat/strbcatf					\
	base/string/strcat/strscat					\
	base/string/strcat/strscatf					\
	base/string/strcat/strscatfs					\
	base/string/strchr/strcasechr					\
	base/string/strchr/strcasechrnul				\
	base/string/strchr/strncasechr					\
	base/string/strchr/strncasechrnul				\
	base/string/strchr/strnchr					\
	base/string/strchr/strnchrnul					\
	base/string/strchr/strnrcasechr					\
	base/string/strchr/strnrcasechrnul				\
	base/string/strchr/strnrchr					\
	base/string/strchr/strnrchrnul					\
	base/string/strchr/strrcasechr					\
	base/string/strchr/strrcasechrnul				\
	base/string/strchr/strrchrnul					\
	base/string/strcpy/strlcpys					\
	base/string/strcpy/strscpy					\
	base/string/strlwr/strlwr					\
	base/string/strlwr/strnlwr					\
	base/string/strlwr/strupr					\
	base/string/strlwr/strnupr					\
	base/string/strstr/strncasestr					\
	base/string/strstr/strscasestr					\
	base/string/strstr/strsstr					\
	base/sys/socket/tcp/client					\
	base/sys/socket/tcp/server					\
	base/sys/socket/msghdr						\
	base/sys/socket/timestamp					\
	base/sys/types							\
	base/time/gettime						\
	base/time/timespec

SRC	= $(MODULES:%=$(SRC_DIR)/%.c)
DEP	= $(MODULES:%=$(BUILD_TMP_DIR)/%.d)
OBJ	= $(MODULES:%=$(BUILD_TMP_DIR)/%.o)

BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(BUILD_TMP_DIR)/%.d: $(SRC_DIR)/%.c $(MK_DEPS)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(BUILD_TMP_DIR)/$*.a.s"			\
			-MT"$(BUILD_TMP_DIR)/$*.so.s"			\
			-M $< -MF $@
$(BUILD_TMP_DIR)/%.a.s: $(SRC_DIR)/%.c $(BUILD_TMP_DIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(BUILD_TMP_DIR)/%.so.s: $(SRC_DIR)/%.c $(BUILD_TMP_DIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(BUILD_TMP_DIR)/%.o: $(BUILD_TMP_DIR)/%.s
	@echo	"	AS	build/tmp/$*.o"
	$(Q)$(AS) $< -o $@

include $(DEP)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################

