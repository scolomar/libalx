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
	$(CURDIR)/memchr/memchrend.o					\
	$(CURDIR)/strcat/strbcatf.o					\
	$(CURDIR)/strcat/strscat.o					\
	$(CURDIR)/strcat/strscatf.o					\
	$(CURDIR)/strcat/strscatfs.o					\
	$(CURDIR)/strchr/strcasechr.o					\
	$(CURDIR)/strchr/strcasechrnul.o				\
	$(CURDIR)/strchr/strncasechr.o					\
	$(CURDIR)/strchr/strncasechrnul.o				\
	$(CURDIR)/strchr/strnchr.o					\
	$(CURDIR)/strchr/strnchrnul.o					\
	$(CURDIR)/strchr/strnrcasechr.o					\
	$(CURDIR)/strchr/strnrcasechrnul.o				\
	$(CURDIR)/strchr/strnrchr.o					\
	$(CURDIR)/strchr/strnrchrnul.o					\
	$(CURDIR)/strchr/strrcasechr.o					\
	$(CURDIR)/strchr/strrcasechrnul.o				\
	$(CURDIR)/strchr/strrchrnul.o					\
	$(CURDIR)/strcpy/strlcpys.o					\
	$(CURDIR)/strcpy/strscpy.o					\
	$(CURDIR)/strlwr/strlwr.o					\
	$(CURDIR)/strlwr/strnlwr.o					\
	$(CURDIR)/strlwr/strupr.o					\
	$(CURDIR)/strlwr/strnupr.o					\
	$(CURDIR)/strgrep.o						\
	$(CURDIR)/strstr/strncasestr.o					\
	$(CURDIR)/strstr/strscasestr.o					\
	$(CURDIR)/strstr/strsstr.o

OBJ_TST		=							\
		strgrep-test.o

SRC	=								\
	$(SRC_DIR)/base/string/memchr/memchrend.c			\
	$(SRC_DIR)/base/string/strcat/strbcatf.c			\
	$(SRC_DIR)/base/string/strcat/strscat.c				\
	$(SRC_DIR)/base/string/strcat/strscatf.c			\
	$(SRC_DIR)/base/string/strcat/strscatfs.c			\
	$(SRC_DIR)/base/string/strchr/strcasechr.c			\
	$(SRC_DIR)/base/string/strchr/strcasechrnul.c			\
	$(SRC_DIR)/base/string/strchr/strncasechr.c			\
	$(SRC_DIR)/base/string/strchr/strncasechrnul.c			\
	$(SRC_DIR)/base/string/strchr/strnchr.c				\
	$(SRC_DIR)/base/string/strchr/strnchrnul.c			\
	$(SRC_DIR)/base/string/strchr/strnrcasechr.c			\
	$(SRC_DIR)/base/string/strchr/strnrcasechrnul.c			\
	$(SRC_DIR)/base/string/strchr/strnrchr.c			\
	$(SRC_DIR)/base/string/strchr/strnrchrnul.c			\
	$(SRC_DIR)/base/string/strchr/strrcasechr.c			\
	$(SRC_DIR)/base/string/strchr/strrcasechrnul.c			\
	$(SRC_DIR)/base/string/strchr/strrchrnul.c			\
	$(SRC_DIR)/base/string/strcpy/strlcpys.c			\
	$(SRC_DIR)/base/string/strcpy/strscpy.c				\
	$(SRC_DIR)/base/string/strlwr/strlwr.c				\
	$(SRC_DIR)/base/string/strlwr/strnlwr.c				\
	$(SRC_DIR)/base/string/strlwr/strupr.c				\
	$(SRC_DIR)/base/string/strlwr/strnupr.c				\
	$(SRC_DIR)/base/string/strgrep.c				\
	$(SRC_DIR)/base/string/strstr/strncasestr.c			\
	$(SRC_DIR)/base/string/strstr/strscasestr.c			\
	$(SRC_DIR)/base/string/strstr/strsstr.c

TST_STRGREP_SRC	=							\
		$(SRC_DIR)/base/string/strgrep-test.c			\
		$(SRC_DIR)/base/string/strgrep.c

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(CURDIR)/%.d: $(SRC_DIR)/base/string/%.c
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/base/string/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/base/string/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/string/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/base/string/%.c $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/string/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/base/string/$*.o"
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
