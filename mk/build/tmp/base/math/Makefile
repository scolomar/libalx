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
	$(CURDIR)/array_division.o					\
	$(CURDIR)/array_multiplication.o				\
	$(CURDIR)/array_sum.o						\
	$(CURDIR)/binomial_coefficient.o				\
	$(CURDIR)/matrix_addition.o					\
	$(CURDIR)/matrix_subtraction.o					\
	$(CURDIR)/pascal_triangle.o					\
	$(CURDIR)/prime.o						\
	$(CURDIR)/prime_defactorization.o				\
	$(CURDIR)/prime_factorization.o					\
	$(CURDIR)/scale_linear.o

SRC	=								\
	$(SRC_DIR)/base/math/array_division.c				\
	$(SRC_DIR)/base/math/array_multiplication.c			\
	$(SRC_DIR)/base/math/array_sum.c				\
	$(SRC_DIR)/base/math/binomial_coefficient.c			\
	$(SRC_DIR)/base/math/matrix_addition.c				\
	$(SRC_DIR)/base/math/matrix_subtraction.c			\
	$(SRC_DIR)/base/math/pascal_triangle.c				\
	$(SRC_DIR)/base/math/prime.c					\
	$(SRC_DIR)/base/math/prime_defactorization.c			\
	$(SRC_DIR)/base/math/prime_factorization.c			\
	$(SRC_DIR)/base/math/scale_linear.c

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(CURDIR)/%.d: $(SRC_DIR)/base/math/%.c
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/base/math/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/base/math/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/math/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/base/math/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/math/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/base/math/$*.o"
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
