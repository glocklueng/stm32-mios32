# $Id: Makefile 194 2008-12-18 01:47:21Z tk $

################################################################################
# The make rule compiles the code and generates the mios32_bsl_*.inc file
################################################################################
all: MBHP_CORE_STM32 MBHP_CORE_STM32_CL STM32_PRIMER STM32F4DISCOVERY LPCXPRESSO_1768 LPCXPRESSO_1769 dummy cleanall

MBHP_CORE_STM32:
	make -f Makefile.bsl_MBHP_CORE_STM32 cleanall
	make -f Makefile.bsl_MBHP_CORE_STM32
	mv project_build/project.bin project_MBHP_CORE_STM32.bin
	perl gen_inc_file.pl project_MBHP_CORE_STM32.bin ../../mios32/STM32F10x/mios32_bsl_MBHP_CORE_STM32.inc mios32_bsl_image mios32_bsl
	perl gen_inc_file.pl project_MBHP_CORE_STM32.bin ../updater/bsl_image_MBHP_CORE_STM32.inc bsl_image 0

MBHP_CORE_STM32_CL:
	make -f Makefile.bsl_MBHP_CORE_STM32_CL cleanall
	make -f Makefile.bsl_MBHP_CORE_STM32_CL
	mv project_build/project.bin project_MBHP_CORE_STM32_CL.bin
	perl gen_inc_file.pl project_MBHP_CORE_STM32_CL.bin ../../mios32/STM32F10x/mios32_bsl_MBHP_CORE_STM32_CL.inc mios32_bsl_image mios32_bsl
	perl gen_inc_file.pl project_MBHP_CORE_STM32_CL.bin ../updater/bsl_image_MBHP_CORE_STM32_CL.inc bsl_image 0

STM32_PRIMER:
	make -f Makefile.bsl_STM32_PRIMER cleanall
	make -f Makefile.bsl_STM32_PRIMER
	mv project_build/project.bin project_STM32_PRIMER.bin
	perl gen_inc_file.pl project_STM32_PRIMER.bin ../../mios32/STM32F10x/mios32_bsl_STM32_PRIMER.inc mios32_bsl_image mios32_bsl

STM32F4DISCOVERY:
	make -f Makefile.bsl_STM32F4DISCOVERY cleanall
	make -f Makefile.bsl_STM32F4DISCOVERY
	mv project_build/project.bin project_STM32F4DISCOVERY.bin
	perl gen_inc_file.pl project_STM32F4DISCOVERY.bin ../../mios32/STM32F4xx/mios32_bsl_STM32F4DISCOVERY.inc mios32_bsl_image mios32_bsl
	perl gen_inc_file.pl project_STM32F4DISCOVERY.bin ../updater/bsl_image_STM32F4DISCOVERY.inc bsl_image 0

LPCXPRESSO_1768:
	make -f Makefile.bsl_LPCXPRESSO_1768 cleanall
	make -f Makefile.bsl_LPCXPRESSO_1768
	mv project_build/project.bin project_LPCXPRESSO_1768.bin
	perl gen_inc_file.pl project_LPCXPRESSO_1768.bin ../../mios32/LPC17xx/mios32_bsl_LPCXPRESSO_1768.inc mios32_bsl_image mios32_bsl -calc_lpc17_checksum
	perl gen_inc_file.pl project_LPCXPRESSO_1768.bin ../updater/bsl_image_LPCXPRESSO_1768.inc bsl_image 0 -calc_lpc17_checksum

LPCXPRESSO_1769:
	make -f Makefile.bsl_LPCXPRESSO_1769 cleanall
	make -f Makefile.bsl_LPCXPRESSO_1769
	mv project_build/project.bin project_LPCXPRESSO_1769.bin
	perl gen_inc_file.pl project_LPCXPRESSO_1769.bin ../../mios32/LPC17xx/mios32_bsl_LPCXPRESSO_1769.inc mios32_bsl_image mios32_bsl -calc_lpc17_checksum
	perl gen_inc_file.pl project_LPCXPRESSO_1769.bin ../updater/bsl_image_LPCXPRESSO_1769.inc bsl_image 0 -calc_lpc17_checksum

dummy:
	make -f Makefile.bsl_dummy cleanall
	make -f Makefile.bsl_dummy
	mv project_build/project.bin project_dummy.bin
	perl gen_inc_file.pl project_dummy.bin ../../mios32/STM32F10x/mios32_bsl_dummy.inc mios32_bsl_image mios32_bsl


clean:
	make -f Makefile.bsl_MBHP_CORE_STM32 clean

cleanall:
	make -f Makefile.bsl_MBHP_CORE_STM32 cleanall
