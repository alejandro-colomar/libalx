################################################################################
# Commands (CC, etc...)
CC		= gcc
CXX		= g++
AS		= as
AR		= ar
LD		= ld
SZ		= size
INSTALL		= cp -r -f $(v) #install -D -o root -g root $(v)
INSTALL_PROGRAM	= $(INSTALL) # -m 755
INSTALL_DATA	= $(INSTALL) # -m 644
LDCONFIG	= flock /tmp -c ldconfig

export	CC
export	CXX
export	AS
export	AR
export	LD
export	SZ
export	INSTALL
export	INSTALL_PROGRAM
export	INSTALL_DATA
export	LDCONFIG


################################################################################
######## End of file ###########################################################
################################################################################

