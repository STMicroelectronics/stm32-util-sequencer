# origin-pack: STMicroelectronics::sequencer@2.1.0
# file-format: 1.0.0
project(STMicroelectronics_sequencer_2_1_0)
cmake_minimum_required(VERSION 3.30)
add_library(STMicroelectronics_sequencer_2_1_0 INTERFACE)

# List of all CMSIS properties that influence conditions for this package
if(NOT DEFINED CMSIS_Dname)
  set(CMSIS_Dname "CMSIS_Dname not set")
  message(DEBUG "CMSIS_Dname is not set to any value")
endif()

if(NOT DEFINED CMSIS_Dvendor)
  set(CMSIS_Dvendor "CMSIS_Dvendor not set")
  message(DEBUG "CMSIS_Dvendor is not set to any value")
endif()


# Device specific defined symbols








# Enable all components in this package
if(CMSIS_ENTIRE_STMicroelectronics_sequencer_2_1_0)
  list(APPEND CMSIS_COMPONENTS_LIST "Cvendor:STMicroelectronics#Cclass:Utility#Cgroup:SEQUENCER#Csub:Core#Cversion:1.0.0")
endif()

# All conditions used by this package

# condition: STMicroelectronics.sequencer.2.1.0
# description: 
if((CMSIS_Dname MATCHES "STM32.*" AND CMSIS_Dvendor STREQUAL "STMicroelectronics:13"))
  set(STMicroelectronics.sequencer.2.1.0 "1")
  message(DEBUG "CMSIS condition STMicroelectronics.sequencer.2.1.0 enabled")
else()
  set(STMicroelectronics.sequencer.2.1.0 0)
endif()


# condition: STMicroelectronics.sequencer.2.1.0:Seq Config
# description: STMicroelectronics Utility Sequencer Config
set(STMicroelectronics.sequencer.2.1.0_Seq_Config "$<NOT:$<STREQUAL:$<FILTER:${CMSIS_COMPONENTS_LIST},INCLUDE,.*Cclass:Utility#.*Cgroup:SEQUENCER#.*Csub:Core(#.*|$)>,>>")
message(DEBUG "CMSIS condition STMicroelectronics.sequencer.2.1.0_Seq_Config enabled")

# Files and components in this package
if("Cvendor:STMicroelectronics#Cclass:Utility#Cgroup:SEQUENCER#Csub:Core#Cversion:1.0.0" IN_LIST CMSIS_COMPONENTS_LIST)  # Utility Sequencer (SEQ) driver 
  message(DEBUG "Using component Utility_SEQUENCER_Core_1_0_0")
  target_compile_definitions(STMicroelectronics_sequencer_2_1_0 INTERFACE "-DCMSIS_USE_Utility_SEQUENCER_Core_1_0_0=1")
  target_include_directories(STMicroelectronics_sequencer_2_1_0 INTERFACE "${CMAKE_CURRENT_LIST_DIR}/.")
  target_include_directories(STMicroelectronics_sequencer_2_1_0 INTERFACE "${CMAKE_CURRENT_LIST_DIR}/templates")
  target_sources(STMicroelectronics_sequencer_2_1_0 INTERFACE "${CMAKE_CURRENT_LIST_DIR}/sequencer.c")
endif()

