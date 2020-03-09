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
	$(CURDIR)/chebyshev.o						\
	$(CURDIR)/euclidean.o						\
	$(CURDIR)/manhattan.o

SRC	=								\
	$(SRC_DIR)/extra/gsl/distance/chebyshev.c			\
	$(SRC_DIR)/extra/gsl/distance/euclidean.c			\
	$(SRC_DIR)/extra/gsl/distance/manhattan.c

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# cflags
CFLAGS_A	+= `pkg-config --cflags gsl`
CFLAGS_SO	+= `pkg-config --cflags gsl`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(CURDIR)/%.d: $(SRC_DIR)/extra/gsl/distance/%.c
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/extra/gsl/distance/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/extra/gsl/distance/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/extra/gsl/distance/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/extra/gsl/distance/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/extra/gsl/distance/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/extra/gsl/distance/$*.o"
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
