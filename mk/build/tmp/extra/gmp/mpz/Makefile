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
	$(CURDIR)/arithmetic.o						\
	$(CURDIR)/cmp.o							\
	$(CURDIR)/division.o						\
	$(CURDIR)/exp.o							\
	$(CURDIR)/get.o							\
	$(CURDIR)/init_set.o						\
	$(CURDIR)/misc.o						\
	$(CURDIR)/root.o						\
	$(CURDIR)/set.o							\
	$(CURDIR)/theoretic.o

SRC	=								\
	$(SRC_DIR)/extra/gmp/mpz/arithmetic.c				\
	$(SRC_DIR)/extra/gmp/mpz/cmp.c					\
	$(SRC_DIR)/extra/gmp/mpz/division.c				\
	$(SRC_DIR)/extra/gmp/mpz/exp.c					\
	$(SRC_DIR)/extra/gmp/mpz/get.c					\
	$(SRC_DIR)/extra/gmp/mpz/init_set.c				\
	$(SRC_DIR)/extra/gmp/mpz/misc.c					\
	$(SRC_DIR)/extra/gmp/mpz/root.c					\
	$(SRC_DIR)/extra/gmp/mpz/set.c					\
	$(SRC_DIR)/extra/gmp/mpz/theoretic.c

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# cflags
#CFLAGS_A	+=
#CFLAGS_SO	+=

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(CURDIR)/%.d: $(SRC_DIR)/extra/gmp/mpz/%.c
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/extra/gmp/mpz/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/extra/gmp/mpz/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/extra/gmp/mpz/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/extra/gmp/mpz/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/extra/gmp/mpz/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/extra/gmp/mpz/$*.o"
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
