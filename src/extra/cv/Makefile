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
	$(SRC_DIR)/extra/cv/Makefile					\
	$(SRC_DIR)/tmp.mk						\
	$(PROJECT_DIR)/Makefile

MODULES	=								\
	extra/cv/alx/compare						\
	extra/cv/alx/gray						\
	extra/cv/alx/lines						\
	extra/cv/alx/max						\
	extra/cv/alx/mean						\
	extra/cv/alx/median						\
	extra/cv/alx/skeleton						\
	extra/cv/core/array/bitwise					\
	extra/cv/core/array/component					\
	extra/cv/core/array/minmax					\
	extra/cv/core/array/normalize					\
	extra/cv/core/contours/extract					\
	extra/cv/core/contours/init					\
	extra/cv/core/img/img						\
	extra/cv/core/pixel/pixel					\
	extra/cv/core/rect/rect						\
	extra/cv/core/roi/roi						\
	extra/cv/features2d/orb						\
	extra/cv/highgui/file						\
	extra/cv/highgui/window						\
	extra/cv/imgproc/features/edges					\
	extra/cv/imgproc/features/features				\
	extra/cv/imgproc/filter/border					\
	extra/cv/imgproc/filter/dilate_erode				\
	extra/cv/imgproc/filter/edges					\
	extra/cv/imgproc/filter/smooth					\
	extra/cv/imgproc/geometric/mirror				\
	extra/cv/imgproc/geometric/resize				\
	extra/cv/imgproc/geometric/rotate				\
	extra/cv/imgproc/histogram/hist					\
	extra/cv/imgproc/miscellaneous/color				\
	extra/cv/imgproc/miscellaneous/distance				\
	extra/cv/imgproc/miscellaneous/fill				\
	extra/cv/imgproc/miscellaneous/resolution			\
	extra/cv/imgproc/miscellaneous/threshold			\
	extra/cv/imgproc/shape/contour/contours				\
	extra/cv/imgproc/shape/contour/draw				\
	extra/cv/imgproc/shape/contour/sort				\
	extra/cv/imgproc/shape/rect					\
	extra/cv/videoio/cam						\
	extra/cv/ximgproc/thinning

SRC	= $(MODULES:%=$(SRC_DIR)/%.cxx)
DEP	= $(MODULES:%=$(BUILD_TMP_DIR)/%.d)
OBJ	= $(MODULES:%=$(BUILD_TMP_DIR)/%.o)

BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# cflags
CXXFLAGS_A	+= `pkg-config --cflags opencv4`
CXXFLAGS_SO	+= `pkg-config --cflags opencv4`

################################################################################
# target: dependencies
#	action

.PHONY: all
all: $(BOTH_OBJ)
	@:


$(BUILD_TMP_DIR)/%.d: $(SRC_DIR)/%.cxx $(MK_DEPS)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX -M	build/tmp/$*.d"
	$(Q)$(CXX) $(CXXFLAGS_A) -MG -MT"$@"				\
			-MT"$(BUILD_TMP_DIR)/$*.a.s"			\
			-MT"$(BUILD_TMP_DIR)/$*.so.s"			\
			-M $< -MF $@
$(BUILD_TMP_DIR)/%.a.s: $(SRC_DIR)/%.cxx $(BUILD_TMP_DIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX	build/tmp/$*.a.s"
	$(Q)$(CXX) $(CXXFLAGS_A) -S $< -o $@
$(BUILD_TMP_DIR)/%.so.s: $(SRC_DIR)/%.cxx $(BUILD_TMP_DIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX	build/tmp/$*.so.s"
	$(Q)$(CXX) $(CXXFLAGS_SO) -S $< -o $@
$(BUILD_TMP_DIR)/%.o: $(BUILD_TMP_DIR)/%.s
	@echo	"	AS	build/tmp/$*.o"
	$(Q)$(AS) $< -o $@

include $(DEP)


.PHONY: clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.


################################################################################
######## End of file ###########################################################
################################################################################

