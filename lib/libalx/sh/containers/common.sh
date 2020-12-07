################################################################################
##      Copyright (C) 2020        Alejandro Colomar Andrés                    ##
##      SPDX-License-Identifier:  GPL-2.0-only                                ##
################################################################################
##
## Copy configs and secrets into /run/
## ===================================
##
################################################################################


################################################################################
##	include guard							      ##
################################################################################
if [ -n "${ALX_CONTAINERS_COMMON_H}" ]; then
	return;
fi
export	ALX_CONTAINERS_COMMON_H="/usr/local/lib/libalx/sh/containers/common.sh"


################################################################################
##	source								      ##
################################################################################


################################################################################
##	definitions							      ##
################################################################################


################################################################################
##	functions							      ##
################################################################################
## sudo
function alx_cp_configs()
{
	local	project="$1";

	mkdir -pv	/run/configs/;
	cp --remove-destination -LrvT					\
			run/configs/${project}/	/run/configs/${project} ||:;
}

## sudo
function alx_shred_configs()
{
	local	project="$1";

	local	config_files=$(find -L "/run/configs/${project}/" -type f);
	for file in ${config_files}; do
		shred -f --remove=wipe "${file}";
	done
	rm -rfv /run/configs/${project};
}

## sudo
function alx_cp_secrets()
{
	local	project="$1";

	mkdir -pv	/run/secrets/;
	cp --remove-destination -LrvT					\
			run/secrets/${project}/	/run/secrets/${project} ||:;
}

## sudo
function alx_shred_secrets()
{
	local	project="$1";

	local	secret_files=$(find -L "/run/secrets/${project}/" -type f);
	for file in ${secret_files}; do
		shred -f --remove=wipe "${file}";
	done
	rm -rfv /run/secrets/${project};
}


################################################################################
##	end of file							      ##
################################################################################
