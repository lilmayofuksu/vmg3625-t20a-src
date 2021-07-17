SUBTARGET:=vmg3625_t20a
BOARDNAME:=VMG3625_T20A of EN7512

# Prepare ECONET SDK compilation flags (extract from $(TOPDIR)/.config)
# __ZYXEL__start,
# Replace 'CONFIG_ECONETSDK_' for menuconfig only supports a single prompt problem.
PLATFORM_PREFIX=CONFIG_$(call qstrip, $(CONFIG_CUSTOM_SDK_PREFIX))_
$(foreach v, \
	$(filter $(PLATFORM_PREFIX)%,$(.VARIABLES)), \
	$(eval $(shell echo $v|sed "s/$(PLATFORM_PREFIX)//")=$($v)))
# __ZYXEL__end

## add Trendchip compile flags.
ifneq ($(call qstrip, $(CONFIG_TC_RULE_MAK)),)
include $(PLATFORM_DIR)/$(call qstrip, $(CONFIG_TC_RULE_MAK))
else
include $(PLATFORM_DIR)/tc_rule.mak
endif
#export PROFILE=en7512_demo
export KERNEL_2_6_36=1

#for toolchain path
export TOOLCHAIN_DIR

#These two compile cannot defined at the same time!!
export TC_BUILD_RELEASECODE=y
#export CUSTOMER_BUILD_RELEASECODE=y
##

#ECONET SDK PATH
export ECONET_BUILD_DIR=$(KERNEL_BUILD_DIR)/econet-sdk-$(shell echo $(CONFIG_TC_SDK_VERSION))

##For kernel to include trx.h
#export TC_TRX_INCLUDE_PATH=$(STAGING_DIR_HOST)/include/trx
export TC_TRX_INCLUDE_PATH=$(STAGING_DIR)/usr/include/trx

define Target/Description
	Build images for VMG3625-T20A.
endef
