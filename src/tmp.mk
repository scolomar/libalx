#!/usr/bin/make -f

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

%: Makefile

PHONY := all
all: base alx extra


PHONY += base
base:
	$(Q)$(MAKE)	-C $(SRC_DIR)/base/


PHONY += alx
alx: data-structures
#alx: npcomplete
alx: robot

PHONY += data-structures
data-structures:
	$(Q)$(MAKE)	-C $(SRC_DIR)/alx/$@/

PHONY += npcomplete
npcomplete:
	$(Q)$(MAKE)	-C $(SRC_DIR)/alx/$@/

PHONY += robot
robot:
	$(Q)$(MAKE)	-C $(SRC_DIR)/alx/$@/ur/
#	$(Q)$(MAKE)	-C $(SRC_DIR)/alx/$@/kawasaki/


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
	$(Q)$(MAKE)	-C $(SRC_DIR)/extra/$@/

PHONY += cv
cv:
	$(Q)$(MAKE)	-C $(SRC_DIR)/extra/$@/

PHONY += gmp
gmp:
	$(Q)$(MAKE)	-C $(SRC_DIR)/extra/$@/

PHONY += gsl
gsl:
	$(Q)$(MAKE)	-C $(SRC_DIR)/extra/$@/

PHONY += ncurses
ncurses:
	$(Q)$(MAKE)	-C $(SRC_DIR)/extra/$@/

PHONY += ocr
ocr:
	$(Q)$(MAKE)	-C $(SRC_DIR)/extra/$@/

PHONY += plot
plot:
	$(Q)$(MAKE)	-C $(SRC_DIR)/extra/$@/

PHONY += telnet-tcp
telnet-tcp:
	$(Q)$(MAKE)	-C $(SRC_DIR)/extra/$@/

PHONY += zbar
zbar:
	$(Q)$(MAKE)	-C $(SRC_DIR)/extra/$@/


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
