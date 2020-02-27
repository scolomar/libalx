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
# Do not print "Entering directory ..."
MAKEFLAGS += --no-print-directory

################################################################################
# target: dependencies
#	action

PHONY	:= all
all: base alx extra


PHONY	+= base_tmp
base: base_tmp base_lib


PHONY	+= alx
alx: data-structures npcomplete robot

PHONY	+= data-structures
data-structures: data-structures_tmp data-structures_lib

PHONY	+= npcomplete
npcomplete: npcomplete_tmp npcomplete_lib

PHONY	+= robot
robot: robot_tmp robot_lib


PHONY	+= extra
extra: curl cv gmp gsl ncurses ocr telnet-tcp zbar

PHONY	+= curl
curl: curl_tmp curl_lib

PHONY	+= cv
cv: cv_tmp cv_lib

PHONY	+= gmp
gmp: gmp_tmp gmp_lib

PHONY	+= gsl
gsl: gsl_tmp gsl_lib

PHONY	+= ncurses
ncurses: ncurses_tmp ncurses_lib

PHONY	+= ocr
ocr: ocr_tmp ocr_lib

PHONY	+= telnet-tcp
telnet-tcp: telnet-tcp_tmp telnet-tcp_lib

PHONY	+= zbar
zbar: zbar_tmp zbar_lib

################################################################################
# target: dependencies
#	action


PHONY	+= base_tmp
base_tmp:
	$(Q)$(MAKE) base		-C $(BUILD_TMP_DIR)
PHONY	+= base_tmp
base_lib: base_tmp
	$(Q)$(MAKE) base		-C $(BUILD_LIB_DIR)



PHONY	+= data-structures_tmp
data-structures_tmp:
	$(Q)$(MAKE) data-structures	-C $(BUILD_TMP_DIR)
PHONY	+= data-structures_lib
data-structures_lib: data-structures_tmp base_lib
	$(Q)$(MAKE) data-structures	-C $(BUILD_LIB_DIR)

PHONY	+= npcomplete_tmp
npcomplete_tmp:
	$(Q)$(MAKE) npcomplete		-C $(BUILD_TMP_DIR)
PHONY	+= npcomplete_lib
npcomplete_lib: npcomplete_tmp base_lib
	$(Q)$(MAKE) npcomplete		-C $(BUILD_LIB_DIR)

PHONY	+= robot_tmp
robot_tmp:
	$(Q)$(MAKE) robot		-C $(BUILD_TMP_DIR)
PHONY	+= robot_lib
robot_lib: robot_tmp base_lib
	$(Q)$(MAKE) robot		-C $(BUILD_LIB_DIR)



PHONY	+= curl_tmp
curl_tmp:
	$(Q)$(MAKE) curl		-C $(BUILD_TMP_DIR)
PHONY	+= curl_lib
curl_lib: curl_tmp data-structures_lib base_lib
	$(Q)$(MAKE) curl		-C $(BUILD_LIB_DIR)

PHONY	+= cv_tmp
cv_tmp:
	$(Q)$(MAKE) cv			-C $(BUILD_TMP_DIR)
PHONY	+= cv_lib
cv_lib: cv_tmp gsl_lib base_lib
	$(Q)$(MAKE) cv			-C $(BUILD_LIB_DIR)

PHONY	+= gmp_tmp
gmp_tmp:
	$(Q)$(MAKE) gmp			-C $(BUILD_TMP_DIR)
PHONY	+= gmp_lib
gmp_lib: gmp_tmp base_lib
	$(Q)$(MAKE) gmp			-C $(BUILD_LIB_DIR)

PHONY	+= gsl_tmp
gsl_tmp:
	$(Q)$(MAKE) gsl			-C $(BUILD_TMP_DIR)
PHONY	+= gsl_lib
gsl_lib: gsl_tmp base_lib
	$(Q)$(MAKE) gsl			-C $(BUILD_LIB_DIR)

PHONY	+= ncurses
ncurses_tmp:
	$(Q)$(MAKE) ncurses		-C $(BUILD_TMP_DIR)
PHONY	+= ncurses
ncurses_lib: ncurses_tmp base_lib
	$(Q)$(MAKE) ncurses		-C $(BUILD_LIB_DIR)

PHONY	+= ocr
ocr_tmp:
	$(Q)$(MAKE) ocr			-C $(BUILD_TMP_DIR)
PHONY	+= ocr
ocr_lib: ocr_tmp base_lib
	$(Q)$(MAKE) ocr			-C $(BUILD_LIB_DIR)

PHONY	+= telnet-tcp
telnet-tcp_tmp:
	$(Q)$(MAKE) telnet-tcp		-C $(BUILD_TMP_DIR)
PHONY	+= telnet-tcp
telnet-tcp_lib: telnet-tcp_tmp base_lib
	$(Q)$(MAKE) telnet-tcp		-C $(BUILD_LIB_DIR)

PHONY	+= zbar
zbar_tmp:
	$(Q)$(MAKE) zbar		-C $(BUILD_TMP_DIR)
PHONY	+= zbar
zbar_lib: zbar_tmp base_lib
	$(Q)$(MAKE) zbar		-C $(BUILD_LIB_DIR)



PHONY	+= tst
tst: all
	@echo	"	MAKE	tst"
	$(Q)$(MAKE)	-C $(TST_DIR)

################################################################################
PHONY	+= install
install: install_base install_alx install_extra install_sh install_py

PHONY	+= install_base
install_base: inst_base

PHONY	+= install_alx
install_alx: inst_alx

PHONY	+= install_extra
install_extra: inst_extra

PHONY	+= install_sh
install_sh: inst_sh

PHONY	+= install_py
install_py: inst_py

################################################################################
PHONY	+= inst_base
inst_base:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/*"
	$(Q)cp -rf $(v)		$(INC_DIR)/libalx/base/*		\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/*"
	$(Q)cp -rf $(v)		$(SHARE_DIR)/libalx/*			\
					$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/
	$(Q)$(MAKE)	inst_libalx-base

PHONY	+= inst_alx
inst_alx: inst_base
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/*"
	$(Q)cp -r -f $(v)	$(INC_DIR)/libalx/alx/*			\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/
	$(Q)$(MAKE)	inst_libalx-data-structures
#	$(Q)$(MAKE)	inst_libalx-npcomplete
	$(Q)$(MAKE)	inst_libalx-robot

PHONY	+= inst_extra
inst_extra: inst_alx inst_base
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/*"
	$(Q)cp -r -f $(v)	$(ETC_DIR)/libalx/extra/*		\
					$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/*"
	$(Q)cp -r -f $(v)	$(INC_DIR)/libalx/extra/*		\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/
	$(Q)$(MAKE)	inst_libalx-curl
	$(Q)$(MAKE)	inst_libalx-cv
	$(Q)$(MAKE)	inst_libalx-gmp
	$(Q)$(MAKE)	inst_libalx-gsl
	$(Q)$(MAKE)	inst_libalx-ncurses
	$(Q)$(MAKE)	inst_libalx-ocr
	$(Q)$(MAKE)	inst_libalx-telnet-tcp
	$(Q)$(MAKE)	inst_libalx-zbar

PHONY	+= inst_sh
inst_sh:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/*"
	$(Q)cp -rf $(v)		$(LIB_DIR)/libalx/sh/*			\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/
	@echo

PHONY	+= inst_py
inst_py:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/*"
	$(Q)cp -rf $(v)		$(LIB_DIR)/libalx/py/*			\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/
	@echo

PHONY	+= inst_libalx-%
inst_lib%: inst_lib%.a inst_lib%.so inst_lib%.pc
	@:

PHONY += inst_lib%.a
inst_lib%.a:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/lib$*.a"
	$(Q)cp -f $(v)		$(BUILD_LIB_DIR)/libalx/lib$*.a		\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/

PHONY += inst_lib%.so
inst_lib%.so:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/lib$*.so"
	$(Q)cp -f $(v)		$(BUILD_LIB_DIR)/libalx/lib$*.so	\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/

PHONY += inst_lib%.pc
inst_lib%.pc:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/lib$*.pc"
	$(Q)cp -f $(v)		$(LIB_DIR)/pkgconfig/lib$*.pc		\
					$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/

################################################################################
PHONY += uninstall
uninstall:
	@echo	"	Clean old installations:"
	@echo
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/libalx*.pc"
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/
	$(Q)find		$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/	\
				-type f -name 'libalx*.pc' -exec rm '{}' '+'
	@echo	"	RM	$(DESTDIR)/etc/ld.so.conf.d/libalx*.conf"
	$(Q)find		$(DESTDIR)/etc/ld.so.conf.d/		\
				-type f -name 'libalx*.conf' -exec rm '{}' '+'
	@echo	"	LDCONFIG"
	$(Q)ldconfig
	@echo	"	Done"
	@echo

################################################################################
PHONY	+= conf_ld
conf_ld:
	@echo	"	CP -r	$(DESTDIR)/etc/ld.so.conf.d/*"
	$(Q)cp -r -f $(v)	$(ETC_DIR)/ld.so.conf.d/*		\
					$(DESTDIR)/etc/ld.so.conf.d/
	@echo	"	LDCONFIG"
	$(Q)ldconfig
	@echo

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
