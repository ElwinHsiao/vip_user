# always force this build to re-run its dependencies
FORCE_GYP := $(shell make -C ../../ GypAndroid.mk)
GYP_CONFIGURATION := Debug

include ../../GypAndroid.mk
