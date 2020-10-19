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
if [ -n "${ALX_CONTAINERS_OPENSHIFT_H}" ]; then
	return;
fi
export	ALX_CONTAINERS_OPENSHIFT_H="/usr/local/lib/libalx/sh/containers/openshift.sh"


################################################################################
##	source								      ##
################################################################################
source	/usr/local/lib/libalx/sh/containers/common.sh;
source	/usr/local/lib/libalx/sh/containers/kubernetes.sh;


################################################################################
##	definitions							      ##
################################################################################


################################################################################
##	functions							      ##
################################################################################
## sudo
function alx_oc_create_configmaps__()
{
	local	project="$1";
	local	stack="$2";
	local	kubectl="oc";

	alx_kube_create_configmaps__	"${project}" "${stack}" "${kubectl}";
}

## sudo
function alx_oc_create_secrets__()
{
	local	project="$1";
	local	stack="$2";
	local	kubectl="oc";

	alx_kube_create_secrets__	"${project}" "${stack}" "${kubectl}";
}

## sudo
function alx_oc_deploy()
{
	local	project="$1";
	local	stack="$2";

	oc new-project "${stack}";
	alx_oc_create_configmaps__	"${project}" "${stack}";
	alx_oc_create_secrets__		"${project}" "${stack}";

	local	yaml_files=$(find -L "etc/docker/openshift/" -type f |sort);
	for file in ${yaml_files}; do
		oc apply -f "${file}" -n "${stack}";
	done
}

function alx_oc_delete()
{
	local	stack="$1";

	oc delete project "${stack}";
}


################################################################################
##	end of file							      ##
################################################################################
