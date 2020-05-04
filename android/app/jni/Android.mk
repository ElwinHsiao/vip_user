# always force this build to re-run its dependencies
FORCE_GYP := $(shell make -C ../../ GypAndroid.mk)
GYP_CONFIGURATION := Debug

include $(call all-subdir-makefiles)
include ../../GypAndroid.mk
