#!/bin/sh

# =============================================================================
# Color Definitions
# see also: https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux
# =============================================================================

# Reset
Color_Off='\033[0m' # Text Reset

# Regular Colors
Black='\033[0;30m'  # Black
Red='\033[0;31m'    # Red
Green='\033[0;32m'  # Green
Yellow='\033[0;33m' # Yellow
Blue='\033[0;34m'   # Blue
Purple='\033[0;35m' # Purple
Cyan='\033[0;36m'   # Cyan
White='\033[0;37m'  # White

# Bold
BBlack='\033[1;30m'  # Black
BRed='\033[1;31m'    # Red
BGreen='\033[1;32m'  # Green
BYellow='\033[1;33m' # Yellow
BBlue='\033[1;34m'   # Blue
BPurple='\033[1;35m' # Purple
BCyan='\033[1;36m'   # Cyan
BWhite='\033[1;37m'  # White

# Underline
UBlack='\033[4;30m'  # Black
URed='\033[4;31m'    # Red
UGreen='\033[4;32m'  # Green
UYellow='\033[4;33m' # Yellow
UBlue='\033[4;34m'   # Blue
UPurple='\033[4;35m' # Purple
UCyan='\033[4;36m'   # Cyan
UWhite='\033[4;37m'  # White

# Background
On_Black='\033[40m'  # Black
On_Red='\033[41m'    # Red
On_Green='\033[42m'  # Green
On_Yellow='\033[43m' # Yellow
On_Blue='\033[44m'   # Blue
On_Purple='\033[45m' # Purple
On_Cyan='\033[46m'   # Cyan
On_White='\033[47m'  # White

# =============================================================================
# Log Level Definitions
# =============================================================================

export CMAKE_LOG_LEVEL_TRACE=2
export CMAKE_LOG_LEVEL_DEBUG=3
export CMAKE_LOG_LEVEL_INFO=4
export CMAKE_LOG_LEVEL_WARN=5
export CMAKE_LOG_LEVEL_ERROR=6

CMAKE_CURRENT_LOG_LEVEL=$CMAKE_LOG_LEVEL_INFO

# =============================================================================
# Functions Definitions
# =============================================================================

function log_message() {
    echo -e "$1"
}

function log_trace() {
    if [[ $CMAKE_CURRENT_LOG_LEVEL -le $CMAKE_LOG_LEVEL_TRACE ]]; then
        THIS_SCRIPT=$(echo $0 | awk -F "/" '{print $NF}')
        log_message "$BWhite[TRACE][$THIS_SCRIPT] $1 $Color_Off"
    fi
}

function log_debug() {
    if [[ $CMAKE_CURRENT_LOG_LEVEL -le $CMAKE_LOG_LEVEL_DEBUG ]]; then
        THIS_SCRIPT=$(echo $0 | awk -F "/" '{print $NF}')
        log_message "$Cyan[DEBUG][$THIS_SCRIPT] $1 $Color_Off"
    fi
}

function log_info() {
    THIS_SCRIPT=$(echo $0 | awk -F "/" '{print $NF}')
    log_message "$Green[INFO ][$THIS_SCRIPT] $1 $Color_Off"
}

function log_warn() {
    THIS_SCRIPT=$(echo $0 | awk -F "/" '{print $NF}')
    log_message "$Yellow[WARN ][$THIS_SCRIPT] $1 $Color_Off"
}

function log_error() {
    THIS_SCRIPT=$(echo $0 | awk -F "/" '{print $NF}')
    log_message "$Red[ERROR][$THIS_SCRIPT] $1 $Color_Off"
}

function log_fatal() {
    THIS_SCRIPT=$(echo $0 | awk -F "/" '{print $NF}')
    log_message "$On_Red[FATAL][$THIS_SCRIPT] $1$Color_Off"
    exit 1
}
