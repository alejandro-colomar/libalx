################################################################################
##      Copyright (C) 2020        Alejandro Colomar Andrés                    ##
##      SPDX-License-Identifier:  GPL-2.0-only                                ##
################################################################################
##
## Deploy/delete stack
## ===================
##
################################################################################


################################################################################
##	include guard							      ##
################################################################################
if [ -n "${ALX_CONTAINERS_H}" ]; then
	return;
fi
export	ALX_CONTAINERS_H="/usr/local/lib/libalx/sh/containers.sh"


################################################################################
##	source								      ##
################################################################################
source	/usr/local/lib/libalx/sh/containers/kubernetes.sh;
source	/usr/local/lib/libalx/sh/containers/openshift.sh;
source	/usr/local/lib/libalx/sh/containers/swarm.sh;


################################################################################
##	definitions							      ##
################################################################################


################################################################################
##	functions							      ##
################################################################################
## sudo
function alx_stack_deploy()
{
	local	mode="$1";	## "swarm", "kubernetes", or "openshift"
	local	project="$2";
	local	stack="$3";

	case "${mode}" in
	"kubernetes")
		alx_kube_deploy		"${project}" "${stack}";
		;;
	"openshift")
		alx_oc_deploy		"${project}" "${stack}";
		;;
	"swarm")
		alx_swarm_deploy	"${project}" "${stack}";
		;;
	esac
}

function alx_stack_delete()
{
	local	mode="$1";	## "swarm", "kubernetes", or "openshift"
	local	stack="$2";

	case "${mode}" in
	"kubernetes")
		alx_kube_delete		"${stack}";
		;;
	"openshift")
		alx_oc_delete		"${stack}";
		;;
	"swarm")
		alx_swarm_delete	"${stack}";
		;;
	esac
}


################################################################################
##	end of file							      ##
################################################################################
