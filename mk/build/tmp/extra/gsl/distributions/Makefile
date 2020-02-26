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
	$(CURDIR)/binomial.o						\
	$(CURDIR)/exponential.o						\
	$(CURDIR)/geometric.o						\
	$(CURDIR)/normal.o						\
	$(CURDIR)/poisson.o						\
	$(CURDIR)/uniform.o

SRC	=								\
	$(SRC_DIR)/extra/gsl/distributions/binomial.c			\
	$(SRC_DIR)/extra/gsl/distributions/exponential.c		\
	$(SRC_DIR)/extra/gsl/distributions/geometric.c			\
	$(SRC_DIR)/extra/gsl/distributions/normal.c			\
	$(SRC_DIR)/extra/gsl/distributions/poisson.c			\
	$(SRC_DIR)/extra/gsl/distributions/uniform.c

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


$(CURDIR)/%.d: $(SRC_DIR)/extra/gsl/distributions/%.c
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/extra/gsl/distributions/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/extra/gsl/distributions/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/extra/gsl/distributions/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/extra/gsl/distributions/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/extra/gsl/distributions/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/extra/gsl/distributions/$*.o"
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
