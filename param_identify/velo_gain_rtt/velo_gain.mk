# Copyright 2012 The MathWorks, Inc.
# Autogenerated on: 22-Dec-2015 19:52:53
# Model: VELO_GAIN
# MyTemplate
# File name: velo_gain.mk
# Template: gmake 
# Template Version: 1.0 
# Tool Chain Configuration: Arduinomega2560
# Tool Chain Configuration Version: 2.0

ifeq (windows,$(HOST_PLATFORM))
SHELL=%SystemRoot%/System32/cmd.exe 
endif

THIS_MAKEFILE := $(lastword $(MAKEFILE_LIST))
EMPTY :=
SPACE := $(EMPTY) $(EMPTY)

MODEL_NAME := velo_gain
HOST_PLATFORM := mac
BUILD_CFG := MW
TARGET_EXT := .elf
TARGET_HEX_EXT := .hex
OBJ_EXT := .o
TOOL_CHAIN_CFG := Arduinomega2560
FORMAT_PATH = $(if $(filter \\\\%,$(1)),"$(1)",$(subst $(SPACE),\$(SPACE),$(subst \,/,$(1))))

MATLAB_ROOT_RELATIVE := ../../../../../../../../Applications/MATLAB_R2015a.app/#MATLAB_ROOT_RELATIVE_END
MATLAB_ROOT_ABSOLUTE := /Applications/MATLAB_R2015a.app/#MATLAB_ROOT_ABSOLUTE_END
SOURCE_PATH := $(call FORMAT_PATH,./)

ifneq (.a,$(strip $(TARGET_EXT)))
OUTPUT_PATH := $(call FORMAT_PATH,$(SOURCE_PATH)$(BUILD_CFG)/)
else
OUTPUT_PATH := $(call FORMAT_PATH,$(SOURCE_PATH)/)
endif

DERIVED_PATH := $(call FORMAT_PATH,$(SOURCE_PATH))
TARGET_NAME_PREFIX := 
TARGET_NAME_POSTFIX := 
TARGET_FILE_NO_EXT := $(TARGET_NAME_PREFIX)$(MODEL_NAME)$(TARGET_NAME_POSTFIX)
TARGET_FILE := $(TARGET_FILE_NO_EXT)$(TARGET_EXT)

TARGET := $(OUTPUT_PATH)$(TARGET_FILE)
TARGET_HEX := $(TARGET_FILE_NO_EXT)$(TARGET_HEX_EXT)

#Code Generation Files

ifneq (.a,$(strip $(TARGET_EXT)))
SOURCE_FILES := $(call FORMAT_PATH,./ext_svr.c) $(call FORMAT_PATH,./ext_work.c) $(call FORMAT_PATH,./updown.c) $(call FORMAT_PATH,./ext_serial_pkt.c) $(call FORMAT_PATH,./ext_svr_serial_transport.c) $(call FORMAT_PATH,./rtiostream_serial_interface.c) $(call FORMAT_PATH,./rtiostream_utils.c) $(call FORMAT_PATH,./ert_main.c) $(call FORMAT_PATH,./velo_gain.c) $(call FORMAT_PATH,./velo_gain_data.c) $(call FORMAT_PATH,./HardwareSerial.cpp) $(call FORMAT_PATH,./IPAddress.cpp) $(call FORMAT_PATH,./Print.cpp) $(call FORMAT_PATH,./WInterrupts.c) $(call FORMAT_PATH,./WMath.cpp) $(call FORMAT_PATH,./WString.cpp) $(call FORMAT_PATH,./new.cpp) $(call FORMAT_PATH,./wiring.c) $(call FORMAT_PATH,./wiring_analog.c) $(call FORMAT_PATH,./wiring_digital.c) $(call FORMAT_PATH,./rtiostream_serial.cpp) $(call FORMAT_PATH,./io_wrappers.cpp)
else
SOURCE_FILES := $(call FORMAT_PATH,./ext_svr.c) $(call FORMAT_PATH,./ext_work.c) $(call FORMAT_PATH,./updown.c) $(call FORMAT_PATH,./ext_serial_pkt.c) $(call FORMAT_PATH,./ext_svr_serial_transport.c) $(call FORMAT_PATH,./rtiostream_serial_interface.c) $(call FORMAT_PATH,./rtiostream_utils.c) $(call FORMAT_PATH,./ert_main.c) $(call FORMAT_PATH,./velo_gain.c) $(call FORMAT_PATH,./velo_gain_data.c) $(call FORMAT_PATH,./HardwareSerial.cpp) $(call FORMAT_PATH,./IPAddress.cpp) $(call FORMAT_PATH,./Print.cpp) $(call FORMAT_PATH,./WInterrupts.c) $(call FORMAT_PATH,./WMath.cpp) $(call FORMAT_PATH,./WString.cpp) $(call FORMAT_PATH,./new.cpp) $(call FORMAT_PATH,./wiring.c) $(call FORMAT_PATH,./wiring_analog.c) $(call FORMAT_PATH,./wiring_digital.c) $(call FORMAT_PATH,./rtiostream_serial.cpp) $(call FORMAT_PATH,./io_wrappers.cpp)
endif

HEADER_FILES := $(call FORMAT_PATH,../../../../../../../../Applications/MATLAB_R2015a.app/rtw/c/src/ext_mode/common/ext_svr.h) $(call FORMAT_PATH,../../../../../../../../Applications/MATLAB_R2015a.app/rtw/c/src/ext_mode/common/ext_work.h) $(call FORMAT_PATH,../../../../../../../../Applications/MATLAB_R2015a.app/rtw/c/src/ext_mode/common/updown.h) $(call FORMAT_PATH,../../../../../../../../Applications/MATLAB_R2015a.app/rtw/c/src/ext_mode/serial/ext_serial_pkt.h) $(call FORMAT_PATH,../../../../../../../../Applications/MATLAB_R2015a.app/toolbox/coder/rtiostream/src/utils/rtiostream_utils.h) $(call FORMAT_PATH,./velo_gain.h) $(call FORMAT_PATH,../../../../SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/HardwareSerial.h) $(call FORMAT_PATH,../../../../SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/IPAddress.h) $(call FORMAT_PATH,../../../../SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/Print.h) $(call FORMAT_PATH,../../../../SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/WString.h) $(call FORMAT_PATH,../../../../SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/new.h)

LIBRARY_FILES := 

OBJ_FILES := $(addprefix $(DERIVED_PATH),$(addsuffix $(OBJ_EXT),$(basename $(notdir $(SOURCE_FILES)))))

SKIPPED_FILES := 

#Code Generation Information

COMPILER_CODEGEN_ARGS := -I"/Users/shohei/Documents/MATLAB/SupportPackages/R2015a/arduinobase/toolbox/realtime/targets/arduino/include" -I"/Users/shohei/Documents/MATLAB/SupportPackages/R2015a/arduinobase/toolbox/realtime/targets/arduino/blocks/sfcn/include" -I"/Users/shohei/Documents/MATLAB/Projects/control/param_identify/velo_gain_rtt" -I"/Users/shohei/Documents/MATLAB/Projects/control/param_identify" -I"/Applications/MATLAB_R2015a.app/extern/include" -I"/Applications/MATLAB_R2015a.app/simulink/include" -I"/Applications/MATLAB_R2015a.app/rtw/c/src" -I"/Applications/MATLAB_R2015a.app/rtw/c/src/ext_mode/common" -I"/Applications/MATLAB_R2015a.app/rtw/c/ert" -I"/Applications/MATLAB_R2015a.app/toolbox/coder/rtiostream/src/utils" -I"/Users/shohei/Documents/MATLAB/SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino" -I"/Users/shohei/Documents/MATLAB/SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/mega" -I"/Users/shohei/Documents/MATLAB/SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/libraries/Servo" -I"/Applications/MATLAB_R2015a.app/rtw/c/src/ext_mode/serial" -I"/Users/shohei/Documents/MATLAB/SupportPackages/R2015a/arduino/toolbox/realtime/targets/arduinomega2560/src" -mmcu=atmega2560 -ffunction-sections -fdata-sections -std=gnu99 -Wall -Wstrict-prototypes -g -Os -D"MODEL=velo_gain" -D"NUMST=2" -D"NCSTATES=0" -D"HAVESTDIO=" -D"UNIX=" -D"ON_TARGET_WAIT_FOR_START=1" -D"ONESTEPFCN=0" -D"EXT_MODE=1" -D"TERMFCN=1" -D"MAT_FILE=0" -D"MULTI_INSTANCE_CODE=0" -D"INTEGER_CODE=0" -D"MT=0" -D"CLASSIC_INTERFACE=0" -D"ALLOCATIONFCN=0" -D"TID01EQ=1" -D"F_CPU=16000000" -D"ARDUINO=105" -D"_RUNONTARGETHARDWARE_BUILD_=" -D"_ROTH_MEGA2560_=" -D"_RTT_NUMSERVOS_=0" -D"EXT_BAUD_RATE=115200" -D"EXIT_FAILURE=1" -D"EXTMODE_DISABLEPRINTF=" -D"EXTMODE_DISABLETESTING=" -D"EXTMODE_DISABLE_ARGS_PROCESSING=1"

COMPILER_TCCFG_ARGS := -c -x none
COMPILER_ARGS := $(COMPILER_CODEGEN_ARGS) $(COMPILER_TCCFG_ARGS)

LINKER_CODEGEN_ARGS :=  -lm -mmcu=atmega2560 -g -Wl,--gc-sections 

LINKER_TCCFG_ARGS := -o $(TARGET)
LINKER_ARGS := $(LINKER_CODEGEN_ARGS) $(LINKER_TCCFG_ARGS)

PREBUILD_ARGS := 

POSTBUILD_ARGS := -O ihex -R .eeprom $(TARGET)  velo_gain.hex

EXECUTE_ARGS := 



COMPILER ?= $(subst \,/,/Users/shohei/Documents/MATLAB/SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc)

LINKER ?= $(subst \,/,/Users/shohei/Documents/MATLAB/SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc)

PREBUILD_TOOL ?= 

POSTBUILD_TOOL ?= $(subst \,/,/Users/shohei/Documents/MATLAB/SupportPackages/R2015a/arduino-1.0.5/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-objcopy)

EXECUTE_USES_TARGET = off
ifeq (on,$(EXECUTE_USES_TARGET))
 EXECUTE_TOOL ?= $(TARGET)
else
 EXECUTE_TOOL ?= 
endif
ifeq (windows,$(HOST_PLATFORM))
 RM ?= del /q
else
 RM ?= rm -f
endif
ifeq (windows,$(HOST_PLATFORM))
 MKDIR ?= mkdir
else
 MKDIR ?= mkdir -p
endif

#Targets
.DEFAULT_GOAL := all

.PHONY : all execute prebuild build postbuild info environment check clean

all : execute

ifneq (,$(strip $(EXECUTE_TOOL)))
execute : build
	$(info "Evaluating execute target")
	"$(EXECUTE_TOOL)" $(EXECUTE_ARGS)
else
execute : build
endif

ifneq (.a,$(strip $(TARGET_EXT)))
build : prebuild $(TARGET) $(TARGET_HEX)
	$(info "Evaluating build target")
else
build : prebuild $(TARGET)
	$(info "Evaluating build target")
endif

ifneq (,$(strip $(PREBUILD_TOOL)))
ifneq (.a,$(strip $(TARGET_EXT)))
prebuild : | $(OUTPUT_PATH) $(DERIVED_PATH)
	$(info "Evaluating prebuild target")
	"$(PREBUILD_TOOL)" $(PREBUILD_ARGS)
    else
prebuild : | $(OUTPUT_PATH) $(DERIVED_PATH)
    endif
else
prebuild : | $(OUTPUT_PATH) $(DERIVED_PATH)
endif

ifneq (,$(strip $(POSTBUILD_TOOL)))
ifneq (.a,$(strip $(TARGET_EXT)))
postbuild : $(TARGET)
	$(info "Evaluating postbuild target")
	"$(POSTBUILD_TOOL)" $(POSTBUILD_ARGS)
$(TARGET_HEX) : $(TARGET)
	"$(POSTBUILD_TOOL)" $(POSTBUILD_ARGS)
    else
postbuild : $(TARGET)
    endif
else
postbuild : $(TARGET)
endif

ifneq (,$(strip $(LINKER)))
ifneq (.a,$(strip $(TARGET_EXT)))
ifneq (,$(strip $(POSTBUILD_TOOL)))
$(TARGET) : $(OBJ_FILES) $(LIBRARY_FILES)
	"$(LINKER)" $(OBJ_FILES) $(LIBRARY_FILES) $(LINKER_ARGS)
	"$(POSTBUILD_TOOL)" $(POSTBUILD_ARGS)
else
$(TARGET) : $(OBJ_FILES) $(LIBRARY_FILES)
	"$(LINKER)" $(OBJ_FILES) $(LIBRARY_FILES) $(LINKER_ARGS)
endif
else
$(TARGET) : $(OBJ_FILES)
	"$(LINKER)" $(OBJ_FILES) $(LIBRARY_FILES) $(LINKER_ARGS)
endif

$(OBJ_FILES) : $(SOURCE_FILES) $(HEADER_FILES)
	"$(COMPILER)" $(COMPILER_ARGS) $(SOURCE_FILES)
else
ifneq (,$(strip $(POSTBUILD_TOOL)))
$(TARGET) : $(SOURCE_FILES) $(HEADER_FILES)
	"$(COMPILER)" $(COMPILER_ARGS) $(SOURCE_FILES)
	"$(POSTBUILD_TOOL)" $(POSTBUILD_ARGS)
else
$(TARGET) : $(SOURCE_FILES) $(HEADER_FILES)
	"$(COMPILER)" $(COMPILER_ARGS) $(SOURCE_FILES)
endif
endif

$(OUTPUT_PATH) :
ifeq (,$(wildcard $(OUTPUT_PATH)))
	@$(MKDIR) "$(OUTPUT_PATH)"
endif

$(DERIVED_PATH) :
ifeq (,$(wildcard $(DERIVED_PATH)))
	@$(MKDIR) "$(DERIVED_PATH)"
endif

clean :
	-@$(RM) $(TARGET) $(OBJ_FILES)

info : 
	$(info MODEL_NAME=$(MODEL_NAME))
	$(info HOST_PLATFORM=$(HOST_PLATFORM))
	$(info BUILD_CFG=$(BUILD_CFG))
	$(info TOOL_CHAIN_CFG=$(TOOL_CHAIN_CFG))
	$(info TARGET_EXT=$(TARGET_EXT))
	$(info OBJ_EXT=$(OBJ_EXT))
	$(info SOURCE_PATH=$(SOURCE_PATH))
	$(info OUTPUT_PATH=$(OUTPUT_PATH))
	$(info DERIVED_PATH=$(DERIVED_PATH))
	$(info TARGET_FILE=$(TARGET_FILE))
	$(info TARGET=$(TARGET))
	$(info COMPILER=$(COMPILER))
	$(info COMPILER_ARGS=$(COMPILER_ARGS))
	$(info COMPILER_CODEGEN_ARGS=$(COMPILER_CODEGEN_ARGS))
	$(info COMPILER_TCCFG_ARGS=$(COMPILER_TCCFG_ARGS))
	$(info LINKER=$(LINKER))
	$(info LINKER_ARGS=$(LINKER_ARGS))
	$(info LINKER_CODEGEN_ARGS=$(LINKER_CODEGEN_ARGS))
	$(info LINKER_TCCFG_ARGS=$(LINKER_TCCFG_ARGS))
	$(info PREBUILD_TOOL=$(PREBUILD_TOOL))
	$(info PREBUILD_ARGS=$(PREBUILD_ARGS))
	$(info POSTBUILD_TOOL=$(POSTBUILD_TOOL))
	$(info POSTBUILD_ARGS=$(POSTBUILD_ARGS))
	$(info EXECUTE_TOOL=$(EXECUTE_TOOL))
	$(info EXECUTE_ARGS=$(EXECUTE_ARGS))
	$(info SOURCE_FILES=$(SOURCE_FILES))
	$(info HEADER_FILES=$(HEADER_FILES))
	$(info LIBRARY_FILES=$(LIBRARY_FILES))
	$(info OBJ_FILES=$(OBJ_FILES))
	$(info SKIPPED_FILES=$(SKIPPED_FILES))
	$(info RM=$(RM))
	$(info MKDIR=$(MKDIR))

environment :
	$(if $(findstring windows,$(HOST_PLATFORM)),$(info ENVIRONMENT=$(shell set)),$(info ENVIRONMENT=$(shell env)))
