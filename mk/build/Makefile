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
install: | install-base
install: | install_alx
install: | install_extra
install: | install_sh
install: | install_py
install: | install-doc

PHONY	+= install-doc
install-doc: inst-share

PHONY	+= install-base
install-base: inst-inc-base
install-base: inst-libalx-base
install-base: | install-doc

PHONY	+= install_alx
install_alx: install-data-structures
install_alx: install-npcomplete
install_alx: install-robot
install_alx: | install-base

PHONY	+= install-data-structures
install-data-structures: inst-inc-a-data-structures inst-libalx-data-structures
install-data-structures: | install-base
PHONY	+= install-npcomplete
install-npcomplete: inst-inc-a-npcomplete inst-libalx-npcomplete | install-base
PHONY	+= install-robot
install-robot: inst-inc-a-robot inst-libalx-robot
install-robot: | install-base install-telnet-tcp

PHONY	+= install_extra
install_extra: | install-curl
install_extra: | install-cv
install_extra: | install-gmp
install_extra: | install-gsl
install_extra: | install-ncurses
install_extra: | install-ocr
install_extra: | install-telnet-tcp
install_extra: | install-zbar
install_extra: | install-base

PHONY	+= install-curl
install-curl: inst-inc-x-curl inst-libalx-curl | install-base
PHONY	+= install-cv
install-cv: inst-inc-x-cv inst-libalx-cv | install-base install-gsl
PHONY	+= install-gmp
install-gmp: inst-inc-x-gmp inst-libalx-gmp | install-base
PHONY	+= install-gsl
install-gsl: inst-inc-x-gsl inst-libalx-gsl | install-base
PHONY	+= install-ncurses
install-ncurses: inst-inc-x-ncurses inst-libalx-ncurses | install-base
PHONY	+= install-ocr
install-ocr: inst-etc-x-ocr inst-inc-x-ocr inst-libalx-ocr | install-base
PHONY	+= install-telnet-tcp
install-telnet-tcp: inst-inc-x-telnet-tcp inst-libalx-telnet-tcp | install-base
PHONY	+= install-zbar
install-zbar: inst-inc-x-zbar inst-libalx-zbar | install-base

PHONY	+= install-sh
install_sh: inst-sh | install-doc

PHONY	+= install-py
install_py: inst-py | install-doc

################################################################################
PHONY	+= inst-base
inst-base:

PHONY	+= inst-sh
inst-sh:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/*"
	$(Q)cp -rf $(v)		$(LIB_DIR)/libalx/sh/*			\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/sh/
	@echo

PHONY	+= inst-py
inst-py:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/*"
	$(Q)cp -rf $(v)		$(LIB_DIR)/libalx/py/*			\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/py/
	@echo

PHONY += inst-share
inst-share:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/*"
	$(Q)cp -r -f $(v)	$(SHARE_DIR)/libalx/*		\
					$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/

PHONY += inst-etc-x-%
inst-etc-x-%:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/$*/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/$*/*"
	$(Q)cp -r -f $(v)	$(ETC_DIR)/libalx/extra/$*/*		\
					$(DESTDIR)/$(INSTALL_ETC_DIR)/libalx/extra/$*/

PHONY += inst-inc-base
inst-inc-base:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/*"
	$(Q)cp -r -f $(v)	$(INC_DIR)/libalx/base/*		\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/

PHONY += inst-inc-a-%
inst-inc-a-%:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/$*/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/$*/*"
	$(Q)cp -r -f $(v)	$(INC_DIR)/libalx/alx/$*/*		\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/alx/$*/

PHONY += inst-inc-x-%
inst-inc-x-%:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/$*/
	@echo	"	CP -r	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/$*/*"
	$(Q)cp -r -f $(v)	$(INC_DIR)/libalx/extra/$*/*		\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/$*/

PHONY	+= inst-lib%
inst-lib%: inst--lib%.a inst--lib%.so inst--lib%.pc
	@:

PHONY += inst--lib%.a
inst--lib%.a:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/lib$*.a"
	$(Q)cp -f $(v)		$(BUILD_LIB_DIR)/libalx/lib$*.a		\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/

PHONY += inst--lib%.so
inst--lib%.so:
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	CP	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/lib$*.so"
	$(Q)cp -f $(v)		$(BUILD_LIB_DIR)/libalx/lib$*.so	\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/

PHONY += inst--lib%.pc
inst--lib%.pc:
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
