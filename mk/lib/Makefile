#! /usr/bin/make -f

# MACRO = substitute with this

# dependencies

MK_DEPS	=								\
	$(MK_LIB_DIR)/Makefile						\
	$(LIBALX_DIR)/Makefile

BUILD_PATH	= $(BUILD_LIB_DIR)/libalx

BASE_MODULES	=							\
		base/assert/array					\
		base/assert/assert					\
		base/assert/char					\
		base/assert/stddef					\
		base/assert/stdint					\
		base/assert/type					\
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
		base/math/prime						\
		base/math/prime_defactorization				\
		base/math/prime_factorization				\
		base/math/scale_linear					\
		base/signal/sigpipe					\
		base/signal/sigterm					\
		base/socket/tcp/client					\
		base/socket/tcp/server					\
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
		base/stdlib/average					\
		base/stdlib/clz						\
		base/stdlib/compare					\
		base/stdlib/ctz						\
		base/stdlib/getenv/getenv_f				\
		base/stdlib/getenv/getenv_i				\
		base/stdlib/getenv/getenv_s				\
		base/stdlib/getenv/getenv_u				\
		base/stdlib/local_maxima				\
		base/stdlib/maximum					\
		base/stdlib/minimum					\
		base/stdlib/popcnt					\
		base/stdlib/pow						\
		base/stdlib/search					\
		base/stdlib/seed					\
		base/stdlib/strto/strtof_s				\
		base/stdlib/strto/strtoi_s				\
		base/stdlib/strto/strtou_s				\
		base/stdlib/swap					\
		base/string/memchr/memchrend				\
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
		base/string/strgrep					\
		base/string/strstr/strncasestr				\
		base/string/strstr/strscasestr				\
		base/string/strstr/strsstr				\
		base/sys/types
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
ALX_ROBOT_MODULES	=						\
		alx/robot/ur/ur
#		alx/robot/kawasaki/kawasaki
ALX_ROBOT_A_OBJ	= $(ALX_ROBOT_MODULES:%=$(BUILD_TMP_DIR)/%.a.o)
ALX_ROBOT_SO_OBJ= $(ALX_ROBOT_MODULES:%=$(BUILD_TMP_DIR)/%.so.o)

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
		extra/cv/core/array/normalize				\
		extra/cv/core/contours/contours				\
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
		extra/cv/imgproc/shape/contours				\
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
		extra/gsl/distance/chebyshev				\
		extra/gsl/distance/euclidean				\
		extra/gsl/distance/manhattan				\
		extra/gsl/distributions/binomial			\
		extra/gsl/distributions/exponential			\
		extra/gsl/distributions/geometric			\
		extra/gsl/distributions/normal				\
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


ALL	= base alx extra

# target: dependencies
#	action

PHONY := all
all: $(ALL)


PHONY += base
base:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so


PHONY += alx
alx: data-structures
#alx: npcomplete
alx: robot

PHONY += data-structures
data-structures:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so

PHONY += npcomplete
npcomplete:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so

PHONY += robot
robot:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so


PHONY += extra
extra: curl
extra: cv
extra: gmp
extra: gsl
extra: ncurses
extra: ocr
extra: plot
extra: telnet-tcp
extra: zbar

PHONY += curl
curl:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so

PHONY += cv
cv:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so

PHONY += gmp
gmp:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so

PHONY += gsl
gsl:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so

PHONY += ncurses
ncurses:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so

PHONY += ocr
ocr:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so

PHONY += plot
plot:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so

PHONY += telnet-tcp
telnet-tcp:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so

PHONY += zbar
zbar:
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.a
	$(Q)$(MAKE)	$(BUILD_PATH)/libalx-$@.so


%.so:
%.a:
	$(Q)mkdir -p		$(@D)/
	@echo	"	AR	build/lib/libalx/$(@F)"
	$(Q)$(AR) -r -c -s -o $@ $^



$(BUILD_PATH)/libalx-base.a: $(BASE_A_OBJ)
$(BUILD_PATH)/libalx-base.so: $(BASE_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs libbsd-overlay` -l m


$(BUILD_PATH)/libalx-data-structures.a: $(ALX_DS_A_OBJ)
$(BUILD_PATH)/libalx-data-structures.so: $(ALX_DS_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ -l alx-base


$(BUILD_PATH)/libalx-npcomplete.a: $(ALX_NPC_A_OBJ)
$(BUILD_PATH)/libalx-npcomplete.so: $(ALX_NPC_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ -fopenmp -l alx-base


$(BUILD_PATH)/libalx-robot.a: $(ALX_ROBOT_A_OBJ)
$(BUILD_PATH)/libalx-robot.so: $(ALX_ROBOT_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ -l alx-base

$(BUILD_PATH)/libalx-curl.a: $(CURL_A_OBJ)
$(BUILD_PATH)/libalx-curl.so: $(CURL_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs libcurl`	\
					-l alx-data-structures -l alx-base

$(BUILD_PATH)/libalx-cv.a: $(CV_A_OBJ)
$(BUILD_PATH)/libalx-cv.so: $(CV_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX	build/lib/libalx/$(@F)"
	$(Q)$(CXX) $(LDFLAGS) -o $@ $^ `pkg-config --libs opencv4`	\
						-l alx-gsl -l alx-base -l m

$(BUILD_PATH)/libalx-gmp.a: $(GMP_A_OBJ)
$(BUILD_PATH)/libalx-gmp.so: $(GMP_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ -l gmp				\
						-l alx-base

$(BUILD_PATH)/libalx-gsl.a: $(GSL_A_OBJ)
$(BUILD_PATH)/libalx-gsl.so: $(GSL_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs gsl`		\
						-l alx-base

$(BUILD_PATH)/libalx-ncurses.a: $(NCURSES_A_OBJ)
$(BUILD_PATH)/libalx-ncurses.so: $(NCURSES_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs ncurses`	\
						-l alx-base

$(BUILD_PATH)/libalx-ocr.a: $(OCR_A_OBJ)
$(BUILD_PATH)/libalx-ocr.so: $(OCR_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs tesseract`	\
						-l alx-base

$(BUILD_PATH)/libalx-plot.a: $(PLOT_A_OBJ)
$(BUILD_PATH)/libalx-plot.so: $(PLOT_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ 					\
						-l alx-base

$(BUILD_PATH)/libalx-telnet-tcp.a: $(TELNET_TCP_A_OBJ)
$(BUILD_PATH)/libalx-telnet-tcp.so: $(TELNET_TCP_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^					\
						-l alx-base

$(BUILD_PATH)/libalx-zbar.a: $(ZBAR_A_OBJ)
$(BUILD_PATH)/libalx-zbar.so: $(ZBAR_SO_OBJ)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/lib/libalx/$(@F)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs zbar`		\
						-l alx-base


PHONY += clean
clean:
	$(Q)rm -f *.a *.so

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################

