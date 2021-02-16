#!/usr/bin/make -f

# MACRO = substitute with this

# dependencies

MK_DEPS	=								\
	$(SRC_DIR)/lib.mk						\
	$(PROJECT_DIR)/Makefile

BASE_MODULES	=							\
		base/assert/array					\
		base/assert/assert					\
		base/assert/char					\
		base/assert/pointer					\
		base/assert/must_be					\
		base/assert/stddef					\
		base/assert/stdint					\
		base/assert/type					\
		base/compiler/attribute					\
		base/compiler/size					\
		base/compiler/type					\
		base/compiler/unused					\
		base/errno/error					\
		base/errno/perror					\
		base/float/constant					\
		base/float/printf					\
		base/float/scanf					\
		base/libgen/basename					\
		base/libgen/dirname					\
		base/linux/membarrier					\
		base/math/array_division				\
		base/math/array_multiplication				\
		base/math/array_sum					\
		base/math/binomial_coefficient				\
		base/math/matrix_addition				\
		base/math/matrix_subtraction				\
		base/math/pascal_triangle				\
		base/math/scale_linear					\
		base/signal/sigpipe					\
		base/signal/sigterm					\
		base/stdint/constants					\
		base/stdint/mask/bit					\
		base/stdint/mask/field					\
		base/stdint/mask/mask					\
		base/stdint/types					\
		base/stdio/fgets					\
		base/stdio/get						\
		base/stdio/printf/b					\
		base/stdio/printf/sbprintf				\
		base/stdio/printf/snprintfs				\
		base/stdio/seekc					\
		base/stdio/sscan					\
		base/stdio/tmpfname					\
		base/stdlib/alloc/callocs				\
		base/stdlib/alloc/frees					\
		base/stdlib/alloc/mallocarray				\
		base/stdlib/alloc/mallocarrays				\
		base/stdlib/alloc/mallocs				\
		base/stdlib/alloc/reallocarrayf				\
		base/stdlib/alloc/reallocarrayfs			\
		base/stdlib/alloc/reallocarrays				\
		base/stdlib/alloc/reallocfs				\
		base/stdlib/alloc/reallocs				\
		base/stdlib/array_split_pos_neg				\
		base/stdlib/avg						\
		base/stdlib/bsearch					\
		base/stdlib/clz						\
		base/stdlib/cmp						\
		base/stdlib/ctz						\
		base/stdlib/getenv/getenv_f				\
		base/stdlib/getenv/getenv_i				\
		base/stdlib/getenv/getenv_u				\
		base/stdlib/lmax					\
		base/stdlib/popcnt					\
		base/stdlib/pow						\
		base/stdlib/search					\
		base/stdlib/seed					\
		base/stdlib/strto/strtof_s				\
		base/stdlib/strto/strtoi_s				\
		base/stdlib/strto/strtou_s				\
		base/stdlib/swap					\
		base/string/memchr/memchrend				\
		base/string/strbool/strbool				\
		base/string/strcat/strbcatf				\
		base/string/strcat/strscat				\
		base/string/strcat/strscatf				\
		base/string/strcat/strscatfs				\
		base/string/strchr/strcasechr				\
		base/string/strchr/strcasechrnul			\
		base/string/strchr/strncasechr				\
		base/string/strchr/strncasechrnul			\
		base/string/strchr/strnchr				\
		base/string/strchr/strnchrnul				\
		base/string/strchr/strnrcasechr				\
		base/string/strchr/strnrcasechrnul			\
		base/string/strchr/strnrchr				\
		base/string/strchr/strnrchrnul				\
		base/string/strchr/strrcasechr				\
		base/string/strchr/strrcasechrnul			\
		base/string/strchr/strrchrnul				\
		base/string/strcpy/strlcpys				\
		base/string/strcpy/strscpy				\
		base/string/strlwr/strlwr				\
		base/string/strlwr/strnlwr				\
		base/string/strlwr/strupr				\
		base/string/strlwr/strnupr				\
		base/string/strstr/strncasestr				\
		base/string/strstr/strscasestr				\
		base/string/strstr/strsstr				\
		base/sys/socket/tcp/client				\
		base/sys/socket/tcp/server				\
		base/sys/socket/msghdr					\
		base/sys/socket/timestamp				\
		base/sys/types						\
		base/time/gettime					\
		base/time/timespec
BASE_A_OBJ	= $(BASE_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
BASE_SO_OBJ	= $(BASE_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)

ALX_DS_MODULES	=							\
		alx/data-structures/bst					\
		alx/data-structures/dataframe				\
		alx/data-structures/dyn-array				\
		alx/data-structures/dyn-buffer				\
		alx/data-structures/llist				\
		alx/data-structures/node				\
		alx/data-structures/types
ALX_DS_A_OBJ	= $(ALX_DS_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
ALX_DS_SO_OBJ	= $(ALX_DS_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
ALX_NPC_MODULES	=							\
		alx/npcomplete/solver_lut
ALX_NPC_A_OBJ	= $(ALX_NPC_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
ALX_NPC_SO_OBJ	= $(ALX_NPC_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
ALX_ROBOT_UR_MODULES	=						\
		alx/robot-ur/core/core					\
		alx/robot-ur/core/msg/msg				\
		alx/robot-ur/core/msg/robot_state			\
		alx/robot-ur/io/io					\
		alx/robot-ur/miscellaneous/miscellaneous		\
		alx/robot-ur/move/move					\
		alx/robot-ur/pose/pose					\
		alx/robot-ur/setup/setup
ALX_ROBOT_UR_A_OBJ	= $(ALX_ROBOT_UR_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
ALX_ROBOT_UR_SO_OBJ	= $(ALX_ROBOT_UR_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
ALX_ROBOT_KW_MODULES	=						\
#		alx/robot-kawasaki/kawasaki
ALX_ROBOT_KW_A_OBJ	= $(ALX_ROBOT_KW_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
ALX_ROBOT_KW_SO_OBJ	= $(ALX_ROBOT_KW_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)

CURL_MODULES	=							\
		extra/curl/fcurl/fclose					\
		extra/curl/fcurl/feof					\
		extra/curl/fcurl/fgetc					\
		extra/curl/fcurl/fgets					\
		extra/curl/fcurl/fopen					\
		extra/curl/fcurl/fread					\
		extra/curl/fcurl/init					\
		extra/curl/fcurl/internal				\
		extra/curl/fcurl/rewind					\
		extra/curl/fcurl/ungetc					\
		extra/curl/fcurl/URL_FILE
CURL_A_OBJ	= $(CURL_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
CURL_SO_OBJ	= $(CURL_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
CV_MODULES	=							\
		extra/cv/alx/compare					\
		extra/cv/alx/gray					\
		extra/cv/alx/lines					\
		extra/cv/alx/max					\
		extra/cv/alx/mean					\
		extra/cv/alx/median					\
		extra/cv/alx/skeleton					\
		extra/cv/core/array/bitwise				\
		extra/cv/core/array/component				\
		extra/cv/core/array/minmax				\
		extra/cv/core/array/normalize				\
		extra/cv/core/contours/extract				\
		extra/cv/core/contours/init				\
		extra/cv/core/img/img					\
		extra/cv/core/pixel/pixel				\
		extra/cv/core/rect/rect					\
		extra/cv/core/roi/roi					\
		extra/cv/features2d/orb					\
		extra/cv/highgui/file					\
		extra/cv/highgui/window					\
		extra/cv/imgproc/features/edges				\
		extra/cv/imgproc/features/features			\
		extra/cv/imgproc/filter/border				\
		extra/cv/imgproc/filter/dilate_erode			\
		extra/cv/imgproc/filter/edges				\
		extra/cv/imgproc/filter/smooth				\
		extra/cv/imgproc/geometric/mirror			\
		extra/cv/imgproc/geometric/resize			\
		extra/cv/imgproc/geometric/rotate			\
		extra/cv/imgproc/histogram/hist				\
		extra/cv/imgproc/miscellaneous/color			\
		extra/cv/imgproc/miscellaneous/distance			\
		extra/cv/imgproc/miscellaneous/fill			\
		extra/cv/imgproc/miscellaneous/resolution		\
		extra/cv/imgproc/miscellaneous/threshold		\
		extra/cv/imgproc/shape/contour/contours			\
		extra/cv/imgproc/shape/contour/draw			\
		extra/cv/imgproc/shape/contour/sort			\
		extra/cv/imgproc/shape/rect				\
		extra/cv/videoio/cam					\
		extra/cv/ximgproc/thinning
CV_A_OBJ	= $(CV_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
CV_SO_OBJ	= $(CV_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
GMP_MODULES	=							\
		extra/gmp/mpq/cmp					\
		extra/gmp/mpz/arithmetic				\
		extra/gmp/mpz/cmp					\
		extra/gmp/mpz/division					\
		extra/gmp/mpz/exp					\
		extra/gmp/mpz/get					\
		extra/gmp/mpz/init_set					\
		extra/gmp/mpz/misc					\
		extra/gmp/mpz/root					\
		extra/gmp/mpz/set					\
		extra/gmp/mpz/theoretic
GMP_A_OBJ	= $(GMP_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
GMP_SO_OBJ	= $(GMP_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
GSL_MODULES	=							\
		extra/gsl/cblas/lvl1/iXamax				\
		extra/gsl/cblas/lvl1/iXamin				\
		extra/gsl/distance/chebyshev				\
		extra/gsl/distance/euclidean				\
		extra/gsl/distance/manhattan				\
		extra/gsl/distributions/binomial			\
		extra/gsl/distributions/exp				\
		extra/gsl/distributions/gauss				\
		extra/gsl/distributions/geometric			\
		extra/gsl/distributions/poisson				\
		extra/gsl/distributions/uniform				\
		extra/gsl/rstat/median					\
		extra/gsl/statistics/mean				\
		extra/gsl/units/len					\
		extra/gsl/units/temp					\
		extra/gsl/units/weight
GSL_A_OBJ	= $(GSL_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
GSL_SO_OBJ	= $(GSL_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
NCURSES_MODULES	=							\
		extra/ncurses/common					\
		extra/ncurses/get					\
		extra/ncurses/menu					\
		extra/ncurses/perror
NCURSES_A_OBJ	= $(NCURSES_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
NCURSES_SO_OBJ	= $(NCURSES_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
NPCOMPLETE_MODULES	=						\
		extra/npcomplete/solver_lut
NPCOMPLETE_A_OBJ	= $(NPCOMPLETE_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
NPCOMPLETE_SO_OBJ	= $(NPCOMPLETE_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
OCR_MODULES	=							\
		extra/ocr/ocr
OCR_A_OBJ	= $(OCR_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
OCR_SO_OBJ	= $(OCR_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
PLOT_MODULES	=							\
		extra/plot/core						\
		extra/plot/multi					\
		extra/plot/plot						\
		extra/plot/setup
PLOT_A_OBJ	= $(PLOT_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
PLOT_SO_OBJ	= $(PLOT_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
TELNET_TCP_MODULES	=						\
		extra/telnet-tcp/client/client
TELNET_TCP_A_OBJ	= $(TELNET_TCP_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
TELNET_TCP_SO_OBJ	= $(TELNET_TCP_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)
ZBAR_MODULES	=							\
		extra/zbar/zbar
ZBAR_A_OBJ	= $(ZBAR_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
ZBAR_SO_OBJ	= $(ZBAR_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)


# target: dependencies
#	action
PHONY += base
base: base_a base_so
PHONY += base_a
base_a: $(BUILD_A_DIR_)/libalx-base.a
PHONY += base_so
base_so: $(BUILD_SO_DIR_)/libalx-base.so.$(LIBVERSION)


PHONY += data-structures
data-structures: data-structures_a data-structures_so
PHONY += data-structures_a
data-structures_a: $(BUILD_A_DIR_)/libalx-data-structures.a
PHONY += data-structures_a
data-structures_so: $(BUILD_SO_DIR_)/libalx-data-structures.so.$(LIBVERSION)

PHONY += npcomplete
npcomplete: npcomplete_a npcomplete_so
PHONY += npcomplete_a
npcomplete_a: $(BUILD_A_DIR_)/libalx-npcomplete.a
PHONY += npcomplete_so
npcomplete_so: $(BUILD_SO_DIR_)/libalx-npcomplete.so.$(LIBVERSION)

PHONY += robot-ur
robot-ur: robot-ur_a robot-ur_so
PHONY += robot-ur_a
robot-ur_a: $(BUILD_A_DIR_)/libalx-robot-ur.a
PHONY += robot-ur_so
robot-ur_so: $(BUILD_SO_DIR_)/libalx-robot-ur.so.$(LIBVERSION)

PHONY += robot-kawasaki
robot-kawasaki: robot-kawasaki_a robot-kawasaki_so
PHONY += robot-kawasaki_a
robot-kawasaki_a: $(BUILD_A_DIR_)/libalx-robot-kawasaki.a
PHONY += robot-kawasaki_so
robot-kawasaki_so: $(BUILD_SO_DIR_)/libalx-robot-kawasaki.so.$(LIBVERSION)


PHONY += curl
curl: curl_a curl_so
PHONY += curl_a
curl_a: $(BUILD_A_DIR_)/libalx-curl.a
PHONY += curl_so
curl_so: $(BUILD_SO_DIR_)/libalx-curl.so.$(LIBVERSION)

PHONY += cv
cv: cv_a cv_so
PHONY += cv_a
cv_a: $(BUILD_A_DIR_)/libalx-cv.a
PHONY += cv_so
cv_so: $(BUILD_SO_DIR_)/libalx-cv.so.$(LIBVERSION)

PHONY += gmp
gmp: gmp_a gmp_so
PHONY += gmp_a
gmp_a: $(BUILD_A_DIR_)/libalx-gmp.a
PHONY += gmp_so
gmp_so: $(BUILD_SO_DIR_)/libalx-gmp.so.$(LIBVERSION)

PHONY += gsl
gsl: gsl_a gsl_so
PHONY += gsl_a
gsl_a: $(BUILD_A_DIR_)/libalx-gsl.a
PHONY += gsl_so
gsl_so: $(BUILD_SO_DIR_)/libalx-gsl.so.$(LIBVERSION)

PHONY += ncurses
ncurses: ncurses_a ncurses_so
PHONY += ncurses_a
ncurses_a: $(BUILD_A_DIR_)/libalx-ncurses.a
PHONY += ncurses_so
ncurses_so: $(BUILD_SO_DIR_)/libalx-ncurses.so.$(LIBVERSION)

PHONY += ocr
ocr: ocr_a ocr_so
PHONY += ocr_a
ocr_a: $(BUILD_A_DIR_)/libalx-ocr.a
PHONY += ocr_so
ocr_so: $(BUILD_SO_DIR_)/libalx-ocr.so.$(LIBVERSION)

PHONY += plot
plot: plot_a plot_so
PHONY += plot_a
plot_a: $(BUILD_A_DIR_)/libalx-plot.a
PHONY += plot_so
plot_so: $(BUILD_SO_DIR_)/libalx-plot.so.$(LIBVERSION)

PHONY += telnet-tcp
telnet-tcp: telnet-tcp_a telnet-tcp_so
PHONY += telnet-tcp_a
telnet-tcp_a: $(BUILD_A_DIR_)/libalx-telnet-tcp.a
PHONY += telnet-tcp_so
telnet-tcp_so: $(BUILD_SO_DIR_)/libalx-telnet-tcp.so.$(LIBVERSION)

PHONY += zbar
zbar: zbar_a zbar_so
PHONY += zbar_a
zbar_a: $(BUILD_A_DIR_)/libalx-zbar.a
PHONY += zbar_so
zbar_so: $(BUILD_SO_DIR_)/libalx-zbar.so.$(LIBVERSION)


%.so.$(LIBVERSION):
%.a:
	$(Q)mkdir -p		$(@D)/
	@echo	"	AR	build/lib/static/libalx/$(@F)"
	$(Q)$(AR) -r -c -s -o $@ $^



$(BUILD_A_DIR_)/libalx-base.a: $(BASE_A_OBJ)
$(BUILD_SO_DIR_)/libalx-base.so.$(LIBVERSION): %.$(LIBVERSION): $(BASE_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			`pkg-config --libs libbsd-overlay`		\
			-l m
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*


$(BUILD_A_DIR_)/libalx-data-structures.a: $(ALX_DS_A_OBJ)
$(BUILD_SO_DIR_)/libalx-data-structures.so.$(LIBVERSION): %.$(LIBVERSION): $(ALX_DS_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-npcomplete.a: $(ALX_NPC_A_OBJ)
$(BUILD_SO_DIR_)/libalx-npcomplete.so.$(LIBVERSION): %.$(LIBVERSION): $(ALX_NPC_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			-fopenmp					\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-robot-ur.a: $(ALX_ROBOT_UR_A_OBJ)
$(BUILD_SO_DIR_)/libalx-robot-ur.so.$(LIBVERSION): %.$(LIBVERSION): $(ALX_ROBOT_UR_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-robot-kawasaki.a: $(ALX_ROBOT_KW_A_OBJ)
$(BUILD_SO_DIR_)/libalx-robot-kawasaki.so.$(LIBVERSION): %.$(LIBVERSION): $(ALX_ROBOT_KW_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*


$(BUILD_A_DIR_)/libalx-curl.a: $(CURL_A_OBJ)
$(BUILD_SO_DIR_)/libalx-curl.so.$(LIBVERSION): %.$(LIBVERSION): $(CURL_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			`pkg-config --libs libcurl`			\
			$(*D)/libalx-data-structures.so.$(LIBVERSION)\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-cv.a: $(CV_A_OBJ)
$(BUILD_SO_DIR_)/libalx-cv.so.$(LIBVERSION): %.$(LIBVERSION): $(CV_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX	build/lib/shared/libalx/$(@F)"
	$(Q)$(CXX) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			`pkg-config --libs opencv4`			\
			$(*D)/libalx-gsl.so.$(LIBVERSION)		\
			-l gsl						\
			$(*D)/libalx-base.so.$(LIBVERSION)		\
			-l m
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-gmp.a: $(GMP_A_OBJ)
$(BUILD_SO_DIR_)/libalx-gmp.so.$(LIBVERSION): %.$(LIBVERSION): $(GMP_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			-l gmp						\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-gsl.a: $(GSL_A_OBJ)
$(BUILD_SO_DIR_)/libalx-gsl.so.$(LIBVERSION): %.$(LIBVERSION): $(GSL_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			`pkg-config --libs gsl`				\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-ncurses.a: $(NCURSES_A_OBJ)
$(BUILD_SO_DIR_)/libalx-ncurses.so.$(LIBVERSION): %.$(LIBVERSION): $(NCURSES_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			`pkg-config --libs ncurses`			\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-ocr.a: $(OCR_A_OBJ)
$(BUILD_SO_DIR_)/libalx-ocr.so.$(LIBVERSION): %.$(LIBVERSION): $(OCR_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			`pkg-config --libs tesseract`			\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-plot.a: $(PLOT_A_OBJ)
$(BUILD_SO_DIR_)/libalx-plot.so.$(LIBVERSION): %.$(LIBVERSION): $(PLOT_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-telnet-tcp.a: $(TELNET_TCP_A_OBJ)
$(BUILD_SO_DIR_)/libalx-telnet-tcp.so.$(LIBVERSION): %.$(LIBVERSION): $(TELNET_TCP_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*

$(BUILD_A_DIR_)/libalx-zbar.a: $(ZBAR_A_OBJ)
$(BUILD_SO_DIR_)/libalx-zbar.so.$(LIBVERSION): %.$(LIBVERSION): $(ZBAR_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/shared/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -Wl,-soname,$(*F).$(VERSION) -o $@ $^	\
			`pkg-config --libs zbar`			\
			$(*D)/libalx-base.so.$(LIBVERSION)
	$(Q)ln -sf -T	$(*F).$(LIBVERSION)	$*


PHONY += clean
clean:
	$(Q)rm -f *.a *.so

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################

