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

OBJ		=							\
	$(CURDIR)/fgets.o						\
	$(CURDIR)/freads.o						\
	$(CURDIR)/get.o							\
	$(CURDIR)/printf/b.o						\
	$(CURDIR)/printf/sbprintf.o					\
	$(CURDIR)/printf/snprintfs.o					\
	$(CURDIR)/seekc.o						\
	$(CURDIR)/sscan.o

SRC	=								\
	$(SRC_DIR)/base/stdio/fgets.c					\
	$(SRC_DIR)/base/stdio/freads.c					\
	$(SRC_DIR)/base/stdio/get.c					\
	$(SRC_DIR)/base/stdio/printf/b.c				\
	$(SRC_DIR)/base/stdio/printf/sbprintf.c				\
	$(SRC_DIR)/base/stdio/printf/snprintfs.c			\
	$(SRC_DIR)/base/stdio/seekc.c					\
	$(SRC_DIR)/base/stdio/sscan.c

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(CURDIR)/%.d: $(SRC_DIR)/base/stdio/%.c
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/base/stdio/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/base/stdio/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/stdio/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/base/stdio/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/stdio/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/base/stdio/$*.o"
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
