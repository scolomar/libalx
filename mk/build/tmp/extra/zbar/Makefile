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
OBJ	=								\
	$(CURDIR)/zbar.o

SRC	=								\
	$(SRC_DIR)/extra/zbar/zbar.c

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# cflags
CFLAGS_A	+= `pkg-config --cflags zbar`
CFLAGS_SO	+= `pkg-config --cflags zbar`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(CURDIR)/%.d: $(SRC_DIR)/extra/zbar/%.c
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/extra/zbar/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/extra/zbar/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/extra/zbar/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/extra/zbar/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/extra/zbar/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/extra/zbar/$*.o"
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
