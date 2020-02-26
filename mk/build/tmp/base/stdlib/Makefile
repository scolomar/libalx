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
	$(CURDIR)/alloc/callocs.o					\
	$(CURDIR)/alloc/frees.o						\
	$(CURDIR)/alloc/mallocarray.o					\
	$(CURDIR)/alloc/mallocarrays.o					\
	$(CURDIR)/alloc/mallocs.o					\
	$(CURDIR)/alloc/reallocarrayf.o					\
	$(CURDIR)/alloc/reallocarrayfs.o				\
	$(CURDIR)/alloc/reallocarrays.o					\
	$(CURDIR)/alloc/reallocfs.o					\
	$(CURDIR)/alloc/reallocs.o					\
	$(CURDIR)/array_split_pos_neg.o					\
	$(CURDIR)/average.o						\
	$(CURDIR)/bsearch.o						\
	$(CURDIR)/clz.o							\
	$(CURDIR)/compare.o						\
	$(CURDIR)/ctz.o							\
	$(CURDIR)/local_maxima.o					\
	$(CURDIR)/maximum.o						\
	$(CURDIR)/minimum.o						\
	$(CURDIR)/popcnt.o						\
	$(CURDIR)/pow.o							\
	$(CURDIR)/search.o						\
	$(CURDIR)/seed.o						\
	$(CURDIR)/strto/strtof_s.o					\
	$(CURDIR)/strto/strtoi_s.o					\
	$(CURDIR)/strto/strtou_s.o					\
	$(CURDIR)/swap.o

SRC	=								\
	$(SRC_DIR)/base/stdlib/alloc/callocs.c				\
	$(SRC_DIR)/base/stdlib/alloc/frees.c				\
	$(SRC_DIR)/base/stdlib/alloc/mallocarray.c			\
	$(SRC_DIR)/base/stdlib/alloc/mallocarrays.c			\
	$(SRC_DIR)/base/stdlib/alloc/mallocs.c				\
	$(SRC_DIR)/base/stdlib/alloc/reallocarrayf.c			\
	$(SRC_DIR)/base/stdlib/alloc/reallocarrayfs.c			\
	$(SRC_DIR)/base/stdlib/alloc/reallocarrays.c			\
	$(SRC_DIR)/base/stdlib/alloc/reallocfs.c			\
	$(SRC_DIR)/base/stdlib/alloc/reallocs.c				\
	$(SRC_DIR)/base/stdlib/array_split_pos_neg.c			\
	$(SRC_DIR)/base/stdlib/average.c				\
	$(SRC_DIR)/base/stdlib/bsearch.c				\
	$(SRC_DIR)/base/stdlib/clz.c					\
	$(SRC_DIR)/base/stdlib/compare.c				\
	$(SRC_DIR)/base/stdlib/ctz.c					\
	$(SRC_DIR)/base/stdlib/local_maxima.c				\
	$(SRC_DIR)/base/stdlib/maximum.c				\
	$(SRC_DIR)/base/stdlib/minimum.c				\
	$(SRC_DIR)/base/stdlib/popcnt.c					\
	$(SRC_DIR)/base/stdlib/pow.c					\
	$(SRC_DIR)/base/stdlib/search.c					\
	$(SRC_DIR)/base/stdlib/seed.c					\
	$(SRC_DIR)/base/stdlib/strto/strtof_s.c				\
	$(SRC_DIR)/base/stdlib/strto/strtoi_s.c				\
	$(SRC_DIR)/base/stdlib/strto/strtou_s.c				\
	$(SRC_DIR)/base/stdlib/swap.c

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(CURDIR)/%.d: $(SRC_DIR)/base/stdlib/%.c
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/base/stdlib/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/base/stdlib/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/stdlib/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/base/stdlib/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/stdlib/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/base/stdlib/$*.o"
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
