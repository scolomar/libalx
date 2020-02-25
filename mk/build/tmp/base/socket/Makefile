#! /usr/bin/make -f

################################################################################
# Copyright (C) 2020	Alejandro Colomar Andrés
# SPDX-License-Identifier:	LGPL-2.0-only
################################################################################
# *AUTHOR*
# FULL NAME	"Alejandro Colomar Andrés"
# EMAIL		"1903716@gmail.com"
################################################################################

################################################################################
# dependencies

DIRS		=							\
		tcp

OBJ		=							\
		tcp/client.o						\
		tcp/server.o

TCP_CLIENT_INC	=							\
		$(INC_DIR)/libalx/base/socket/tcp/client.h
TCP_CLIENT_SRC	=							\
		$(SRC_DIR)/base/socket/tcp/client.c

TCP_SERVER_INC	=							\
		$(INC_DIR)/libalx/base/socket/tcp/server.h
TCP_SERVER_SRC	=							\
		$(SRC_DIR)/base/socket/tcp/server.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))
	@:


$(DIRS):
	@echo	"	MKDIR	build/tmp/base/string/$@"
	$(Q)mkdir -p		$@/


tcp/%.a.s: | tcp


%.a.s:
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/socket/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/socket/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/base/socket/$@"
	$(Q)$(AS) $< -o $@


tcp/client.a.s: $(TCP_CLIENT_SRC) $(TCP_CLIENT_INC)
tcp/client.so.s: $(TCP_CLIENT_SRC) $(TCP_CLIENT_INC)

tcp/server.a.s: $(TCP_SERVER_SRC) $(TCP_SERVER_INC)
tcp/server.so.s: $(TCP_SERVER_SRC) $(TCP_SERVER_INC)


PHONY += clean
clean:
	$(Q)rm -rf *.o *.s

################################################################################
# Declare the contents of the PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
