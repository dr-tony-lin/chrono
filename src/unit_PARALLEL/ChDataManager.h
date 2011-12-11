#ifndef CH_SYSTEMGPUKERNEL_H
#define CH_SYSTEMGPUKERNEL_H

//////////////////////////////////////////////////
//
//   ChGPUDataManager.h
//
//   GPU Data Manager Class
//
//   HEADER file for CHRONO,
//	 Multibody dynamics engine
//
// ------------------------------------------------
// 	 Copyright:Alessandro Tasora / DeltaKnowledge
//             www.deltaknowledge.com
// ------------------------------------------------
///////////////////////////////////////////////////

#include "ChCuda.h"
#include <vector>

using namespace std;

namespace chrono {
struct gpu_container {

		thrust::device_vector<float3> device_norm_data;
		thrust::device_vector<float3> device_cpta_data;
		thrust::device_vector<float3> device_cptb_data;
		thrust::device_vector<float> device_dpth_data;
		thrust::device_vector<int2> device_bids_data;
		thrust::device_vector<float3> device_ObA_data;

		thrust::device_vector<float3> device_ObB_data;
		thrust::device_vector<float3> device_ObC_data;
		thrust::device_vector<float4> device_ObR_data;
		thrust::device_vector<int2> device_fam_data;
		thrust::device_vector<int3> device_typ_data;
		thrust::device_vector<float3> device_aabb_data;
		thrust::device_vector<uint3> device_bin_data;
		thrust::device_vector<long long> device_pair_data;

		thrust::device_vector<float3> device_vel_data;
		thrust::device_vector<float3> device_omg_data;
		thrust::device_vector<float3> device_pos_data;
		thrust::device_vector<float4> device_rot_data;
		thrust::device_vector<float3> device_inr_data;
		thrust::device_vector<float3> device_frc_data;
		thrust::device_vector<float3> device_trq_data;
		thrust::device_vector<float3> device_acc_data;
		thrust::device_vector<float3> device_aux_data;
		thrust::device_vector<float3> device_dem_data;
		thrust::device_vector<float3> device_lim_data;
		thrust::device_vector<float3> device_gyr_data;
		thrust::device_vector<float3> device_fap_data;

		thrust::device_vector<float4> device_bilateral_data;
		thrust::device_vector<float3> device_gam_data;
		thrust::device_vector<float> device_dgm_data;

		thrust::device_vector<float3> vel_update;
		thrust::device_vector<float3> omg_update;
		thrust::device_vector<uint> update_offset;
		thrust::device_vector<uint> body_number;
		thrust::device_vector<uint> offset_counter;

		float3 min_bounding_point, max_bounding_point;
		uint number_of_contacts;
		uint number_of_contacts_possible;
		uint number_of_models;
		uint number_of_objects;
		uint number_of_bilaterals;
		uint number_of_updates;
};

class ChApiGPU ChGPUDataManager {
	public:
		ChGPUDataManager(unsigned int ngpu = 1);
		void HostToDevice();
		void DeviceToHost();
		/// Depending on the number of GPUs this function will split the

		gpu_container gpu_data;

		uint number_of_contacts;
		uint number_of_contacts_possible;
		uint number_of_models;
		uint number_of_objects;
		uint number_of_bilaterals;
		uint number_of_updates;
		float3 min_bounding_point, max_bounding_point;

		//contact data
		thrust::host_vector<float3> host_norm_data;
		thrust::host_vector<float3> host_cpta_data;
		thrust::host_vector<float3> host_cptb_data;
		thrust::host_vector<float> host_dpth_data;
		thrust::host_vector<int2> host_bids_data;
		thrust::host_vector<long long> host_pair_data;
		thrust::host_vector<float3> host_gam_data;
		thrust::host_vector<float> host_dgm_data;
		//collision data
		thrust::host_vector<float3> host_ObA_data;
		thrust::host_vector<float3> host_ObB_data;
		thrust::host_vector<float3> host_ObC_data;
		thrust::host_vector<float4> host_ObR_data;
		thrust::host_vector<int2> host_fam_data;
		thrust::host_vector<int3> host_typ_data;
		thrust::host_vector<float3> host_aabb_data;
		thrust::host_vector<uint3> host_bin_data;

		//object data
		thrust::host_vector<float3> host_vel_data;
		thrust::host_vector<float3> host_omg_data;
		thrust::host_vector<float3> host_pos_data;
		thrust::host_vector<float4> host_rot_data;
		thrust::host_vector<float3> host_inr_data;
		thrust::host_vector<float3> host_frc_data;
		thrust::host_vector<float3> host_trq_data;
		thrust::host_vector<float3> host_acc_data;
		thrust::host_vector<float3> host_aux_data;
		thrust::host_vector<float3> host_lim_data;
		thrust::host_vector<float3> host_dem_data;
		thrust::host_vector<float3> host_gyr_data;
		thrust::host_vector<float3> host_fap_data;

		//bilateral data
		thrust::host_vector<float4> host_bilateral_data;

};
}

#endif
