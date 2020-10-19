################################################################################
#	Copyright (C) 2019	Alejandro Colomar Andrés		       #
#	SPDX-License-Identifier:	LGPL-2.0-only			       #
################################################################################
#
# ANSI escape sequences
#
################################################################################


################################################################################
##	include guard							      ##
################################################################################
if [ -n "${ALX_ESCAPE_SEQUENCES_H}" ]; then
	return;
fi
export	ALX_ESCAPE_SEQUENCES_H="/usr/local/lib/libalx/sh/escape_sequences.sh"


################################################################################
#	constants							       #
################################################################################
export	SGR_RESET='\033[0m'
export	SGR_BOLD='\033[1m'
export	SGR_FAINT='\033[2m'
export	SGR_ITALIC='\033[3m'
export	SGR_UNDERLINE='\033[4m'
export	SGR_BLINK_SLOW='\033[5m'
export	SGR_BLINK_FAST='\033[6m'
export	SGR_REVERSE='\033[7m'
export	SGR_CONCEAL='\033[8m'
export	SGR_CROSSED='\033[9m'
export	SGR_FONT_0='\033[10m'
export	SGR_FONT_1='\033[11m'
export	SGR_FONT_2='\033[12m'
export	SGR_FONT_3='\033[13m'
export	SGR_FONT_4='\033[14m'
export	SGR_FONT_5='\033[15m'
export	SGR_FONT_6='\033[16m'
export	SGR_FONT_7='\033[17m'
export	SGR_FONT_8='\033[18m'
export	SGR_FONT_9='\033[19m'
export	SGR_FRAKTUR='\033[20m'
export	SGR_UNDERLINE_DOUBLE='\033[21m'
export	SGR_COLOR_OFF='\033[22m'
export	SGR_ITALIC_OFF='\033[23m'
export	SGR_UNDERLINE_OFF='\033[24m'
export	SGR_BLINK_OFF='\033[25m'

export	SGR_REVERSE_OFF='\033[27m'
export	SGR_CONCEAL_OFF='\033[28m'
export	SGR_CROSSED_OFF='\033[29m'
export	SGR_FGND_BLACK='\033[30m'
export	SGR_FGND_RED='\033[31m'
export	SGR_FGND_GREEN='\033[32m'
export	SGR_FGND_YELLOW='\033[33m'
export	SGR_FGND_BLUE='\033[34m'
export	SGR_FGND_MAGENTA='\033[35m'
export	SGR_FGND_CYAN='\033[36m'
export	SGR_FGND_WHITE='\033[37m'
#export	SGR_FGND_8_BIT='\033[38m'
export	SGR_FGND_DEFAULT='\033[39m'
export	SGR_BKGD_BLACK='\033[40m'
export	SGR_BKGD_RED='\033[41m'
export	SGR_BKGD_GREEN='\033[42m'
export	SGR_BKGD_YELLOW='\033[43m'
export	SGR_BKGD_BLUE='\033[44m'
export	SGR_BKGD_MAGENTA='\033[45m'
export	SGR_BKGD_CYAN='\033[46m'
export	SGR_BKGD_WHITE='\033[47m'
#export	SGR_BKGD_8_BIT='\033[48m'
export	SGR_BKGD_DEFAULT='\033[49m'

export	SGR_FGND_BRGH_BLACK='\033[90m'
export	SGR_FGND_BRGH_RED='\033[91m'
export	SGR_FGND_BRGH_GREEN='\033[92m'
export	SGR_FGND_BRGH_YELLOW='\033[93m'
export	SGR_FGND_BRGH_BLUE='\033[94m'
export	SGR_FGND_BRGH_MAGENTA='\033[95m'
export	SGR_FGND_BRGH_CYAN='\033[96m'
export	SGR_FGND_BRGH_WHITE='\033[97m'

export	SGR_BKGD_BRGH_BLACK='\033[100m'
export	SGR_BKGD_BRGH_RED='\033[101m'
export	SGR_BKGD_BRGH_GREEN='\033[102m'
export	SGR_BKGD_BRGH_YELLOW='\033[103m'
export	SGR_BKGD_BRGH_BLUE='\033[104m'
export	SGR_BKGD_BRGH_MAGENTA='\033[105m'
export	SGR_BKGD_BRGH_CYAN='\033[106m'
export	SGR_BKGD_BRGH_WHITE='\033[107m'


################################################################################
#	end of file							       #
################################################################################
