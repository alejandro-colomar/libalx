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
if [ -n "${ALX_CONTAINERS_KUBERNETES_H}" ]; then
	return;
fi
export	ALX_CONTAINERS_KUBERNETES_H="/usr/local/lib/libalx/sh/containers/kubernetes.sh"


################################################################################
##	source								      ##
################################################################################
source	/usr/local/lib/libalx/sh/containers/common.sh;


################################################################################
##	definitions							      ##
################################################################################


################################################################################
##	functions							      ##
################################################################################
## sudo
function alx_kube_create_configmaps__()
{
	local	project="$1";
	local	stack="$2";
	local	kubectl="$3";

	alx_cp_configs	"${project}";

	local	cm_files=$(find -L "/run/configs/${project}/" -type f);
	for file in ${cm_files}; do
		cm="${file#/run/configs/${project}/}";
		cm="${cm//\//-}";
		cm="${cm//./-}";
		cm="${cm//_/-}";
		cm="${cm}-${project}-cm";
		${kubectl} create configmap "${cm}" --from-file "${file}"	\
				-n "${stack}";
	done

	alx_shred_configs	"${project}";
}

## sudo
function alx_kube_create_secrets__()
{
	local	project="$1";
	local	stack="$2";
	local	kubectl="$3";

	alx_cp_secrets	"${project}";

	local	secret_files=$(find -L "/run/secrets/${project}/" -type f);
	for file in ${secret_files}; do
		secret="${file#/run/secrets/${project}/}";
		secret="${secret//\//-}";
		secret="${secret//./-}";
		secret="${secret//_/-}";
		secret="${secret}-${project}-secret";
		${kubectl} create secret generic "${secret}"		\
				--from-file "${file}" -n "${stack}";
	done

	alx_shred_secrets	"${project}";
}

## sudo
function alx_kube_deploy()
{
	local	project="$1";
	local	stack="$2";
	local	kubectl="kubectl";

	kubectl create namespace "${stack}";
	alx_kube_create_configmaps__	"${project}" "${stack}" "${kubectl}";
	alx_kube_create_secrets__	"${project}" "${stack}" "${kubectl}";

	local	yaml_files=$(find -L "etc/docker/kubernetes/" -type f |sort);
	for file in ${yaml_files}; do
		kubectl apply -f "${file}" -n "${stack}";
	done
}

function alx_kube_delete()
{
	local	stack="$1";

	kubectl delete namespace "${stack}";
}


################################################################################
##	end of file							      ##
################################################################################
