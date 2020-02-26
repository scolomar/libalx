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
	$(CURDIR)/bst.o							\
	$(CURDIR)/dataframe.o						\
	$(CURDIR)/dyn-array.o						\
	$(CURDIR)/dyn-buffer.o						\
	$(CURDIR)/llist.o						\
	$(CURDIR)/node.o						\
	$(CURDIR)/types.o

SRC	=								\
	$(SRC_DIR)/alx/data-structures/bst.c				\
	$(SRC_DIR)/alx/data-structures/dataframe.c			\
	$(SRC_DIR)/alx/data-structures/dyn-array.c			\
	$(SRC_DIR)/alx/data-structures/dyn-buffer.c			\
	$(SRC_DIR)/alx/data-structures/llist.c				\
	$(SRC_DIR)/alx/data-structures/node.c				\
	$(SRC_DIR)/alx/data-structures/types.c

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(CURDIR)/%.d: $(SRC_DIR)/alx/data-structures/%.c
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/alx/data-structures/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/alx/data-structures/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/alx/data-structures/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/alx/data-structures/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/alx/data-structures/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/alx/data-structures/$*.o"
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
