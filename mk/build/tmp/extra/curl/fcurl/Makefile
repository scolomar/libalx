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
	$(CURDIR)/fclose.o						\
	$(CURDIR)/feof.o						\
	$(CURDIR)/fgetc.o						\
	$(CURDIR)/fgets.o						\
	$(CURDIR)/fopen.o						\
	$(CURDIR)/fread.o						\
	$(CURDIR)/init.o						\
	$(CURDIR)/internal.o						\
	$(CURDIR)/rewind.o						\
	$(CURDIR)/ungetc.o						\
	$(CURDIR)/URL_FILE.o

SRC	=								\
	$(SRC_DIR)/extra/curl/fcurl/fclose.c				\
	$(SRC_DIR)/extra/curl/fcurl/feof.c				\
	$(SRC_DIR)/extra/curl/fcurl/fgetc.c				\
	$(SRC_DIR)/extra/curl/fcurl/fgets.c				\
	$(SRC_DIR)/extra/curl/fcurl/fopen.c				\
	$(SRC_DIR)/extra/curl/fcurl/fread.c				\
	$(SRC_DIR)/extra/curl/fcurl/init.c				\
	$(SRC_DIR)/extra/curl/fcurl/internal.c				\
	$(SRC_DIR)/extra/curl/fcurl/rewind.c				\
	$(SRC_DIR)/extra/curl/fcurl/ungetc.c				\
	$(SRC_DIR)/extra/curl/fcurl/URL_FILE.c

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


$(CURDIR)/%.d: $(SRC_DIR)/extra/curl/fcurl/%.c
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/extra/curl/fcurl/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/extra/curl/fcurl/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/extra/curl/fcurl/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/extra/curl/fcurl/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/extra/curl/fcurl/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/extra/curl/fcurl/$*.o"
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
