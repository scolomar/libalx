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
# target: dependencies
#	action

PHONY := all
all: base alx extra


PHONY += base
base:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/assert/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/compiler/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/errno/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/float/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/libgen/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/linux/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/math/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/signal/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/socket/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/stdint/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/stdio/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/stdlib/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/string/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/base/sys/


PHONY += alx
alx: data-structures
#alx: npcomplete
alx: robot

PHONY += data-structures
data-structures:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/alx/$@/

PHONY += npcomplete
npcomplete:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/alx/$@/

PHONY += robot
robot:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/alx/$@/ur/
#	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/alx/$@/kawasaki/


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
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/fcurl/

PHONY += cv
cv:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/alx/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/core/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/features2d/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/highgui/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/imgproc/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/videoio/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/ximgproc/

PHONY += gmp
gmp:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/mpq/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/mpz/

PHONY += gsl
gsl:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/distance/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/distributions/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/rstat/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/statistics/
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/units/

PHONY += ncurses
ncurses:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/

PHONY += ocr
ocr:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/

PHONY += plot
plot:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/

PHONY += telnet-tcp
telnet-tcp:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/client/

PHONY += zbar
zbar:
	$(Q)$(MAKE)	-C $(BUILD_TMP_DIR)/extra/$@/


PHONY += clean
clean:
	@echo	"	RM	*.o *.s"
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################
